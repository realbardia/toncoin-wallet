#include "tonlibbackend.h"
#include "core/tools/crypto.h"

#include <tonlib/Client.h>
#include <td/utils/base64.h>
#include <td/utils/optional.h>
#include <tonlib/tonlib/keys/bip39.h>
#include <crypto/smc-envelope/WalletInterface.h>

#include <optional>

#include <QDir>
#include <QDebug>
#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>
#include <QSemaphore>
#include <QDataStream>
#include <QFile>
#include <QPointer>
#include <QCryptographicHash>

#define KEYS_DB_PATH QString(mKeysDir + QStringLiteral("/key_db"))
#define GENERATE_ID QRandomGenerator::global()->generate64()
#define BALANCE_RATIO (1/1000000000.0)

#define ERR(OBJ) \
    [](const ton::tl_object_ptr<tonlib_api::error> &err){ \
        Error e; \
        e.code = err->code_; \
        e.message = QString::fromStdString(err->message_); \
        return e; \
    }(ton::move_tl_object_as<tonlib_api::error>(OBJ.object))

using tonlib_api::make_object;
using namespace TON::Wallet;
using namespace std::string_literals;

const std::string TonLibBackend::v4r2_code = "te6cckECFAEAAtQAART/APSkE/S88sgLAQIBIAIDAgFIBAUE+PKDCNcYINMf0x/THwL4I7vyZO1E0NMf0x/T//QE0VFDuvKhUVG68qIF+QFUEGT5EPKj+AAkpMjLH1JAyx9SMMv/UhD0AMntVPgPAdMHIcAAn2xRkyDXSpbTB9QC+wDoMOAhwAHjACHAAuMAAcADkTDjDQOkyMsfEssfy/8QERITAubQAdDTAyFxsJJfBOAi10nBIJJfBOAC0x8hghBwbHVnvSKCEGRzdHK9sJJfBeAD+kAwIPpEAcjKB8v/ydDtRNCBAUDXIfQEMFyBAQj0Cm+hMbOSXwfgBdM/yCWCEHBsdWe6kjgw4w0DghBkc3RyupJfBuMNBgcCASAICQB4AfoA9AQw+CdvIjBQCqEhvvLgUIIQcGx1Z4MesXCAGFAEywUmzxZY+gIZ9ADLaRfLH1Jgyz8gyYBA+wAGAIpQBIEBCPRZMO1E0IEBQNcgyAHPFvQAye1UAXKwjiOCEGRzdHKDHrFwgBhQBcsFUAPPFiP6AhPLassfyz/JgED7AJJfA+ICASAKCwBZvSQrb2omhAgKBrkPoCGEcNQICEekk30pkQzmkD6f+YN4EoAbeBAUiYcVnzGEAgFYDA0AEbjJftRNDXCx+AA9sp37UTQgQFA1yH0BDACyMoHy//J0AGBAQj0Cm+hMYAIBIA4PABmtznaiaEAga5Drhf/AABmvHfaiaEAQa5DrhY/AAG7SB/oA1NQi+QAFyMoHFcv/ydB3dIAYyMsFywIizxZQBfoCFMtrEszMyXP7AMhAFIEBCPRR8qcCAHCBAQjXGPoA0z/IVCBHgQEI9FHyp4IQbm90ZXB0gBjIywXLAlAGzxZQBPoCFMtqEssfyz/Jc/sAAgBsgQEI1xj6ANM/MFIkgQEI9Fnyp4IQZHN0cnB0gBjIywXLAlAFzxZQA/oCE8tqyx8Syz/Jc/sAAAr0AMntVGliJeU="s;
const std::string TonLibBackend::v4r1_code = "te6cckECFQEAAvUAART/APSkE/S88sgLAQIBIAIDAgFIBAUE+PKDCNcYINMf0x/THwL4I7vyY+1E0NMf0x/T//QE0VFDuvKhUVG68qIF+QFUEGT5EPKj+AAkpMjLH1JAyx9SMMv/UhD0AMntVPgPAdMHIcAAn2xRkyDXSpbTB9QC+wDoMOAhwAHjACHAAuMAAcADkTDjDQOkyMsfEssfy/8REhMUA+7QAdDTAwFxsJFb4CHXScEgkVvgAdMfIYIQcGx1Z70ighBibG5jvbAighBkc3RyvbCSXwPgAvpAMCD6RAHIygfL/8nQ7UTQgQFA1yH0BDBcgQEI9ApvoTGzkl8F4ATTP8glghBwbHVnupEx4w0kghBibG5juuMABAYHCAIBIAkKAFAB+gD0BDCCEHBsdWeDHrFwgBhQBcsFJ88WUAP6AvQAEstpyx9SEMs/AFL4J28ighBibG5jgx6xcIAYUAXLBSfPFiT6AhTLahPLH1Iwyz8B+gL0AACSghBkc3Ryuo41BIEBCPRZMO1E0IEBQNcgyAHPFvQAye1UghBkc3Rygx6xcIAYUATLBVjPFiL6AhLLassfyz+UEDRfBOLJgED7AAIBIAsMAFm9JCtvaiaECAoGuQ+gIYRw1AgIR6STfSmRDOaQPp/5g3gSgBt4EBSJhxWfMYQCAVgNDgARuMl+1E0NcLH4AD2ynftRNCBAUDXIfQEMALIygfL/8nQAYEBCPQKb6ExgAgEgDxAAGa3OdqJoQCBrkOuF/8AAGa8d9qJoQBBrkOuFj8AAbtIH+gDU1CL5AAXIygcVy//J0Hd0gBjIywXLAiLPFlAF+gIUy2sSzMzJcfsAyEAUgQEI9FHypwIAbIEBCNcYyFQgJYEBCPRR8qeCEG5vdGVwdIAYyMsFywJQBM8WghAF9eEA+gITy2oSyx/JcfsAAgBygQEI1xgwUgKBAQj0WfKn+CWCEGRzdHJwdIAYyMsFywJQBc8WghAF9eEA+gIUy2oTyx8Syz/Jc/sAAAr0AMntVEap808="s;

class TonLibBackend::Engine: public QThread
{
public:

    struct ResposeUnit {
        std::function<void(tonlib::Client::Response)> callback;
        QPointer<QObject> receiver;
    };

    Engine(QObject *parent) : mParent(parent) {}
    virtual ~Engine() {}

    void append(tonlib_api::object_ptr<tonlib_api::Function> func, QObject *receiver, const std::function<void(tonlib::Client::Response)> &responseCallback) {
        tonlib::Client::Request req;
        req.id = GENERATE_ID;
        req.function = std::move(func);

        ResposeUnit u;
        u.callback = responseCallback;
        u.receiver = receiver? receiver : this;

        mMutex.lock();
        mCallbacks[req.id] = u;
        mMutex.unlock();

        mClient.send(std::move(req));
    }

    void doTerminate() {
        mTerimnated = true;

        auto close_fnc = make_object<tonlib_api::close>();
        append(std::move(close_fnc), this, [](tonlib::Client::Response){});
    }

protected:
    void run() override {
        while (!mTerimnated)
        {
            auto resp = mClient.receive(INT_MAX);
            if (resp.id)
            {
                mMutex.lock();
                auto unit = mCallbacks.take(resp.id);
                mMutex.unlock();

                auto resp_ptr = std::make_shared<tonlib::Client::Response>(std::move(resp));
                QMetaObject::invokeMethod(mParent, [resp_ptr, unit](){
                    if (!unit.receiver)
                        return;
                    unit.callback(std::move(*resp_ptr));
                }, Qt::QueuedConnection);
            }
        }
    }

private:
    tonlib::Client mClient;
    QObject *mParent;

    QHash<quint64, ResposeUnit> mCallbacks;

    QMutex mMutex;
    bool mTerimnated = false;
};


class TonLibBackend::Private
{
public:
    struct KeyInfo {
        std::string public_key;
        td::SecureString secret;
        std::optional<std::string> password;
        bool encrypted;
    };

    tonlib_api::object_ptr<tonlib_api::inputKeyRegular> getInputKey(const QByteArray &publicKey)
    {
        if (!keys.contains(publicKey))
            return nullptr;

        const auto k = keys.value(publicKey);

        auto key = make_object<tonlib_api::key>();
        key->public_key_ = k->public_key;
        key->secret_ = k->secret.copy();

        td::SecureString password;
        if (k->password.has_value())
            password = td::SecureString(k->password.value());

        return make_object<tonlib_api::inputKeyRegular>(std::move(key), std::move(password));
    }

    tonlib_api::object_ptr<tonlib_api::InitialAccountState> getInitialAccountState(const QByteArray &publicKey, const QString &walletVersion, td::int32 &revision, qint32 seqNo)
    {
        const auto version_lowerCase = walletVersion.toLower();
        if (version_lowerCase == QStringLiteral("v3r1") || version_lowerCase == QStringLiteral("v3r2"))
        {
            revision = version_lowerCase.right(1).toInt();
            return make_object<tonlib_api::wallet_v3_initialAccountState>(publicKey.toStdString(), walletId);
        }
        else if (version_lowerCase == QStringLiteral("v4r1") || version_lowerCase == QStringLiteral("v4r2"))
        {
            revision = version_lowerCase.right(1).toInt();

            auto dataCell = vm::CellBuilder()
                .store_long(seqNo, 32)
                .store_long(walletId + workchainId, 32)
                .store_bytes( block::PublicKey::parse(publicKey.toStdString()).move_as_ok().key )
                .store_zeroes(1)
                .finalize();
            std::string data = vm::std_boc_serialize(std::move(dataCell)).move_as_ok().as_slice().str();

            auto code = td::base64_decode(td::Slice(revision == 1? v4r1_code : v4r2_code)).move_as_ok();

            return make_object<tonlib_api::raw_initialAccountState>(code, data);
        }
        else
        {
            qDebug() << "Bad wallet version:" << walletVersion;
            return nullptr;
        }
    }

    QHash<QByteArray, std::shared_ptr<KeyInfo>> keys;

    td::uint32 walletId = 0;
    td::int32 workchainId = 0;
};

TonLibBackend::TonLibBackend(QObject *parent)
    : AbstractWalletBackend(parent)
{
    p = new Private;
    SET_VERBOSITY_LEVEL(0);
//    SET_VERBOSITY_LEVEL(3);

    setWalletVersion(QStringLiteral("v4r2"));

    mEngine = new Engine(this);
    mEngine->start();
}

TonLibBackend::~TonLibBackend()
{
    mEngine->doTerminate();
    mEngine->quit();
    mEngine->wait();

    delete mEngine;
    delete p;
}

void TonLibBackend::init(const QString &keysDir, const QByteArray &configs, QObject *receiver, const std::function<void(bool done, const Error &error)> &callback)
{
    mKeysDir = keysDir;

    QDir().mkpath(mKeysDir);
    loadKeys();

    auto ks_type = make_object<tonlib_api::keyStoreTypeDirectory>(mKeysDir.toStdString());
    auto config = make_object<tonlib_api::config>(configs.toStdString(), std::string(), false, false);

    auto init_fnc = make_object<tonlib_api::init>(make_object<tonlib_api::options>(std::move(config), std::move(ks_type)));

    mEngine->append(std::move(init_fnc), receiver, [callback, this](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(false, ERR(resp));
        else
        {
            auto info = ton::move_tl_object_as<tonlib_api::options_info>(resp.object);
            if (info->config_info_)
            {
                p->walletId = info->config_info_->default_wallet_id_;
            }
            callback(true, Error());
        }
    });
}

void TonLibBackend::createNewKey(QObject *receiver, const std::function<void (const QByteArray &, const Error &)> &callback)
{
    std::string entropy;
    while (entropy.size() < 20)
        entropy += (char)QRandomGenerator::securelySeeded().generate();

    auto createKey_fnc = make_object<tonlib_api::createNewKey>(td::SecureString(), td::SecureString(), td::SecureString(entropy));
    mEngine->append(std::move(createKey_fnc), receiver, [callback, this](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QByteArray(), ERR(resp));
        else
        {
            auto key = ton::move_tl_object_as<tonlib_api::key>(resp.object);
            const auto publicKey = QByteArray::fromStdString(key->public_key_);

            auto info = std::make_shared<Private::KeyInfo>();
            info->public_key = key->public_key_;
            info->secret = std::move(key->secret_);
            info->encrypted = false;

            p->keys[publicKey] = info;
            storeKeys();

            callback(publicKey, Error());
        }
    });
}

void TonLibBackend::deleteKey(const QByteArray &publicKey, QObject *receiver, const std::function<void (bool, const Error &)> &callback)
{
    if (!p->keys.contains(publicKey))
        return;

    const auto &k = p->keys.value(publicKey);
    auto key = make_object<tonlib_api::key>(k->public_key, td::SecureString(k->secret.as_slice()));
    auto deleteKey_fnc = make_object<tonlib_api::deleteKey>(std::move(key));
    mEngine->append(std::move(deleteKey_fnc), receiver, [callback, publicKey, this](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(false, ERR(resp));
        else
        {
            p->keys.remove(publicKey);
            storeKeys();
            callback(true, Error());
        }
    });
}

void TonLibBackend::exportKey(const QByteArray &publicKey, QObject *receiver, const std::function<void (const QStringList &, const Error &)> &callback)
{
    auto input = p->getInputKey(publicKey);
    if (!input)
        return;

    auto exportKey_fnc = make_object<tonlib_api::exportKey>(std::move(input));
    mEngine->append(std::move(exportKey_fnc), receiver, [callback](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QStringList(), ERR(resp));
        else
        {
            auto keys = ton::move_tl_object_as<tonlib_api::exportedKey>(resp.object);

            QStringList words;
            for (const auto &w: keys->word_list_)
                words << QString::fromStdString(w.as_slice().str());

            callback(words, Error());
        }
    });
}

void TonLibBackend::importKeys(const QStringList &words, QObject *receiver, const std::function<void (const QByteArray &, const Error &)> &callback)
{
    std::vector<td::SecureString> word_list;
    for (const auto &w: words)
        word_list.push_back( td::SecureString(w.toStdString()) );

    auto key = make_object<tonlib_api::exportedKey>(std::move(word_list));

    auto importKey_fnc = make_object<tonlib_api::importKey>(td::SecureString(""), td::SecureString(""), std::move(key));
    mEngine->append(std::move(importKey_fnc), receiver, [callback, this](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QByteArray(), ERR(resp));
        else
        {
            auto key = ton::move_tl_object_as<tonlib_api::key>(resp.object);
            const auto publicKey = QByteArray::fromStdString(key->public_key_);

            auto info = std::make_shared<Private::KeyInfo>();
            info->public_key = key->public_key_;
            info->secret = std::move(key->secret_);
            info->encrypted = false;

            p->keys[publicKey] = info;
            storeKeys();

            callback(publicKey, Error());
        }
    });
}

void TonLibBackend::getAddress(const QByteArray &publicKey, QObject *receiver, const std::function<void (const QString &, const Error &)> &callback)
{
    td::int32 revision;
    auto state = p->getInitialAccountState(publicKey, walletVersion(), revision, 0);
    if (!state)
        return;

    auto getAddress_fnc = make_object<tonlib_api::getAccountAddress>(std::move(state), revision, p->workchainId);
    mEngine->append(std::move(getAddress_fnc), receiver, [callback](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QString(), ERR(resp));
        else
        {
            auto adrs = ton::move_tl_object_as<tonlib_api::accountAddress>(resp.object);
            const auto accountAddress = QString::fromStdString(adrs->account_address_);

            callback(accountAddress, Error());
        }
    });

}

void TonLibBackend::getAccountState(const QString &address, QObject *receiver, const std::function<void (const AccountState &, const Error &)> &callback)
{
    auto accountAddress = make_object<tonlib_api::accountAddress>(address.toStdString());
    auto getAccountState_fnc = make_object<tonlib_api::getAccountState>( std::move(accountAddress) );
    mEngine->append(std::move(getAccountState_fnc), receiver, [callback](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(AccountState(), ERR(resp));
        else
        {
            auto state = ton::move_tl_object_as<tonlib_api::fullAccountState>(resp.object);
            AccountState s;
            s.address = QString::fromStdString(state->address_->account_address_);
            s.balance = state->balance_ * (state->balance_ > 0) * BALANCE_RATIO;
            s.datetime = QDateTime::fromSecsSinceEpoch(state->sync_utime_);
            s.lastTransaction.id = state->last_transaction_id_->lt_;
            s.lastTransaction.hash = QByteArray::fromStdString(state->last_transaction_id_->hash_);

            switch (state->account_state_->get_id())
            {
            case tonlib_api::raw_accountState::ID:
            {
                auto raw = ton::move_tl_object_as<tonlib_api::raw_accountState>(state->account_state_);

                ton::WalletInterface::State state;
                state.code = vm::std_boc_deserialize(td::Slice(raw->code_)).move_as_ok();
                state.data = vm::std_boc_deserialize(td::Slice(raw->data_)).move_as_ok();
                ton::SmartContract smc(std::move(state));
                s.sequence = ton::GenericAccount::get_seqno(smc).move_as_ok();
            }
                break;
            case tonlib_api::wallet_v3_accountState::ID:
            {
                auto w3 = ton::move_tl_object_as<tonlib_api::wallet_v3_accountState>(state->account_state_);
                s.sequence = w3->seqno_;
            }
                break;
            case tonlib_api::wallet_highload_v2_accountState::ID:
            case tonlib_api::wallet_highload_v1_accountState::ID:
            case tonlib_api::rwallet_accountState::ID:
                qDebug() << "Unsupported state";
                break;
            }

            callback(s, Error());
        }
    });
}

void TonLibBackend::getTransactions(const QByteArray &publicKey, const TransactionId &from, int count, QObject *receiver, const std::function<void (const QList<Transaction> &, const Error &)> &callback)
{
    getAddress(publicKey, receiver, [this, publicKey, from, count, receiver, callback] (const QString &address, const Error &err) {
        if (err.code)
        {
            callback(QList<Transaction>(), err);
            return;
        }

        auto doRequest = [this, publicKey, count, receiver, callback](const TransactionId &from, const QString &address, const Error &err){
            auto input = p->getInputKey(publicKey);
            if (err.code || !input)
            {
                callback(QList<Transaction>(), err);
                return;
            }

            auto accountAddress = make_object<tonlib_api::accountAddress>(address.toStdString());
            auto fromObject = make_object<tonlib_api::internal_transactionId>((std::int64_t)from.id, from.hash.toStdString());

            auto getTransactions_fnc = make_object<tonlib_api::raw_getTransactionsV2>(
                            std::move(input),
                            std::move(accountAddress),
                            std::move(fromObject),
                            (std::int32_t)count,
                            true
                        );

            mEngine->append(std::move(getTransactions_fnc), receiver, [callback, address](tonlib::Client::Response resp){
                if (resp.object->get_id() == tonlib_api::error::ID)
                    callback(QList<Transaction>(), ERR(resp));
                else
                {
                    auto transactions = ton::move_tl_object_as<tonlib_api::raw_transactions>(resp.object);
                    QList<Transaction> res;
                    for (const auto &t_: transactions->transactions_)
                    {
                        auto createTransaction = [&](const tonlib_api::object_ptr<tonlib_api::raw_message> &msg){
                            Transaction t;
                            t.source = QString::fromStdString(msg->source_->account_address_);
                            t.destination = QString::fromStdString(msg->destination_->account_address_);
                            t.unknown = (t.source.isEmpty() || t.destination.isEmpty());

                            t.fee = t_->fee_ * BALANCE_RATIO;
                            t.storage_fee = t_->storage_fee_ * BALANCE_RATIO;
                            t.other_fee = t_->other_fee_ * BALANCE_RATIO;
                            t.value = msg->value_ * BALANCE_RATIO;

                            t.id.id = t_->transaction_id_->lt_;
                            t.id.hash = QByteArray::fromStdString(t_->transaction_id_->hash_);
                            t.datetime = QDateTime::fromSecsSinceEpoch(t_->utime_);
                            t.body_hash = QByteArray::fromStdString(t_->in_msg_->body_hash_);
                            t.sent = (t.source == address);

                            switch (msg->msg_data_->get_id())
                            {
                            case tonlib_api::msg_dataRaw::ID:
                            {
                                auto obj = ton::move_tl_object_as<tonlib_api::msg_dataRaw>(std::move(msg->msg_data_));
                                t.raw_message = QByteArray::fromStdString(obj->body_);
                            }
                                break;
                            case tonlib_api::msg_dataText::ID:
                            {
                                auto obj = ton::move_tl_object_as<tonlib_api::msg_dataText>(std::move(msg->msg_data_));
                                t.message = QString::fromStdString(obj->text_);
                            }
                                break;
                            case tonlib_api::msg_dataDecryptedText::ID:
                            {
                                auto obj = ton::move_tl_object_as<tonlib_api::msg_dataDecryptedText>(std::move(msg->msg_data_));
                                t.message = QString::fromStdString(obj->text_);
                            }
                                break;
                            case tonlib_api::msg_dataEncryptedText::ID:
                            {
                                auto obj = ton::move_tl_object_as<tonlib_api::msg_dataEncryptedText>(std::move(msg->msg_data_));
                                t.message = QString::fromStdString(obj->text_);
                            }
                                break;
                            }

                            res << t;
                        };

                        if (t_->out_msgs_.size() == 0)
                            createTransaction(t_->in_msg_);
                        for(const auto &msg: t_->out_msgs_)
                            createTransaction(msg);
                    }

                    callback(res, Error());
                }
            });
        };

        if (from.id == 0)
        {
            getAccountState(address, receiver, [doRequest, address, callback](const AccountState &state, const Error &err){
                if (err.code)
                    callback(QList<Transaction>(), err);
                else
                    doRequest(state.lastTransaction, address, err);
            });
        }
        else
            doRequest(from, address, err);
    });
}

void TonLibBackend::prepareTransfer(const QByteArray &publicKey, const QString &dest, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void (const PreparedTransferItem &item, const Error &)> &callback)
{
    getAddress(publicKey, receiver, [this, publicKey, dest, value, message, encryption, force, receiver, callback] (const QString &from, const Error &err) {
        if (err.code)
        {
            callback(PreparedTransferItem(), err);
            return;
        }

        getAccountState(from, this, [this, publicKey, dest, value, message, encryption, force, receiver, callback, from](const AccountState &accountState, const Error &err){
            if (err.code)
            {
                callback(PreparedTransferItem(), err);
                return;
            }

            auto input = p->getInputKey(publicKey);
            if (!input)
                return;

            auto pem_fnc = make_object<tonlib_api::exportPemKey>(std::move(input), td::SecureString());
            mEngine->append(std::move(pem_fnc), this, [this, publicKey, dest, value, message, encryption, force, receiver, callback, from, accountState](tonlib::Client::Response resp){
                auto input = p->getInputKey(publicKey);
                if (!input)
                    return;

                if (resp.object->get_id() == tonlib_api::error::ID)
                {
                    callback(PreparedTransferItem(), ERR(resp));
                    return;
                }
                else
                {
                    auto pem = ton::move_tl_object_as<tonlib_api::exportedPemKey>(resp.object);

                    td::Ed25519::PrivateKey prvKey = td::Ed25519::PrivateKey::from_pem(pem->pem_.as_slice(), td::Slice()).move_as_ok();
                    td::Ed25519::PublicKey pubKey(td::SecureString(block::PublicKey::parse(publicKey.toStdString()).move_as_ok().key));

                    td::int32 revision;
                    auto state = p->getInitialAccountState(publicKey, walletVersion(), revision, 0);

                    const qint64 amount = value / BALANCE_RATIO;

                    auto dest_address = make_object<tonlib_api::accountAddress>(dest.toStdString());
                    auto from_address = make_object<tonlib_api::accountAddress>(from.toStdString());

                    tonlib_api::object_ptr<tonlib_api::Function> query_fnc;
                    const auto version_lowerCase = walletVersion().toLower();
                    if (version_lowerCase == QStringLiteral("v3r1") || version_lowerCase == QStringLiteral("v3r2"))
                    {
                        tonlib_api::object_ptr<tonlib_api::msg_Data> data;
                        if (encryption)
                            data = make_object<tonlib_api::msg_dataDecryptedText>(message.toStdString());
                        else
                            data = make_object<tonlib_api::msg_dataText>(message.toStdString());

                        auto msg = make_object<tonlib_api::msg_message>(std::move(dest_address), "", amount, std::move(data), -1);

                        std::vector<tonlib_api::object_ptr<tonlib_api::msg_message>> messages;
                        messages.push_back( std::move(msg) );

                        auto action = make_object<tonlib_api::actionMsg>(std::move(messages), force);

                        query_fnc = make_object<tonlib_api::createQuery>(std::move(input), std::move(from_address), 60, std::move(action), (state? std::move(state) : nullptr));
                    }
                    else if (version_lowerCase == QStringLiteral("v4r1") || version_lowerCase == QStringLiteral("v4r2"))
                    {
                        const auto revision = version_lowerCase.right(1).toInt();

                        vm::CellBuilder cb; cb
                            .store_long(p->walletId + p->workchainId, 32)
                            .store_long(QDateTime::currentSecsSinceEpoch()+60, 32)
                            .store_long(accountState.sequence, 32)
                            .store_long(0, 8)
                            .store_long(3, 8);

                        {
                            ton::WalletInterface::Gift gift;
                            gift.destination = block::StdAddress::parse(td::Slice(dest.toStdString())).move_as_ok();
                            gift.message = message.toStdString();
                            gift.is_encrypted = encryption;
                            gift.gramms = amount;
                            gift.send_mode = 3;

                            cb.store_long(3, 8).store_ref(ton::WalletInterface::create_int_message(gift));
                        }

                        auto external_msg = cb.finalize();

                        auto signature = prvKey.sign(external_msg->get_hash().as_slice()).move_as_ok();
                        auto body_msg = vm::CellBuilder().store_bytes(signature).append_cellslice(vm::load_cell_slice(external_msg)).finalize();
                        auto body_msg_cells = vm::std_boc_serialize(std::move(body_msg)).move_as_ok().as_slice().str();

                        auto dataCell = vm::CellBuilder()
                            .store_long(accountState.sequence, 32)
                            .store_long(p->walletId + p->workchainId, 32)
                            .store_bytes( block::PublicKey::parse(publicKey.toStdString()).move_as_ok().key )
                            .store_zeroes(1)
                            .finalize();
                        std::string data = vm::std_boc_serialize(std::move(dataCell)).move_as_ok().as_slice().str();

                        auto code = td::base64_decode(td::Slice(revision == 1? v4r1_code : v4r2_code)).move_as_ok();

                        query_fnc = make_object<tonlib_api::raw_createQuery>(std::move(from_address), code, data, body_msg_cells);
                    }
                    else
                    {
                        qDebug() << "Bad wallet version:" << walletVersion();
                        return;
                    }


                    mEngine->append(std::move(query_fnc), receiver, [callback](tonlib::Client::Response resp){
                        if (resp.object->get_id() == tonlib_api::error::ID)
                            callback(PreparedTransferItem(), ERR(resp));
                        else
                        {
                            auto info = ton::move_tl_object_as<tonlib_api::query_info>(resp.object);

                            PreparedTransferItem p;
                            p.id = info->id_;
                            p.body_hash = QByteArray::fromStdString(info->body_hash_);

                            callback(p, Error());
                        }
                    });
                }
            });
        });
    });
}

void TonLibBackend::estimateTransfer(const QByteArray &publicKey, const QString &dest, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void (const Fee &, const Error &)> &callback)
{
    prepareTransfer(publicKey, dest, value, message, encryption, force, receiver, [this, receiver, callback](const PreparedTransferItem &item, const Error &err){
        if (err.code)
        {
            callback(Fee(), err);
            return;
        }

        auto estimate_fnc = make_object<tonlib_api::query_estimateFees>(item.id, true);
        mEngine->append(std::move(estimate_fnc), receiver, [callback](tonlib::Client::Response resp){
            if (resp.object->get_id() == tonlib_api::error::ID)
                callback(Fee(), ERR(resp));
            else
            {
                auto res = ton::move_tl_object_as<tonlib_api::query_fees>(resp.object);
                Fee f;
                f.gas_fee = res->source_fees_->gas_fee_ * BALANCE_RATIO;
                f.fwd_fee = res->source_fees_->fwd_fee_ * BALANCE_RATIO;
                f.in_fwd_fee = res->source_fees_->in_fwd_fee_ * BALANCE_RATIO;
                f.storage_fee = res->source_fees_->storage_fee_ * BALANCE_RATIO;

                callback(f, Error());
            }
        });
    });
}

void TonLibBackend::doTransfer(const QByteArray &publicKey, const QString &dest, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void (const QByteArray &bodyHash, const Error &)> &callback)
{
    prepareTransfer(publicKey, dest, value, message, encryption, force, this, [this, receiver, callback](const PreparedTransferItem &item, const Error &err){
        if (err.code)
        {
            callback(QByteArray(), err);
            return;
        }

        auto query_fnc = make_object<tonlib_api::query_send>(item.id);
        mEngine->append(std::move(query_fnc), receiver, [callback, item](tonlib::Client::Response resp){
            if (resp.object->get_id() == tonlib_api::error::ID)
                callback(QByteArray(), ERR(resp));
            else
                callback(item.body_hash, Error());
        });
    });
}

void TonLibBackend::changeLocalPassword(const QByteArray &publicKey, const QString &newPassword, QObject *receiver, const std::function<void (const QByteArray &, const Error &)> &callback)
{
    auto input = p->getInputKey(publicKey);
    if (!input)
        return;

    auto getAddress_fnc = make_object<tonlib_api::changeLocalPassword>(std::move(input), td::SecureString(newPassword.toStdString()));
    mEngine->append(std::move(getAddress_fnc), receiver, [callback, this, receiver, newPassword, old_publicKey = publicKey](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QByteArray(), ERR(resp));
        else
        {
            auto key = ton::move_tl_object_as<tonlib_api::key>(resp.object);
            const auto publicKey = QByteArray::fromStdString(key->public_key_);

            auto info = std::make_shared<Private::KeyInfo>();
            info->public_key = old_publicKey.toStdString();
            info->secret = std::move(key->secret_);
            info->password = newPassword.toStdString();
            info->encrypted = !newPassword.isEmpty();

            deleteKey(old_publicKey, receiver, [info = std::move(info), old_publicKey, this, callback](bool,const Error &){
                p->keys[old_publicKey] = info;
                storeKeys();
                callback(old_publicKey, Error());
            });

        }
    });
}

QList<QByteArray> TonLibBackend::keys() const
{
    return p->keys.keys();
}

QStringList TonLibBackend::words() const
{
    return QString::fromStdString(tonlib::bip39_english().str()).split('\n', Qt::SkipEmptyParts);
}

QStringList TonLibBackend::availableVersions() const
{
    return {
        QStringLiteral("v4R2"),
        QStringLiteral("v4R1"),
        QStringLiteral("v3R2"),
        QStringLiteral("v3R1"),
    };
}

void TonLibBackend::storeKeys()
{
    QFile f(KEYS_DB_PATH);
    if (!f.open(QFile::WriteOnly))
        return;

    QByteArray d;
    QDataStream stream(&d, QIODevice::WriteOnly);
    stream << (int)p->keys.size();
    for (auto& info : p->keys)
    {
        const auto publicKey = QByteArray::fromStdString(info->public_key);
        const auto password = QString::fromStdString(info->password.value_or(std::string()));
        const auto secret = QByteArray::fromStdString(info->secret.as_slice().str());

        TON::Tools::CryptoAES secret_crypto(password.size()? KEYS_DB_SECRET_AES_SALT + password + KEYS_DB_SECRET_AES_SALT : "");

        stream << publicKey;
        stream << secret_crypto.encrypt(secret);
        stream << info->encrypted;
    }

    TON::Tools::CryptoAES crypto(KEYS_DB_FILE_AES_PASS);

    f.write( crypto.encrypt(d) );
    f.close();
}

void TonLibBackend::loadKeys()
{
    QFile f(KEYS_DB_PATH);
    if (!f.open(QFile::ReadOnly))
        return;

    TON::Tools::CryptoAES crypto(KEYS_DB_FILE_AES_PASS);

    QByteArray d = crypto.decrypt(f.readAll());
    f.close();

    QDataStream stream(&d, QIODevice::ReadOnly);

    int size;
    stream >> size;
    for (int i=0; i<size; i++)
    {
        QByteArray publicKey;
        stream >> publicKey;

        QByteArray secret;
        stream >> secret;

        bool encrypted;
        stream >> encrypted;

        const auto password = p->keys.value(publicKey)? p->keys.value(publicKey)->password.value_or(std::string()) : std::string();
        TON::Tools::CryptoAES secret_crypto(password.size()? KEYS_DB_SECRET_AES_SALT + QString::fromStdString(password) + KEYS_DB_SECRET_AES_SALT : "");
        const auto dec = secret_crypto.decrypt(secret);

        auto info = std::make_shared<Private::KeyInfo>();
        info->public_key = publicKey.toStdString();
        info->secret = td::SecureString( (dec.size()? dec : secret).toStdString() );
        info->password = password;
        info->encrypted = encrypted;

        p->keys[publicKey] = info;
    }
}

void TonLibBackend::unlockUsingPassword(const QByteArray &publicKey, const QString &newPassword)
{
    auto key = p->keys[publicKey];
    key->encrypted = !newPassword.isEmpty();
    if (key->encrypted)
        key->password = newPassword.toStdString();
    else
        key->password.reset();
    loadKeys();
}

bool TonLibBackend::hasPassword(const QByteArray &publicKey)
{
    return p->keys.contains(publicKey) && p->keys.value(publicKey)->encrypted;
}

bool TonLibBackend::testPassword(const QByteArray &publicKey, const QString &password)
{
    loadKeys();
    if (!p->keys.contains(publicKey))
        return false;

    const auto &k = p->keys.value(publicKey);
    if (k->password.has_value() && k->password.value() == password.toStdString())
        return true;

    const auto secret = QByteArray::fromStdString(k->secret.as_slice().str());

    TON::Tools::CryptoAES secret_crypto(KEYS_DB_SECRET_AES_SALT + password + KEYS_DB_SECRET_AES_SALT);
    const auto dec = secret_crypto.decrypt(secret);

    return !dec.isEmpty();
}

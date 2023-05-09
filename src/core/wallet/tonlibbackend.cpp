#include "tonlibbackend.h"
#include "core/tools/crypto.h"

#include <tonlib/Client.h>
#include <td/utils/base64.h>
#include <td/utils/optional.h>

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

#define KEYS_DB_PATH QString(mKeysDir + QStringLiteral("/key_db"))
#define GENERATE_ID QRandomGenerator::global()->generate64()

#define ERR(OBJ) \
    [](const ton::tl_object_ptr<tonlib_api::error> &err){ \
        Error e; \
        e.code = err->code_; \
        e.message = QString::fromStdString(err->message_); \
        return e; \
    }(ton::move_tl_object_as<tonlib_api::error>(OBJ.object))

using tonlib_api::make_object;
using namespace TON::Wallet;

class TonLibBackend::Engine: public QThread
{
public:
    typedef std::function<void(tonlib::Client::Response)> ResposeCallback;

    Engine(QObject *parent) : mParent(parent) {}
    virtual ~Engine() {}

    void append(tonlib_api::object_ptr<tonlib_api::Function> func, const ResposeCallback &responseCallback) {
        auto req = std::make_shared<tonlib::Client::Request>();
        req->id = GENERATE_ID;
        req->function = std::move(func);

        mMutex.lock();
        mCallbacks[req->id] = responseCallback;
        mRequests << req;
        mMutex.unlock();
    }

    void doTerminate() {
        mTerimnated = true;
    }

protected:
    void run() override {
        tonlib::Client client;

        while (!mTerimnated)
        {
            mMutex.lock();
            const auto requestsCount = mRequests.count();
            const auto callbacksCount = mCallbacks.count();
            mMutex.unlock();

            auto resp = client.receive(callbacksCount || requestsCount? 0.001 : 0.2);
            if (resp.id)
            {
                mMutex.lock();
                auto callback = mCallbacks.take(resp.id);
                mMutex.unlock();

                auto resp_ptr = std::make_shared<tonlib::Client::Response>(std::move(resp));
                QMetaObject::invokeMethod(mParent, [resp_ptr, callback](){
                    callback(std::move(*resp_ptr));
                }, Qt::QueuedConnection);
            }

            if (requestsCount)
            {
                mMutex.lock();
                auto req = mRequests.takeFirst();
                client.send(std::move(*req));
                mMutex.unlock();
            }
        }

        mRequests.clear();
    }

private:
    QObject *mParent;

    QQueue<std::shared_ptr<tonlib::Client::Request>> mRequests;
    QHash<quint64, ResposeCallback> mCallbacks;

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

    tonlib_api::object_ptr<tonlib_api::inputKeyRegular> getInputKey(const QString &publicKey)
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

    QHash<QString, std::shared_ptr<KeyInfo>> keys;

    td::int32 walletVersion = 2;
    td::int32 walletRevision = 0;
    td::uint32 walletId = 0;
    td::int32 workchainId = 0;
};

TonLibBackend::TonLibBackend(QObject *parent)
    : AbstractWalletBackend(parent)
{
    p = new Private;
    SET_VERBOSITY_LEVEL(0);

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

void TonLibBackend::init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback)
{
    mKeysDir = keysDir;

    QDir().mkpath(mKeysDir);
    loadKeys();

    tonlib_api::object_ptr<tonlib_api::KeyStoreType> ks_type = make_object<tonlib_api::keyStoreTypeDirectory>(mKeysDir.toStdString());

    auto init_fnc = make_object<tonlib_api::init>(make_object<tonlib_api::options>(nullptr, std::move(ks_type)));

    mEngine->append(std::move(init_fnc), [callback](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(false, ERR(resp));
        else
        {
            auto info = ton::move_tl_object_as<tonlib_api::options_info>(resp.object);
            if (info->config_info_)
                qDebug() << info->config_info_->default_wallet_id_;
            callback(true, Error());
        }
    });
}

void TonLibBackend::createNewKey(const std::function<void (const QString &, const Error &)> &callback)
{
    std::string entropy;
    while (entropy.size() < 20)
        entropy += (char)QRandomGenerator::securelySeeded().generate();

    auto createKey_fnc = make_object<tonlib_api::createNewKey>(td::SecureString(), td::SecureString(), td::SecureString(entropy));
    mEngine->append(std::move(createKey_fnc), [callback, this](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(QString(), ERR(resp));
        else
        {
            auto key = ton::move_tl_object_as<tonlib_api::key>(resp.object);
            const auto publicKey = QString::fromStdString(key->public_key_);

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

void TonLibBackend::exportKey(const QString &publicKey, const std::function<void (const QStringList &, const Error &)> &callback)
{
    auto input = p->getInputKey(publicKey);
    if (!input)
        return;

    auto exportKey_fnc = make_object<tonlib_api::exportKey>(std::move(input));
    mEngine->append(std::move(exportKey_fnc), [callback](tonlib::Client::Response resp){
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

void TonLibBackend::getAddress(const QString &publicKey, const std::function<void (const QString &, const Error &)> &callback)
{
    tonlib_api::object_ptr<tonlib_api::InitialAccountState> state;
    switch (p->walletVersion)
    {
    case 4:
        state = make_object<tonlib_api::wallet_highload_v1_initialAccountState>(publicKey.toStdString(), p->walletId);
        break;
    case 5:
        state = make_object<tonlib_api::wallet_highload_v2_initialAccountState>(publicKey.toStdString(), p->walletId);
        break;
    case 6:
        state = make_object<tonlib_api::dns_initialAccountState>(publicKey.toStdString(), p->walletId);
        break;
    default:
        state = make_object<tonlib_api::wallet_v3_initialAccountState>(publicKey.toStdString(), p->walletId);
        break;
    }

    auto getAddress_fnc = make_object<tonlib_api::getAccountAddress>(std::move(state), p->walletRevision, p->workchainId);
    mEngine->append(std::move(getAddress_fnc), [callback](tonlib::Client::Response resp){
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

void TonLibBackend::changeLocalPassword(const QString &publicKey, const QString &newPassword, const std::function<void (bool, const Error &)> &callback)
{
    auto input = p->getInputKey(publicKey);
    if (!input)
        return;

    auto getAddress_fnc = make_object<tonlib_api::changeLocalPassword>(std::move(input), td::SecureString(newPassword.toStdString()));
    mEngine->append(std::move(getAddress_fnc), [callback, this, newPassword](tonlib::Client::Response resp){
        if (resp.object->get_id() == tonlib_api::error::ID)
            callback(false, ERR(resp));
        else
        {
            auto key = ton::move_tl_object_as<tonlib_api::key>(resp.object);
            const auto publicKey = QString::fromStdString(key->public_key_);

            auto info = std::make_shared<Private::KeyInfo>();
            info->public_key = key->public_key_;
            info->secret = std::move(key->secret_);
            info->password = newPassword.toStdString();
            info->encrypted = !newPassword.isEmpty();

            p->keys[publicKey] = info;
            storeKeys();

            callback(true, Error());
        }
    });
}

QStringList TonLibBackend::keys() const
{
    return p->keys.keys();
}

void TonLibBackend::storeKeys()
{
    QFile f(KEYS_DB_PATH);
    if (!f.open(QFile::WriteOnly))
        return;

    QByteArray d;
    QDataStream stream(&d, QIODevice::WriteOnly);
    stream << p->keys.size();
    for (auto& info : p->keys)
    {
        const auto publicKey = QString::fromStdString(info->public_key);
        const auto password = QString::fromStdString(info->password.value_or(std::string()));
        const auto secret = QByteArray::fromStdString(info->secret.as_slice().str());

        TON::Tools::CryptoAES secret_crypto(KEYS_DB_SECRET_AES_SALT + password + KEYS_DB_SECRET_AES_SALT);

        stream << publicKey;
        stream << secret_crypto.encrypt(secret);
        stream << (bool)!password.isEmpty();
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
        QString publicKey;
        stream >> publicKey;

        QByteArray secret;
        stream >> secret;

        bool encrypted;
        stream >> encrypted;

        const auto password = p->keys.value(publicKey)? p->keys.value(publicKey)->password : std::optional<std::string>();
        TON::Tools::CryptoAES secret_crypto(KEYS_DB_SECRET_AES_SALT + QString::fromStdString(password.value_or(std::string())) + KEYS_DB_SECRET_AES_SALT);

        auto info = std::make_shared<Private::KeyInfo>();
        info->public_key = publicKey.toStdString();
        info->secret = td::SecureString( secret_crypto.decrypt(secret).toStdString() );
        info->password = password;
        info->encrypted = encrypted;

        p->keys[publicKey] = info;
    }
}

void TonLibBackend::setPassword(const QString &publicKey, const QString &newPassword)
{
    auto key = p->keys[publicKey];
    key->encrypted = !newPassword.isEmpty();
    if (key->encrypted)
        key->password = newPassword.toStdString();
    else
        key->password.reset();
    loadKeys();
}

bool TonLibBackend::hasPassword(const QString &publicKey)
{
    return p->keys.value(publicKey)->encrypted;
}

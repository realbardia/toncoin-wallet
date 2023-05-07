#include "tonwallet.h"
#include "core/tools/crypto.h"

#include <tonlib/Client.h>
#include <td/utils/base64.h>
#include <td/utils/optional.h>

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

class TonWallet::Engine: public QThread
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


class TonWallet::Private
{
public:
    struct KeyInfo {
        std::string public_key;
        td::SecureString secret;
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
        if (passwords.contains(publicKey))
            password = td::SecureString(passwords.value(publicKey).toStdString());

        return make_object<tonlib_api::inputKeyRegular>(std::move(key), std::move(password));
    }

    QHash<QString, QString> passwords;
    QHash<QString, std::shared_ptr<KeyInfo>> keys;

    td::int32 walletVersion = 2;
    td::int32 walletRevision = 0;
    td::uint32 walletId = 0;
    td::int32 workchainId = 0;
};

TonWallet::TonWallet(QObject *parent)
    : Abstracts::AbstractWallet(parent)
{
    p = new Private;
    SET_VERBOSITY_LEVEL(0);

    mEngine = new Engine(this);
    mEngine->start();
}

TonWallet::~TonWallet()
{
    mEngine->doTerminate();
    mEngine->quit();
    mEngine->wait();

    delete mEngine;
    delete p;
}

void TonWallet::init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback)
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

void TonWallet::createNewKey(const std::function<void (const QString &, const Error &)> &callback)
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

            p->keys[publicKey] = info;
            storeKeys();

            callback(publicKey, Error());
        }
    });
}

void TonWallet::exportKey(const QString &publicKey, const std::function<void (const QStringList &, const Error &)> &callback)
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

void TonWallet::getAddress(const QString &publicKey, const std::function<void (const QString &, const Error &)> &callback)
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

void TonWallet::changeLocalPassword(const QString &publicKey, const QString &newPassword, const std::function<void (bool, const Error &)> &callback)
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

            p->passwords[publicKey] = newPassword;
            p->keys[publicKey] = info;
            storeKeys();

            callback(true, Error());
        }
    });
}

QStringList TonWallet::keys() const
{
    return p->keys.keys();
}

void TonWallet::storeKeys()
{
    QFile f(KEYS_DB_PATH);
    if (!f.open(QFile::WriteOnly))
        return;

    QDataStream stream(&f);
    stream << p->keys.size();
    for (auto& info : p->keys)
    {
        const auto publicKey = QString::fromStdString(info->public_key);
        const auto password = p->passwords.value(publicKey);
        const auto secret = QByteArray::fromStdString(info->secret.as_slice().str());

        stream << publicKey;
        stream << secret;
        stream << (bool)!password.isEmpty();
    }

    f.close();
}

void TonWallet::loadKeys()
{
    QFile f(KEYS_DB_PATH);
    if (!f.open(QFile::ReadOnly))
        return;

    QDataStream stream(&f);

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

        auto info = std::make_shared<Private::KeyInfo>();
        info->public_key = publicKey.toStdString();
        info->secret = td::SecureString(secret.toStdString());

        p->keys[publicKey] = info;
    }

    f.close();
}

QString TonWallet::password(const QString &publicKey) const
{
    return p->passwords.value(publicKey);
}

void TonWallet::setPassword(const QString &publicKey, const QString &newPassword)
{
    p->passwords[publicKey] = newPassword;
    loadKeys();
}

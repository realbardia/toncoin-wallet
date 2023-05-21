#include "walletitem.h"
#include "core/wallet/backendmanager.h"
#include "core/tools/crypto.h"

#include "qtquick/cpp/toolkit/core/asemandevices.h"

#include <QtQml>

using namespace TON::Wallet;

WalletItem::WalletItem(QObject *parent)
    : AsemanQuickObject(parent)
{
    mRefresher = new AsemanRefresherObject(this);
    mRefresher->setForceActiveOnInitialize(true);
    mRefresher->setDelay(5000);

    connect(mRefresher, &AsemanRefresherObject::refreshingChanged, this, &WalletItem::loadingChanged);
}

WalletItem::~WalletItem()
{

}

QString WalletItem::publicKey() const
{
    return mPublicKey;
}

void WalletItem::setPublicKey(const QString &newPublicKey)
{
    if (mPublicKey == newPublicKey)
        return;
    mPublicKey = newPublicKey;
    reload();
    Q_EMIT publicKeyChanged();
}

bool WalletItem::changePassword(const QString &password)
{
    if (!mBackend)
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return false;
    }
    auto backend = mBackend->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return false;
    }

    backend->changeLocalPassword(QByteArray::fromBase64(mPublicKey.toLatin1()), password, this, [this, password](const QByteArray &newPublicKey, const AbstractWalletBackend::Error &error){
        if (!newPublicKey.isEmpty())
        {
            TON::Tools::CryptoAES crypto(KEYS_DB_SECRET_AES_SALT + AsemanDevices::deviceId() + KEYS_DB_SECRET_AES_SALT);
            const auto secureKey = QString::fromLatin1( crypto.encrypt(password.toUtf8()).toBase64() );
            Q_EMIT passwordChangedSuccessfully(QString::fromLatin1(newPublicKey.toBase64()), secureKey);
        }
        else
            Q_EMIT passwordChangeFailed(error.code, error.message);
    });

    return true;
}

bool WalletItem::testPassword(const QString &password)
{
    if (!mBackend)
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return false;
    }
    auto backend = mBackend->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return false;
    }

    return backend->testPassword(QByteArray::fromBase64(mPublicKey.toLatin1()), password);
}

bool WalletItem::unlock(const QString &password)
{
    if (!testPassword(password))
        return false;

    auto backend = mBackend->backendObject();
    backend->unlockUsingPassword(QByteArray::fromBase64(mPublicKey.toLatin1()), password);
    return true;
}

void WalletItem::reload()
{
    if (!mBackend || !mBackend->initialized())
    {
        reset();
        return;
    }

    auto backend = mBackend->backendObject();
    if (!backend)
    {
        reset();
        return;
    }

    if (mPublicKey.isEmpty())
        return;

    const auto pkey = QByteArray::fromBase64(mPublicKey.toLatin1());

    setLoading(true);
    setHasPassword( backend->hasPassword(pkey) );
    backend->getAddress(pkey, this, [this](const QString &address, const AbstractWalletBackend::Error &){
        setLoading(false);
        setAddress(address);
    });
}

QString WalletItem::decodeSecureKey(const QString &secureKey) const
{
    TON::Tools::CryptoAES crypto(KEYS_DB_SECRET_AES_SALT + AsemanDevices::deviceId() + KEYS_DB_SECRET_AES_SALT);
    const auto bytes = crypto.decrypt( QByteArray::fromBase64(secureKey.toLatin1()) );
    return QString::fromUtf8(bytes);
}

void WalletItem::reset()
{
    setHasPassword(false);
    setAddress(QString());
}

QString WalletItem::address() const
{
    return mAddress;
}

void WalletItem::setAddress(const QString &newAddress)
{
    if (mAddress == newAddress)
        return;
    mAddress = newAddress;
    Q_EMIT addressChanged();
}

bool WalletItem::loading() const
{
    return mRefresher->refreshing();
}

QByteArray WalletItem::initState() const
{
    if (!mBackend || !mBackend->backendObject())
        return QByteArray();
    return mBackend->backendObject()->getInitState( QByteArray::fromBase64(mPublicKey.toLatin1()) );
}

void WalletItem::setLoading(bool state)
{
    mRefresher->setRefreshing(state);
}

bool WalletItem::hasPassword() const
{
    return mHasPassword;
}

void WalletItem::setHasPassword(bool newHasPassword)
{
    if (mHasPassword == newHasPassword)
        return;
    mHasPassword = newHasPassword;
    Q_EMIT hasPasswordChanged();
}

WalletBackend *WalletItem::backend() const
{
    return mBackend;
}

void WalletItem::setBackend(WalletBackend *newBackend)
{
    if (mBackend == newBackend)
        return;
    if (mBackend)
        mBackend->disconnect(this);

    mBackend = newBackend;
    if (mBackend)
    {
        connect(mBackend, &WalletBackend::backendChanged, this, &WalletItem::reload);
        connect(mBackend, &WalletBackend::initializedChanged, this, &WalletItem::reload);
        connect(mBackend, &WalletBackend::walletVersionChanged, this, &WalletItem::reload);
    }

    reload();
    Q_EMIT backendChanged();
}

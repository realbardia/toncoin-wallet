#include "walletitem.h"
#include "core/wallet/backendmanager.h"

#include <QtQml>

using namespace TON::Wallet;

WalletItem::WalletItem(QObject *parent)
    : TonToolkitQuickObject(parent)
{

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

    backend->changeLocalPassword(QByteArray::fromBase64(mPublicKey.toLatin1()), password, [this](const QByteArray &newPublicKey, const AbstractWalletBackend::Error &error){
        if (!newPublicKey.isEmpty())
            Q_EMIT passwordChangedSuccessfully(QString::fromLatin1(newPublicKey.toBase64()));
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
    backend->getAddress(pkey, [this](const QString &address, const AbstractWalletBackend::Error &error){
        setLoading(false);
        setAddress(address);
    });
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
    return mLoading;
}

void WalletItem::setLoading(bool newLoading)
{
    if (mLoading == newLoading)
        return;
    mLoading = newLoading;
    Q_EMIT loadingChanged();
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
    }

    reload();
    Q_EMIT backendChanged();
}

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

    backend->changeLocalPassword(mPublicKey, password, [this](bool done, const AbstractWalletBackend::Error &error){
        if (done)
            Q_EMIT passwordChangedSuccessfully();
        else
            Q_EMIT passwordChangeFailed(error.code, error.message);
    });

    return true;
}

WalletBackend *WalletItem::backend() const
{
    return mBackend;
}

void WalletItem::setBackend(WalletBackend *newBackend)
{
    if (mBackend == newBackend)
        return;
    mBackend = newBackend;
    Q_EMIT backendChanged();
}

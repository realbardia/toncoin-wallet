#include "walletitem.h"
#include "core/wallet/backendmanager.h"

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

void WalletItem::changePassword(const QString &password)
{
    auto backend = mWalletBackend->backendObject();
    backend->changeLocalPassword(mPublicKey, password, [this](bool done, const AbstractWalletBackend::Error &error){
        if (done)
            Q_EMIT passwordChangedSuccessfully();
        else
            Q_EMIT passwordChangeFailed(error.code, error.message);
    });
}

WalletBackend *WalletItem::keysManager() const
{
    return mWalletBackend;
}

void WalletItem::setWalletBackend(WalletBackend *newWalletBackend)
{
    if (mWalletBackend == newWalletBackend)
        return;
    mWalletBackend = newWalletBackend;
    Q_EMIT keysManagerChanged();
}

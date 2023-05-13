#include "abstractwalletmodel.h"

#include <QtQml>

AbstractWalletModel::AbstractWalletModel(QObject *parent)
    : TonToolkitAbstractListModel(parent)
{
}

AbstractWalletModel::~AbstractWalletModel()
{

}

WalletItem *AbstractWalletModel::wallet() const
{
    return mWallet;
}

void AbstractWalletModel::setWallet(WalletItem *newWallet)
{
    if (mWallet == newWallet)
        return;

    if (mWallet)
        mWallet->disconnect(this);
    if (mWallet && mWallet == mDefaultWallet)
        delete mWallet;

    mWallet = newWallet;
    if (mWallet)
    {
        connect(mWallet, &WalletItem::addressChanged, this, [this](){
            reload();
        });
        connect(mWallet, &WalletItem::backendChanged, this, [this](){
            reload();
        });
        connect(mWallet, &WalletItem::publicKeyChanged, this, [this](){
            reload();
        });

        reload();
    }

    Q_EMIT walletChanged();
}

void AbstractWalletModel::tryReload()
{
    reset();
    reload();

    Q_EMIT countChanged();
}

bool AbstractWalletModel::refreshing() const
{
    return mRefreshing;
}

QSharedPointer<TON::Wallet::AbstractWalletBackend> AbstractWalletModel::beginAction()
{
    if (!mWallet)
    {
        qmlWarning(this) << "wallet property is null. Please set backend property first.";
        return nullptr;
    }

    if (!mWallet->backend())
        return nullptr;

    auto qmlBackend = mWallet->backend();
    if (!qmlBackend->initialized())
        return nullptr;

    auto backend = qmlBackend->backendObject();
    if (!backend)
        return nullptr;

    if (mRefreshing)
        return nullptr;

    setRefreshing(true);
    return backend;
}

void AbstractWalletModel::endAction()
{
    setRefreshing(false);
}

void AbstractWalletModel::setRefreshing(bool newRefreshing)
{
    if (mRefreshing == newRefreshing)
        return;
    mRefreshing = newRefreshing;
    Q_EMIT refreshingChanged();
}

void AbstractWalletModel::setError(qint32 code, const QString &message)
{
    mError = code;
    mErrorString = message;
    Q_EMIT errorChanged();
}

qint32 AbstractWalletModel::error() const
{
    return mError;
}

QString AbstractWalletModel::errorString() const
{
    return mErrorString;
}

int AbstractWalletModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return count();
}

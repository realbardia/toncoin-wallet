#include "abstractwalletmodel.h"

AbstractWalletModel::AbstractWalletModel(QObject *parent)
    : TonToolkitAbstractListModel(parent)
{

}

AbstractWalletModel::~AbstractWalletModel()
{

}

WalletBackend *AbstractWalletModel::backend() const
{
    return mBackend;
}

void AbstractWalletModel::setBackend(WalletBackend *newBackend)
{
    if (mBackend == newBackend)
        return;
    if (mBackend)
        mBackend->disconnect(this);
    mBackend = newBackend;
    if (mBackend)
    {
        connect(mBackend, &WalletBackend::initializedChanged, this, &AbstractWalletModel::tryReload);
    }
    tryReload();
    Q_EMIT backendChanged();
}

QString AbstractWalletModel::publicKey() const
{
    return mPublicKey;
}

void AbstractWalletModel::setPublicKey(const QString &newPublicKey)
{
    if (mPublicKey == newPublicKey)
        return;
    mPublicKey = newPublicKey;
    tryReload();
    Q_EMIT publicKeyChanged();
}

void AbstractWalletModel::tryReload()
{
    reset();
    if (!mPublicKey.isEmpty() && mBackend && mBackend->initialized())
        reload();

    Q_EMIT countChanged();
}

bool AbstractWalletModel::refreshing() const
{
    return mRefreshing;
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

#include "abstractwalletmodel.h"

#include <QtQml>

AbstractWalletModel::AbstractWalletModel(QObject *parent)
    : AsemanAbstractListModel(parent)
{
    mRefresher = new AsemanRefresherObject(this);
    mRefresher->setForceActiveOnInitialize(true);
    mRefresher->setDelay(5000);

    connect(mRefresher, &AsemanRefresherObject::refreshingChanged, this, &AbstractWalletModel::refreshingChanged);

    mRefreshTimer = new QTimer(this);
    mRefreshTimer->setInterval(100);
    mRefreshTimer->setSingleShot(true);

    connect(mRefreshTimer, &QTimer::timeout, this, &AbstractWalletModel::tryReload);
}

AbstractWalletModel::~AbstractWalletModel()
{

}

void AbstractWalletModel::refresh()
{
    mRefreshTimer->stop();
    mRefreshTimer->start();
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
            mRefresher->setForceActiveOnInitialize(true);
            refresh();
        });
        connect(mWallet, &WalletItem::backendChanged, this, [this](){
            refresh();
        });
        connect(mWallet, &WalletItem::publicKeyChanged, this, [this](){
            refresh();
        });

        refresh();
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
    return mRefresher->refreshing();
}

AsemanRefresherObject *AbstractWalletModel::refresher() const
{
    return mRefresher;
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

    if (mRefresher->active())
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
    mRefresher->setRefreshing(newRefreshing);
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

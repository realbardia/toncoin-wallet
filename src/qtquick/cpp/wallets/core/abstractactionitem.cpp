#include "abstractactionitem.h"

#include <QtQml>

using namespace TON::Wallet;

AbstractActionItem::AbstractActionItem(QObject *parent) :
    AsemanQuickObject(parent)
{
    mRefresher = new AsemanRefresherObject(this);
    mRefresher->setForceActiveOnInitialize(true);
    mRefresher->setDelay(5000);

    connect(mRefresher, &AsemanRefresherObject::refreshingChanged, this, &AbstractActionItem::runningChanged);

    mDefaultWallet = new WalletItem(this);
    mWallet = mDefaultWallet;
}

AbstractActionItem::~AbstractActionItem()
{

}

WalletItem *AbstractActionItem::wallet() const
{
    return mWallet;
}

void AbstractActionItem::setWallet(WalletItem *newWallet)
{
    if (mWallet == newWallet)
        return;
    if (mWallet && mWallet == mDefaultWallet)
        delete mWallet;

    mWallet = newWallet;
    Q_EMIT walletChanged();
}

QString AbstractActionItem::errorString() const
{
    return mErrorString;
}

qint32 AbstractActionItem::error() const
{
    return mError;
}

bool AbstractActionItem::running() const
{
    return mRefresher->refreshing();
}

AsemanRefresherObject *AbstractActionItem::refresher() const
{
    return mRefresher;
}

QSharedPointer<AbstractWalletBackend> AbstractActionItem::beginAction()
{
    if (!mWallet)
    {
        qmlWarning(this) << "wallet property is null. Please set backend property first.";
        return nullptr;
    }

    if (!mWallet->backend())
    {
        qmlWarning(this) << "wallet.backend property is null. Please set backend property first.";
        return nullptr;
    }
    auto backend = mWallet->backend()->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return nullptr;
    }

    if (mRefresher->active())
        return nullptr;

    setRunning(true);
    return backend;
}

void AbstractActionItem::endAction()
{
    setRunning(false);
}

void AbstractActionItem::setError(qint32 code, const QString &message)
{
    mError = code;
    mErrorString = message;
    Q_EMIT errorChanged();
}

void AbstractActionItem::setRunning(bool newRunning)
{
    mRefresher->setRefreshing(newRunning);
}

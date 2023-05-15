#include "walletstate.h"
#include "core/wallet/backendmanager.h"

#include <QtQml>

using namespace TON::Wallet;

WalletState::WalletState(QObject *parent)
    : AbstractActionItem(parent)
{
    mRetryTimer = new QTimer(this);
    mRetryTimer->setInterval(5000);
    mRetryTimer->setSingleShot(true);

    connect(mRetryTimer, &QTimer::timeout, this, [this](){
        endAction();
        reload();
    });

    mRefreshTimer = new QTimer(this);
    mRefreshTimer->setInterval(100);
    mRefreshTimer->setSingleShot(true);

    connect(mRefreshTimer, &QTimer::timeout, this, &WalletState::doReload);

    auto doConnect = [this](){
        auto w = wallet();
        if (mOldWallet)
            mOldWallet->disconnect(this);

        mOldWallet = w;
        if (w)
        {
            connect(w, &WalletItem::addressChanged, this, [w, this](){
                setAddress(w->address());
                reload();
            });
            connect(w, &WalletItem::backendChanged, this, [this](){
                reload();
            });

            setAddress(w->address());
            reload();
        }
        else
        {
            setAddress(QString());
        }
    };

    connect(this, &WalletState::walletChanged, this, doConnect);
    doConnect();
}

WalletState::~WalletState()
{
}

void WalletState::reload()
{
    mRefreshTimer->stop();
    mRefreshTimer->start();
}

void WalletState::doReload()
{
    if (mAddress.isEmpty())
        return;

    auto backend = beginAction();
    if (!backend)
    {
        reset();
        return;
    }

    const auto emitedByTimer = (sender() == mRetryTimer);
    if (!emitedByTimer)
        mRetryCount = 0;

    backend->getAccountState(mAddress, this, [this, backend](const AbstractWalletBackend::AccountState &state, const AbstractWalletBackend::Error &error){
        mRetryTimer->stop();
        if (error.code)
        {
            if (mRetryCount < mMaximumRetries)
            {
                mRetryTimer->start();
                mRetryCount++;
                return;
            }
            Q_EMIT errorChanged();
            setError(error.code, error.message);
            endAction();
            return;
        }

        endAction();

        auto balance = QString::number(state.balance);
        auto dotIdx = balance.indexOf('.');
        if (dotIdx < 0)
        {
            dotIdx = balance.count();
            balance += '.';
        }
        balance = balance.left(dotIdx) + '.' + balance.mid(dotIdx+1).leftJustified(5, '0');

        setLastTransactionId(QString::number(state.lastTransaction.id));
        setLastTransactionHash(QString::fromLatin1(state.lastTransaction.hash.toBase64()));
        setBalance(balance);
    });
}

void WalletState::reset()
{
    setError(0, QString());
}

QString WalletState::lastTransactionHash() const
{
    return mLastTransactionHash;
}

void WalletState::setLastTransactionHash(const QString &newLastTransactionHash)
{
    if (mLastTransactionHash == newLastTransactionHash)
        return;
    mLastTransactionHash = newLastTransactionHash;
    Q_EMIT lastTransactionHashChanged();
}

int WalletState::maximumRetries() const
{
    return mMaximumRetries;
}

void WalletState::setMaximumRetries(int newMaximumRetries)
{
    if (mMaximumRetries == newMaximumRetries)
        return;
    mMaximumRetries = newMaximumRetries;
    Q_EMIT maximumRetriesChanged();
}

QString WalletState::lastTransactionId() const
{
    return mLastTransactionId;
}

void WalletState::setLastTransactionId(const QString &newLastTransactionId)
{
    if (mLastTransactionId == newLastTransactionId)
        return;
    mLastTransactionId = newLastTransactionId;
    Q_EMIT lastTransactionIdChanged();
}

QString WalletState::balance() const
{
    return mBalance;
}

void WalletState::setBalance(const QString &newBalance)
{
    if (mBalance == newBalance)
        return;
    mBalance = newBalance;
    Q_EMIT balanceChanged();
}

void WalletState::setAddress(const QString &newAddress)
{
    if (mAddress == newAddress)
        return;
    mAddress = newAddress;
    reload();
}

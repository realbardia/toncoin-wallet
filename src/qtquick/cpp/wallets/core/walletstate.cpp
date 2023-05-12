#include "walletstate.h"
#include "core/wallet/backendmanager.h"

#include <QtQml>

using namespace TON::Wallet;

WalletState::WalletState(QObject *parent)
    : TonToolkitQuickObject(parent)
{
    mRetryTimer = new QTimer(this);
    mRetryTimer->setInterval(5000);
    mRetryTimer->setSingleShot(true);

    connect(mRetryTimer, &QTimer::timeout, this, &WalletState::reload);
}

WalletState::~WalletState()
{
}

void WalletState::reload()
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

    if (mAddress.isEmpty())
        return;

    const auto emitedByTimer = (sender() == mRetryTimer);
    if (!emitedByTimer)
        mRetryCount = 0;

    setLoading(true);
    backend->getAccountState(mAddress, [this, backend](const AbstractWalletBackend::AccountState &state, const AbstractWalletBackend::Error &error){
        mRetryTimer->stop();
        if (error.code)
        {
            if (mRetryCount < mMaximumRetries)
            {
                mRetryTimer->start();
                mRetryCount++;
                return;
            }
            mError = error.code;
            mErrorString = error.message;
            Q_EMIT errorChanged();
            return;
        }

        setLoading(false);

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
    mError = 0;
    mErrorString.clear();
    Q_EMIT errorChanged();
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

qint32 WalletState::error() const
{
    return mError;
}

QString WalletState::errorString() const
{
    return mErrorString;
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

QString WalletState::address() const
{
    return mAddress;
}

void WalletState::setAddress(const QString &newAddress)
{
    if (mAddress == newAddress)
        return;
    mAddress = newAddress;
    reload();
    Q_EMIT addressChanged();
}

bool WalletState::loading() const
{
    return mLoading;
}

void WalletState::setLoading(bool newLoading)
{
    if (mLoading == newLoading)
        return;
    mLoading = newLoading;
    Q_EMIT loadingChanged();
}

WalletBackend *WalletState::backend() const
{
    return mBackend;
}

void WalletState::setBackend(WalletBackend *newBackend)
{
    if (mBackend == newBackend)
        return;
    if (mBackend)
        mBackend->disconnect(this);

    mBackend = newBackend;
    if (mBackend)
    {
        connect(mBackend, &WalletBackend::backendChanged, this, &WalletState::reload);
        connect(mBackend, &WalletBackend::initializedChanged, this, &WalletState::reload);
    }

    reload();
    Q_EMIT backendChanged();
}

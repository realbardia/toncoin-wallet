#ifndef WALLETSTATE_H
#define WALLETSTATE_H

#include "walletbackend.h"
#include "abstractactionitem.h"

#include <QPointer>
#include <QTimer>

class WalletState : public AbstractActionItem
{
    Q_OBJECT
    Q_PROPERTY(QString balance READ balance NOTIFY balanceChanged)
    Q_PROPERTY(QString lastTransactionId READ lastTransactionId NOTIFY lastTransactionIdChanged)
    Q_PROPERTY(QString lastTransactionHash READ lastTransactionHash NOTIFY lastTransactionHashChanged)
    Q_PROPERTY(int maximumRetries READ maximumRetries WRITE setMaximumRetries NOTIFY maximumRetriesChanged)

public:
    WalletState(QObject *parent = nullptr);
    virtual ~WalletState();

    QString balance() const;
    QString lastTransactionId() const;
    QString lastTransactionHash() const;

    int maximumRetries() const;
    void setMaximumRetries(int newMaximumRetries);

public Q_SLOTS:
    void reload();

Q_SIGNALS:
    void balanceChanged();
    void lastTransactionIdChanged();
    void lastTransactionHashChanged();
    void maximumRetriesChanged();

protected:
    void setBalance(const QString &newBalance);
    void setAddress(const QString &address);
    void setLastTransactionId(const QString &newLastTransactionId);
    void setLastTransactionHash(const QString &newLastTransactionHash);

    void reset();

private:
    QString mBalance;
    QString mAddress;

    QString mLastTransactionId = 0;
    QString mLastTransactionHash;

    QTimer *mRetryTimer;
    QPointer<WalletItem> mOldWallet;

    int mRetryCount = 0;
    int mMaximumRetries = 5;
};

#endif // WALLETSTATE_H

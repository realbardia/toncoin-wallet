#ifndef WALLETSTATE_H
#define WALLETSTATE_H

#include "tontoolkitquickobject.h"
#include "walletbackend.h"

#include <QPointer>
#include <QTimer>

class WalletState : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(WalletBackend *backend READ backend WRITE setBackend NOTIFY backendChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)
    Q_PROPERTY(QString balance READ balance NOTIFY balanceChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(QString lastTransactionId READ lastTransactionId NOTIFY lastTransactionIdChanged)
    Q_PROPERTY(QString lastTransactionHash READ lastTransactionHash NOTIFY lastTransactionHashChanged)
    Q_PROPERTY(int maximumRetries READ maximumRetries WRITE setMaximumRetries NOTIFY maximumRetriesChanged)

public:
    WalletState(QObject *parent = nullptr);
    virtual ~WalletState();

    WalletBackend *backend() const;
    void setBackend(WalletBackend *newBackend);

    QString address() const;
    void setAddress(const QString &newAddress);

    bool loading() const;

    QString balance() const;
    QString lastTransactionId() const;
    QString lastTransactionHash() const;

    QString errorString() const;
    qint32 error() const;

    int maximumRetries() const;
    void setMaximumRetries(int newMaximumRetries);

public Q_SLOTS:
    void reload();

Q_SIGNALS:
    void addressChanged();
    void backendChanged();

    void loadingChanged();
    void balanceChanged();
    void lastTransactionIdChanged();
    void lastTransactionHashChanged();
    void errorChanged();

    void maximumRetriesChanged();

protected:
    void setLoading(bool newLoading);
    void setBalance(const QString &newBalance);
    void setLastTransactionId(const QString &newLastTransactionId);
    void setLastTransactionHash(const QString &newLastTransactionHash);

    void reset();

private:
    QString mAddress;
    QPointer<WalletBackend> mBackend;
    QString mBalance;

    QString mErrorString;
    qint32 mError = 0;
    QString mLastTransactionId = 0;
    QString mLastTransactionHash;

    QTimer *mRetryTimer;
    int mRetryCount = 0;
    int mMaximumRetries = 5;

    bool mLoading = false;
};

#endif // WALLETSTATE_H

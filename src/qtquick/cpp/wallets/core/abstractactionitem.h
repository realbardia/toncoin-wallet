#ifndef ABSTRACTACTIONITEM_H
#define ABSTRACTACTIONITEM_H

#include "walletitem.h"
#include "core/wallet/abstractwalletbackend.h"
#include "tontoolkitrefresherobject.h"

#include <QSharedPointer>

class AbstractActionItem : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(WalletItem *wallet READ wallet WRITE setWallet NOTIFY walletChanged)
    Q_PROPERTY(TonToolkitRefresherObject* refresher READ refresher NOTIFY refresherChanged)
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)

public:
    AbstractActionItem(QObject *parent = nullptr);
    virtual ~AbstractActionItem();

    WalletItem *wallet() const;
    void setWallet(WalletItem *newWallet);

    QString errorString() const;
    qint32 error() const;

    bool running() const;
    TonToolkitRefresherObject *refresher() const;

Q_SIGNALS:
    void walletChanged();
    void runningChanged();
    void errorChanged();
    void refresherChanged();

protected:
    void setRunning(bool newRunning);

    QSharedPointer<TON::Wallet::AbstractWalletBackend> beginAction();
    void endAction();

    void setError(qint32 code, const QString &message);

private:
    QPointer<WalletItem> mWallet;
    QPointer<WalletItem> mDefaultWallet;

    TonToolkitRefresherObject *mRefresher;

    QString mErrorString;
    qint32 mError = 0;
};

#endif // ABSTRACTACTIONITEM_H

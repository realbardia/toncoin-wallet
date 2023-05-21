#ifndef ABSTRACTWALLETMODEL_H
#define ABSTRACTWALLETMODEL_H

#include "asemanabstractlistmodel.h"
#include "asemanrefresherobject.h"
#include "walletitem.h"

#include <QPointer>
#include <QTimer>

class AbstractWalletModel : public AsemanAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(WalletItem *wallet READ wallet WRITE setWallet NOTIFY walletChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool refreshing READ refreshing NOTIFY refreshingChanged)
    Q_PROPERTY(AsemanRefresherObject* refresher READ refresher NOTIFY refresherChanged)

public:
    AbstractWalletModel(QObject *parent = nullptr);
    virtual ~AbstractWalletModel();

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int count() const = 0;

    WalletItem *wallet() const;
    void setWallet(WalletItem *newWallet);

    QString errorString() const;
    qint32 error() const;

    bool refreshing() const;
    AsemanRefresherObject *refresher() const;

public Q_SLOTS:
    void refresh();

Q_SIGNALS:
    void countChanged();
    void errorChanged();
    void refreshingChanged();
    void walletChanged();
    void refresherChanged();

protected:
    virtual void reset() = 0;
    virtual void reload() = 0;

    QSharedPointer<TON::Wallet::AbstractWalletBackend> beginAction();
    void endAction();

    void setError(qint32 code, const QString &message);
    void setRefreshing(bool newRefreshing);

    void tryReload();

private:
    QTimer *mRefreshTimer;

    QPointer<WalletItem> mWallet;
    QPointer<WalletItem> mDefaultWallet;

    QString mErrorString;
    qint32 mError = 0;

    AsemanRefresherObject *mRefresher;
};

#endif // ABSTRACTWALLETMODEL_H

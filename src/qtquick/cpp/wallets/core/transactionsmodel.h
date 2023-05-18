#ifndef TRANSACTIONSMODEL_H
#define TRANSACTIONSMODEL_H

#include "abstractwalletmodel.h"
#include "transferrequest.h"
#include "feeestimater.h"

#include <QTimer>

class TransactionsModel : public AbstractWalletModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 limit READ limit WRITE setLimit NOTIFY limitChanged)
    Q_PROPERTY(QString cachePath READ cachePath WRITE setCachePath NOTIFY cachePathChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    class Private;

public:
    enum Roles {
        RoleId = Qt::UserRole,
        RoleHash,
        RoleSource,
        RoleDestination,
        RoleValue,
        RoleDatetime,
        RoleSection,
        RoleFee,
        RoleStorageFee,
        RoleOtherFee,
        RoleMessage,
        RoleSent,
        RolePending,
        RoleInitializeWallet,
        RoleFailed,
    };
    Q_ENUM(Roles)
    TransactionsModel(QObject *parent = nullptr);
    virtual ~TransactionsModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;

    qint32 limit() const;
    void setLimit(qint32 newLimit);

    QString cachePath() const;
    void setCachePath(const QString &newCachePath);

    QString password() const;
    void setPassword(const QString &newPassword);

public Q_SLOTS:
    void addPending(TransferRequest *req, FeeEstimater *fee = nullptr);
    void more();

Q_SIGNALS:
    void limitChanged();
    void cachePathChanged();
    void passwordChanged();
    void listRefreshed();

protected:
    void reset() Q_DECL_OVERRIDE;
    void reload() Q_DECL_OVERRIDE;

    void store();
    void restore();

    void startCheckingPending();

private:
    qint32 mLimit = 20;

    QString mLastRequestId;

    QTimer *mPendingTimer;
    QTimer *mReloadTimer;

    QString mCachePath;
    QString mPassword;

    bool mInited = false;

    struct Transaction: TON::Wallet::AbstractWalletBackend::Transaction
    {
        Transaction() {}
        Transaction(const TON::Wallet::AbstractWalletBackend::Transaction &t): TON::Wallet::AbstractWalletBackend::Transaction(t) {}

        bool pending = false;

        bool failed() const {
            return pending && datetime.secsTo(QDateTime::currentDateTime()) > 60;
        }

        bool operator==(const Transaction &another) const;
        bool operator<(const Transaction &another) const;
    };


    void change(const QList<Transaction> &list);

    QList<Transaction> mTransactions;
    QList<Transaction> mPendingTransactions;
};

#endif // TRANSACTIONSMODEL_H

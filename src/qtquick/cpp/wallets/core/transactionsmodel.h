#ifndef TRANSACTIONSMODEL_H
#define TRANSACTIONSMODEL_H

#include "abstractwalletmodel.h"

#include <QTimer>

class TransactionsModel : public AbstractWalletModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 limit READ limit WRITE setLimit NOTIFY limitChanged)
    Q_PROPERTY(QString offsetTransactionId READ offsetTransactionId WRITE setOffsetTransactionId NOTIFY offsetTransactionIdChanged)
    Q_PROPERTY(QString offsetTransactionHash READ offsetTransactionHash WRITE setOffsetTransactionHash NOTIFY offsetTransactionHashChanged)
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
    };
    Q_ENUM(Roles)
    TransactionsModel(QObject *parent = nullptr);
    virtual ~TransactionsModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;

    QString offsetTransactionId() const;
    void setOffsetTransactionId(const QString &newOffsetTransactionId);

    QString offsetTransactionHash() const;
    void setOffsetTransactionHash(const QString &newOffsetTransactionHash);

    qint32 limit() const;
    void setLimit(qint32 newLimit);

    QString cachePath() const;
    void setCachePath(const QString &newCachePath);

    QString password() const;
    void setPassword(const QString &newPassword);

public Q_SLOTS:
    void refresh();
    void more();

Q_SIGNALS:
    void offsetTransactionIdChanged();
    void offsetTransactionHashChanged();
    void limitChanged();
    void cachePathChanged();
    void passwordChanged();

protected:
    void reset() Q_DECL_OVERRIDE;
    void reload() Q_DECL_OVERRIDE;

    void store();
    void restore();

private:
    qint32 mLimit = 20;
    QString mOffsetTransactionId = 0;
    QString mOffsetTransactionHash;

    QTimer *mRefreshTimer;

    QString mCachePath;
    QString mPassword;

    QList<TON::Wallet::AbstractWalletBackend::Transaction> mTransactions;
};

#endif // TRANSACTIONSMODEL_H

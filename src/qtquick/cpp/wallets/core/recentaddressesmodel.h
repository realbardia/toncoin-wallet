#ifndef RECENTADDRESSESMODEL_H
#define RECENTADDRESSESMODEL_H

#include "asemanlistmodel.h"

#include <QDateTime>
#include <QTimer>

class RecentAddressesModel : public AsemanAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(QString cachePath READ cachePath WRITE setCachePath NOTIFY cachePathChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(qint32 limit READ limit WRITE setLimit NOTIFY limitChanged)

public:
    enum Roles {
        RoleAddress = Qt::UserRole,
        RoleDomain,
        RoleDateTime,
    };
    Q_ENUM(Roles)

    RecentAddressesModel(QObject *parent = nullptr);
    virtual ~RecentAddressesModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int count() const;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    QString cachePath() const;
    void setCachePath(const QString &newCachePath);

    QString password() const;
    void setPassword(const QString &newPassword);

    qint32 limit() const;
    void setLimit(qint32 newLimit);

public Q_SLOTS:
    void reload();
    void append(const QString &address, const QString &domain, const QDateTime &datetime);
    void remove(int index);

Q_SIGNALS:
    void countChanged();
    void cachePathChanged();
    void passwordChanged();
    void limitChanged();

protected:
    void store();
    void restore();
    void doReload();

private:
    struct Item {
        QString address;
        QString domain;
        QDateTime datetime;

        bool operator==(const Item &b) const {
            return address == b.address &&
                   domain == b.domain;
        }
    };

    QList<Item> mItems;

    QString mCachePath;
    QString mPassword;
    qint32 mLimit = 10;

    QTimer *mReloadTimer;
};

#endif // RECENTADDRESSESMODEL_H

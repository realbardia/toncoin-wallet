#include "recentaddressesmodel.h"
#include "core/tools/crypto.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#ifndef CRYPTO_FILE_STORE_SALT
#define CRYPTO_FILE_STORE_SALT "6ef44d15-ae3b-4231-b832-80847b4192cf"
#endif

RecentAddressesModel::RecentAddressesModel(QObject *parent)
    : AsemanAbstractListModel(parent)
{
    mReloadTimer = new QTimer(this);
    mReloadTimer->setInterval(100);
    mReloadTimer->setSingleShot(true);

    connect(mReloadTimer, &QTimer::timeout, this, &RecentAddressesModel::doReload);
}

RecentAddressesModel::~RecentAddressesModel()
{

}

QVariant RecentAddressesModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    const auto i = mItems.at(row);

    switch (role)
    {
    case RoleAddress:
        return i.address;
    case RoleDomain:
        return i.domain;
    case RoleDateTime:
        return i.datetime;
    }

    return QVariant();
}

int RecentAddressesModel::rowCount(const QModelIndex &) const
{
    return count();
}

int RecentAddressesModel::count() const
{
    return mItems.count();
}

QHash<qint32, QByteArray> RecentAddressesModel::roleNames() const
{
    return {
        {RoleAddress, "address"},
        {RoleDomain, "domain"},
        {RoleDateTime, "datetime"},
    };
}

QString RecentAddressesModel::cachePath() const
{
    return mCachePath;
}

void RecentAddressesModel::setCachePath(const QString &newCachePath)
{
    if (mCachePath == newCachePath)
        return;
    mCachePath = newCachePath;
    reload();
    Q_EMIT cachePathChanged();
}

QString RecentAddressesModel::password() const
{
    return mPassword;
}

void RecentAddressesModel::setPassword(const QString &newPassword)
{
    if (mPassword == newPassword)
        return;
    mPassword = newPassword;
    reload();
    Q_EMIT passwordChanged();
}

void RecentAddressesModel::reload()
{
    mReloadTimer->stop();
    mReloadTimer->start();
}

void RecentAddressesModel::append(const QString &address, const QString &domain, const QDateTime &datetime)
{
    Item item;
    item.address = address;
    item.domain = domain;
    item.datetime = datetime;

    const auto existsIdx = mItems.indexOf(item);
    if (existsIdx >= 0)
    {
        beginRemoveRows(QModelIndex(), existsIdx, existsIdx);
        mItems.removeAt(existsIdx);
        endRemoveRows();
    }

    beginInsertRows(QModelIndex(), 0, 0);
    mItems.prepend(item);
    endInsertRows();

    if (mLimit < mItems.count())
    {
        beginRemoveRows(QModelIndex(), mLimit, mItems.count());
        while (mLimit < mItems.count())
            mItems.removeLast();
        endRemoveRows();
    }

    store();
    Q_EMIT countChanged();
}

void RecentAddressesModel::remove(int index)
{
    if (index < 0 || index >= mItems.count())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    mItems.removeAt(index);
    endRemoveRows();

    store();
    Q_EMIT countChanged();
}

void RecentAddressesModel::store()
{
    QFile f(mCachePath);
    if (!f.open(QFile::WriteOnly))
        return;

    QJsonArray array;
    for (const auto &i: mItems)
    {
        QJsonObject o;
        o[QStringLiteral("address")] = i.address;
        o[QStringLiteral("domain")] = i.domain;
        o[QStringLiteral("datetime")] = QString::number(i.datetime.toMSecsSinceEpoch());

        array << o;
    }

    QJsonDocument json(array);
    auto data = json.toJson(QJsonDocument::Compact);

    if (mPassword.count())
    {
        TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
        data = crypto.encrypt(data);
    }

    f.write(data);
    f.close();
}

void RecentAddressesModel::restore()
{
    beginResetModel();
    mItems.clear();

    QFile f(mCachePath);
    if (f.open(QFile::ReadOnly))
    {
        auto data = f.readAll();
        if (mPassword.count())
        {
            TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
            data = crypto.decrypt(data);
        }

        const auto json = QJsonDocument::fromJson(data);
        for (const auto &item: json.array())
        {
            if (mItems.count() >= mLimit)
                break;

            const auto o = item.toObject();
            Item i;
            i.address = o.value(QStringLiteral("address")).toString();
            i.domain = o.value(QStringLiteral("domain")).toString();
            i.datetime = QDateTime::fromMSecsSinceEpoch(o.value(QStringLiteral("datetime")).toString().toLongLong());

            mItems << i;
        }
    }

    Q_EMIT countChanged();
    endResetModel();
}

void RecentAddressesModel::doReload()
{
    restore();
}

qint32 RecentAddressesModel::limit() const
{
    return mLimit;
}

void RecentAddressesModel::setLimit(qint32 newLimit)
{
    if (mLimit == newLimit)
        return;
    mLimit = newLimit;
    reload();
    Q_EMIT limitChanged();
}

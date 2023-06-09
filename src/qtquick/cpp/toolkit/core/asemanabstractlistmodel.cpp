#include "asemanabstractlistmodel.h"

#include <QHash>

AsemanAbstractListModel::AsemanAbstractListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

QStringList AsemanAbstractListModel::roles() const
{
    QStringList result;
    const QHash<int,QByteArray> &roles = roleNames();
    QHashIterator<int,QByteArray> i(roles);
    while(i.hasNext())
    {
        i.next();
        result << QString::fromUtf8(i.value());
    }

    std::sort(result.begin(), result.end());
    return result;
}

QVariant AsemanAbstractListModel::get(int row, int role) const
{
    if(row >= rowCount() || row < 0)
        return QVariant();

    const QModelIndex &idx = index(row,0);
    return data(idx , role);
}

QVariant AsemanAbstractListModel::get(int index, const QString &roleName) const
{
    const int role = roleNames().key(roleName.toUtf8());
    return get(index, role);
}

QVariantMap AsemanAbstractListModel::get(int index) const
{
    if(index >= rowCount())
        return QVariantMap();

    QVariantMap result;
    const QHash<int,QByteArray> &roles = roleNames();
    QHashIterator<int,QByteArray> i(roles);
    while(i.hasNext())
    {
        i.next();
        result[QString::fromUtf8(i.value())] = get(index, i.key());
    }

    return result;
}

AsemanAbstractListModel::~AsemanAbstractListModel()
{
}

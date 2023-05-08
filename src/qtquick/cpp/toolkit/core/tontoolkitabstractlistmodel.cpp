#include "tontoolkitabstractlistmodel.h"

#include <QHash>

TonToolkitAbstractListModel::TonToolkitAbstractListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

QStringList TonToolkitAbstractListModel::roles() const
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

QVariant TonToolkitAbstractListModel::get(int row, int role) const
{
    if(row >= rowCount() || row < 0)
        return QVariant();

    const QModelIndex &idx = index(row,0);
    return data(idx , role);
}

QVariant TonToolkitAbstractListModel::get(int index, const QString &roleName) const
{
    const int role = roleNames().key(roleName.toUtf8());
    return get(index, role);
}

QVariantMap TonToolkitAbstractListModel::get(int index) const
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

TonToolkitAbstractListModel::~TonToolkitAbstractListModel()
{
}

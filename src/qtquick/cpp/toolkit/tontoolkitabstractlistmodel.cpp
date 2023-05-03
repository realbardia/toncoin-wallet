/*
    Copyright (C) 2017 TonToolkit Team
    http://tontoolkit.co

    TonToolkitQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TonToolkitQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*!
    \class TonToolkitAbstractListModel
    \brief TonToolkit's Abstract list model class provides some useful get methods
    for QML.

    TonToolkitAbstractListModel provide abstract ListModel class, has some get
    functions that is useful on the QML.
    Every model create based on TonToolkitAbstractListModel, could pass data
    to the QML using this functions.

    \reentrant
    \ingroup TonToolkitCore
*/

#include "tontoolkitabstractlistmodel.h"

#include <QHash>

TonToolkitAbstractListModel::TonToolkitAbstractListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

/*!
    Returns all roles keys of the Model as a QStringList.
    \sa get
 */
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


/*!
    Return value based on the \a row number and \a role id.
    \sa roles
 */
QVariant TonToolkitAbstractListModel::get(int row, int role) const
{
    if(row >= rowCount() || row < 0)
        return QVariant();

    const QModelIndex &idx = index(row,0);
    return data(idx , role);
}


/*!
    Return value based on the \a row number and \a roleName.
    \sa roles
 */
QVariant TonToolkitAbstractListModel::get(int index, const QString &roleName) const
{
    const int role = roleNames().key(roleName.toUtf8());
    return get(index, role);
}


/*!
    Return all values based on the \a row number as a QVariantMap object.
    \sa roles
 */
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

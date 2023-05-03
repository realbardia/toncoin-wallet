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

#ifndef TONTOOLKITABSTRACTLISTMODEL_H
#define TONTOOLKITABSTRACTLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class TonToolkitAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TonToolkitAbstractListModel(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitAbstractListModel();

    Q_INVOKABLE QStringList roles() const;

public Q_SLOTS:
    QVariant get(int index, int role) const;
    QVariant get(int index, const QString &roleName) const;
    QVariantMap get(int index) const;
};

#endif // TONTOOLKITABSTRACTLISTMODEL_H

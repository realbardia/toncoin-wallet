/*
    Copyright (C) 2019 TonToolkit Team
    http://tontoolkit.io

    This project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TONTOOLKITVIEWPORTITEM_H
#define TONTOOLKITVIEWPORTITEM_H

#include <QObject>
#include <QVariant>

class TonToolkitViewportItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QVariant component READ component WRITE setComponent NOTIFY componentChanged)

    class Private;

public:
    TonToolkitViewportItem(QObject *parent = Q_NULLPTR);
    TonToolkitViewportItem(const QString &name, const QVariant &component, QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitViewportItem();

    QString name() const;
    void setName(const QString &name);

    QVariant component() const;
    void setComponent(const QVariant &component);

Q_SIGNALS:
    void nameChanged();
    void componentChanged();

private:
    Private *p;
};

#endif // TONTOOLKITVIEWPORTITEM_H

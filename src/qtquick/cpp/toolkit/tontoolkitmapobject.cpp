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

#include "tontoolkitmapobject.h"

#include <QList>
#include <QPair>
#include <QDebug>
#include <QDebug>

class TonToolkitMapObjectPrivate
{
public:
    QMultiMap<QString,QVariant> map;
};

TonToolkitMapObject::TonToolkitMapObject(QObject *parent) :
    QObject(parent)
{
    p = new TonToolkitMapObjectPrivate;
}

void TonToolkitMapObject::insert(const QString &key, const QVariant &value)
{
    p->map.replace(key,value);
    Q_EMIT countChanged();
    Q_EMIT valuesChanged();
    Q_EMIT keysChanged();
}

void TonToolkitMapObject::insertMulti(const QString &key, const QVariant &value)
{
    p->map.insert(key,value);
    Q_EMIT countChanged();
    Q_EMIT valuesChanged();
    Q_EMIT keysChanged();
}

void TonToolkitMapObject::remove(const QString &key)
{
    p->map.remove(key);
    Q_EMIT countChanged();
    Q_EMIT valuesChanged();
    Q_EMIT keysChanged();
}

void TonToolkitMapObject::remove(const QString &key, const QVariant &value)
{
    p->map.remove(key,value);
    Q_EMIT countChanged();
    Q_EMIT valuesChanged();
    Q_EMIT keysChanged();
}

QVariant TonToolkitMapObject::key(const QVariant &value)
{
    return p->map.key(value);
}

QStringList TonToolkitMapObject::keys(const QVariant &value)
{
    return p->map.keys(value);
}

QStringList TonToolkitMapObject::uniqueKeys()
{
    return p->map.uniqueKeys();
}

QStringList TonToolkitMapObject::keys()
{
    return p->map.keys();
}

QVariant TonToolkitMapObject::value(const QString &key)
{
    return p->map.value(key);
}

QVariantList TonToolkitMapObject::values(const QString &key)
{
    return p->map.values(key);
}

QVariantList TonToolkitMapObject::values() const
{
    return p->map.values();
}

QVariant TonToolkitMapObject::containt(const QString &key)
{
    return contains(key);
}

QVariant TonToolkitMapObject::containt(const QString &key, const QVariant &value)
{
    return contains(key, value);
}

QVariant TonToolkitMapObject::contains(const QString &key)
{
    return p->map.contains(key);
}

QVariant TonToolkitMapObject::contains(const QString &key, const QVariant &value)
{
    return p->map.contains(key,value);
}

void TonToolkitMapObject::clear()
{
    if(p->map.isEmpty())
        return;
    p->map.clear();
    Q_EMIT countChanged();
    Q_EMIT valuesChanged();
    Q_EMIT keysChanged();
}

int TonToolkitMapObject::count()
{
    return p->map.count();
}

QVariantMap TonToolkitMapObject::toMap() const
{
    QVariantMap map;
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QMapIterator<QString, QVariant> i(p->map);
#else
    QMultiMapIterator<QString, QVariant> i(p->map);
#endif
    while(i.hasNext())
    {
        i.next();
        map.insert(i.key(), i.value());
    }
    return map;
}

TonToolkitMapObject::~TonToolkitMapObject()
{
    delete p;
}

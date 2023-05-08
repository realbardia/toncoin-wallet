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

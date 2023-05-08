#include "tontoolkitquickobject.h"

#include <QSet>

QSet<TonToolkitQuickObject*> tontoolkit_quick_objs;

class TonToolkitQuickObjectPrivate
{
public:
    QList<QObject*> items;
};

TonToolkitQuickObject::TonToolkitQuickObject(QObject *parent) :
    QObject(parent)
{
    p = new TonToolkitQuickObjectPrivate;
    tontoolkit_quick_objs.insert(this);
}

QQmlListProperty<QObject> TonToolkitQuickObject::items()
{
    return QQmlListProperty<QObject>(this, &p->items, QQmlListProperty<QObject>::AppendFunction(append),
                                                      QQmlListProperty<QObject>::CountFunction(count),
                                                      QQmlListProperty<QObject>::AtFunction(at),
                                     QQmlListProperty<QObject>::ClearFunction(clear) );
}

QList<QObject *> TonToolkitQuickObject::itemsList() const
{
    return p->items;
}

bool TonToolkitQuickObject::isValid(TonToolkitQuickObject *obj)
{
    return tontoolkit_quick_objs.contains(obj);
}

void TonToolkitQuickObject::append(QQmlListProperty<QObject> *p, QObject *v)
{
    TonToolkitQuickObject *aobj = static_cast<TonToolkitQuickObject*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int TonToolkitQuickObject::count(QQmlListProperty<QObject> *p)
{
    TonToolkitQuickObject *aobj = static_cast<TonToolkitQuickObject*>(p->object);
    return aobj->p->items.count();
}

QObject *TonToolkitQuickObject::at(QQmlListProperty<QObject> *p, int idx)
{
    TonToolkitQuickObject *aobj = static_cast<TonToolkitQuickObject*>(p->object);
    return aobj->p->items.at(idx);
}

void TonToolkitQuickObject::clear(QQmlListProperty<QObject> *p)
{
    TonToolkitQuickObject *aobj = static_cast<TonToolkitQuickObject*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

TonToolkitQuickObject::~TonToolkitQuickObject()
{
    tontoolkit_quick_objs.remove(this);
    delete p;
}

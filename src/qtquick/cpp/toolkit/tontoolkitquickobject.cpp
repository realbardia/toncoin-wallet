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

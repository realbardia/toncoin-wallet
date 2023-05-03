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

#include "tontoolkitlistobject.h"

#include <QVariantList>
#include <QDebug>
#include <QDateTime>

class TonToolkitListObjectPrivate
{
public:
    QVariantList list;
};

TonToolkitListObject::TonToolkitListObject(QObject *parent) :
    QObject(parent)
{
    p = new TonToolkitListObjectPrivate;
}

void TonToolkitListObject::removeAll(const QVariant &v)
{
    p->list.removeAll( v );
    Q_EMIT countChanged();
}

void TonToolkitListObject::removeOne(const QVariant &v)
{
    p->list.removeOne( v );
    Q_EMIT countChanged();
}

void TonToolkitListObject::removeAt(int index)
{
    p->list.removeAt( index );
    Q_EMIT countChanged();
}

QVariant TonToolkitListObject::takeLast()
{
    if( p->list.isEmpty() )
        return QVariant();

    const QVariant & res = p->list.takeLast();
    Q_EMIT countChanged();

    return res;
}

QVariant TonToolkitListObject::takeFirst()
{
    if( p->list.isEmpty() )
        return QVariant();

    const QVariant & res = p->list.takeFirst();
    Q_EMIT countChanged();

    return res;
}

QVariant TonToolkitListObject::takeAt(int index)
{
    const QVariant & res = p->list.takeAt( index );
    Q_EMIT countChanged();

    return res;
}

void TonToolkitListObject::clear()
{
    p->list.clear();
    Q_EMIT countChanged();
}

QVariant TonToolkitListObject::last() const
{
    if( p->list.isEmpty() )
        return QVariant();

    return p->list.last();
}

QVariant TonToolkitListObject::first() const
{
    if( p->list.isEmpty() )
        return QVariant();

    return p->list.first();
}

void TonToolkitListObject::insert(int index, const QVariant &v)
{
    p->list.insert( index, v );
    Q_EMIT countChanged();
}

void TonToolkitListObject::append(const QVariant &v)
{
    p->list.append( v );
    Q_EMIT countChanged();
}

void TonToolkitListObject::prepend(const QVariant &v)
{
    p->list.prepend( v );
    Q_EMIT countChanged();
}

void TonToolkitListObject::replace(int index, const QVariant &v)
{
    p->list.replace(index, v);
}

void TonToolkitListObject::swap(int idx0, int idx1)
{
    const auto val_0 = p->list.value(idx0);
    const auto val_1 = p->list.value(idx1);

    p->list[idx0] = val_1;
    p->list[idx1] = val_0;
}

int TonToolkitListObject::count() const
{
    return p->list.count();
}

bool TonToolkitListObject::isEmpty() const
{
    return p->list.isEmpty();
}

QVariant TonToolkitListObject::at(int index) const
{
    if(index == -1)
        return QVariant();

    return p->list.at(index);
}

int TonToolkitListObject::indexOf(const QVariant &v) const
{
    return p->list.indexOf(v);
}

void TonToolkitListObject::fromList(const QVariantList &list)
{
    if( p->list == list )
        return;

    p->list = list;
    Q_EMIT countChanged();
}

QVariantList TonToolkitListObject::toList() const
{
    return p->list;
}

bool TonToolkitListObject::contains(const QVariant &v) const
{
    return p->list.contains(v);
}

TonToolkitListObject::~TonToolkitListObject()
{
    delete p;
}

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

#include "tontoolkitbackhandler.h"
#include "tontoolkittools.h"

#include <QPair>
#include <QStack>
#include <QDebug>

class TonToolkitHandlerItem
{
public:
    QObject *obj = Q_NULLPTR;
    QJSValue jsv;
};

class TonToolkitBackHandlerPrivate
{
public:
    QList<TonToolkitHandlerItem> stack;

    TonToolkitHandlerItem lastActiveItem(qint32 *index = Q_NULLPTR) {
        if (index)
            *index = -1;

        TonToolkitHandlerItem item;
        for (qint32 i=stack.count()-1; i>=0; i--)
        {
            TonToolkitHandlerItem _itm = stack.at(i);
            if (_itm.obj->property("disableBack").toBool() == false)
            {
                item = _itm;
                if (index)
                    *index = i;
                break;
            }
        }

        return item;
    }
};

TonToolkitBackHandler::TonToolkitBackHandler(QObject *parent) :
    QObject(parent)
{
    p = new TonToolkitBackHandlerPrivate;
}

QObject *TonToolkitBackHandler::topHandlerObject() const
{
    if( p->stack.isEmpty() )
        return Q_NULLPTR;

    return p->stack.last().obj;
}

QJSValue TonToolkitBackHandler::topHandlerMethod() const
{
    if( p->stack.isEmpty() )
        return QString();

    return p->stack.last().jsv;
}

int TonToolkitBackHandler::count()
{
    qint32 index = 0;
    TonToolkitHandlerItem item = p->lastActiveItem(&index);
    return index+1;
}

void TonToolkitBackHandler::pushHandler(QObject *obj, QJSValue jsv)
{
    TonToolkitHandlerItem item;
    item.obj = obj;
    item.jsv = jsv;

    p->stack.append( item );
    Q_EMIT countChanged();

    setupObject(obj);
}

void TonToolkitBackHandler::pushDownHandler(QObject *obj, QJSValue jsv)
{
    TonToolkitHandlerItem item;
    item.obj = obj;
    item.jsv = jsv;

    p->stack.prepend( item );
    Q_EMIT countChanged();

    setupObject(obj);
}

void TonToolkitBackHandler::removeHandler(QObject *obj)
{
    for( int i=p->stack.count()-1; i>=0; i-- )
        if( p->stack.at(i).obj == obj )
        {
            p->stack.removeAt(i);
            break;
        }

    Q_EMIT countChanged();
}

QObject *TonToolkitBackHandler::tryPopHandler()
{
    if( p->stack.isEmpty() )
        return Q_NULLPTR;

    qint32 index = 0;
    TonToolkitHandlerItem item = p->lastActiveItem(&index);
    if (!item.obj)
        return Q_NULLPTR;

    const int count = p->stack.count();

    const QJSValue & res = item.jsv.call();
    if( !res.isUndefined() && res.toBool() == false )
        return Q_NULLPTR;

    if( p->stack.count() == count )
        p->stack.takeAt(index);

    Q_EMIT countChanged();
    return item.obj;
}

QObject *TonToolkitBackHandler::forcePopHandler()
{
    if( p->stack.isEmpty() )
        return Q_NULLPTR;

    qint32 index = 0;
    TonToolkitHandlerItem item = p->lastActiveItem(&index);
    if (!item.obj)
        return Q_NULLPTR;

    const int count = p->stack.count();

    item.jsv.call();
    if( p->stack.count() == count )
        p->stack.takeAt(index);

    Q_EMIT countChanged();
    return item.obj;
}

void TonToolkitBackHandler::clear()
{
    p->stack.clear();
}

bool TonToolkitBackHandler::back()
{
    if(count() == 0)
    {
        Q_EMIT backFinished();
        return false;
    }

    tryPopHandler();
    return true;
}

void TonToolkitBackHandler::object_destroyed(QObject *obj)
{
    for( int i=0; i<p->stack.count(); i++ )
        if( p->stack.at(i).obj == obj )
        {
            p->stack.removeAt(i);
            i--;
        }

    Q_EMIT countChanged();
}

void TonToolkitBackHandler::setupObject(QObject *obj)
{
    if (!obj->property("disableBack").isNull())
        connect(obj, SIGNAL(disableBackChanged()), this, SIGNAL(countChanged()));

    connect(obj, &QObject::destroyed, this, &TonToolkitBackHandler::object_destroyed );
}

TonToolkitBackHandler::~TonToolkitBackHandler()
{
    delete p;
}

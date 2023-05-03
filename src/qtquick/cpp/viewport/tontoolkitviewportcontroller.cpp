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

#include "tontoolkitviewportcontroller.h"

#include <QSet>
#include <QPointer>
#include <QQmlInfo>
#include <QUrl>
#include <QUrlQuery>


class TonToolkitViewportController::Private
{
public:
    QPointer<TonToolkitViewport> viewport;
    QList<TonToolkitViewportControllerRoute*> routes;
    bool allowRecursiveTrigger;

    static QList<TonToolkitViewportController*> controllers;
};

QList<TonToolkitViewportController*> TonToolkitViewportController::Private::controllers;

TonToolkitViewportController::TonToolkitViewportController(QObject *parent) :
    QObject(parent)
{
    p = new Private;
    p->allowRecursiveTrigger = false;

    Private::controllers << this;
}

QQmlListProperty<TonToolkitViewportControllerRoute> TonToolkitViewportController::routes()
{
    return QQmlListProperty<TonToolkitViewportControllerRoute>(this, &p->routes, QQmlListProperty<TonToolkitViewportControllerRoute>::AppendFunction(append),
                                                          QQmlListProperty<TonToolkitViewportControllerRoute>::CountFunction(count),
                                                          QQmlListProperty<TonToolkitViewportControllerRoute>::AtFunction(at),
                                                          QQmlListProperty<TonToolkitViewportControllerRoute>::ClearFunction(clear) );
}

void TonToolkitViewportController::setViewport(TonToolkitViewport *viewport)
{
    if (p->viewport == viewport)
        return;

    p->viewport = viewport;
    Q_EMIT viewportChanged();
}

TonToolkitViewport *TonToolkitViewportController::viewport() const
{
    return p->viewport;
}

bool TonToolkitViewportController::allowRecursiveTrigger() const
{
    return p->allowRecursiveTrigger;
}

void TonToolkitViewportController::setAllowRecursiveTrigger(bool allowRecursiveTrigger)
{
    if (p->allowRecursiveTrigger == allowRecursiveTrigger)
        return;

    p->allowRecursiveTrigger = allowRecursiveTrigger;
    Q_EMIT allowRecursiveTriggerChanged();
}

QVariantMap TonToolkitViewportController::lookup(const QString &url, QVariantMap properties, TonToolkitViewport *viewport)
{
    QVariantMap res;
    if (!viewport)
        viewport = p->viewport;

    if (!viewport)
    {
        qmlWarning(this) << "viewport property cannot be null.";
        return res;
    }

    for (TonToolkitViewportControllerRoute *r: p->routes)
    {
        auto rx = r->route();
        rx.setPattern( "^" + rx.pattern() + "$" );
        if (url.indexOf(rx) == 0)
        {
            properties["properties"] = properties;
            properties["url"] = url;

            QUrl urlObj(url);
            QUrlQuery query(urlObj);
            auto queryItems = query.queryItems();
            for (auto qi: queryItems)
                properties[qi.first] = qi.second;

            QVariant item;
            QVariant component = r->component();
            QVariant type = r->viewportType().length()? r->viewportType() : urlObj.scheme();
            QVariant props = properties;

            res["component"] = component;
            res["type"] = type;
            res["properties"] = props;
            res["viewport"] = QVariant::fromValue<QObject*>(viewport);

            return res;
        }
    }

    TonToolkitViewportAttechedProperty attachProperty(p->viewport);
    TonToolkitViewportController *parentController = static_cast<TonToolkitViewportController*>(attachProperty.controller());
    if (parentController && p->allowRecursiveTrigger)
        return parentController->lookup(url, properties, viewport);
    else
        qmlWarning(this) << "Cannot find any route to handle " << url;

    return res;
}

void TonToolkitViewportController::append(QQmlListProperty<TonToolkitViewportControllerRoute> *p, TonToolkitViewportControllerRoute *v)
{
    TonToolkitViewportController *aobj = static_cast<TonToolkitViewportController*>(p->object);
    aobj->p->routes.append(v);
    Q_EMIT aobj->routesChanged();
}

int TonToolkitViewportController::count(QQmlListProperty<TonToolkitViewportControllerRoute> *p)
{
    TonToolkitViewportController *aobj = static_cast<TonToolkitViewportController*>(p->object);
    return aobj->p->routes.count();
}

TonToolkitViewportControllerRoute *TonToolkitViewportController::at(QQmlListProperty<TonToolkitViewportControllerRoute> *p, int idx)
{
    TonToolkitViewportController *aobj = static_cast<TonToolkitViewportController*>(p->object);
    return aobj->p->routes.at(idx);
}

void TonToolkitViewportController::clear(QQmlListProperty<TonToolkitViewportControllerRoute> *p)
{
    TonToolkitViewportController *aobj = static_cast<TonToolkitViewportController*>(p->object);
    aobj->p->routes.clear();
    Q_EMIT aobj->routesChanged();
}

QList<TonToolkitViewportController *> TonToolkitViewportController::controllers(TonToolkitViewport *viewport)
{
    QList<TonToolkitViewportController *> res;
    for (TonToolkitViewportController *controller: Private::controllers)
        if (controller->p->viewport == viewport)
            res << controller;
    return res;
}

TonToolkitViewportController::~TonToolkitViewportController()
{
    Private::controllers.removeOne(this);
    delete p;
}

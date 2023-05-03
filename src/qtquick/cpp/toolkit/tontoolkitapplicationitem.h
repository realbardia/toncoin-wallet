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

#ifndef TONTOOLKITAPPLICATIONITEM_H
#define TONTOOLKITAPPLICATIONITEM_H

#include "tontoolkit_macros.h"
#include "tontoolkitquickobject.h"
#include "tontoolkitapplication.h"

#include <QVariant>
#include <QCoreApplication>
#include <QUrl>
#include <QJSValue>
#include <QQmlEngine>
#include <QQmlListProperty>

class TonToolkitApplicationItemPrivate;
class TonToolkitApplicationItem : public TonToolkitApplication
{
    Q_OBJECT
    Q_PROPERTY(QString applicationId READ applicationId WRITE setApplicationId NOTIFY applicationIdChanged)
    Q_PROPERTY(bool isRunning READ isRunning NOTIFY isRunningChanged)
    Q_PROPERTY(int statusBarStyle READ statusBarStyle WRITE setStatusBarStyle NOTIFY statusBarStyleChanged)

    Q_PROPERTY(QQmlListProperty<QObject> items READ items NOTIFY itemsChanged)
    Q_CLASSINFO("DefaultProperty", "items")

    Q_ENUMS(StatusBarStyles)

public:
    enum StatusBarStyles {
        StatusBarStyleLight,
        StatusBarStyleDark,
        StatusBarStyleAuto
    };

    TonToolkitApplicationItem(QQmlEngine *engine);
    TonToolkitApplicationItem();
    virtual ~TonToolkitApplicationItem();

    static void setApplicationId(const QString &applicationId);
    static QString applicationId();

    static bool isRunning();

    QQmlListProperty<QObject> items();
    QList<QObject*> itemsList() const;

    int statusBarStyle();
    void setStatusBarStyle(int statusBarStyle);

public Q_SLOTS:
    void sendMessage(const QString &msg);

    bool checkPermissions(const QString &persmission);
    QVariantMap requestPermissions(QStringList persmissions, QJSValue callback);

Q_SIGNALS:
    void applicationIdChanged();
    void isRunningChanged();
    void messageReceived(const QString &msg);
    void itemsChanged();
    void statusBarStyleChanged();

private:
    static void append(QQmlListProperty<QObject> *p, QObject *v);
    static int count(QQmlListProperty<QObject> *p);
    static QObject *at(QQmlListProperty<QObject> *p, int idx);
    static void clear(QQmlListProperty<QObject> *p);

private:
    static bool tontoolkit_app_inited;
    static bool tontoolkit_app_init();

private:
    TonToolkitApplicationItemPrivate *p;
};

#endif // TONTOOLKITAPPLICATIONITEM_H

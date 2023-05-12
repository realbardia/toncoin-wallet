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
    static void sendMessage(const QString &msg);

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

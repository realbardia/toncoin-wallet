#include "tontoolkitapplicationitem.h"
#include "tontoolkitdevices.h"
#include "tontoolkittools.h"
#include "qtsingleapplication/qtlocalpeer.h"

#ifdef Q_OS_ANDROID
#include "tontoolkitjavalayer.h"
#endif

#include <QDir>
#include <QThread>
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QStandardPaths>
#include <QPointer>
#include <QQmlEngine>
#include <QGuiApplication>

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#endif
#ifdef Q_OS_IOS
#include "private/quickios/quickios.h"
#endif

static TonToolkitApplicationItem *tontoolkit_app_singleton = 0;
static QSet<TonToolkitApplicationItem*> tontoolkit_app_objects;

bool TonToolkitApplicationItem::tontoolkit_app_inited = TonToolkitApplicationItem::tontoolkit_app_init();

class TonToolkitApplicationItemPrivate
{
public:
    QPointer<QQmlEngine> engine;
    QList<QObject*> items;

    static QtLocalPeer *peer;

    static qint32 statusBarStyle;
    QTimer *statusbarStyleTimer_ios;
};

QtLocalPeer *TonToolkitApplicationItemPrivate::peer = 0;
qint32 TonToolkitApplicationItemPrivate::statusBarStyle = TonToolkitApplicationItem::StatusBarStyleAuto;


TonToolkitApplicationItem::TonToolkitApplicationItem(QQmlEngine *engine) :
    TonToolkitApplicationItem()
{
    p->engine = engine;
}

TonToolkitApplicationItem::TonToolkitApplicationItem() :
    TonToolkitApplication()
{
    p = new TonToolkitApplicationItemPrivate;

#ifdef Q_OS_IOS
    p->statusbarStyleTimer_ios = new QTimer(this);
    p->statusbarStyleTimer_ios->setSingleShot(true);
    connect(p->statusbarStyleTimer_ios, &QTimer::timeout, this, [this](){
        if (p->engine)
            return;

        setStatusBarStyle(p->statusBarStyle);
        p->statusbarStyleTimer_ios->start(2000);
    });

    auto app = qobject_cast<QGuiApplication*>(QGuiApplication::instance());
    if (app)
    {
        connect(app, &QGuiApplication::applicationStateChanged, this, [this](Qt::ApplicationState state){
            if (p->engine)
                return;

            switch (static_cast<int>(state))
            {
            case Qt::ApplicationActive:
                p->statusbarStyleTimer_ios->stop();
                p->statusbarStyleTimer_ios->start(10);
                break;
            }
        });
    }
#endif
}

bool TonToolkitApplicationItem::tontoolkit_app_init()
{
    if(tontoolkit_app_inited)
        return true;

#ifndef FORCE_TONTOOLKIT_DENSITY
#ifdef Q_OS_ANDROID
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    if(!QGuiApplication::testAttribute(Qt::AA_EnableHighDpiScaling) && qgetenv("QT_SCALE_FACTOR").isNull() && qgetenv("TONTOOLKIT_SCALE_FACTOR").isNull())
    {
        qreal ratio = TonToolkitJavaLayer::instance()->density()*(TonToolkitDevices::isTablet()? 1.28 : 1);
        qputenv("QT_SCALE_FACTOR",QByteArray::number(ratio));
    }
#endif
#endif
    return true;
}

void TonToolkitApplicationItem::setApplicationId(const QString &applicationId)
{
    if(TonToolkitApplicationItemPrivate::peer && TonToolkitApplicationItemPrivate::peer->applicationId() == applicationId)
        return;
    if(TonToolkitApplicationItemPrivate::peer)
        delete TonToolkitApplicationItemPrivate::peer;

    TonToolkitApplicationItemPrivate::peer = 0;
    if(!applicationId.isEmpty())
    {
        TonToolkitApplicationItemPrivate::peer = new QtLocalPeer(0, applicationId);
        for(TonToolkitApplicationItem *app: tontoolkit_app_objects)
            connect(TonToolkitApplicationItemPrivate::peer, &QtLocalPeer::messageReceived, app, &TonToolkitApplicationItem::messageReceived);
    }

    for(TonToolkitApplicationItem *app: tontoolkit_app_objects)
    {
        Q_EMIT app->applicationIdChanged();
        Q_EMIT app->isRunningChanged();
    }
}

QString TonToolkitApplicationItem::applicationId()
{
    if(TonToolkitApplicationItemPrivate::peer)
        return TonToolkitApplicationItemPrivate::peer->applicationId();
    else
        return QString();
}

bool TonToolkitApplicationItem::isRunning()
{
    if(TonToolkitApplicationItemPrivate::peer)
        return TonToolkitApplicationItemPrivate::peer->isClient();

    return false;
}

int TonToolkitApplicationItem::statusBarStyle()
{
    return p->statusBarStyle;
}

void TonToolkitApplicationItem::setStatusBarStyle(int statusBarStyle)
{
#ifdef Q_OS_IOS
    QuickIOS::StatusBarStyle style = QuickIOS::StatusBarStyleDefault;
    switch (statusBarStyle)
    {
    case StatusBarStyleLight:
        style = QuickIOS::StatusBarStyleLightContent;
        break;
    case StatusBarStyleDark:
        style = QuickIOS::StatusBarStyleBlackTranslucent;
        break;
    case StatusBarStyleAuto:
        style = QuickIOS::StatusBarStyleDefault;
        break;
    }

    QuickIOS::setStatusBarStyle(style);
#endif

    if (p->statusBarStyle == statusBarStyle)
        return;

    p->statusBarStyle = statusBarStyle;
#ifdef Q_OS_IOS
    switch (statusBarStyle)
    {
    case StatusBarStyleLight:
    case StatusBarStyleDark:
        p->statusbarStyleTimer_ios->stop();
        p->statusbarStyleTimer_ios->start(1);
        break;
    case StatusBarStyleAuto:
        p->statusbarStyleTimer_ios->stop();
        break;
    }
#endif

    Q_EMIT statusBarStyleChanged();
}

void TonToolkitApplicationItem::sendMessage(const QString &msg)
{
    if(TonToolkitApplicationItemPrivate::peer)
        TonToolkitApplicationItemPrivate::peer->sendMessage(msg, 5000);
}

#ifdef QT_QML_LIB
bool TonToolkitApplicationItem::checkPermissions(const QString &persmission)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)) && defined (Q_OS_ANDROID)
    if (QtAndroid::checkPermission(persmission) == QtAndroid::PermissionResult::Granted)
        return true;
    else
        return false;
#else
    Q_UNUSED(persmission)
    return true;
#endif
}
#endif

#ifdef QT_QML_LIB
QVariantMap TonToolkitApplicationItem::requestPermissions(QStringList persmissions, QJSValue callback)
{
    QVariantMap _res;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)) && defined (Q_OS_ANDROID)
    auto c_callback = [callback](const QtAndroid::PermissionResultMap &res) -> QVariantMap {
        QVariantMap map;

        QHashIterator<QString, QtAndroid::PermissionResult> i(res);
        while(i.hasNext())
        {
            i.next();
            map[i.key()] = (i.value() == QtAndroid::PermissionResult::Granted);
        }

        return map;
    };

    for(QString pr: persmissions)
        if(QtAndroid::checkPermission(pr) == QtAndroid::PermissionResult::Granted)
        {
            persmissions.removeAll(pr);
            _res[pr] = true;
        }

    if(persmissions.count())
    {
        if(callback.isCallable())
            QtAndroid::requestPermissions(persmissions, [callback, c_callback, _res, this](const QtAndroid::PermissionResultMap &res){
                QVariantMap map = c_callback(res);
                map.unite(_res);

                QJSValue callbackCopy = callback;
                if(p->engine)
                    callbackCopy.call(QJSValueList() << p->engine->toScriptValue<QVariant>(map));
            });
        else
            _res.unite(c_callback( QtAndroid::requestPermissionsSync(persmissions) ));
    }
    else
    {
        if(callback.isCallable())
        {
            if(p->engine)
                callback.call(QJSValueList() << p->engine->toScriptValue<QVariant>(_res));
        }
    }
#else
    QVariantMap map;
    for (const QString &perm: persmissions)
        map[perm] = true;

    QJSValue callbackCopy = callback;
    if(p->engine)
        callbackCopy.call(QJSValueList() << p->engine->toScriptValue<QVariant>(map));
#endif
    return _res;
}
#endif

QQmlListProperty<QObject> TonToolkitApplicationItem::items()
{
    return QQmlListProperty<QObject>(this, &p->items, QQmlListProperty<QObject>::AppendFunction(append),
                                                      QQmlListProperty<QObject>::CountFunction(count),
                                                      QQmlListProperty<QObject>::AtFunction(at),
                                     QQmlListProperty<QObject>::ClearFunction(clear) );
}

QList<QObject *> TonToolkitApplicationItem::itemsList() const
{
    return p->items;
}

void TonToolkitApplicationItem::append(QQmlListProperty<QObject> *p, QObject *v)
{
    TonToolkitApplicationItem *aobj = static_cast<TonToolkitApplicationItem*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int TonToolkitApplicationItem::count(QQmlListProperty<QObject> *p)
{
    TonToolkitApplicationItem *aobj = static_cast<TonToolkitApplicationItem*>(p->object);
    return aobj->p->items.count();
}

QObject *TonToolkitApplicationItem::at(QQmlListProperty<QObject> *p, int idx)
{
    TonToolkitApplicationItem *aobj = static_cast<TonToolkitApplicationItem*>(p->object);
    return aobj->p->items.at(idx);
}

void TonToolkitApplicationItem::clear(QQmlListProperty<QObject> *p)
{
    TonToolkitApplicationItem *aobj = static_cast<TonToolkitApplicationItem*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

TonToolkitApplicationItem::~TonToolkitApplicationItem()
{
    tontoolkit_app_objects.remove(this);
    if(tontoolkit_app_singleton == this)
    {
        if(TonToolkitApplicationItemPrivate::peer)
        {
            delete TonToolkitApplicationItemPrivate::peer;
            TonToolkitApplicationItemPrivate::peer = 0;
        }
        tontoolkit_app_singleton = 0;
    }

    delete p;
}

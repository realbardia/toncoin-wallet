#include "tonqtquick.h"

#include "viewport/tontoolkitviewport.h"
#include "viewport/tontoolkitabstractviewporttype.h"
#include "viewport/tontoolkitviewportcontroller.h"

#include "toolkit/tontoolkitmapobject.h"
#include "toolkit/tontoolkitquickobject.h"
#include "toolkit/tontoolkitsettings.h"
#include "toolkit/tontoolkitapplicationitem.h"
#include "toolkit/tontoolkittranslationmanager.h"
#include "toolkit/tontoolkitdevicesitem.h"
#include "toolkit/tontoolkittoolsitem.h"
#include "toolkit/tontoolkitbackhandler.h"
#include "toolkit/tontoolkitapplicationsingleton.h"
#include "toolkit/tontoolkitquickview.h"
#include "toolkit/tontoolkitstickeritem.h"
#include "toolkit/qmlwidgetmenu.h"
#include "toolkit/tontoolkitlistobject.h"
#include "toolkit/materialicons.h"

#include <QtQml>

void TonQtQuick::registerToolkit()
{
    qmlRegisterType<TonToolkitMapObject>("Toolkit", 1, 0, "MapObject");
    qmlRegisterType<TonToolkitListObject>("Toolkit", 1, 0, "ListObject");
    qmlRegisterType<TonToolkitQuickObject>("Toolkit", 1, 0, "TonToolkitObject");
    qmlRegisterType<TonToolkitSettings>("Toolkit", 1, 0, "Settings");
    qmlRegisterType<TonToolkitApplicationItem>("Toolkit", 1,0, "TonToolkitApplicationBase");
    qmlRegisterType<TonToolkitTranslationManager>("Toolkit", 1, 0, "TranslationManager");

    qmlRegisterType<TonToolkitStickerItem>("Toolkit", 1, 0, "StickerItem");

#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewMobile.qml"), "Toolkit", 1, 0, "TScrollView");
#elif defined(Q_OS_MACOS)
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "Toolkit", 1, 0, "TScrollView");
#else
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "Toolkit", 1, 0, "TScrollView");
//    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktop.qml"), "Toolkit", 1, 0, "TScrollView");
#endif

    qmlRegisterType<QmlWidgetMenu>("Toolkit", 1, 0, "QmlWidgetMenu");
    qmlRegisterType<QmlWidgetMenuItem>("Toolkit", 1, 0, "QmlWidgetMenuItem");

    qmlRegisterSingletonType<TonToolkitQuickView>("Toolkit", 1, 0, "View", [](QQmlEngine *engine, QJSEngine *){ return new TonToolkitQuickView(engine); });
    qmlRegisterSingletonInstance<TonToolkitDevicesItem>("Toolkit", 1, 0, "Devices", new TonToolkitDevicesItem);
    qmlRegisterSingletonInstance<TonToolkitToolsItem>("Toolkit", 1, 0, "Tools", new TonToolkitToolsItem);
    qmlRegisterSingletonInstance<MaterialIcons>("Toolkit", 1, 0, "MaterialIcons", new MaterialIcons);
    qmlRegisterSingletonInstance<TonToolkitToolsItem>("Toolkit", 1, 0, "Tools", new TonToolkitToolsItem);
    qmlRegisterSingletonInstance<TonToolkitBackHandler>("Toolkit", 1, 0, "BackHandler", new TonToolkitBackHandler);
    qmlRegisterSingletonType<TonToolkitApplicationSingleton>("Toolkit", 1, 0, "TonToolkitApp", [](QQmlEngine *engine, QJSEngine *){ return new TonToolkitApplicationSingleton(engine); });
#ifdef Q_OS_ANDROID
    qmlRegisterSingletonInstance<TonToolkitJavaLayer>("Toolkit", 1, 0, "JavaLayer", new TonToolkitJavaLayer);
#endif
}

void TonQtQuick::registerViewport()
{
    qmlRegisterType<TonToolkitAbstractViewportType>("Viewport", 1, 0, "AbstractViewportTypeCore");
    qmlRegisterType<TonToolkitViewport>("Viewport", 1, 0, "ViewportCore");
    qmlRegisterType<TonToolkitViewportItem>("Viewport", 1, 0, "ViewportItem");
    qmlRegisterType<TonToolkitViewportController>("Viewport", 1, 0, "ViewportControllerCore");
    qmlRegisterType<TonToolkitViewportControllerRoute>("Viewport", 1, 0, "ViewportControllerRoute");
    qmlRegisterUncreatableType<TonToolkitViewportType>("Viewport", 1, 0, "ViewportType", "");
}

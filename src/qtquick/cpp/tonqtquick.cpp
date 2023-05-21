#include "tonqtquick.h"

#include "toolkit/viewport/asemanviewport.h"
#include "toolkit/viewport/asemanabstractviewporttype.h"
#include "toolkit/viewport/asemanviewportcontroller.h"

#include "toolkit/core/asemanmapobject.h"
#include "toolkit/core/asemanquickobject.h"
#include "toolkit/core/asemansettings.h"
#include "toolkit/core/asemanapplicationitem.h"
#include "toolkit/core/asemantranslationmanager.h"
#include "toolkit/core/asemandevicesitem.h"
#include "toolkit/core/asemantoolsitem.h"
#include "toolkit/core/asemanbackhandler.h"
#include "toolkit/core/asemanquicklistmodel.h"
#include "toolkit/core/asemanapplicationsingleton.h"
#include "toolkit/core/asemanquickview.h"
#include "toolkit/core/asemanstickeritem.h"
#include "toolkit/core/qmlwidgetmenu.h"
#include "toolkit/core/asemanlistobject.h"
#include "toolkit/core/materialicons.h"
#include "toolkit/core/asemanqrcreator.h"
#include "toolkit/core/asemankeyhandler.h"
#include "toolkit/core/asemanrefresherobject.h"
#ifdef Q_OS_ANDROID
#include "toolkit/core/asemanjavalayer.h"
#endif

#include "wallets/core/keysmanager.h"
#include "wallets/core/recoveryphrasesmodel.h"
#include "wallets/core/phrasesquizmodel.h"
#include "wallets/core/tonqmlglobal.h"
#include "wallets/core/walletbackend.h"
#include "wallets/core/walletitem.h"
#include "wallets/core/recoverywordsmodel.h"
#include "wallets/core/walletstate.h"
#include "wallets/core/transactionsmodel.h"
#include "wallets/core/currencyprice.h"
#include "wallets/core/walleturlparser.h"
#include "wallets/core/feeestimater.h"
#include "wallets/core/transferrequest.h"

#include "wallets/tonconnect/tonconnect.h"
#include "wallets/tonconnect/tonconnectservice.h"

#include <QtQml>

void TonQtQuick::registerToolkit()
{
    qmlRegisterType<KeysManager>("Wallet.Core", 1, 0, "KeysManager");
    qmlRegisterType<RecoveryPhrasesModel>("Wallet.Core", 1, 0, "RecoveryPhrasesModel");
    qmlRegisterType<PhrasesQuizModel>("Wallet.Core", 1, 0, "PhrasesQuizModel");
    qmlRegisterType<WalletBackend>("Wallet.Core", 1, 0, "Backend");
    qmlRegisterType<WalletItem>("Wallet.Core", 1, 0, "WalletItem");
    qmlRegisterType<WalletState>("Wallet.Core", 1, 0, "WalletState");
    qmlRegisterType<RecoveryWordsModel>("Wallet.Core", 1, 0, "RecoveryWordsModel");
    qmlRegisterType<TransactionsModel>("Wallet.Core", 1, 0, "TransactionsModel");
    qmlRegisterType<CurrencyPrice>("Wallet.Core", 1, 0, "CurrencyPrice");
    qmlRegisterType<WalletUrlParser>("Wallet.Core", 1, 0, "WalletUrlParser");
    qmlRegisterType<FeeEstimater>("Wallet.Core", 1, 0, "FeeEstimater");
    qmlRegisterType<TransferRequest>("Wallet.Core", 1, 0, "TransferRequest");
    qmlRegisterUncreatableType<AsemanRefresherObject>("Wallet.Core", 1, 0, "RefresherObject", "");
    qmlRegisterSingletonInstance("Wallet.Core", 1,0, "TonQmlGlobal", new TonQmlGlobal);

    qmlRegisterType<TonConnectService>("Wallet.TonConnect", 1, 0, "TonConnectService");
    qmlRegisterType<TonConnect>("Wallet.TonConnect", 1, 0, "TonConnect");

    qmlRegisterType<AsemanMapObject>("Toolkit.Core", 1, 0, "MapObject");
    qmlRegisterType<AsemanListObject>("Toolkit.Core", 1, 0, "ListObject");
    qmlRegisterType<AsemanQuickObject>("Toolkit.Core", 1, 0, "AsemanObject");
    qmlRegisterType<AsemanSettings>("Toolkit.Core", 1, 0, "Settings");
    qmlRegisterType<AsemanApplicationItem>("Toolkit.Core", 1,0, "AsemanApplicationBase");
    qmlRegisterType<AsemanTranslationManager>("Toolkit.Core", 1, 0, "TranslationManager");
    qmlRegisterType<AsemanQuickListModel>("Toolkit.Core", 1, 0, "ToolkitListModel");
    qmlRegisterType<AsemanQrCreator>("Toolkit.Core", 1, 0, "QrCreator");
    qmlRegisterType<AsemanKeyHandler>("Toolkit.Core", 1, 0, "KeyHandler");

    qmlRegisterType<AsemanStickerItem>("Toolkit.Core", 1, 0, "StickerItem");

#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewMobile.qml"), "Toolkit.Core", 1, 0, "TScrollView");
#elif defined(Q_OS_MACOS)
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "Toolkit.Core", 1, 0, "TScrollView");
#else
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktop.qml"), "Toolkit.Core", 1, 0, "TScrollView");
#endif
#else
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "Toolkit.Core", 1, 0, "TScrollView");
#else
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktop.qml"), "Toolkit.Core", 1, 0, "TScrollView");
#endif
#endif


#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    qmlRegisterType(QUrl("qrc:/components/private/qt5/ZXingCamera.qml"), "Toolkit.Core", 1, 0, "ZXingCamera");
    qmlRegisterType(QUrl("qrc:/components/private/qt5/OpacityMask.qml"), "Toolkit.Core", 1, 0, "OpacityMask");
    qmlRegisterType(QUrl("qrc:/components/private/qt5/FastBlur.qml"), "Toolkit.Core", 1, 0, "FastBlur");
#else
    qmlRegisterType(QUrl("qrc:/components/private/qt6/ZXingCamera.qml"), "Toolkit.Core", 1, 0, "ZXingCamera");
    qmlRegisterType(QUrl("qrc:/components/private/qt6/OpacityMask.qml"), "Toolkit.Core", 1, 0, "OpacityMask");
    qmlRegisterType(QUrl("qrc:/components/private/qt6/FastBlur.qml"), "Toolkit.Core", 1, 0, "FastBlur");
#endif

    qmlRegisterType<QmlWidgetMenu>("Toolkit.Core", 1, 0, "QmlWidgetMenu");
    qmlRegisterType<QmlWidgetMenuItem>("Toolkit.Core", 1, 0, "QmlWidgetMenuItem");

    qmlRegisterSingletonType<AsemanQuickView>("Toolkit.Core", 1, 0, "View", [](QQmlEngine *engine, QJSEngine *){ return new AsemanQuickView(engine); });
    qmlRegisterSingletonInstance<AsemanDevicesItem>("Toolkit.Core", 1, 0, "Devices", new AsemanDevicesItem);
    qmlRegisterSingletonInstance<AsemanToolsItem>("Toolkit.Core", 1, 0, "Tools", new AsemanToolsItem);
    qmlRegisterSingletonInstance<MaterialIcons>("Toolkit.Core", 1, 0, "MaterialIcons", new MaterialIcons);
    qmlRegisterSingletonInstance<AsemanToolsItem>("Toolkit.Core", 1, 0, "Tools", new AsemanToolsItem);
    qmlRegisterSingletonInstance<AsemanBackHandler>("Toolkit.Core", 1, 0, "BackHandler", new AsemanBackHandler);
    qmlRegisterSingletonType<AsemanApplicationSingleton>("Toolkit.Core", 1, 0, "AsemanApp", [](QQmlEngine *engine, QJSEngine *){ return new AsemanApplicationSingleton(engine); });
#ifdef Q_OS_ANDROID
    qmlRegisterSingletonInstance<AsemanJavaLayer>("Toolkit.Core", 1, 0, "JavaLayer", new AsemanJavaLayer);
#endif
}

void TonQtQuick::registerViewport()
{
    qmlRegisterType<AsemanAbstractViewportType>("Toolkit.Viewport", 1, 0, "AbstractViewportTypeCore");
    qmlRegisterType<AsemanViewport>("Toolkit.Viewport", 1, 0, "ViewportCore");
    qmlRegisterType<AsemanViewportItem>("Toolkit.Viewport", 1, 0, "ViewportItem");
    qmlRegisterType<AsemanViewportController>("Toolkit.Viewport", 1, 0, "ViewportControllerCore");
    qmlRegisterType<AsemanViewportControllerRoute>("Toolkit.Viewport", 1, 0, "ViewportControllerRoute");
    qmlRegisterUncreatableType<AsemanViewportType>("Toolkit.Viewport", 1, 0, "ViewportType", "");
}

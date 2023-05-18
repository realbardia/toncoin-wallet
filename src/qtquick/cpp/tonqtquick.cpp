#include "tonqtquick.h"

#include "toolkit/viewport/tontoolkitviewport.h"
#include "toolkit/viewport/tontoolkitabstractviewporttype.h"
#include "toolkit/viewport/tontoolkitviewportcontroller.h"

#include "toolkit/core/tontoolkitmapobject.h"
#include "toolkit/core/tontoolkitquickobject.h"
#include "toolkit/core/tontoolkitsettings.h"
#include "toolkit/core/tontoolkitapplicationitem.h"
#include "toolkit/core/tontoolkittranslationmanager.h"
#include "toolkit/core/tontoolkitdevicesitem.h"
#include "toolkit/core/tontoolkittoolsitem.h"
#include "toolkit/core/tontoolkitbackhandler.h"
#include "toolkit/core/tontoolkitquicklistmodel.h"
#include "toolkit/core/tontoolkitapplicationsingleton.h"
#include "toolkit/core/tontoolkitquickview.h"
#include "toolkit/core/tontoolkitstickeritem.h"
#include "toolkit/core/qmlwidgetmenu.h"
#include "toolkit/core/tontoolkitlistobject.h"
#include "toolkit/core/materialicons.h"
#include "toolkit/core/tontoolkitqrcreator.h"
#include "toolkit/core/tontoolkitkeyhandler.h"

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
    qmlRegisterSingletonInstance("Wallet.Core", 1,0, "TonQmlGlobal", new TonQmlGlobal);

    qmlRegisterType<TonConnectService>("Wallet.TonConnect", 1, 0, "TonConnectService");
    qmlRegisterType<TonConnect>("Wallet.TonConnect", 1, 0, "TonConnect");

    qmlRegisterType<TonToolkitMapObject>("Toolkit.Core", 1, 0, "MapObject");
    qmlRegisterType<TonToolkitListObject>("Toolkit.Core", 1, 0, "ListObject");
    qmlRegisterType<TonToolkitQuickObject>("Toolkit.Core", 1, 0, "TonToolkitObject");
    qmlRegisterType<TonToolkitSettings>("Toolkit.Core", 1, 0, "Settings");
    qmlRegisterType<TonToolkitApplicationItem>("Toolkit.Core", 1,0, "TonToolkitApplicationBase");
    qmlRegisterType<TonToolkitTranslationManager>("Toolkit.Core", 1, 0, "TranslationManager");
    qmlRegisterType<TonToolkitQuickListModel>("Toolkit.Core", 1, 0, "ToolkitListModel");
    qmlRegisterType<TonToolkitQrCreator>("Toolkit.Core", 1, 0, "QrCreator");
    qmlRegisterType<TonToolkitKeyHandler>("Toolkit.Core", 1, 0, "KeyHandler");

    qmlRegisterType<TonToolkitStickerItem>("Toolkit.Core", 1, 0, "StickerItem");

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

    qmlRegisterSingletonType<TonToolkitQuickView>("Toolkit.Core", 1, 0, "View", [](QQmlEngine *engine, QJSEngine *){ return new TonToolkitQuickView(engine); });
    qmlRegisterSingletonInstance<TonToolkitDevicesItem>("Toolkit.Core", 1, 0, "Devices", new TonToolkitDevicesItem);
    qmlRegisterSingletonInstance<TonToolkitToolsItem>("Toolkit.Core", 1, 0, "Tools", new TonToolkitToolsItem);
    qmlRegisterSingletonInstance<MaterialIcons>("Toolkit.Core", 1, 0, "MaterialIcons", new MaterialIcons);
    qmlRegisterSingletonInstance<TonToolkitToolsItem>("Toolkit.Core", 1, 0, "Tools", new TonToolkitToolsItem);
    qmlRegisterSingletonInstance<TonToolkitBackHandler>("Toolkit.Core", 1, 0, "BackHandler", new TonToolkitBackHandler);
    qmlRegisterSingletonType<TonToolkitApplicationSingleton>("Toolkit.Core", 1, 0, "TonToolkitApp", [](QQmlEngine *engine, QJSEngine *){ return new TonToolkitApplicationSingleton(engine); });
#ifdef Q_OS_ANDROID
    qmlRegisterSingletonInstance<TonToolkitJavaLayer>("Toolkit.Core", 1, 0, "JavaLayer", new TonToolkitJavaLayer);
#endif
}

void TonQtQuick::registerViewport()
{
    qmlRegisterType<TonToolkitAbstractViewportType>("Toolkit.Viewport", 1, 0, "AbstractViewportTypeCore");
    qmlRegisterType<TonToolkitViewport>("Toolkit.Viewport", 1, 0, "ViewportCore");
    qmlRegisterType<TonToolkitViewportItem>("Toolkit.Viewport", 1, 0, "ViewportItem");
    qmlRegisterType<TonToolkitViewportController>("Toolkit.Viewport", 1, 0, "ViewportControllerCore");
    qmlRegisterType<TonToolkitViewportControllerRoute>("Toolkit.Viewport", 1, 0, "ViewportControllerRoute");
    qmlRegisterUncreatableType<TonToolkitViewportType>("Toolkit.Viewport", 1, 0, "ViewportType", "");
}

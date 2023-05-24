#if defined(QT_WIDGETS_LIB)
#include <QApplication>
#else
#include <QGuiApplication>
#endif
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFileInfo>
#include <QTimer>
#include <QSharedPointer>

#include <iostream>

#ifdef QZXING_AVAILABLE
#include "QZXing.h"
#endif

#include "thirdparty/tricks-app/checks.h"
#include "qtquick/cpp/toolkit/core/asemanapplicationitem.h"
#include "qtquick/cpp/tonqtquick.h"

#ifdef Q_OS_MACX
#include "macappdelegate.h"
#endif
#ifdef Q_OS_IOS
#include "iosappdelegate.h"
#endif

int main(int argc, char *argv[])
{
    qputenv("QT_ANDROID_ENABLE_WORKAROUND_TO_DISABLE_PREDICTIVE_TEXT", "1");
    qputenv("QT_LOGGING_RULES", "qt.qml.connections=false");

#if !defined(Q_OS_LINUX) || defined(Q_OS_ANDROID)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
#ifdef Q_OS_ANDROID
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);
#endif
#endif

#if defined(QT_WIDGETS_LIB)
    QApplication app(argc, argv);
#else
    QGuiApplication app(argc, argv);
#endif
    app.setApplicationName("Tonium");
    app.setWindowIcon(QIcon(":/ton/common/icons/icon.png"));
    app.setApplicationVersion(VERSION_STR);
    if (app.arguments().contains("--help"))
    {
        std::cout << app.applicationName().toStdString() << " " << app.applicationVersion().toStdString() << std::endl << std::endl;

        const auto fileName = QFileInfo(app.applicationFilePath()).fileName().toStdString();
        std::cout << "To transfer using deeplink just run below command:" << std::endl;
        std::cout << fileName << " ton://transfer/SOME_ADDRESS\n" << std::endl;

        std::cout << "To connect using Ton Connect:" << std::endl;
        std::cout << fileName << " ton://connect?blahblah\n" << std::endl;
        return 0;
    }

#if defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)
    if (!app.arguments().contains("--no-check-desktop-installation"))
        Checks::checkLinuxDesktopIcon();
#endif
#if defined(Q_OS_WIN)
    Checks::checkWindowsDeeplink();
    if (app.arguments().contains("--install-deeplinks"))
        return 0;
#endif

#if defined(Q_OS_MACX)
    MacAppDelegate macApp;
    Q_UNUSED(macApp)
#endif
#ifdef Q_OS_IOS
    IOSAppDelegate iosApp;
    Q_UNUSED(iosApp)
#endif

    AsemanApplicationItem::setApplicationId( QStringLiteral("8c37fdef-2156-458e-ae82-6c7aad1078b3") );
    if (AsemanApplicationItem::isRunning())
    {
        for (const auto &arg: app.arguments().mid(1))
            if (arg.left(1) != "-")
            {
                AsemanApplicationItem::sendMessage(arg);
                return 0;
            }

        qDebug() << "is running";
        return 0;
    }

    TonQtQuick::registerToolkit();
    TonQtQuick::registerViewport();

#if defined(QT_WIDGETS_LIB)
    if (app.arguments().contains(QStringLiteral("--widgets")))
    {
        qDebug() << "Under construction!";
        return 0;
    }
    else
#endif
    {
        QQmlApplicationEngine engine;

        engine.rootContext()->setContextProperty("testMode", qEnvironmentVariable("TON_TEST_MODE") == QStringLiteral("1"));
        engine.rootContext()->setContextProperty("linkToOpen", QString());
        for (const auto &arg: app.arguments().mid(1))
            if (arg.left(1) != "-")
            {
                engine.rootContext()->setContextProperty("linkToOpen", arg);
                break;
            }

#ifdef QZXING_AVAILABLE
        QZXing::registerQMLTypes();
        QZXing::registerQMLImageProvider(engine);
        engine.rootContext()->setContextProperty("qzxing", true);
#else
        engine.rootContext()->setContextProperty("qzxing", false);
#endif

#ifdef TOUCH_ID_SECURE_KEY
        engine.rootContext()->setContextProperty("touchIdSecureKey", TOUCH_ID_SECURE_KEY);
#else
        engine.rootContext()->setContextProperty("touchIdSecureKey", QString());
#endif

        const QUrl url(QStringLiteral("qrc:/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
            &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
        engine.load(url);

        return app.exec();
    }
}

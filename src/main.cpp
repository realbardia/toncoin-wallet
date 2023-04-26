#include <QApplication>
#include <QIcon>
#include <QQmlApplicationEngine>

#include "qtquick/cpp/tgstickeritem.h"
#include "qtquick/cpp/qmlwidgetmenu.h"
#include "qtquick/cpp/qmlwidgetmenuitem.h"

int main(int argc, char *argv[])
{
    qputenv("QT_ANDROID_ENABLE_WORKAROUND_TO_DISABLE_PREDICTIVE_TEXT", "1");
    qputenv("QT_LOGGING_RULES", "qt.qml.connections=false");

    qmlRegisterType<TON::QML::TgStickerItem>("TonToolkit", 1, 0, "TgStickerItem");

#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewMobile.qml"), "TonToolkit.private", 1, 0, "TScrollView");
#elif defined(Q_OS_MACOS)
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "TonToolkit.private", 1, 0, "TScrollView");
#else
    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktopClassic.qml"), "TonToolkit.private", 1, 0, "TScrollView");
//    qmlRegisterType(QUrl("qrc:/components/private/TScrollViewDesktop.qml"), "TonToolkit.private", 1, 0, "TScrollView");
#endif

    qmlRegisterType<QmlWidgetMenu>("TonToolkit.private", 1, 0, "QmlWidgetMenu");
    qmlRegisterType<QmlWidgetMenuItem>("TonToolkit.private", 1, 0, "QmlWidgetMenuItem");


#if !defined(Q_OS_LINUX) || defined(Q_OS_ANDROID)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
#ifdef Q_OS_ANDROID
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Ceil);
#endif
#endif

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/ton/common/icons/icon.png"));

    if (app.arguments().contains(QStringLiteral("--widgets")))
    {
        qDebug() << "Under construction!";
        return 0;
    }
    else
    {
        QQmlApplicationEngine engine;
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

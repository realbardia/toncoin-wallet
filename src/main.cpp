#include <QApplication>
#include <QIcon>
#include <QQmlApplicationEngine>

#include "qtquick/cpp/tonqtquick.h"
#include "core/wallet/tonwallet.h"

int main(int argc, char *argv[])
{
    TON::Wallet::TonWallet t;
    t.init("/home/bardia/Desktop/test", [&t](bool stt, const TON::Wallet::TonWallet::Error &err){
        qDebug() << stt << err.message;
//        t.createNewKey([](const QString &pkey, const TON::Wallet::TonWallet::Error &err){
//            qDebug() << pkey;
//        });

        for (const auto &k: t.keys())
        {
            t.exportKey(k, [](const QStringList &words, const TON::Wallet::TonWallet::Error &err){
                qDebug() << words;
            });
            t.getAddress(k, [k](const QString &words, const TON::Wallet::TonWallet::Error &err){
                qDebug() << k << words;
            });
        }
    });

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

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/ton/common/icons/icon.png"));

    TonQtQuick::registerToolkit();
    TonQtQuick::registerViewport();

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

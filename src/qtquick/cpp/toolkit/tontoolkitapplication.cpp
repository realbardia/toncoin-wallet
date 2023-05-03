#include "tontoolkitapplication.h"
#include "tontoolkitdevices.h"
#include "tontoolkittools.h"
#ifdef Q_OS_ANDROID
#include "tontoolkitjavalayer.h"
#endif

#include <QDir>
#include <QFont>
#include <QPalette>
#include <QSettings>
#include <QThread>
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <QStandardPaths>
#include <QPointer>

#ifdef QT_GUI_LIB
#define READ_DEFINITION(FUNCTION, DEFAULT_VALUE) \
    switch(tontoolkit_app_singleton->p->appType) { \
    case GuiApplication: \
        return static_cast<QGuiApplication*>(QCoreApplication::instance())->FUNCTION(); \
        break; \
    default: \
        return DEFAULT_VALUE; \
        break; \
    }
#else
#define READ_DEFINITION(FUNCTION, DEFAULT_VALUE) \
    return DEFAULT_VALUE;
#endif

#ifdef QT_GUI_LIB
#define SET_DIFINITION(FUNCTION, VALUE) \
    switch(tontoolkit_app_singleton->p->appType) { \
    case GuiApplication: \
        static_cast<QGuiApplication*>(QCoreApplication::instance())->FUNCTION(VALUE); \
        break; \
    }
#else
#define SET_DIFINITION(FUNCTION, VALUE)
    Q_UNUSED(VALUE)
#endif

#ifdef Q_OS_ANDROID
#include <QtAndroid>
#endif

#ifdef QT_GUI_LIB
#include <QGuiApplication>
#endif
#ifdef QT_CORE_LIB
#include <QCoreApplication>
#endif

static QSettings *app_global_settings = 0;
static TonToolkitApplication *tontoolkit_app_singleton = 0;
static QSet<TonToolkitApplication*> tontoolkit_app_objects;
static QString *tontoolkit_app_home_path = 0;
static QString *tontoolkit_app_log_path = 0;
static QString *tontoolkit_app_tmp_path = 0;

#if defined(Q_OS_MAC) && defined(Q_PROCESSOR_X86_32)
#include <objc/objc.h>
#include <objc/message.h>

bool dockClickHandler(id self,SEL _cmd,...)
{
    Q_UNUSED(self)
    Q_UNUSED(_cmd)
    if(tontoolkit_app_singleton) tontoolkit_app_singleton->clickedOnDock();
    return true;
}
#endif

class TonToolkitApplicationPrivate
{
public:
    QUrl windowIcon;
    QTimer *clickOnDock_timer;
    QFont globalFont;
    int appType;
    QCoreApplication *app;
    bool app_owner;
    QString appAbout;
};

TonToolkitApplication::TonToolkitApplication() :
    QObject()
{
    p = new TonToolkitApplicationPrivate;
    p->app = QCoreApplication::instance();
    p->appType = NoneApplication;
    p->app_owner = false;

#ifdef QT_GUI_LIB
    if( qobject_cast<QGuiApplication*>(p->app) )
    {
        p->appType = GuiApplication;
    }
    else
#endif
#ifdef QT_CORE_LIB
    if( qobject_cast<QCoreApplication*>(p->app) )
        p->appType = CoreApplication;
#endif

    tontoolkit_app_objects.insert(this);
    if(!tontoolkit_app_singleton)
        tontoolkit_app_singleton = this;

    p->app->installEventFilter(this);
    init();
}

TonToolkitApplication::TonToolkitApplication(int &argc, char **argv, ApplicationType appType) :
    QObject()
{
    if(!tontoolkit_app_singleton)
        tontoolkit_app_singleton = this;

    p = new TonToolkitApplicationPrivate;
    p->appType = appType;
    p->app_owner = true;

    switch(p->appType)
    {
#ifdef QT_CORE_LIB
    case CoreApplication:
        p->app = new QCoreApplication(argc, argv);
        break;
#endif
#ifdef QT_GUI_LIB
    case GuiApplication:
        p->app = new QGuiApplication(argc, argv);
        break;
#endif
    default:
        p->app = 0;
        break;
    }

    tontoolkit_app_objects.insert(this);
    if(p->app)
        p->app->installEventFilter(this);

    init();
}

void TonToolkitApplication::init()
{
#ifndef FORCE_TONTOOLKIT_DENSITY
    if(!qgetenv("TONTOOLKIT_SCALE_FACTOR").isNull())
        TonToolkitDevices::setFlag(TonToolkitDevices::TonToolkitScaleFactorEnable);
    else
    if(!qgetenv("QT_SCALE_FACTOR").isNull())
        TonToolkitDevices::setFlag(TonToolkitDevices::DisableDensities);
#endif
#ifdef Q_OS_WIN
    else
    if(QGuiApplication::testAttribute(Qt::AA_EnableHighDpiScaling))
        TonToolkitDevices::setFlag(TonToolkitDevices::DisableDensities);
#endif

    switch(p->appType)
    {
#ifdef QT_GUI_LIB
    case GuiApplication:
        connect(static_cast<QGuiApplication*>(p->app), &QGuiApplication::lastWindowClosed, this, &TonToolkitApplication::lastWindowClosed);
        connect(static_cast<QGuiApplication*>(p->app), &QGuiApplication::applicationStateChanged, this, &TonToolkitApplication::applicationStateChanged);
        p->globalFont = static_cast<QGuiApplication*>(p->app)->font();
#endif
#ifdef QT_CORE_LIB
    case CoreApplication:
        connect(p->app, &QCoreApplication::organizationNameChanged, this, &TonToolkitApplication::organizationNameChanged);
        connect(p->app, &QCoreApplication::organizationDomainChanged, this, &TonToolkitApplication::organizationDomainChanged);
        connect(p->app, &QCoreApplication::applicationNameChanged, this, &TonToolkitApplication::applicationNameChanged);
        connect(p->app, &QCoreApplication::applicationVersionChanged, this, &TonToolkitApplication::applicationVersionChanged);
        break;
#endif

    default:
        p->app = 0;
        break;
    }

    p->clickOnDock_timer = new QTimer(this);
    p->clickOnDock_timer->setSingleShot(true);
    p->clickOnDock_timer->setInterval(500);

#if defined(Q_OS_MAC) && defined(Q_PROCESSOR_X86_32)
#ifndef Q_OS_IOS
    objc_object* cls = objc_getClass("NSApplication");
    SEL sharedApplication = sel_registerName("sharedApplication");
    objc_object* appInst = objc_msgSend(cls,sharedApplication);

    if(appInst != NULL)
    {
        objc_object* delegate = objc_msgSend(appInst, sel_registerName("delegate"));
        objc_object* delClass = objc_msgSend(delegate,  sel_registerName("class"));
        const char* tst = class_getName(delClass->isa);
        bool test = class_addMethod((objc_class*)delClass, sel_registerName("applicationShouldHandleReopen:hasVisibleWindows:"), (IMP)dockClickHandler,"B@:");

        Q_UNUSED(tst)
        if (!test)
        {
            // failed to register handler...
        }
    }
#endif
#endif
}

QString TonToolkitApplication::homePath()
{
    if(tontoolkit_app_home_path)
        return *tontoolkit_app_home_path;

    tontoolkit_app_home_path = new QString();

    QString oldPath;
#ifdef Q_OS_WIN
    oldPath = QDir::homePath() + "/AppData/Local/" + QCoreApplication::applicationName();
#else
    oldPath = QDir::homePath() + "/.config/" + QCoreApplication::applicationName();
#endif

    QStringList paths = QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation);
    if(paths.isEmpty())
        paths << oldPath;

    if( oldPath.count() && QFileInfo::exists(oldPath) )
        *tontoolkit_app_home_path = oldPath;
    else
        *tontoolkit_app_home_path = paths.first();

    QDir().mkpath(*tontoolkit_app_home_path);
    return *tontoolkit_app_home_path;
}

void TonToolkitApplication::setHomePath(const QString &path)
{
    homePath();
    *tontoolkit_app_home_path = path;

    if(tontoolkit_app_singleton)
    {
        Q_EMIT tontoolkit_app_singleton->homePathChanged();
        Q_EMIT tontoolkit_app_singleton->logPathChanged();
        Q_EMIT tontoolkit_app_singleton->confsPathChanged();
        Q_EMIT tontoolkit_app_singleton->backupsPathChanged();
    }
}

QString TonToolkitApplication::startPath()
{
#ifdef Q_OS_ANDROID
    return QStringLiteral("/sdcard/");
#else
#ifdef Q_OS_IOS
    return homePath();
#else
    return QDir::homePath();
#endif
#endif
}

QString TonToolkitApplication::appPath()
{
    return QCoreApplication::applicationDirPath();
}

QString TonToolkitApplication::appFilePath()
{
    return QCoreApplication::applicationFilePath();
}

QString TonToolkitApplication::logPath()
{
    if(!tontoolkit_app_log_path)
    {
        tontoolkit_app_log_path = new QString();
        *tontoolkit_app_log_path = homePath() + "/log";
        QDir().mkpath(*tontoolkit_app_log_path);
    }

    return *tontoolkit_app_log_path;
}

void TonToolkitApplication::setLogPath(const QString &path)
{
    if( logPath() == path )
        return;

    *tontoolkit_app_log_path = path;
    if(tontoolkit_app_singleton)
        Q_EMIT tontoolkit_app_singleton->logPathChanged();
}

QString TonToolkitApplication::confsPath()
{
    return homePath() + "/config.ini";
}

QString TonToolkitApplication::tempPath()
{
    if(!tontoolkit_app_tmp_path)
    {
        tontoolkit_app_tmp_path = new QString();
#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
        *tontoolkit_app_tmp_path = homePath() + "/tmp/";
#else
        *tontoolkit_app_tmp_path = QDir::tempPath();
#endif
        QDir().mkpath(*tontoolkit_app_tmp_path);
    }

    return *tontoolkit_app_tmp_path;
}

QString TonToolkitApplication::backupsPath()
{
#ifdef Q_OS_ANDROID
    return "/sdcard/" + QCoreApplication::organizationDomain() + "/" + QCoreApplication::applicationName() + "/backups";
#else
#ifdef Q_OS_IOS
    return homePath() + "/backups/";
#else
    return homePath() + "/backups";
#endif
#endif
}

QString TonToolkitApplication::cameraPath()
{
#ifdef Q_OS_ANDROID
    return "/sdcard/DCIM";
#else
#ifdef Q_OS_IOS
    return QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation).first() + "/camera/";
#else
    return QDir::homePath() + "/Pictures/Camera";
#endif
#endif
}

QString TonToolkitApplication::applicationDirPath()
{
    return QCoreApplication::applicationDirPath();
}

QString TonToolkitApplication::applicationFilePath()
{
    return QCoreApplication::applicationFilePath();
}

qint64 TonToolkitApplication::applicationPid()
{
    return QCoreApplication::applicationPid();
}

void TonToolkitApplication::setOrganizationDomain(const QString &orgDomain)
{
    QCoreApplication::setOrganizationDomain(orgDomain);
}

QString TonToolkitApplication::organizationDomain()
{
    return QCoreApplication::organizationDomain();
}

void TonToolkitApplication::setOrganizationName(const QString &orgName)
{
    QCoreApplication::setOrganizationName(orgName);
}

QString TonToolkitApplication::organizationName()
{
    return QCoreApplication::organizationName();
}

void TonToolkitApplication::setApplicationName(const QString &application)
{
    QCoreApplication::setApplicationName(application);
}

QString TonToolkitApplication::applicationName()
{
    return QCoreApplication::applicationName();
}

void TonToolkitApplication::setApplicationVersion(const QString &version)
{
    QCoreApplication::setApplicationVersion(version);
}

QString TonToolkitApplication::applicationVersion()
{
    return QCoreApplication::applicationVersion();
}

void TonToolkitApplication::setApplicationDisplayName(const QString &name)
{
    SET_DIFINITION(setApplicationDisplayName, name)
}

QString TonToolkitApplication::applicationDisplayName()
{
    READ_DEFINITION(applicationDisplayName, QString())
}

void TonToolkitApplication::setApplicationAbout(const QString &desc)
{
    if(!tontoolkit_app_singleton)
        return;
    if( tontoolkit_app_singleton->p->appAbout == desc )
        return;

    tontoolkit_app_singleton->p->appAbout = desc;
    Q_EMIT tontoolkit_app_singleton->applicationAboutChanged();
}

QString TonToolkitApplication::applicationAbout()
{
    if(tontoolkit_app_singleton)
        return tr(tontoolkit_app_singleton->p->appAbout.toUtf8());
    else
        return QString();
}

void TonToolkitApplication::setQpaNoTextHandles(bool stt)
{
    bool currentResult = qpaNoTextHandles();
    if(currentResult == stt)
        return;

    if(stt)
    {
        qputenv("QT_ANDROID_ENABLE_WORKAROUND_TO_DISABLE_PREDICTIVE_TEXT", "1");
        qputenv("QT_QPA_NO_TEXT_HANDLES", "1");
    }
    else
    {
        qunsetenv("QT_QPA_NO_TEXT_HANDLES");
        qunsetenv("QT_ANDROID_ENABLE_WORKAROUND_TO_DISABLE_PREDICTIVE_TEXT");
    }

    Q_EMIT tontoolkit_app_singleton->qpaNoTextHandlesChanged();
}

bool TonToolkitApplication::qpaNoTextHandles()
{
    return qgetenv("QT_QPA_NO_TEXT_HANDLES") == "1";
}

QString TonToolkitApplication::platformName()
{
    READ_DEFINITION(platformName, QString())
}

QStringList TonToolkitApplication::arguments()
{
    return QCoreApplication::arguments();
}

void TonToolkitApplication::setQuitOnLastWindowClosed(bool quit)
{
    SET_DIFINITION(setQuitOnLastWindowClosed, quit)
}

bool TonToolkitApplication::quitOnLastWindowClosed()
{
    READ_DEFINITION(quitOnLastWindowClosed, false)
}

QClipboard *TonToolkitApplication::clipboard()
{
    READ_DEFINITION(clipboard, 0)
}

void TonToolkitApplication::setWindowIcon(const QUrl &icon)
{
    if(p->windowIcon == icon)
        return;

    p->windowIcon = icon;
    QString file = icon.toString();
    if(file.left(6) == QStringLiteral("qrc://"))
        file = file.replace(0, 6, QStringLiteral(":/"));

#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
    SET_DIFINITION(setWindowIcon, QIcon(file))
#else
    Q_UNUSED(icon)
#endif
    Q_EMIT windowIconChanged();
}

QUrl TonToolkitApplication::windowIcon() const
{
    return p->windowIcon;
}

int TonToolkitApplication::appType()
{
    return tontoolkit_app_singleton->p->appType;
}

bool TonToolkitApplication::isDebug()
{
#ifdef QT_DEBUG
    return true;
#else
    return false;
#endif
}

TonToolkitApplication *TonToolkitApplication::instance()
{
    return tontoolkit_app_singleton;
}

QCoreApplication *TonToolkitApplication::qapp()
{
    return QCoreApplication::instance();
}

void TonToolkitApplication::setGlobalFont(const QFont &font)
{
    if(p->globalFont == font)
        return;

    p->globalFont = font;
    Q_EMIT globalFontChanged();
}

QFont TonToolkitApplication::globalFont() const
{
    return p->globalFont;
}

QFont TonToolkitApplication::font()
{
    READ_DEFINITION(font, QFont())
}

void TonToolkitApplication::setFont(const QFont &f)
{
    SET_DIFINITION(setFont, f);
}

#ifdef QT_GUI_LIB
QPalette TonToolkitApplication::palette()
{
    READ_DEFINITION(palette, QPalette())
}

void TonToolkitApplication::setPalette(const QPalette &pal)
{
    SET_DIFINITION(setPalette, pal);
}

int TonToolkitApplication::applicationState()
{
    READ_DEFINITION(applicationState, Qt::ApplicationActive)
}
#endif

QSettings *TonToolkitApplication::settings()
{
    if( !app_global_settings )
    {
        QDir().mkpath(TonToolkitApplication::homePath());
        app_global_settings = new QSettings( TonToolkitApplication::homePath() + "/config.ini", QSettings::IniFormat );
    }

    return app_global_settings;
}

void TonToolkitApplication::refreshTranslations()
{
    Q_EMIT languageUpdated();
}

void TonToolkitApplication::back()
{
    Q_EMIT backRequest();
}

int TonToolkitApplication::exec()
{
    p->clickOnDock_timer->stop();
    p->clickOnDock_timer->start();

    return p->app->exec();
}

void TonToolkitApplication::exit(int retcode)
{
    tontoolkit_app_singleton->p->app->exit(retcode);
}

void TonToolkitApplication::sleep(quint64 ms)
{
    QThread::msleep(ms);
}

void TonToolkitApplication::setSetting(const QString &key, const QVariant &value)
{
    settings()->setValue(key, value);
}

QVariant TonToolkitApplication::readSetting(const QString &key, const QVariant &defaultValue)
{
    return settings()->value(key, defaultValue);
}

bool TonToolkitApplication::eventFilter(QObject *o, QEvent *e)
{
    if(o == p->app)
    {
#ifdef Q_OS_MAC
        switch(e->type()) {
        case QEvent::ApplicationActivate:
            if(p->clickOnDock_timer->isActive())
            {
                p->clickOnDock_timer->stop();
                p->clickOnDock_timer->start();
            }
            else
                Q_EMIT clickedOnDock();
            break;

        default:
            break;
        }
#endif
    }

    return QObject::eventFilter(o,e);
}

TonToolkitApplication::~TonToolkitApplication()
{
    tontoolkit_app_objects.remove(this);
    if(tontoolkit_app_singleton == this)
        tontoolkit_app_singleton = 0;

    if(p->app && p->app_owner)
        delete p->app;

    delete p;
}

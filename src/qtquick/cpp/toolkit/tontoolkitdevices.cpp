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

#define LINUX_DEFAULT_DPI 96
#define WINDOWS_DEFAULT_DPI 96
#define UTOUCH_DEFAULT_DPI 76

#define TABLET_RATIO 1.28
#define FONT_RATIO 1.28

#include "tontoolkitdevices.h"
#include "tontoolkitapplication.h"

#ifdef Q_OS_ANDROID
#include "tontoolkitjavalayer.h"
#endif
#ifdef Q_OS_IOS
#include "tontoolkitobjectiveclayer.h"
#endif

#ifdef Q_OS_MACX
#include <IOKit/IOKitLib.h>
#include "tontoolkitmacmanager.h"
#endif

#include <QTimerEvent>
#include <QGuiApplication>
#include <QMimeType>
#include <QMimeDatabase>
#include <QUrl>
#include <QDesktopServices>
#include <QDir>
#include <QImageWriter>
#include <QFileInfo>
#include <QFile>
#include <QClipboard>
#include <QtCore/qmath.h>
#include <QScreen>
#include <QDateTime>
#include <QDebug>
#include <QMimeData>
#include <QProcess>
#include <QGuiApplication>
#include <QCryptographicHash>
#include <QTimer>
#include <QVariantMap>
#include <QSysInfo>
#include <QJsonDocument>
#include <QThread>
#include <QStandardPaths>
#include <QInputMethodQueryEvent>

#ifdef TONTOOLKIT_MULTIMEDIA
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
#include <QBuffer>
#include <QCameraInfo>
#endif
#endif

class TonToolkitDevicesPrivate
{
public:
    int hide_keyboard_timer;
    bool keyboard_stt;

    QMimeDatabase mime_db;

#ifdef Q_OS_ANDROID
    TonToolkitJavaLayer *java_layer;
    qint32 androidKeyboardHeight;
#endif
#ifdef Q_OS_IOS
    TonToolkitObjectiveCLayer *objc_layer;
#endif

    bool transparentStatusBar;
    bool transparentNavigationBar;

    static QHash<int, bool> flags;
    static qreal fontScale;
    static QSet<TonToolkitDevices*> devicesObjs;
};

QHash<int, bool> TonToolkitDevicesPrivate::flags;
qreal TonToolkitDevicesPrivate::fontScale = 1;
QSet<TonToolkitDevices*> TonToolkitDevicesPrivate::devicesObjs;

TonToolkitDevices::TonToolkitDevices(QObject *parent) :
    QObject(parent)
{
    p = new TonToolkitDevicesPrivate;
    p->hide_keyboard_timer = 0;
    p->keyboard_stt = false;
    p->transparentStatusBar = false;
    p->transparentNavigationBar = false;

    refreshTransparentStatusBar();
    refreshTransparentNavigationBar();

#ifdef Q_OS_ANDROID
    p->androidKeyboardHeight = 0;
    p->java_layer = TonToolkitJavaLayer::instance();

    connect( p->java_layer, &TonToolkitJavaLayer::incomingShare, this, &TonToolkitDevices::incoming_share, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::incomingImage, this, &TonToolkitDevices::incomingImage, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::selectImageResult, this, &TonToolkitDevices::selectImageResult, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::activityPaused, this, &TonToolkitDevices::activity_paused, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::activityResumed, this, &TonToolkitDevices::activity_resumed, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::keyboardVisiblityChanged, this, [this](qint32 height){
        height = height/deviceDensity();
        if(p->androidKeyboardHeight == height)
            return;

        p->androidKeyboardHeight = height;
        Q_EMIT geometryChanged();
    });
#endif
#ifdef Q_OS_IOS
   p->objc_layer = new TonToolkitObjectiveCLayer(this);
   connect(p->objc_layer, &TonToolkitObjectiveCLayer::keyboardHeightChanged, this, &TonToolkitDevices::keyboard_changed);

   QTimer *intervalChecks = new QTimer(this);
   intervalChecks->setInterval(1000);
   intervalChecks->setSingleShot(false);
   intervalChecks->connect(intervalChecks, &QTimer::timeout, this, [this](){
       static qreal lastStatusBarHeight = TonToolkitObjectiveCLayer::statusBarHeight();
       qreal newStatusBarHeight = TonToolkitObjectiveCLayer::statusBarHeight();
       if (lastStatusBarHeight == newStatusBarHeight)
           return;

       lastStatusBarHeight = newStatusBarHeight;
       Q_EMIT statusBarHeightChanged();
   });
   intervalChecks->start();
#endif

    connect( QGuiApplication::inputMethod(), &QInputMethod::visibleChanged, this, &TonToolkitDevices::keyboard_changed);
    connect( static_cast<QGuiApplication*>(QCoreApplication::instance())->clipboard(), &QClipboard::dataChanged, this, &TonToolkitDevices::clipboardChanged);

    QScreen *scr = screen();
    if( scr )
        connect( scr, &QScreen::geometryChanged, this, &TonToolkitDevices::geometryChanged);

    TonToolkitDevicesPrivate::devicesObjs.insert(this);
}

bool TonToolkitDevices::isMobile()
{
    return isTouchDevice() && !isTablet();
}

bool TonToolkitDevices::isTablet()
{
#ifdef Q_OS_ANDROID
    return isTouchDevice() && TonToolkitJavaLayer::instance()->isTablet();
#else
    return isTouchDevice() && lcdPhysicalSize() >= 6;
#endif
}

bool TonToolkitDevices::isLargeTablet()
{
#ifdef Q_OS_ANDROID
    return isTablet() && TonToolkitJavaLayer::instance()->getSizeName() == 3;
#else
    return isTouchDevice() && lcdPhysicalSize() >= 9;
#endif
}

bool TonToolkitDevices::isTouchDevice()
{
    return isAndroid() || isIOS() || isWindowsPhone() || isUbuntuTouch();
}

bool TonToolkitDevices::isDesktop()
{
    return !isTouchDevice();
}

bool TonToolkitDevices::isMacX()
{
#ifdef Q_OS_MACX
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isWindows()
{
#ifdef Q_OS_WIN
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isLinux()
{
#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isAndroid()
{
#ifdef Q_OS_ANDROID
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isIOS()
{
#ifdef Q_OS_IOS
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isUbuntuTouch()
{
#ifdef Q_OS_UBUNTUTOUCH
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isWindowsPhone()
{
#ifdef Q_OS_WINPHONE
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isWindows8()
{
#ifdef Q_OS_WIN
    return QSysInfo::windowsVersion() == QSysInfo::WV_WINDOWS8 ||
           QSysInfo::windowsVersion() == QSysInfo::WV_WINDOWS8_1;
#else
    return false;
#endif
}

bool TonToolkitDevices::isWebAssembly()
{
#ifdef Q_OS_WASM
    return true;
#else
    return false;
#endif
}

bool TonToolkitDevices::isQt6()
{
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    return true;
#else
    return false;
#endif
}

QScreen *TonToolkitDevices::screen()
{
    const QList<QScreen*> & screens = QGuiApplication::screens();
    if( screens.isEmpty() )
        return 0;

    return screens.first();
}

QObject *TonToolkitDevices::screenObj() const
{
    return screen();
}

qreal TonToolkitDevices::lcdPhysicalSize()
{
    qreal w = lcdPhysicalWidth();
    qreal h = lcdPhysicalHeight();

    return qSqrt( h*h + w*w );
}

qreal TonToolkitDevices::lcdPhysicalWidth()
{
    if( QGuiApplication::screens().isEmpty() )
        return 0;

    return (qreal)screenSize().width()/lcdDpiX();
}

qreal TonToolkitDevices::lcdPhysicalHeight()
{
    if( QGuiApplication::screens().isEmpty() )
        return 0;

    return (qreal)screenSize().height()/lcdDpiY();
}

qreal TonToolkitDevices::lcdDpiX()
{
#ifdef Q_OS_ANDROID
    return TonToolkitJavaLayer::instance()->densityDpi();
#else
    if( QGuiApplication::screens().isEmpty() )
        return 0;

    QScreen *scr = QGuiApplication::screens().first();
    return scr->physicalDotsPerInchX();
#endif
}

qreal TonToolkitDevices::lcdDpiY()
{
#ifdef Q_OS_ANDROID
    return TonToolkitJavaLayer::instance()->densityDpi();
#else
    if( QGuiApplication::screens().isEmpty() )
        return 0;

    QScreen *scr = QGuiApplication::screens().first();
    return scr->physicalDotsPerInchY();
#endif
}

QSize TonToolkitDevices::screenSize()
{
#ifdef Q_OS_ANDROID
    return QSize(TonToolkitJavaLayer::instance()->screenSizeWidth(),
                 TonToolkitJavaLayer::instance()->screenSizeHeight());
#else
    if( QGuiApplication::screens().isEmpty() )
        return QSize();

    QScreen *scr = QGuiApplication::screens().first();
    return scr->size();
#endif
}

qreal TonToolkitDevices::keyboardHeight() const
{
#ifdef Q_OS_ANDROID
    return p->androidKeyboardHeight*density();
#else
#ifdef Q_OS_UBUNTUTOUCH
    return screenSize().height()*0.5;
#else
#ifdef DESKTOP_DEVICE
    return 0;
#else
#ifdef Q_OS_IOS
    return p->objc_layer->keyboardHeight();
#else
    const QSize & scr_size = screenSize();
    bool portrait = scr_size.width()<scr_size.height();
    if( portrait )
    {
        if( isMobile() )
            return screenSize().height()*0.6;
        else
            return screenSize().height()*0.4;
    }
    else
    {
        if( isMobile() )
            return screenSize().height()*0.7;
        else
            return screenSize().height()*0.5;
    }
#endif
#endif
#endif
#endif
}

QString TonToolkitDevices::deviceName()
{
    if(isDesktop())
        return QSysInfo::prettyProductName() + " " + QSysInfo::currentCpuArchitecture();
#ifdef Q_OS_ANDROID
    else
        return TonToolkitJavaLayer::instance()->deviceName();
#else
    else
        return QStringLiteral("mobile");
#endif
}

QString TonToolkitDevices::deviceId()
{
#if defined(Q_OS_ANDROID)
    return TonToolkitJavaLayer::instance()->deviceId();
#elif defined(Q_OS_IOS)
    return TonToolkitObjectiveCLayer::deviceId();
#elif defined(Q_OS_MACX)
    io_registry_entry_t ioRegistryRoot = IORegistryEntryFromPath(kIOMasterPortDefault, "IOService:/");
    CFStringRef uuidCf = (CFStringRef) IORegistryEntryCreateCFProperty(ioRegistryRoot, CFSTR(kIOPlatformUUIDKey), kCFAllocatorDefault, 0);
    IOObjectRelease(ioRegistryRoot);
    char buf[128];
    CFStringGetCString(uuidCf, buf, sizeof(buf), kCFStringEncodingMacRoman);
    CFRelease(uuidCf);
    return QString::fromUtf8( QByteArray(buf, sizeof(buf)) );
#elif defined(Q_OS_LINUX) || defined(Q_OS_WIN32)
    static QString cg_hostId;
    if(!cg_hostId.isEmpty())
        return cg_hostId;

    QProcess prc;
#ifdef Q_OS_WIN
    prc.start(QStringLiteral("wmic"), {QStringLiteral("csproduct"), QStringLiteral("get"), QStringLiteral("UUID")});
#else
    prc.start(QStringLiteral("hostid"));
#endif
    prc.waitForStarted();
    prc.waitForReadyRead();
    prc.waitForFinished();

    cg_hostId = QString::fromUtf8(prc.readAll());
    cg_hostId = cg_hostId.remove(QStringLiteral("UUID")).trimmed();
    if(cg_hostId.isEmpty())
        cg_hostId = QStringLiteral("noid");
    return cg_hostId;
#else
    return QStringLiteral("noid");
#endif
}

QString TonToolkitDevices::deviceShortId()
{
    QString hash = QString::fromUtf8(QCryptographicHash::hash(deviceId().toUtf8(), QCryptographicHash::Md5).toHex());
    return hash.remove(QStringLiteral("-")).left(8);
}

QString TonToolkitDevices::platformVersion()
{
    return QSysInfo::productVersion();
}

QString TonToolkitDevices::platformType()
{
    return QSysInfo::productType();
}

QString TonToolkitDevices::platformName()
{
    return QSysInfo::prettyProductName();
}

QString TonToolkitDevices::platformKernel()
{
    return QSysInfo::kernelType();
}

QString TonToolkitDevices::platformKernelVersion()
{
    return QSysInfo::kernelVersion();
}

QString TonToolkitDevices::platformCpuArchitecture()
{
    return QSysInfo::currentCpuArchitecture();
}

QString TonToolkitDevices::qtVersion()
{
    return QStringLiteral(QT_VERSION_STR);
}

qreal TonToolkitDevices::qtMajorVersion()
{
    static qreal result = 0;
    if(result != 0.0)
        return result;

    const QString &qv = qtVersion();
    int idx0 = qv.indexOf(QStringLiteral("."));
    int idx1 = qv.indexOf(QStringLiteral("."), idx0+1);
    result = qv.left(idx1).toDouble();
    return result;
}

bool TonToolkitDevices::transparentStatusBar()
{
    return p->transparentStatusBar;
}

void TonToolkitDevices::setTransparentStatusBar(bool stt)
{
    if(p->transparentStatusBar == stt)
        return;

#ifdef Q_OS_ANDROID
    TonToolkitJavaLayer::instance()->setTransparentStatusBar(stt);
#else
    Q_UNUSED(stt)
#endif
    p->transparentStatusBar = stt;
    Q_EMIT transparentStatusBarChanged();

    QTimer::singleShot(100, this, [this](){
        refreshTransparentStatusBar();
        Q_EMIT statusBarHeightChanged();
    });
}

bool TonToolkitDevices::transparentNavigationBar()
{
    return p->transparentNavigationBar;
}

void TonToolkitDevices::setTransparentNavigationBar(bool stt)
{
    if(p->transparentNavigationBar == stt)
        return;

#ifdef Q_OS_ANDROID
    TonToolkitJavaLayer::instance()->setTransparentNavigationBar(stt);
#else
    Q_UNUSED(stt)
#endif
    p->transparentNavigationBar = stt;
    Q_EMIT transparentNavigationBarChanged();

    QTimer::singleShot(100, this, [this](){
        refreshTransparentNavigationBar();
        Q_EMIT navigationBarHeightChanged();
    });
}

qreal TonToolkitDevices::standardTitleBarHeight() const
{
    static qreal res = 0;
    if(res)
        return res;

    if(isDesktop())
        res = 54*density();
    else
    if(isMobile())
        res = 56*density();
    else
        res = 54*density();

    return res;
}

qreal TonToolkitDevices::statusBarHeight()
{
    if(!transparentStatusBar())
        return 0;

#ifdef Q_OS_IOS
    return TonToolkitObjectiveCLayer::statusBarHeight();
#else
    static qreal result = 0;
    if(result == 0.0)
    {
#ifdef Q_OS_ANDROID
        result = density()*(TonToolkitJavaLayer::instance()->statusBarHeight()/deviceDensity());
#else
        result = 20*density();
#endif
    }
    return result;
#endif
}

qreal TonToolkitDevices::navigationBarHeight()
{
    if(!transparentNavigationBar())
        return 0;

    static qreal result = 0;
    if(result == 0.0)
    {
#ifdef Q_OS_ANDROID
        result = density()*(TonToolkitJavaLayer::instance()->navigationBarHeight()/deviceDensity());
#else
#ifdef Q_OS_IOS
        result = TonToolkitObjectiveCLayer::navigationBarHeight();
#else
        result = 44*density();
#endif
#endif
    }
    return result;
}

void TonToolkitDevices::setFlag(int flag, bool state)
{
    TonToolkitDevicesPrivate::flags[flag] = state;
}

bool TonToolkitDevices::flag(int flag)
{
    return TonToolkitDevicesPrivate::flags.value(flag);
}

int TonToolkitDevices::densityDpi()
{
#ifdef Q_OS_ANDROID
    return TonToolkitJavaLayer::instance()->densityDpi();
#else
    return lcdDpiX();
#endif
}

qreal TonToolkitDevices::density()
{
    const bool disabled = TonToolkitDevices::flag(DisableDensities);
    if(TonToolkitDevices::flag(TonToolkitScaleFactorEnable))
        return qgetenv("TONTOOLKIT_SCALE_FACTOR").toDouble();
    else
    if(disabled)
        return 1;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)) && !defined(Q_OS_IOS) && !defined (Q_OS_MAC)
    else
    if(QGuiApplication::testAttribute(Qt::AA_EnableHighDpiScaling))
        return deviceDensity()/screen()->devicePixelRatio();
#endif
    else
        return deviceDensity();
}

qreal TonToolkitDevices::deviceDensity()
{
#ifdef Q_OS_ANDROID
    qreal ratio = isTablet()? TABLET_RATIO : 1;
//    if( isLargeTablet() )
//        ratio = 1.6;

    return TonToolkitJavaLayer::instance()->density()*ratio;
#else
#ifdef Q_OS_IOS
    qreal ratio = isTablet()? TABLET_RATIO : 1;
    return ratio*densityDpi()/180.0;
#else
#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
#ifdef Q_OS_UBUNTUTOUCH
    return screen()->logicalDotsPerInch()/UTOUCH_DEFAULT_DPI;
#else
    return screen()->logicalDotsPerInch()/LINUX_DEFAULT_DPI;
#endif
#else
#ifdef Q_OS_WIN32
    return 0.95*screen()->logicalDotsPerInch()/WINDOWS_DEFAULT_DPI;
#else
    return 1;
#endif
#endif
#endif
#endif
}

qreal TonToolkitDevices::fontDensity()
{
#ifdef Q_OS_ANDROID
    const qreal ratio = TonToolkitDevicesPrivate::fontScale*(isMobile()? FONT_RATIO*1.25 : FONT_RATIO*1.35);
    if(TonToolkitDevices::flag(TonToolkitScaleFactorEnable))
        return density()*ratio;
    else
    if(TonToolkitDevices::flag(DisableDensities))
        return ratio;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    else
    if(QGuiApplication::testAttribute(Qt::AA_EnableHighDpiScaling))
        return TonToolkitJavaLayer::instance()->density()*ratio/screen()->devicePixelRatio();
#endif
    else
        return TonToolkitJavaLayer::instance()->density()*ratio;
#else
#ifdef Q_OS_IOS
    return TonToolkitDevicesPrivate::fontScale * 1.4;
#else
#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
#ifdef Q_OS_UBUNTUTOUCH
    qreal ratio = TonToolkitDevicesPrivate::fontScale * 1.3;
    return ratio*density();
#else
    qreal ratio = TonToolkitDevicesPrivate::fontScale * 1.4;
    return ratio*density();
#endif
#else
#ifdef Q_OS_WIN32
    qreal ratio = TonToolkitDevicesPrivate::fontScale * 1.4;
    return ratio*density();
#else
    qreal ratio = TonToolkitDevicesPrivate::fontScale * 1.3;
    return ratio*density();
#endif
#endif
#endif
#endif
}

void TonToolkitDevices::setFontScale(qreal fontScale)
{
    if(TonToolkitDevicesPrivate::fontScale == fontScale)
        return;

    TonToolkitDevicesPrivate::fontScale = fontScale;
    for(TonToolkitDevices *dvc: TonToolkitDevicesPrivate::devicesObjs)
    {
        Q_EMIT dvc->fontScaleChanged();
        Q_EMIT dvc->fontDensityChanged();
    }
}

qreal TonToolkitDevices::fontScale()
{
    return TonToolkitDevicesPrivate::fontScale;
}

bool TonToolkitDevices::cameraIsAvailable() const
{
#ifdef TONTOOLKIT_MULTIMEDIA
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
    return QCameraInfo::availableCameras().count();
#else
    return false;
#endif
#else
    return false;
#endif
}

QString TonToolkitDevices::localFilesPrePath()
{
#ifdef Q_OS_WIN
    return QStringLiteral("file:///");
#else
    return QStringLiteral("file://");
#endif
}

QString TonToolkitDevices::clipboard() const
{
    return QGuiApplication::clipboard()->text();
}

bool TonToolkitDevices::keyboard() const
{
    return p->keyboard_stt;
}

QList<QUrl> TonToolkitDevices::clipboardUrl() const
{
    return QGuiApplication::clipboard()->mimeData()->urls();
}

void TonToolkitDevices::setClipboardUrl(const QList<QUrl> &urls)
{
    QString data = QStringLiteral("copy");

    for( const QUrl &url: urls )
        data += QStringLiteral("\nfile://") + url.toLocalFile();

    QMimeData *mime = new QMimeData();
    mime->setUrls(urls);
    mime->setData( QStringLiteral("x-special/gnome-copied-files"), data.toUtf8() );

    QGuiApplication::clipboard()->setMimeData(mime);
}

QString TonToolkitDevices::cameraLocation()
{
    return TonToolkitApplication::cameraPath();
}

QString TonToolkitDevices::picturesLocation()
{
    QStringList probs;
    probs = QStandardPaths::standardLocations( QStandardPaths::PicturesLocation );

#ifdef Q_OS_ANDROID
    probs << "/sdcard/Pictures";
#else
#ifdef Q_OS_IOS
    probs << QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation).first() + "/Pictures";
#else
    probs << QDir::homePath() + "/Pictures";
#endif
#endif

    for(const QString & prob: probs)
        if( QFile::exists(prob) )
            return prob;

    return probs.last();
}

QString TonToolkitDevices::musicsLocation()
{
    QStringList probs;
    probs = QStandardPaths::standardLocations( QStandardPaths::MusicLocation );

#ifdef Q_OS_ANDROID
    probs << "/sdcard/Music";
#else
#ifdef Q_OS_IOS
    probs << QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation).first() + "/Music";
#else
    probs << QDir::homePath() + "/Music";
#endif
#endif

    for(const QString & prob: probs)
        if( QFile::exists(prob) )
            return prob;

    return probs.last();
}

QString TonToolkitDevices::documentsLocation()
{
    QStringList probs;
    probs = QStandardPaths::standardLocations( QStandardPaths::DocumentsLocation );

#ifdef Q_OS_ANDROID
    probs << "/sdcard/documents";
    probs << "/sdcard/Documents";
#else
#ifdef Q_OS_IOS
    probs << QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation).first() + "/Documents";
#else
    probs << QDir::homePath() + "/Documents";
#endif
#endif

    for(const QString & prob: probs)
        if( QFile::exists(prob) )
            return prob;

    return probs.last();
}

QString TonToolkitDevices::downloadsLocation()
{
    QStringList probs;
    probs = QStandardPaths::standardLocations( QStandardPaths::DownloadLocation );

#ifdef Q_OS_ANDROID
    probs << "/sdcard/downloads";
    probs << "/sdcard/Downloads";
#else
#ifdef Q_OS_IOS
    probs << QStandardPaths::standardLocations(QStandardPaths::QStandardPaths::AppDataLocation).first() + "/Downloads";
#else
    probs << QDir::homePath() + "/Downloads";
#endif
#endif

    for(const QString & prob: probs)
        if( QFile::exists(prob) )
            return prob;

    return probs.last();
}

QString TonToolkitDevices::resourcePath()
{
#ifdef Q_OS_ANDROID
    return "assets:";
#else
#ifndef Q_OS_MAC
    QString result = QCoreApplication::applicationDirPath() + "/../share/" + QCoreApplication::applicationName().toLower();
    QFileInfo file(result);
    if(file.exists() && file.isDir())
        return file.filePath();
    else
        return QCoreApplication::applicationDirPath() + "/";
#else
#ifdef Q_OS_IOS
    return QCoreApplication::applicationDirPath() + "/";
#else
    return QCoreApplication::applicationDirPath() + "/../Resources/";
#endif
#endif
#endif
}

QString TonToolkitDevices::resourcePathQml()
{
#ifdef Q_OS_ANDROID
    return resourcePath();
#else
    return localFilesPrePath() + resourcePath();
#endif
}

QString TonToolkitDevices::libsPath()
{
#ifndef Q_OS_MAC
    QString result = QCoreApplication::applicationDirPath() + "/../lib/" + QCoreApplication::applicationName().toLower();
    QFileInfo file(result);
    if(file.exists() && file.isDir())
        return file.filePath();
    else
        return QCoreApplication::applicationDirPath() + "/";
#else
#ifdef Q_OS_IOS
    return QCoreApplication::applicationDirPath() + "/";
#else
    return QCoreApplication::applicationDirPath() + "/../Resources/";
#endif
#endif
}

QVariantMap TonToolkitDevices::deviceDetails()
{
    QVariantMap map;
    map[QStringLiteral("device.name")] = TonToolkitDevices::deviceName();
    map[QStringLiteral("device.id")] = TonToolkitDevices::deviceId();
    map[QStringLiteral("device.shortId")] = TonToolkitDevices::deviceShortId();

    map[QStringLiteral("platform.version")] = TonToolkitDevices::platformVersion();
    map[QStringLiteral("platform.type")] = TonToolkitDevices::platformType();
    map[QStringLiteral("platform.name")] = TonToolkitDevices::platformName();
    map[QStringLiteral("platform.kernel")] = TonToolkitDevices::platformKernel();
    map[QStringLiteral("platform.kernelVersion")] = TonToolkitDevices::platformKernelVersion();
    map[QStringLiteral("platform.cpuArchitecture")] = TonToolkitDevices::platformCpuArchitecture();

    map[QStringLiteral("qt.version")] = TonToolkitDevices::qtVersion();
    map[QStringLiteral("qt.majorVersion")] = TonToolkitDevices::qtMajorVersion();

    map[QStringLiteral("screen.size")] = TonToolkitDevices::screenSize();
    map[QStringLiteral("screen.keyboardHeight")] = TonToolkitDevices::keyboardHeight();
    map[QStringLiteral("screen.density")] = TonToolkitDevices::density();
    map[QStringLiteral("screen.dpi")] = TonToolkitDevices::densityDpi();
    map[QStringLiteral("screen.deviceDensity")] = TonToolkitDevices::deviceDensity();
    map[QStringLiteral("screen.fontDensity")] = TonToolkitDevices::fontDensity();

    map[QStringLiteral("lcd.physicalSize")] = TonToolkitDevices::lcdPhysicalSize();
    map[QStringLiteral("lcd.physicalWidth")] = TonToolkitDevices::lcdPhysicalWidth();
    map[QStringLiteral("lcd.physicalHeight")] = TonToolkitDevices::lcdPhysicalHeight();
    map[QStringLiteral("lcd.dpiX")] = TonToolkitDevices::lcdDpiX();
    map[QStringLiteral("lcd.dpiY")] = TonToolkitDevices::lcdDpiY();

    map[QStringLiteral("os.mobile")] = TonToolkitDevices::isMobile();
    map[QStringLiteral("os.tablet")] = TonToolkitDevices::isTablet();
    map[QStringLiteral("os.largeTablet")] = TonToolkitDevices::isLargeTablet();
    map[QStringLiteral("os.touchDevice")] = TonToolkitDevices::isTouchDevice();
    map[QStringLiteral("os.desktop")] = TonToolkitDevices::isDesktop();
    map[QStringLiteral("os.macX")] = TonToolkitDevices::isMacX();
    map[QStringLiteral("os.windows")] = TonToolkitDevices::isWindows();
    map[QStringLiteral("os.linux")] = TonToolkitDevices::isLinux();
    map[QStringLiteral("os.android")] = TonToolkitDevices::isAndroid();
    map[QStringLiteral("os.iOS")] = TonToolkitDevices::isIOS();
    map[QStringLiteral("os.ubuntuTouch")] = TonToolkitDevices::isUbuntuTouch();
    map[QStringLiteral("os.windowsPhone")] = TonToolkitDevices::isWindowsPhone();
    map[QStringLiteral("os.windows8")] = TonToolkitDevices::isWindows8();

    map[QStringLiteral("ui.transparentStatusBar")] = TonToolkitDevices::transparentStatusBar();
    map[QStringLiteral("ui.transparentNavigationBar")] = TonToolkitDevices::transparentNavigationBar();
    map[QStringLiteral("ui.standardTitleBarHeight")] = TonToolkitDevices::standardTitleBarHeight();
    map[QStringLiteral("ui.statusBarHeight")] = TonToolkitDevices::statusBarHeight();
    map[QStringLiteral("ui.navigationBarHeight")] = TonToolkitDevices::navigationBarHeight();

    map[QStringLiteral("path.cameraLocation")] = TonToolkitDevices::cameraLocation();
    map[QStringLiteral("path.picturesLocation")] = TonToolkitDevices::picturesLocation();
    map[QStringLiteral("path.musicsLocation")] = TonToolkitDevices::musicsLocation();
    map[QStringLiteral("path.documentsLocation")] = TonToolkitDevices::downloadsLocation();
    map[QStringLiteral("path.resourcePath")] = TonToolkitDevices::resourcePath();
    map[QStringLiteral("path.resourcePathQml")] = TonToolkitDevices::resourcePathQml();
    map[QStringLiteral("path.libsPath")] = TonToolkitDevices::libsPath();

    map[QStringLiteral("app.path.homePath")] = TonToolkitApplication::homePath();
    map[QStringLiteral("app.path.startPath")] = TonToolkitApplication::startPath();
    map[QStringLiteral("app.path.appPath")] = TonToolkitApplication::appPath();
    map[QStringLiteral("app.path.appFilePath")] = TonToolkitApplication::appFilePath();
    map[QStringLiteral("app.path.confsPath")] = TonToolkitApplication::confsPath();
    map[QStringLiteral("app.path.tempPath")] = TonToolkitApplication::tempPath();
    map[QStringLiteral("app.path.backupsPath")] = TonToolkitApplication::backupsPath();
    map[QStringLiteral("app.path.cameraPath")] = TonToolkitApplication::cameraPath();
    map[QStringLiteral("app.path.dirPath")] = TonToolkitApplication::applicationDirPath();
    map[QStringLiteral("app.path.filePath")] = TonToolkitApplication::applicationFilePath();
    map[QStringLiteral("app.path.logPath")] = TonToolkitApplication::logPath();

    map[QStringLiteral("app.pid")] = TonToolkitApplication::applicationPid();
    map[QStringLiteral("app.organizationDomain")] = TonToolkitApplication::organizationDomain();
    map[QStringLiteral("app.organizationName")] = TonToolkitApplication::organizationName();
    map[QStringLiteral("app.name")] = TonToolkitApplication::applicationName();
    map[QStringLiteral("app.version")] = TonToolkitApplication::applicationVersion();
    map[QStringLiteral("app.displayName")] = TonToolkitApplication::applicationDisplayName();
    map[QStringLiteral("app.platformName")] = TonToolkitApplication::platformName();

    map[QStringLiteral("app.appType")] = TonToolkitApplication::appType();
    map[QStringLiteral("app.isDebug")] = TonToolkitApplication::isDebug();
    map[QStringLiteral("app.font")] = TonToolkitApplication::font();

    QMapIterator<QString, QVariant> i(map);
    while(i.hasNext())
    {
        i.next();
        if(i.key().left(5) != QStringLiteral("path.") && i.key().left(9) != QStringLiteral("app.path."))
            continue;

        QString path = i.value().toString();
        QFileInfo inf(path);

        map[i.key() + QStringLiteral(".exists")] = inf.exists();
        map[i.key() + QStringLiteral(".isDir")] = inf.isDir();
        map[i.key() + QStringLiteral(".isFile")] = inf.isFile();
        map[i.key() + QStringLiteral(".isWritable")] = inf.isWritable();
        map[i.key() + QStringLiteral(".isReadable")] = inf.isReadable();
        map[i.key() + QStringLiteral(".isExecutable")] = inf.isExecutable();
        map[i.key() + QStringLiteral(".isSymLink")] = inf.isSymLink();
    }

    return map;
}

QStringList TonToolkitDevices::getLastImages(qint32 offset, qint32 count)
{
#ifdef Q_OS_ANDROID
    return p->java_layer->getLastImages(offset, count).split(QStringLiteral("\n"), Qt::SkipEmptyParts);
#else
    return QStringList();
#endif
}

void TonToolkitDevices::setupImEventFilter(QObject *item)
{
    class ImFixer: public QObject {
    protected:
        bool eventFilter(QObject *obj, QEvent *event) override {
            if (event->type() == QEvent::InputMethodQuery) {
                QInputMethodQueryEvent *imEvt = static_cast<QInputMethodQueryEvent *>(event);
                if (imEvt->queries() == Qt::InputMethodQuery::ImCursorRectangle) {
                    imEvt->setValue(Qt::InputMethodQuery::ImCursorRectangle, QRectF());
                    return true;
                }
            }
            return QObject::eventFilter(obj, event);
        }
    };
    static thread_local ImFixer imf;
    item->installEventFilter(&imf);
}

void TonToolkitDevices::setupWindowColor(QColor color)
{
#ifdef Q_OS_MACX
    QTimer::singleShot(100, [color](){
        TonToolkitMacManager::removeTitlebarFromWindow(color.redF(), color.greenF(), color.blueF());
    });
#else
    Q_UNUSED(color)
#endif
}

void TonToolkitDevices::hideKeyboard()
{
    if( p->hide_keyboard_timer )
        killTimer(p->hide_keyboard_timer);

    p->hide_keyboard_timer = startTimer(250);
}

void TonToolkitDevices::showKeyboard()
{
    if( p->hide_keyboard_timer )
    {
        killTimer(p->hide_keyboard_timer);
        p->hide_keyboard_timer = 0;
    }

    QGuiApplication::inputMethod()->show();
    p->keyboard_stt = true;

    Q_EMIT keyboardChanged();
}

void TonToolkitDevices::share(const QString &subject, const QString &message)
{
#ifdef Q_OS_ANDROID
    p->java_layer->sharePaper( subject, message );
#else
#ifdef Q_OS_IOS
    TonToolkitObjectiveCLayer::sharePaper((subject.length()? subject + '\n' : QString()) + message);
#else
    QString adrs = QStringLiteral("mailto:%1?subject=%2&body=%3").arg(QString(),subject,message);
    QDesktopServices::openUrl( adrs );
#endif
#endif
}

bool TonToolkitDevices::openFile(const QString &address)
{
#ifdef Q_OS_ANDROID
    const QMimeType & t = p->mime_db.mimeTypeForFile(address);
    return p->java_layer->openFile( address, t.name() );
#else
    return QDesktopServices::openUrl( QUrl(address) );
#endif
}

bool TonToolkitDevices::shareFile(const QString &address)
{
#ifdef Q_OS_ANDROID
    const QMimeType & t = p->mime_db.mimeTypeForFile(address);
    return p->java_layer->shareFile( address, t.name() );
#else
    return QDesktopServices::openUrl( QUrl(address) );
#endif
}

bool TonToolkitDevices::saveToGallery(const QString &filePath)
{
#ifdef Q_OS_IOS
    TonToolkitObjectiveCLayer::saveToCameraRoll(filePath);
#else
    QString path = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + QStringLiteral("/") + QCoreApplication::applicationName();
    QDir().mkpath(path);

    QImageWriter writer(path + "/" + filePath.mid(filePath.lastIndexOf(QStringLiteral("/"))+1));
    writer.write(QImage(filePath));
#endif
    return true;
}

void TonToolkitDevices::callNumber(const QString &number)
{
    Q_UNUSED(number)
#ifdef Q_OS_ANDROID
    p->java_layer->callNumber(number);
#else
#endif
}

void TonToolkitDevices::setClipboard(const QString &text)
{
    QGuiApplication::clipboard()->setText( text );
}

QString TonToolkitDevices::startCameraPicture()
{
#ifdef Q_OS_ANDROID
    QString output = cameraLocation() + "/tontoolkit_" + QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch()) + ".jpg";
    if(!p->java_layer->startCamera(output))
        output.clear();

    return output;
#else
    return QString();
#endif
}

bool TonToolkitDevices::getOpenPictures()
{
#ifdef Q_OS_ANDROID
    return p->java_layer->getOpenPictures();
#else
    return false;
#endif
}

void TonToolkitDevices::triggerVibrateFeedback()
{
#ifdef Q_OS_IOS
    p->objc_layer->triggerVibrateFeedback();
#endif
}

QVariantList TonToolkitDevices::getContactList(std::function<void(const QVariantList &)> asyncCallback)
{
    QVariantList res;
#ifdef Q_OS_ANDROID
    if (asyncCallback)
    {
        class ContactThreaded: public QThread
        {
        protected:
            void run() {
                result = QJsonDocument::fromJson(TonToolkitJavaLayer::instance()->getContactList().toUtf8()).toVariant().toList();
            }

        public:
            ContactThreaded(QObject *parent = Q_NULLPTR): QThread(parent) {}
            virtual ~ContactThreaded() {}
            QVariantList result;
        };

        auto currentThread = QThread::currentThread();
        ContactThreaded *thread = new ContactThreaded;
        connect(thread, &ContactThreaded::finished, currentThread, [thread, asyncCallback](){
            asyncCallback(thread->result);
            thread->deleteLater();
        },  Qt::QueuedConnection);
        thread->start();

        return res;
    }
    else
        res = QJsonDocument::fromJson(TonToolkitJavaLayer::instance()->getContactList().toUtf8()).toVariant().toList();
#endif
#ifdef Q_OS_IOS
    if (asyncCallback)
        TonToolkitObjectiveCLayer::getContactList(asyncCallback);
    return res;
#endif

    if (asyncCallback)
        asyncCallback(res);

    return res;
}

void TonToolkitDevices::incoming_share(const QString &title, const QString &msg)
{
    Q_EMIT incomingShare(title,msg);
}

void TonToolkitDevices::activity_paused()
{
    Q_EMIT activityPaused();
}

void TonToolkitDevices::activity_resumed()
{
    Q_EMIT activityResumed();
}

void TonToolkitDevices::keyboard_changed()
{
    Q_EMIT keyboardChanged();
    Q_EMIT geometryChanged();
}

void TonToolkitDevices::timerEvent(QTimerEvent *e)
{
    if( e->timerId() == p->hide_keyboard_timer )
    {
        killTimer(p->hide_keyboard_timer);
        p->hide_keyboard_timer = 0;

        QGuiApplication::inputMethod()->hide();
        p->keyboard_stt = false;

        Q_EMIT keyboardChanged();
    }
}

void TonToolkitDevices::refreshTransparentStatusBar()
{
#ifdef Q_OS_ANDROID
    p->transparentStatusBar = TonToolkitJavaLayer::instance()->transparentStatusBar();
#else
#ifdef Q_OS_IOS
    p->transparentStatusBar = true;
#else
    p->transparentStatusBar = false;
#endif
#endif
}

void TonToolkitDevices::refreshTransparentNavigationBar()
{
#ifdef Q_OS_ANDROID
    p->transparentNavigationBar = TonToolkitJavaLayer::instance()->transparentNavigationBar();
#else
#ifdef Q_OS_IOS
    p->transparentNavigationBar = (TonToolkitObjectiveCLayer::navigationBarHeight() > 0.1);
#else
    p->transparentNavigationBar = false;
#endif
#endif
}

TonToolkitDevices::~TonToolkitDevices()
{
    TonToolkitDevicesPrivate::devicesObjs.remove(this);
    delete p;
}

#include "asemanjavalayer.h"

#include <QDebug>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QSet>
#include <QPair>
#include <QList>
#include <QDateTime>
#include <QFile>
#include <QCoreApplication>
#include <QTimer>
#include <QScreen>
#include <QGuiApplication>
#include <QPointer>
#include <QColor>

#include <jni.h>

static QSet<AsemanToniumJavaLayer*> java_layers_objects;
static QList< QPair<QString,QString> > java_layer_inc_share_buffer;
static QList< QString > java_layer_inc_image_buffer;
static QList< QString > java_layer_inc_deeplinks_buffer;

static bool asemantonium_jlayer_registerNativeMethods();
static bool asemantonium_jlayer_native_methods_registered = asemantonium_jlayer_registerNativeMethods();

class AsemanToniumJavaLayerPrivate
{
public:
    QAndroidJniObject object;
    QAndroidJniEnvironment env;
};

AsemanToniumJavaLayer::AsemanToniumJavaLayer() :
    QObject()
{
    p = new AsemanToniumJavaLayerPrivate;
    p->object = QAndroidJniObject("io/asemantonium/android/AsemanToniumJavaLayer");

#if defined(Q_OS_ANDROID) && defined(ASEMAN_STATIC_BUILD)
    QMetaObject::invokeMethod( this, "registerObject", Qt::QueuedConnection );
#else
    registerObject();
#endif

    QMetaObject::invokeMethod( this, "load_buffer", Qt::QueuedConnection );

    setImplemented(true);
}

void AsemanToniumJavaLayer::registerObject()
{
    java_layers_objects.insert(this);
}

AsemanToniumJavaLayer *AsemanToniumJavaLayer::instance()
{
    if(!asemantonium_jlayer_native_methods_registered)
        asemantonium_jlayer_registerNativeMethods();

    static QPointer<AsemanToniumJavaLayer> java_layer_instance;
    if( !java_layer_instance )
    {
        java_layer_instance = new AsemanToniumJavaLayer();
        if(QCoreApplication::instance())
            QObject::connect(QCoreApplication::instance(), &QCoreApplication::destroyed, java_layer_instance, &AsemanToniumJavaLayer::deleteLater);
    }

    return java_layer_instance;
}

bool AsemanToniumJavaLayer::sharePaper(const QString &title, const QString &msg)
{
    QAndroidJniObject jtitle = QAndroidJniObject::fromString(title.toUtf8());
    QAndroidJniObject jmsg = QAndroidJniObject::fromString(msg.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;Ljava/lang/String;)Z", jtitle.object<jstring>(), jmsg.object<jstring>() );
    return res;
}

bool AsemanToniumJavaLayer::shareFile(const QString &path, const QString &type)
{
    QAndroidJniObject jpath = QAndroidJniObject::fromString(path.toUtf8());
    QAndroidJniObject jtype = QAndroidJniObject::fromString(type.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;Ljava/lang/String;)Z", jpath.object<jstring>(), jtype.object<jstring>() );
    return res;
}

bool AsemanToniumJavaLayer::openFile(const QString &path, const QString &type)
{
    QAndroidJniObject jpath = QAndroidJniObject::fromString(path.toUtf8());
    QAndroidJniObject jtype = QAndroidJniObject::fromString(type.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;Ljava/lang/String;)Z", jpath.object<jstring>(), jtype.object<jstring>() );
    return res;
}

bool AsemanToniumJavaLayer::startCamera(const QString &output)
{
    QAndroidJniObject joutput = QAndroidJniObject::fromString(output.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;)Z", joutput.object<jstring>() );
    return res;
}

bool AsemanToniumJavaLayer::callNumber(const QString &number)
{
    QAndroidJniObject jnumber = QAndroidJniObject::fromString(number.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;)Z", jnumber.object<jstring>() );
    return res;
}

bool AsemanToniumJavaLayer::getOpenPictures()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z");
    return res;
}

bool AsemanToniumJavaLayer::startForeground(qint32 id, const QString &title, const QString &msg, const QString &iconPath, const QString &icon, const QString &channelId)
{
    jint jid = id;
    QAndroidJniObject jtitle = QAndroidJniObject::fromString(title);
    QAndroidJniObject jmsg = QAndroidJniObject::fromString(msg);
    QAndroidJniObject jicon = QAndroidJniObject::fromString(icon);
    QAndroidJniObject jiconPath = QAndroidJniObject::fromString(iconPath);
    QAndroidJniObject jchannelId = QAndroidJniObject::fromString(channelId);
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z",
                                                  jid, jtitle.object<jstring>(), jmsg.object<jstring>(),
                                                  jiconPath.object<jstring>(), jicon.object<jstring>(),
                                                  jchannelId.object<jstring>());
    return res;
}

bool AsemanToniumJavaLayer::stopForeground(bool removeNotification)
{
    jboolean jremoveNotification = removeNotification;
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Z)Z", jremoveNotification);
    return res;
}

bool AsemanToniumJavaLayer::startNotification(qint32 id, const QString &title, const QString &msg, const QString &iconPath, const QString &icon, const QString &channelId, bool sound, bool vibrate)
{
    jint jid = id;
    QAndroidJniObject jtitle = QAndroidJniObject::fromString(title);
    QAndroidJniObject jmsg = QAndroidJniObject::fromString(msg);
    QAndroidJniObject jicon = QAndroidJniObject::fromString(icon);
    QAndroidJniObject jiconPath = QAndroidJniObject::fromString(iconPath);
    QAndroidJniObject jchannelId = QAndroidJniObject::fromString(channelId);
    jboolean jsound = sound;
    jboolean jvibrate = vibrate;
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ZZ)Z",
                                                  jid, jtitle.object<jstring>(), jmsg.object<jstring>(),
                                                  jiconPath.object<jstring>(), jicon.object<jstring>(),
                                                  jchannelId.object<jstring>(), jsound, jvibrate);
    return res;
}

bool AsemanToniumJavaLayer::stopNotification(qint32 id)
{
    jint jid = id;
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(I)Z", jid);
    return res;
}

QString AsemanToniumJavaLayer::createNotificationChannel(const QString &channelId, const QString &channelName, int importance)
{
    QAndroidJniObject jchannelId = QAndroidJniObject::fromString(channelId);
    QAndroidJniObject jchannelName = QAndroidJniObject::fromString(channelName);
    jint jimportance = importance;
    QString res = p->object.callObjectMethod(__FUNCTION__, "(Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/String;",
                                             jchannelId.object<jstring>(), jchannelName.object<jstring>(), jimportance).toString();
    return res;
}

bool AsemanToniumJavaLayer::transparentStatusBar()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z");
    return res;
}

bool AsemanToniumJavaLayer::transparentNavigationBar()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z");
    return res;
}

bool AsemanToniumJavaLayer::startService()
{
    return startQtService();
}

bool AsemanToniumJavaLayer::stopService()
{
    return stopQtService();
}

bool AsemanToniumJavaLayer::killService(const QString &serviceName)
{
    QAndroidJniObject jserviceName = QAndroidJniObject::fromString(serviceName.toUtf8());
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "(Ljava/lang/String;)Z", jserviceName.object<jstring>());
    return res;
}

bool AsemanToniumJavaLayer::startQtService()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z" );
    return res;
}

bool AsemanToniumJavaLayer::stopQtService()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z" );
    return res;
}

int AsemanToniumJavaLayer::densityDpi()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

int AsemanToniumJavaLayer::screenSizeWidth()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

int AsemanToniumJavaLayer::screenSizeHeight()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

int AsemanToniumJavaLayer::getSizeName()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

int AsemanToniumJavaLayer::statusBarHeight()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

int AsemanToniumJavaLayer::navigationBarHeight()
{
    jint res = p->object.callMethod<jint>(__FUNCTION__, "()I" );
    return res;
}

bool AsemanToniumJavaLayer::isTablet()
{
    jboolean res = p->object.callMethod<jboolean>(__FUNCTION__, "()Z");
    return res;
}

qreal AsemanToniumJavaLayer::density()
{
    jfloat res = p->object.callMethod<jfloat>(__FUNCTION__, "()F" );
    return res;
}

QString AsemanToniumJavaLayer::packageName()
{
    QString res = p->object.callObjectMethod(__FUNCTION__, "()Ljava/lang/String;" ).toString();
    return res;
}

QString AsemanToniumJavaLayer::deviceName()
{
    QString res = p->object.callObjectMethod(__FUNCTION__, "()Ljava/lang/String;" ).toString();
    return res;
}

QString AsemanToniumJavaLayer::deviceId()
{
    QString res = p->object.callObjectMethod(__FUNCTION__, "()Ljava/lang/String;" ).toString();
    return res;
}

QRect AsemanToniumJavaLayer::keyboardRect()
{
    jint jheight = p->object.callMethod<jfloat>("menuHeight", "()I" );
    int menuheight = jheight;

    const QList<QScreen*> & screens = QGuiApplication::screens();
    if( screens.isEmpty() )
        return QRect();

    QScreen *screen = screens.first();
    QRect rect = screen->availableGeometry();
    QRect geom = screen->geometry();

    rect.moveTop(rect.top() + menuheight);
    geom.setTop(geom.top() + menuheight);

    QRect final;

    if (rect != geom)
    {
        int ftop, fleft, fwidth, fheight;

        geom.getRect(&fleft, &ftop, &fwidth, &fheight);

        if (rect.top() != ftop)
            fheight = rect.top();
        else if (rect.left() != fleft)
            fwidth = rect.left();
        else if (rect.height() != fheight)
            ftop = rect.height();
        else if (rect.width() != fwidth)
            fleft = rect.width();

        final = QRect(fleft, ftop, fwidth - fleft, fheight - ftop);
    }

    return final;
}

QString AsemanToniumJavaLayer::getLastImages(qint32 offset, qint32 count)
{
    jint joffset = offset;
    jint jcount = count;
    QString res = p->object.callObjectMethod(__FUNCTION__, "(II)Ljava/lang/String;", joffset, jcount).toString();
    return res;
}

QString AsemanToniumJavaLayer::getContactList()
{
    QString res = p->object.callObjectMethod(__FUNCTION__, "()Ljava/lang/String;").toString();
    return res;
}

void AsemanToniumJavaLayer::setKeepScreenOn(bool stt)
{
    jboolean jstt = stt;
    p->object.callMethod<jboolean>(__FUNCTION__, "(Z)V", jstt );
}

void AsemanToniumJavaLayer::reloadBuffer()
{
    load_buffer();
}

bool AsemanToniumJavaLayer::setTransparentNavigationBar(bool stt)
{
    jboolean jstt = stt;
    return p->object.callMethod<jboolean>(__FUNCTION__, "(Z)Z", jstt );
}

bool AsemanToniumJavaLayer::setTransparentStatusBar(bool stt)
{
    jboolean jstt = stt;
    return p->object.callMethod<jboolean>(__FUNCTION__, "(Z)Z", jstt );\
}

void AsemanToniumJavaLayer::load_buffer()
{
    while( !java_layer_inc_share_buffer.isEmpty() )
    {
        const QPair<QString,QString> & pair = java_layer_inc_share_buffer.takeFirst();
        Q_EMIT incomingShare( pair.first, pair.second );
    }
    while( !java_layer_inc_deeplinks_buffer.isEmpty() )
    {
        const auto & link = java_layer_inc_deeplinks_buffer.takeFirst();
        Q_EMIT deepLinkRecieved(link);
    }
}

void AsemanToniumJavaLayer::setImplemented(bool stt)
{
    jboolean jstt = stt;
    p->object.callMethod<jboolean>(__FUNCTION__, "(Z)Z", jstt );
}

AsemanToniumJavaLayer::~AsemanToniumJavaLayer()
{
    java_layers_objects.remove(this);
    delete p;
}

static void noteRecieved( JNIEnv *env, jobject obj ,jstring title, jstring msg )
{
    Q_UNUSED(obj)
    jboolean a;
    jboolean b;
    const char *t = env->GetStringUTFChars(title,&a);
    const char *m = env->GetStringUTFChars(msg,&b);

    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->incomingShare( QString(t), QString(m) );

    if( java_layers_objects.isEmpty() )
        java_layer_inc_share_buffer << QPair<QString,QString>( QString(t), QString(m) );
}

static void deepLinkRecieved( JNIEnv *env, jobject obj ,jstring link)
{
    Q_UNUSED(obj)
    jboolean a;
    const char *l = env->GetStringUTFChars(link,&a);

    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->deepLinkRecieved(QString(l));

    if( java_layers_objects.isEmpty() )
        java_layer_inc_deeplinks_buffer << QString(l);
}

static void imageRecieved( JNIEnv *env, jobject obj ,jstring jpath )
{
    Q_UNUSED(obj)
    jboolean a;
    const char *p = env->GetStringUTFChars(jpath,&a);

    QString path = QString("/sdcard/AsemanTonium/%1.jpeg").arg(QDateTime::currentDateTime().toMSecsSinceEpoch());
    QFile().rename(QString(p),path);

    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->incomingImage(path);

    if( java_layers_objects.isEmpty() )
        java_layer_inc_image_buffer << path;
}

static void selectImageResult( JNIEnv *env, jobject obj ,jstring path )
{
    Q_UNUSED(obj)
    jboolean a;
    const char *p = env->GetStringUTFChars(path,&a);

    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->selectImageResult( QString(p) );
}

static void activityPaused( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityPaused();
}

static void activityStopped( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityStopped();
}

static void activityResumed( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityResumed();
}

static void activityStarted( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityStarted();
}

static void activityRestarted( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityRestarted();
}

static void activityDestroyed( JNIEnv *env, jobject obj )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->activityDestroyed();
}

static void keyboardVisiblityChanged( JNIEnv *env, jobject obj, jint height )
{
    Q_UNUSED(env)
    Q_UNUSED(obj)
    for(AsemanToniumJavaLayer *sjl: java_layers_objects)
        Q_EMIT sjl->keyboardVisiblityChanged(height);
}

bool asemantonium_jlayer_registerNativeMethods() {
    if(asemantonium_jlayer_native_methods_registered)
        return true;

    JNINativeMethod methods[] {{"_sendNote", "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void *>(noteRecieved)},
                               {"_sendImage", "(Ljava/lang/String;)V", reinterpret_cast<void *>(imageRecieved)},
                               {"_sendDeepLink", "(Ljava/lang/String;)V", reinterpret_cast<void *>(deepLinkRecieved)},
                               {"_selectImageResult", "(Ljava/lang/String;)V", reinterpret_cast<void *>(selectImageResult)},
                               {"_activityPaused", "()V", reinterpret_cast<void *>(activityPaused)},
                               {"_activityStopped", "()V", reinterpret_cast<void *>(activityStopped)},
                               {"_activityResumed", "()V", reinterpret_cast<void *>(activityResumed)},
                               {"_activityStarted", "()V", reinterpret_cast<void *>(activityStarted)},
                               {"_activityRestarted", "()V", reinterpret_cast<void *>(activityRestarted)},
                               {"_activityDestroyed", "()V", reinterpret_cast<void *>(activityDestroyed)},
                               {"_keyboardVisiblityChanged", "(I)V", reinterpret_cast<void *>(keyboardVisiblityChanged)}};

    QAndroidJniObject javaClass("io/asemantonium/android/AsemanToniumJavaLayer");
    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());

    env->RegisterNatives(objectClass, methods, sizeof(methods) / sizeof(methods[0]));

    env->DeleteLocalRef(objectClass);
    return true;
}

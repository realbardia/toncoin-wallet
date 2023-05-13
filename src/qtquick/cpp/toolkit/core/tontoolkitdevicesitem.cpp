#include "tontoolkitdevicesitem.h"
#include "tontoolkitapplicationitem.h"
#include "tontoolkittools.h"

#include <QQmlEngine>
#include <QMimeDatabase>
#include <QTimer>
#include <QStandardPaths>
#if defined(QT_WIDGETS_LIB)
#include <QFileDialog>
#endif

#ifdef Q_OS_IOS
#include "private/quickios/qiimagepicker.h"
#include "private/quickios/quickios.h"
#endif

#ifdef Q_OS_ANDROID
#include "tontoolkitjavalayer.h"
#endif

class TonToolkitDevicesItemPrivate
{
public:
#ifdef Q_OS_ANDROID
    TonToolkitJavaLayer *java_layer;
#endif
};

TonToolkitDevicesItem::TonToolkitDevicesItem(QObject *parent) :
    TonToolkitDevices(parent)
{
    p = new TonToolkitDevicesItemPrivate;
#ifdef Q_OS_ANDROID
    p->java_layer = TonToolkitJavaLayer::instance();
    connect( p->java_layer, &TonToolkitJavaLayer::incomingImage, this, &TonToolkitDevicesItem::incoming_image, Qt::QueuedConnection );
    connect( p->java_layer, &TonToolkitJavaLayer::selectImageResult, this, &TonToolkitDevicesItem::select_image_result, Qt::QueuedConnection );
#endif
#ifdef Q_OS_IOS
    QuickIOS::registerTypes();
#endif
}

bool TonToolkitDevicesItem::getOpenPictures()
{
    QString path;

#if defined(Q_OS_ANDROID)
    p->java_layer->getOpenPictures();
    return true;
#elif defined(Q_OS_IOS)
    auto picker = new QIImagePicker(this);

    connect(picker, &QIImagePicker::referenceUrlChanged, this, [picker](){
        QString tempPath = TonToolkitApplication::tempPath() + '/' + QUuid::createUuid().toString(QUuid::WithoutBraces);
        if (picker->referenceUrl().toLower().contains(QStringLiteral("png")))
            tempPath += QStringLiteral(".png");
        else
            tempPath += QStringLiteral(".jpg");

        picker->save(tempPath);
    });
    connect(picker, &QIImagePicker::saved, this, [this, picker](QString url){
        url = TonToolkitTools::urlToLocalPath(url);
        Q_EMIT selectImageResult(url);
        picker->close();
        QTimer::singleShot(1000, picker, &QIImagePicker::deleteLater);
    });

    picker->show();
    return true;
#else
#if defined(QT_WIDGETS_LIB)
    path = QFileDialog::getOpenFileName(Q_NULLPTR, QStringLiteral(""), QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).last());
#elif defined(QT_WIDGETS_LIB)
    path = TonToolkitDesktopTools::getOpenFileName();
#endif

    if(path.isEmpty())
        return false;

    Q_EMIT selectImageResult(path);
    return true;
#endif
}

QVariantList TonToolkitDevicesItem::getContactList(QJSValue asyncCallback)
{
    return TonToolkitDevices::getContactList([this, asyncCallback](const QVariantList &res){
        if (!asyncCallback.isCallable())
            return;

        QQmlEngine *engine = qmlEngine(this);

        if(!engine)
            return;

        QJSValueList args = { engine->toScriptValue(res) };

        QJSValue callback = asyncCallback;
        callback.call(args);
    });
}

void TonToolkitDevicesItem::incoming_image(const QString &path)
{
    Q_EMIT incomingImage(path);
}

void TonToolkitDevicesItem::select_image_result(const QString &path)
{
    Q_EMIT selectImageResult(path);
}

TonToolkitDevicesItem::~TonToolkitDevicesItem()
{
    delete p;
}

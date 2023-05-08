#ifndef TONTOOLKITJAVALAYER_H
#define TONTOOLKITJAVALAYER_H

#include <QObject>

class TonToolkitJavaLayerPrivate;
class TonToolkitJavaLayer : public QObject
{
    Q_OBJECT
    Q_ENUMS(ImportanceTypes)

public:
    TonToolkitJavaLayer();
    virtual ~TonToolkitJavaLayer();

    enum ImportanceTypes {
        ImportanceDefault = 3,
        ImportanceHigh = 4,
        ImportanceLow = 2,
        ImportanceMax = 5,
        ImportanceMin = 1,
        ImportanceNone = 0,
    };

    static TonToolkitJavaLayer *instance();

    bool sharePaper( const QString & title, const QString & msg );
    bool shareFile( const QString & path, const QString & type );
    bool openFile( const QString & path, const QString & type );
    bool startCamera( const QString & output );
    bool callNumber( const QString & number );
    bool getOpenPictures();

    bool transparentStatusBar();
    bool setTransparentStatusBar(bool stt);

    bool transparentNavigationBar();
    bool setTransparentNavigationBar(bool stt);

    int densityDpi();
    int screenSizeWidth();
    int screenSizeHeight();
    int getSizeName();
    int statusBarHeight();
    int navigationBarHeight();
    bool isTablet();
    qreal density();

    QString packageName();
    QString deviceName();
    QString deviceId();

    QRect keyboardRect();

    QString getLastImages(qint32 offset, qint32 count);
    QString getContactList();

    void setKeepScreenOn(bool stt);

public Q_SLOTS:
    bool startService();
    bool stopService();
    bool killService(const QString &serviceName);

    bool startQtService();
    bool stopQtService();

    bool startForeground(qint32 id, const QString &title, const QString &msg, const QString &iconPath, const QString &icon, const QString &channelId);
    bool stopForeground(bool removeNotification);
    bool startNotification(qint32 id, const QString &title, const QString &msg, const QString &iconPath, const QString &icon, const QString &channelId, bool sound = false, bool vibrate = false);
    bool stopNotification(qint32 id);
    QString createNotificationChannel(const QString &channelId ,const QString &channelName, int importance = ImportanceLow);

Q_SIGNALS:
    void incomingShare( const QString & title, const QString & msg );
    void incomingImage( const QString & path );
    void selectImageResult( const QString & path );
    void keyboardVisiblityChanged(qint32 height);
    void activityPaused();
    void activityStopped();
    void activityResumed();
    void activityStarted();
    void activityRestarted();
    void activityDestroyed();

private Q_SLOTS:
    void load_buffer();
    void registerObject();

protected:
    void setImplemented(bool stt);

private:
    TonToolkitJavaLayerPrivate *p;
};

#endif // TONTOOLKITJAVALAYER_H

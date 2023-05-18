#ifndef TONCONNECT_H
#define TONCONNECT_H

#include "tontoolkitquickobject.h"

#include <QStringList>
#include <QVariantMap>

class TonConnectService;
class TonConnect : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList baseUrls READ baseUrls WRITE setBaseUrls NOTIFY baseUrlsChanged)
    Q_PROPERTY(bool connecting READ connecting NOTIFY connectingChanged)

public:
    enum Platforms {
        Platform_linux,
        Platform_windows,
        Platform_macOS,
        Platform_iPad,
        Platform_iPhone,
        Platform_android,
    };
    Q_ENUMS(Platforms)

    TonConnect(QObject *parent = nullptr);
    virtual ~TonConnect();

    QStringList baseUrls() const;
    void setBaseUrls(const QStringList &newBaseUrls);

    bool connecting() const;

public Q_SLOTS:
    bool check(const QString &tag);

    void accept(TonConnectService *service);
    void reject(TonConnectService *service);

Q_SIGNALS:
    void newServiceRequest(const QString &id, const QUrl &manifestUrl, const QVariantList &items);
    void baseUrlsChanged();
    void connectingChanged();
    void connectedSuccessfully();

private Q_SLOTS:
    void appMessage(const QString &message);

protected:
    QString getPlatformName() const;
    void setConnecting(bool newConnecting);

private:
    QStringList mBaseUrls;
    bool mConnecting = false;

    qint32 mUniqueId = 1000;

    int mPlatform = 0;
    QString mAppName;
    QString mAppVersion;
    QString mWalletAddress;
    qint32 mNetworkId = -239;
    QString mPublicKey;
    QString mWalletStateInit;
    QString mSignature;
    QString mPayload;
};

#endif // TONCONNECT_H

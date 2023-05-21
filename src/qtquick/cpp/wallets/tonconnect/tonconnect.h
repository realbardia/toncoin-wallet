#ifndef TONCONNECT_H
#define TONCONNECT_H

#include "tontoolkitquickobject.h"
#include "qtquick/cpp/wallets/core/walletitem.h"

#include <QStringList>
#include <QVariantMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPointer>

class TonConnectService;
class TonConnect : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList baseUrls READ baseUrls WRITE setBaseUrls NOTIFY baseUrlsChanged)
    Q_PROPERTY(bool connecting READ connecting NOTIFY connectingChanged)
    Q_PROPERTY(WalletItem *wallet READ wallet WRITE setWallet NOTIFY walletChanged)
    Q_PROPERTY(int platform READ platform WRITE setPlatform NOTIFY platformChanged)
    Q_PROPERTY(QString appName READ appName WRITE setAppName NOTIFY appNameChanged)
    Q_PROPERTY(QString appVersion READ appVersion WRITE setAppVersion NOTIFY appVersionChanged)
    Q_PROPERTY(QString clientId READ clientId NOTIFY clientIdChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString cachePath READ cachePath WRITE setCachePath NOTIFY cachePathChanged)
    Q_PROPERTY(QVariantList tokens READ tokens NOTIFY tokensChanged)
    Q_PROPERTY(QString bridgeUrl READ bridgeUrl WRITE setBridgeUrl NOTIFY bridgeUrlChanged)
    Q_PROPERTY(QString lastEventId READ lastEventId WRITE setLastEventId NOTIFY lastEventIdChanged)
    Q_PROPERTY(int network READ network WRITE setNetwork NOTIFY networkChanged)
    Q_PROPERTY(bool locked READ locked WRITE setLocked NOTIFY lockedChanged)

public:
    struct Token {
        QString id;
        QString name;
        QString iconUrl;
        QString domain;
        QDateTime datetime;
        qint64 lastId;

        QVariantMap toMap() const;
        static Token fromMap(const QVariantMap &m);
    };

    enum ConnectErrors {
        ConnectUnknownError = 0,
        ConnectBadRequestError = 1,
        ConnectManifestNotFoundError = 2,
        ConnectManifestContentError = 3,
        ConnectUnknownAppError = 100,
        ConnectDeclinedConnectionError = 300,
    };
    Q_ENUMS(ConnectErrors)

    enum ConnectItemErrors {
        ConnectUnknownItemError = 0,
        ConnectUnsupportedItemError = 400,
    };
    Q_ENUMS(ConnectItemErrors)

    enum DisconnectErrors {
        DisonnectUnknownError = 0,
        DisconnectBadRequestError = 1,
        DisconnectUnkownAppError = 100,
        DisconnectUnsupportedMethodError = 400,
    };
    Q_ENUMS(DisconnectErrors)

    enum Network {
        Testnet = -3,
        Mainnet = -239
    };
    Q_ENUMS(Network)

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

    WalletItem *wallet() const;
    void setWallet(WalletItem *newWallet);

    int platform() const;
    void setPlatform(int newPlatform);

    QString appName() const;
    void setAppName(const QString &newAppName);

    QString appVersion() const;
    void setAppVersion(const QString &newAppVersion);

    QString clientId() const;

    QString password() const;
    void setPassword(const QString &newPassword);

    QString cachePath() const;
    void setCachePath(const QString &newCachePath);

    QVariantList tokens() const;

    QString bridgeUrl() const;
    void setBridgeUrl(const QString &newBridgeUrl);

    QString lastEventId() const;
    void setLastEventId(const QString &newLastEventId);

    int network() const;
    void setNetwork(int newNetwork);

    bool locked() const;
    void setLocked(bool newLocked);

public Q_SLOTS:
    bool check(const QString &tag);

    void accept(TonConnectService *service);
    void reject(const QString &id, int error);
    void revoke(const QString &id);

    void transferCompleted(const QString &serviceId, const QString &amount, const QString &address);
    void transferRejected(const QString &serviceId, const QString &amount, const QString &address);

    void runEventListener();

Q_SIGNALS:
    void newServiceRequest(const QString &id, const QUrl &manifestUrl, const QVariantList &items);
    void baseUrlsChanged();
    void connectingChanged();
    void connectedSuccessfully(const QString &id);
    void connectingFailed(const QString &id);
    void walletChanged();
    void platformChanged();
    void appNameChanged();
    void appVersionChanged();
    void clientIdChanged();
    void passwordChanged();
    void tokensChanged();
    void cachePathChanged();
    void bridgeUrlChanged();
    void lastEventIdChanged();
    void newEventArrived(const QString &eventId);
    void failed(const QString &title, const QString &message);
    void newTransferRequest(const QString &serviceId, const QString &serviceName, const QString &serviceIcon, const QString &amount, const QString &address);
    void networkChanged();
    void lockedChanged();

protected:
    QString getPlatformName() const;
    void setConnecting(bool newConnecting);

    void accept(TonConnectService *service, const QByteArray &privateKey, const QByteArray &publicKey);
    QNetworkReply *sendMessage(const QString &serviceId, const QByteArray &decodedData, const std::function<void(const QByteArray &data, bool error)> callback);

    QList<Token> getTokens() const;
    void writeTokens(const QList<Token> &tokens);

    void restartEventListener();
    void processMessage(const Token &from, const QByteArray &data);

private:
    QString mLastEventId;
    QPointer<QNetworkReply> mEventListenerReply;
    QNetworkAccessManager *mAm;

    QString mBridgeUrl;
    QStringList mBaseUrls;
    bool mConnecting = false;
    bool mLocked = false;

    qint32 mUniqueId;

    QPointer<WalletItem> mWallet;
    QPointer<WalletItem> mDefaultWallet;

    int mNetwork = Mainnet;
    int mPlatform = 0;
    QString mAppName;
    QString mAppVersion;

    QString mPassword;
    QString mCachePath;

    QTimer *mRunTimer;
};

#endif // TONCONNECT_H

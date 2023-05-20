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

public Q_SLOTS:
    bool check(const QString &tag);

    void accept(TonConnectService *service);
    void reject(TonConnectService *service);
    void revoke(const QString &id);

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

protected:
    QString getPlatformName() const;
    void setConnecting(bool newConnecting);

    void accept(TonConnectService *service, const QByteArray &privateKey, const QByteArray &publicKey);

    QList<Token> getTokens() const;
    void writeTokens(const QList<Token> &tokens);

private:
    QNetworkAccessManager *mAm;

    QStringList mBaseUrls;
    bool mConnecting = false;

    qint32 mUniqueId;

    QPointer<WalletItem> mWallet;
    QPointer<WalletItem> mDefaultWallet;

    int mPlatform = 0;
    QString mAppName;
    QString mAppVersion;

    QString mPassword;
    QString mCachePath;
};

#endif // TONCONNECT_H

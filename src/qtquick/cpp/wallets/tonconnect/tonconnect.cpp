#include "tonconnect.h"

#include "tonconnectservice.h"
#include "tontoolkitapplicationitem.h"
#include "tontoolkitdevices.h"

#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

TonConnect::TonConnect(QObject *parent)
    : TonToolkitQuickObject(parent)
{
    connect(static_cast<TonToolkitApplicationItem*>(TonToolkitApplicationItem::instance())
            , &TonToolkitApplicationItem::messageReceived, this, &TonConnect::appMessage);

#if defined(Q_OS_ANDROID)
    mPlatform = Platform_android;
#elif defined(Q_OS_IOS)
    TonToolkitDevices devices;
    if (devices.isMobile())
        mPlatform = Platform_iPhone;
    else
        mPlatform = Platform_iPad;
#elif defined(Q_OS_LINUX)
    mPlatform = Platform_linux;
#elif defined(Q_OS_MACX)
    mPlatform = Platform_macOS;
#elif defined(Q_OS_WIN)
    mPlatform = Platform_windows;
#endif
}

TonConnect::~TonConnect()
{

}

bool TonConnect::check(const QString &tag)
{
    QUrl url;
    for (const auto &base: mBaseUrls)
    {
        if (tag.left(base.size()) == base)
        {
            url = QUrl(QStringLiteral("http://t.com/") + tag.mid(base.size()));
            break;
        }
    }
    if (url.isEmpty())
        return false;

    QUrlQuery query(url);

    const auto v = query.queryItemValue("v", QUrl::FullyDecoded);
    if (v != QStringLiteral("2"))
        return false;

    const auto id = query.queryItemValue("id", QUrl::FullyDecoded);
    const auto r = query.queryItemValue("r", QUrl::FullyDecoded);

    auto json = QJsonDocument::fromJson(r.toUtf8());
    if (json.isEmpty())
        return false;

    auto obj = json.object();

    const QUrl manifestUrl = obj.value(QStringLiteral("manifestUrl")).toString();
    const QVariantList items = obj.value("items").toVariant().toList();

    Q_EMIT newServiceRequest(id, manifestUrl, items);
    return true;
}

void TonConnect::accept(TonConnectService *service)
{
    QVariantList replies;
    for (const auto &i: service->items())
    {
        const auto m = i.toMap();
        const auto name = m.value("name").toString();
        if (name == QStringLiteral("ton_proof"))
        {
            QVariantMap domain = {
                {"lengthBytes", service->serviceUrl().host().length()},
                {"value", service->serviceUrl().toString()},
            };
            QVariantMap proof = {
                {"timestamp", QDateTime::currentSecsSinceEpoch()},
                {"domain", domain},
                {"signature", mSignature},
                {"payload", mPayload},
            };
            QVariantMap tonProofItemReplySuccess = {
                {"name", "ton_proof"},
                {"proof", proof},
            };

            replies << tonProofItemReplySuccess;
        }
        else if (name == QStringLiteral("ton_addr"))
        {
            QVariantMap tonAddressItemReply = {
                {"name", "ton_addr"},
                {"address", mWalletAddress},
                {"network", mNetworkId},
                {"publicKey", mPublicKey},
                {"walletStateInit", mWalletStateInit},
            };

            replies << tonAddressItemReply;
        }
    }

    QVariantMap sendTransaction = {{"name", "SendTransaction"}, {"maxMessages", 1}};
    QVariantList features = {sendTransaction};

    QVariantMap deviceInfo = {
        {"platform", getPlatformName()},
        {"appName", mAppName},
        {"appVersion", mAppVersion},
        {"maxProtocolVersion", 2},
        {"features", features},
    };

    QVariantMap payload = {
        {"items", replies},
        {"device", deviceInfo},
    };

    QVariantMap success = {
        {"event", "connect"},
        {"id", mUniqueId++},
        {"payload", payload},
    };

    QTimer::singleShot(2000, this, [this](){
        setConnecting(false);
        Q_EMIT connectedSuccessfully();
    });
    setConnecting(true);
}

void TonConnect::reject(TonConnectService *)
{

}

void TonConnect::appMessage(const QString &message)
{
    check(message);
}

QString TonConnect::getPlatformName() const
{
    switch (mPlatform)
    {
    case Platform_iPhone:
        return "iphone";
    case Platform_iPad:
        return "ipad";
    case Platform_android:
        return "android";
    case Platform_windows:
        return "windows";
    case Platform_macOS:
        return "mac";
    case Platform_linux:
        return "linux";
    default:
        return QString();
    }
}

bool TonConnect::connecting() const
{
    return mConnecting;
}

void TonConnect::setConnecting(bool newConnecting)
{
    if (mConnecting == newConnecting)
        return;
    mConnecting = newConnecting;
    emit connectingChanged();
}

QStringList TonConnect::baseUrls() const
{
    return mBaseUrls;
}

void TonConnect::setBaseUrls(const QStringList &newBaseUrls)
{
    if (mBaseUrls == newBaseUrls)
        return;
    mBaseUrls = newBaseUrls;
    Q_EMIT baseUrlsChanged();
}

#include "tonconnect.h"

#include "tonconnectservice.h"
#include "tontoolkitapplicationitem.h"
#include "tontoolkitdevices.h"
#include "tontoolkitapplication.h"

#include "core/tools/crypto.h"

#include <crypto/block/block.h>
#include <crypto/Ed25519.h>

#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QNetworkRequest>
#include <QDateTime>
#include <QDataStream>
#include <QUrlQuery>
#include <QFile>

#ifndef CRYPTO_FILE_STORE_SALT
#define CRYPTO_FILE_STORE_SALT "f0b033df-5506-43a5-921a-081289f9cf91"
#endif

#define BALANCE_RATIO (1/1000000000.0)
#define DEFINE_BUFFER_STREAM(NAME) QByteArray NAME; QDataStream(&NAME, QIODevice::WriteOnly)

TonConnect::TonConnect(QObject *parent)
    : TonToolkitQuickObject(parent)
{
    mDefaultWallet = new WalletItem(this);
    mWallet = mDefaultWallet;
    mUniqueId = QDateTime::currentSecsSinceEpoch();

    mAm = new QNetworkAccessManager(this);

    mRunTimer = new QTimer(this);
    mRunTimer->setSingleShot(true);
    mRunTimer->setInterval(100);

    connect(mRunTimer, &QTimer::timeout, this, &TonConnect::restartEventListener);

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
    if (mLocked)
        return false;

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
    if (!mWallet || !mWallet->backend() || !mWallet->backend()->backendObject())
        return;

    const auto publicKey = QByteArray::fromBase64(mWallet->publicKey().toLatin1());
    auto backend = mWallet->backend()->backendObject();
    backend->getPrivateKey(publicKey, this, [this, publicKey, service](const QByteArray &privateKey, const TON::Wallet::AbstractWalletBackend::Error &){
        accept(service, privateKey, publicKey);
    });
}

void TonConnect::accept(TonConnectService *service, const QByteArray &privateKey, const QByteArray &publicKey)
{
    td::Ed25519::PrivateKey prvKey = td::Ed25519::PrivateKey::from_pem(td::Slice(privateKey.toStdString()), td::Slice()).move_as_ok();

    const auto rawAddress = block::StdAddress::parse(td::Slice(mWallet->address().toStdString())).move_as_ok();
    const auto addressBytes = QByteArray::fromStdString(rawAddress.addr.as_slice().str());
    const auto addressHex = QString::fromLatin1(addressBytes.toHex());

    QVariantList replies;
    for (const auto &i: service->items())
    {
        const auto m = i.toMap();
        const auto name = m.value("name").toString();
        if (name == QStringLiteral("ton_proof"))
        {
            const auto payload = m.value("payload").toString();

            const auto domain = service->serviceUrl().host();
            const auto domainLength = domain.length();

            const auto timestamp = (qint64)QDateTime::currentSecsSinceEpoch();
            DEFINE_BUFFER_STREAM(timestampBuffer) << timestamp;

            const auto domainBuffer = domain.toUtf8();
            DEFINE_BUFFER_STREAM(domainLengthBuffer) << (int)domainBuffer.length();

            DEFINE_BUFFER_STREAM(addressWorkchainBuffer) << (int)rawAddress.workchain;
            const auto addressBuffer = addressWorkchainBuffer + QByteArray::fromHex(addressHex.toLatin1());

            const auto messageBuffer = QString("ton-proof-item-v2/").toUtf8()
                    + addressBuffer + domainLengthBuffer + domainBuffer
                    + timestampBuffer + payload.toLatin1();

            const auto message = QCryptographicHash::hash(messageBuffer, QCryptographicHash::Sha256);

            const auto bufferToSign = QByteArray::fromHex("ffff") + QString("ton-connect").toLatin1() + message;

            const auto signData = prvKey.sign(bufferToSign.toStdString()).move_as_ok().as_slice().str();
            const auto signature = QString::fromLatin1(QByteArray::fromStdString(signData).toBase64());

            QVariantMap domainMap = {
                {"lengthBytes", domainLength},
                {"value", domain},
            };
            QVariantMap proof = {
                {"timestamp", QString::number(timestamp)},
                {"domain", domainMap},
                {"signature", signature},
                {"payload", payload},
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
                {"name", QString("ton_addr")},
                {"address", QStringLiteral("%1:").arg(rawAddress.workchain) + addressHex},
                {"network", static_cast<int>(rawAddress.testnet? Testnet : Mainnet)},
                {"publicKey", QString::fromLatin1(publicKey.toHex())},
                {"walletStateInit", QString::fromLatin1(mWallet->initState().toBase64())},
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

    QUrlQuery query;
    query.addQueryItem("client_id", clientId());
    query.addQueryItem("to", service->serviceId());
    query.addQueryItem("ttl", "300");

    QUrl url(mBridgeUrl + "/message");
    url.setQuery(query);

    const auto json = QJsonDocument::fromVariant(success).toJson(QJsonDocument::Compact);

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");

    auto reply = mAm->post(req, json.toBase64());

    connect(service, &QObject::destroyed, this, [reply, this](){
        reply->deleteLater();
        setConnecting(false);
    });

    connect(reply, &QNetworkReply::finished, this, [this, reply, service](){
        const auto json = QJsonDocument::fromJson(reply->readAll());
        const auto &id = service->serviceId();
        if (json.object().value("statusCode").toInt() == 200)
        {
            Token t;
            t.id = id;
            t.name = service->serviceName();
            t.iconUrl = service->serviceIcon();
            t.datetime = QDateTime::currentDateTime();
            t.lastId = mUniqueId;
            t.domain = service->serviceUrl().toString();

            auto tokens = getTokens();
            tokens << t;
            writeTokens(tokens);

            Q_EMIT connectedSuccessfully(id);
            Q_EMIT tokensChanged();
        }
        else
            Q_EMIT connectingFailed(id);

        setConnecting(false);
        service->disconnect(this);
        reply->deleteLater();
        runEventListener();
    });

    setConnecting(true);
}

QList<TonConnect::Token> TonConnect::getTokens() const
{
    QList<TonConnect::Token> res;
    if (mCachePath.isEmpty())
        return res;

    QFile f(mCachePath);
    if (!f.open(QFile::ReadOnly))
        return res;

    auto data = f.readAll();
    if (data.isEmpty())
        return res;

    if (mPassword.count())
    {
        TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
        data = crypto.decrypt(data);
    }
    if (data.isEmpty())
        return res;

    const auto &json = QJsonDocument::fromJson(data);
    if (json.isEmpty())
        return res;

    for (const auto &i: json.array())
        res << TonConnect::Token::fromMap( i.toObject().toVariantMap() );

    return res;
}

void TonConnect::writeTokens(const QList<Token> &tokens)
{
    if (mCachePath.isEmpty())
        return;

    QFile f(mCachePath);
    if (!f.open(QFile::WriteOnly))
        return;

    QJsonArray array;
    for (const auto &t: tokens)
        array << QJsonObject::fromVariantMap(t.toMap());

    QJsonDocument doc;
    doc.setArray(array);

    const auto data = doc.toJson(QJsonDocument::Compact);
    if (mPassword.isEmpty())
        f.write(data);
    else
    {
        TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
        f.write( crypto.encrypt(data) );
    }

    f.close();
}

void TonConnect::restartEventListener()
{
    if (mEventListenerReply)
        delete mEventListenerReply;

    const auto clientId = TonConnect::clientId();
    if (clientId.isEmpty())
        return;

    if (mLocked)
        return;

    QUrlQuery query;
    query.addQueryItem("client_id", clientId);
    query.addQueryItem("last_event_id", mLastEventId.count()? mLastEventId : QStringLiteral("0"));

    QUrl url(mBridgeUrl + "/events");
    url.setQuery(query);

    QNetworkRequest req(url);

    QHash<QString, Token> tokens;
    for (const auto &t: getTokens())
        tokens[t.id.toLower()] = t;

    mEventListenerReply = mAm->get(req);
    connect(mEventListenerReply, &QNetworkReply::readyRead, this, [this, clientId, tokens](){
        if (clientId != TonConnect::clientId())
        {
            qDebug() << "Client ID changed...\nTry restarting ton-connect";
            QMetaObject::invokeMethod(this, &TonConnect::restartEventListener, Qt::QueuedConnection);
            return;
        }

        auto lines = QString(mEventListenerReply->readAll()).trimmed().split('\n');

        QString lastId;
        for (const auto &l: lines)
        {
            if (l.left(3) == QStringLiteral("id:"))
            {
                lastId = l.mid(3).trimmed();
                continue;
            }
            if (lastId.isEmpty())
                continue;

            const auto currentId = lastId;
            lastId.clear();
            // Next line of ID must be data
            if (l.left(5) != QStringLiteral("data:"))
                continue;

            const auto jsonStr = l.mid(5).trimmed();
            const auto json = QJsonDocument::fromJson(jsonStr.toUtf8());
            if (json.isEmpty())
                continue;

            const auto obj = json.object();
            const auto from = obj.value(QStringLiteral("from")).toString();
            const auto message = obj.value(QStringLiteral("message")).toString();

            if (tokens.contains(from.toLower()))
                processMessage(tokens.value(from.toLower()), QByteArray::fromBase64(message.toLatin1()));

            Q_EMIT newEventArrived(currentId);
        }
    });
}

void TonConnect::processMessage(const TonConnect::Token &from, const QByteArray &data)
{
    static const auto rx1 = QRegularExpression("0+$");
    static const auto rx2 = QRegularExpression("(?:\\.)0*$");

    const auto json = QJsonDocument::fromJson(data);
    const auto obj = json.object();
    const auto method = obj.value(QStringLiteral("method")).toString();
    if (method == QStringLiteral("sendTransaction"))
    {
        const auto params = obj.value("params").toArray();
        for (const auto &p: params)
        {
            const auto t = p.toObject();
            const auto valid_until = t.value("valid_until").toInt();
            if (valid_until && valid_until < QDateTime::currentSecsSinceEpoch())
            {
                Q_EMIT failed(tr("Timeout"), tr("An expired request received from %1 and rejected").arg(from.name));
                continue;
            }

            const auto network = t.value("network").toString().toInt();
            if (network && network != mNetwork)
            {
                Q_EMIT failed(tr("Bad network"), tr("%1 send a transaction request on the wrong network.").arg(from.name));
                continue;
            }

            const auto fromAddress = t.value("from").toString();
            Q_UNUSED(fromAddress) // Ignored, We dont need it

            const auto messages = t.value("messages").toArray();
            for (const auto &msg: messages)
            {
                const auto msgObj = msg.toObject();
                const auto addressRaw = msgObj.value("address").toString();
                const auto amount = msgObj.value("amount").toString();
                const auto stateInit = msgObj.value("stateInit").toString();
                Q_UNUSED(stateInit)
                const auto payload = msgObj.value("payload").toString();
                Q_UNUSED(payload)

                const auto addressParts = addressRaw.split(':');
                if (addressParts.count() != 2)
                    continue;

                const auto workchain = addressParts.first().toInt();
                const auto address = QByteArray::fromHex(addressParts.last().toLatin1());

                ton::StdSmcAddress smcAddress;
                smcAddress.from_hex(address.toStdString());

                block::StdAddress stdAddress(workchain, smcAddress);

                auto amountTON = QString::number(amount.toLongLong() * BALANCE_RATIO, 'f', 9).remove(rx1).remove(rx2);

                Q_EMIT newTransferRequest(from.id, from.name, from.iconUrl, amountTON, QByteArray::fromStdString(stdAddress.rserialize()));
            }
        }
    }
}

bool TonConnect::locked() const
{
    return mLocked;
}

void TonConnect::setLocked(bool newLocked)
{
    if (mLocked == newLocked)
        return;
    mLocked = newLocked;
    runEventListener();
    Q_EMIT lockedChanged();
}

int TonConnect::network() const
{
    return mNetwork;
}

void TonConnect::setNetwork(int newNetwork)
{
    if (mNetwork == newNetwork)
        return;
    mNetwork = newNetwork;
    runEventListener();
    Q_EMIT networkChanged();
}

QString TonConnect::lastEventId() const
{
    return mLastEventId;
}

void TonConnect::setLastEventId(const QString &newLastEventId)
{
    if (mLastEventId == newLastEventId)
        return;
    mLastEventId = newLastEventId;
    Q_EMIT lastEventIdChanged();
}

QString TonConnect::bridgeUrl() const
{
    return mBridgeUrl;
}

void TonConnect::setBridgeUrl(const QString &newBridgeUrl)
{
    if (mBridgeUrl == newBridgeUrl)
        return;
    mBridgeUrl = newBridgeUrl;
    runEventListener();
    Q_EMIT bridgeUrlChanged();
}

QString TonConnect::cachePath() const
{
    return mCachePath;
}

void TonConnect::setCachePath(const QString &newCachePath)
{
    if (mCachePath == newCachePath)
        return;
    mCachePath = newCachePath;
    runEventListener();
    Q_EMIT cachePathChanged();
}

QVariantList TonConnect::tokens() const
{
    QVariantList res;
    for (const auto &t: getTokens())
        res << t.toMap();
    return res;
}

QString TonConnect::password() const
{
    return mPassword;
}

void TonConnect::setPassword(const QString &newPassword)
{
    if (mPassword == newPassword)
        return;
    mPassword = newPassword;
    runEventListener();
    Q_EMIT passwordChanged();
}

void TonConnect::reject(TonConnectService *)
{

}

void TonConnect::revoke(const QString &id)
{
    QList<Token> tokens;
    for (const auto &t: getTokens())
        if (t.id != id)
            tokens << t;

    writeTokens(tokens);
    runEventListener();
    Q_EMIT tokensChanged();
}

void TonConnect::transferCompleted(const QString &serviceId, const QString &amount, const QString &address)
{

}

void TonConnect::runEventListener()
{
    mRunTimer->stop();
    mRunTimer->start();
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
    Q_EMIT connectingChanged();
}

QString TonConnect::appVersion() const
{
    return mAppVersion;
}

void TonConnect::setAppVersion(const QString &newAppVersion)
{
    if (mAppVersion == newAppVersion)
        return;
    mAppVersion = newAppVersion;
    Q_EMIT appVersionChanged();
}

QString TonConnect::clientId() const
{
    if (!mWallet)
        return QString();
    if (mWallet->address().isEmpty())
        return QString();

    const auto rawAddress = block::StdAddress::parse(td::Slice(mWallet->address().toStdString())).move_as_ok();
    const auto addressBytes = QByteArray::fromStdString(rawAddress.addr.as_slice().str());

    auto clientId = QCryptographicHash::hash("2a0efb19-269b-4ce3-9007-83fe99cd67ac" +
                                             TonToolkitDevices::deviceId().toLatin1() +
                                             addressBytes +
                                             "2a0efb19-269b-4ce3-9007-83fe99cd67ac"
                                             , QCryptographicHash::Sha256).toHex();

    return clientId;
}

QString TonConnect::appName() const
{
    return mAppName;
}

void TonConnect::setAppName(const QString &newAppName)
{
    if (mAppName == newAppName)
        return;
    mAppName = newAppName;
    Q_EMIT appNameChanged();
}

int TonConnect::platform() const
{
    return mPlatform;
}

void TonConnect::setPlatform(int newPlatform)
{
    if (mPlatform == newPlatform)
        return;
    mPlatform = newPlatform;
    Q_EMIT platformChanged();
}

WalletItem *TonConnect::wallet() const
{
    return mWallet;
}

void TonConnect::setWallet(WalletItem *newWallet)
{
    if (mWallet == newWallet)
        return;

    if (mWallet)
        disconnect(mWallet, &WalletItem::addressChanged, this, &TonConnect::runEventListener);

    mWallet = newWallet;
    if (mWallet)
        connect(mWallet, &WalletItem::addressChanged, this, &TonConnect::runEventListener);

    runEventListener();
    Q_EMIT walletChanged();
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

QVariantMap TonConnect::Token::toMap() const
{
    return {
        {"id", id},
        {"name", name},
        {"domain", domain},
        {"iconUrl", iconUrl},
        {"datetime", datetime},
        {"lastId", lastId},
    };
}

TonConnect::Token TonConnect::Token::fromMap(const QVariantMap &m)
{
    TonConnect::Token t;
    t.name = m.value(QStringLiteral("name")).toString();
    t.id = m.value(QStringLiteral("id")).toString();
    t.iconUrl = m.value(QStringLiteral("iconUrl")).toString();
    t.domain = m.value(QStringLiteral("domain")).toString();
    t.datetime = m.value(QStringLiteral("datetime")).toDateTime();
    t.lastId = m.value(QStringLiteral("lastId")).toLongLong();
    return t;
}

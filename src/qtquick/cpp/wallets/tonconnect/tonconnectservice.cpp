#include "tonconnectservice.h"

#include "tontoolkitapplicationitem.h"

#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

TonConnectService::TonConnectService(QObject *parent)
    : TonToolkitQuickObject(parent)
{
    mAm = new QNetworkAccessManager(this);

    mReloadTimer = new QTimer(this);
    mReloadTimer->setInterval(10);
    mReloadTimer->setSingleShot(true);

    connect(mReloadTimer, &QTimer::timeout, this, &TonConnectService::doReload);
}

TonConnectService::~TonConnectService()
{

}

bool TonConnectService::loading() const
{
    return mReply;
}

void TonConnectService::doReload()
{
    if (mReply)
        delete mReply;
    if (mManifestUrl.isEmpty())
    {
        Q_EMIT loadingChanged();
        return;
    }

    QNetworkRequest req(mManifestUrl);
    mReply = mAm->get(req);
    connect(mReply, &QNetworkReply::finished, this, [this](){
        auto json = QJsonDocument::fromJson(mReply->readAll());
        if (json.isObject())
        {
            auto obj = json.object();
            mServiceUrl = obj.value(QStringLiteral("url")).toString();
            mServiceName = obj.value(QStringLiteral("name")).toString();
            mServiceIcon = obj.value(QStringLiteral("iconUrl")).toString();
            mServiceTerms = obj.value(QStringLiteral("termsOfUseUrl")).toString();
            mServicePolicy = obj.value(QStringLiteral("privacyPolicyUrl")).toString();
        }
        else
        {
            mServiceUrl.clear();
            mServiceName.clear();
            mServiceIcon.clear();
            mServiceTerms.clear();
            mServicePolicy.clear();
        }

        mReply->deleteLater();
        mReply = nullptr;
        Q_EMIT loadingChanged();
        Q_EMIT serviceChanged();
    });
    Q_EMIT loadingChanged();
}

QVariantList TonConnectService::items() const
{
    return mItems;
}

void TonConnectService::setItems(const QVariantList &newItems)
{
    if (mItems == newItems)
        return;
    mItems = newItems;
    Q_EMIT itemsChanged();
}

void TonConnectService::reload()
{
    mReloadTimer->stop();
    mReloadTimer->start();
}

QString TonConnectService::requestId() const
{
    return mRequestId;
}

void TonConnectService::setRequestId(const QString &newRequestId)
{
    if (mRequestId == newRequestId)
        return;
    mRequestId = newRequestId;
    Q_EMIT requestIdChanged();
}

QUrl TonConnectService::manifestUrl() const
{
    return mManifestUrl;
}

void TonConnectService::setManifestUrl(const QUrl &newManifestUrl)
{
    if (mManifestUrl == newManifestUrl)
        return;
    mManifestUrl = newManifestUrl;
    reload();
    Q_EMIT manifestUrlChanged();
}

QUrl TonConnectService::servicePolicy() const
{
    return mServicePolicy;
}

QUrl TonConnectService::serviceTerms() const
{
    return mServiceTerms;
}

QString TonConnectService::serviceName() const
{
    return mServiceName;
}

QString TonConnectService::serviceIcon() const
{
    return mServiceIcon;
}

QUrl TonConnectService::serviceUrl() const
{
    return mServiceUrl;
}

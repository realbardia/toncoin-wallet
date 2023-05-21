#include "tonconnectservice.h"

#include "asemanapplicationitem.h"
#include "tonconnect.h"

#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

TonConnectService::TonConnectService(QObject *parent)
    : AsemanQuickObject(parent)
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
        const auto data = mReply->readAll();
        auto json = QJsonDocument::fromJson(data);
        if (json.isObject())
        {
            auto obj = json.object();
            mServiceUrl = obj.value(QStringLiteral("url")).toString();
            mServiceName = obj.value(QStringLiteral("name")).toString();
            if (mServiceUrl.isEmpty() || mServiceName.isEmpty())
            {
                mServiceUrl.clear();
                mServiceName.clear();
                mServiceIcon.clear();
                mServiceTerms.clear();
                mServicePolicy.clear();
                Q_EMIT error(TonConnect::ConnectUnknownAppError);
                return;
            }
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

            if (data.isEmpty())
                Q_EMIT error(TonConnect::ConnectManifestNotFoundError);
            else
                Q_EMIT error(TonConnect::ConnectManifestContentError);
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

QString TonConnectService::serviceId() const
{
    return mServiceId;
}

void TonConnectService::setServiceId(const QString &newRequestId)
{
    if (mServiceId == newRequestId)
        return;
    mServiceId = newRequestId;
    Q_EMIT serviceIdChanged();
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

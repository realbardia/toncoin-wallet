#include "currencyprice.h"

#include <QUrlQuery>
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

CurrencyPrice::CurrencyPrice(QObject *parent) :
    AsemanQuickObject(parent)
{
    mAm = new QNetworkAccessManager(this);

    mReloadTimer = new QTimer(this);
    mReloadTimer->setInterval(100);
    mReloadTimer->setSingleShot(true);

    connect(mReloadTimer, &QTimer::timeout, this, &CurrencyPrice::doReload);

    mTimeoutTimer = new QTimer(this);
    mTimeoutTimer->setInterval(10000);
    mTimeoutTimer->setSingleShot(true);

    connect(mTimeoutTimer, &QTimer::timeout, this, &CurrencyPrice::doReload);
}

CurrencyPrice::~CurrencyPrice()
{

}

QString CurrencyPrice::token() const
{
    return mToken;
}

void CurrencyPrice::setToken(const QString &newToken)
{
    if (mToken == newToken)
        return;
    mToken = newToken;
    reload();
    Q_EMIT tokenChanged();
}

QString CurrencyPrice::currency() const
{
    return mCurrency;
}

void CurrencyPrice::setCurrency(const QString &newCurrency)
{
    if (mCurrency == newCurrency)
        return;
    mCurrency = newCurrency;
    reload();
    Q_EMIT currencyChanged();
}

qreal CurrencyPrice::price() const
{
    return mPrice;
}

bool CurrencyPrice::refreshing() const
{
    return mReply;
}

void CurrencyPrice::reload()
{
    if (mReply)
    {
        delete mReply;
        Q_EMIT refreshingChanged();
    }

    mReloadTimer->stop();
    mReloadTimer->start();
}

void CurrencyPrice::setPrice(qreal newPrice)
{
    if (qFuzzyCompare(mPrice, newPrice))
        return;
    mPrice = newPrice;
    Q_EMIT priceChanged();
}

void CurrencyPrice::doReload()
{
    if (mReply)
        delete mReply;
    if (mToken.isEmpty() || mCurrency.isEmpty())
    {
        mTimeoutTimer->stop();
        Q_EMIT refreshingChanged();
        return;
    }

    QUrlQuery query;
    query.addQueryItem("ids", mToken);
    query.addQueryItem("vs_currencies", mCurrency);

    QUrl url("https://api.coingecko.com/api/v3/simple/price");
    url.setQuery(query);

    QNetworkRequest request;
    request.setRawHeader("accept", "application/json");
    request.setUrl(url);

    auto reply = mAm->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply](){
        if (mReply != reply)
        {
            reply->deleteLater();
            return;
        }

        const auto json = QJsonDocument::fromJson(mReply->readAll());
        if (!json.isEmpty())
            mTimeoutTimer->stop();

        const auto tokenObj = json.object().value(mToken).toObject();
        const auto price = tokenObj.value(mCurrency).toDouble();
        setPrice(price);

        mReply->deleteLater();
        mReply = nullptr;
        Q_EMIT refreshingChanged();
    });

    mTimeoutTimer->stop();
    mTimeoutTimer->start();

    mReply = reply;
    Q_EMIT refreshingChanged();
}

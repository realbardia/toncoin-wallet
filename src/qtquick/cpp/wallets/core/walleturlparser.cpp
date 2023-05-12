#include "walleturlparser.h"

#include <QUrl>
#include <QUrlQuery>

WalletUrlParser::WalletUrlParser(QObject *parent)
    : QObject(parent)
{

}

WalletUrlParser::~WalletUrlParser()
{

}

QString WalletUrlParser::url() const
{
    return mUrl;
}

void WalletUrlParser::setUrl(const QString &newUrl)
{
    if (mUrl == newUrl)
        return;

    mUrl = newUrl;

    const auto idx = mUrl.indexOf(QStringLiteral("://"));

    // We convert it to http link to using on QUrl
    QUrl url;
    if (idx >= 0)
        url = QStringLiteral("http") + mUrl.mid(idx);
    else
        url = QStringLiteral("http://") + mUrl;

    mAddress = url.path().mid(1);

    QUrlQuery query(url);
    mComment = query.queryItemValue("text");
    mAmount = query.queryItemValue("amount");

    Q_EMIT urlChanged();
}

QString WalletUrlParser::address() const
{
    return mAddress;
}

QString WalletUrlParser::amount() const
{
    return mAmount;
}

QString WalletUrlParser::comment() const
{
    return mComment;
}

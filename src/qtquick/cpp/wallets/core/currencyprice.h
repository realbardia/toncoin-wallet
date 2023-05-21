#ifndef CURRENCYPRICE_H
#define CURRENCYPRICE_H

#include "asemanquickobject.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QPointer>

class CurrencyPrice : public AsemanQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString token READ token WRITE setToken NOTIFY tokenChanged)
    Q_PROPERTY(QString currency READ currency WRITE setCurrency NOTIFY currencyChanged)
    Q_PROPERTY(qreal price READ price NOTIFY priceChanged)
    Q_PROPERTY(bool refreshing READ refreshing NOTIFY refreshingChanged)

public:
    CurrencyPrice(QObject *parent = nullptr);
    virtual ~CurrencyPrice();

    QString token() const;
    void setToken(const QString &newToken);

    QString currency() const;
    void setCurrency(const QString &newCurrency);

    qreal price() const;
    bool refreshing() const;

public Q_SLOTS:
    void reload();

Q_SIGNALS:
    void tokenChanged();
    void currencyChanged();
    void priceChanged();
    void refreshingChanged();

protected:
    void setPrice(qreal newPrice);
    void doReload();

private:
    QString mToken;
    QString mCurrency;
    qreal mPrice = 0;

    QTimer *mReloadTimer;
    QTimer *mTimeoutTimer;
    QPointer<QNetworkReply> mReply;
    QNetworkAccessManager *mAm;
};

#endif // CURRENCYPRICE_H

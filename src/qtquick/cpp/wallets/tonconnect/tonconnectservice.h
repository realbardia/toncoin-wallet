#ifndef TONCONNECTSERVICE_H
#define TONCONNECTSERVICE_H

#include "tontoolkitquickobject.h"

#include <QStringList>
#include <QVariantMap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPointer>
#include <QTimer>
#include <QUrl>

class TonConnectService : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl manifestUrl READ manifestUrl WRITE setManifestUrl NOTIFY manifestUrlChanged)
    Q_PROPERTY(QString serviceId READ serviceId WRITE setServiceId NOTIFY serviceIdChanged)
    Q_PROPERTY(QVariantList items READ items WRITE setItems NOTIFY itemsChanged)

    Q_PROPERTY(QUrl serviceUrl READ serviceUrl NOTIFY serviceChanged)
    Q_PROPERTY(QString serviceIcon READ serviceIcon NOTIFY serviceChanged)
    Q_PROPERTY(QString serviceName READ serviceName NOTIFY serviceChanged)
    Q_PROPERTY(QUrl serviceTerms READ serviceTerms NOTIFY serviceChanged)
    Q_PROPERTY(QUrl servicePolicy READ servicePolicy NOTIFY serviceChanged)
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)

public:
    TonConnectService(QObject *parent = nullptr);
    virtual ~TonConnectService();

    QUrl serviceUrl() const;
    QString serviceIcon() const;
    QString serviceName() const;
    QUrl serviceTerms() const;
    QUrl servicePolicy() const;

    bool loading() const;

    QUrl manifestUrl() const;
    void setManifestUrl(const QUrl &newManifestUrl);

    QString serviceId() const;
    void setServiceId(const QString &newRequestId);

    QVariantList items() const;
    void setItems(const QVariantList &newItems);

public Q_SLOTS:
    void reload();

Q_SIGNALS:
    void serviceChanged();
    void loadingChanged();
    void manifestUrlChanged();
    void serviceIdChanged();
    void itemsChanged();
    void error(int error);

protected:
    void doReload();

private:
    QTimer *mReloadTimer;

    QVariantList mItems;
    QString mServiceId;
    QUrl mManifestUrl;

    QUrl mServiceUrl;
    QString mServiceIcon;
    QString mServiceName;
    QUrl mServiceTerms;
    QUrl mServicePolicy;

    QPointer<QNetworkReply> mReply;

    QNetworkAccessManager *mAm;
};

#endif // TONCONNECTSERVICE_H

#ifndef WALLETITEM_H
#define WALLETITEM_H

#include "tontoolkitquickobject.h"
#include "walletbackend.h"

#include <QPointer>

class WalletItem : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString publicKey READ publicKey WRITE setPublicKey NOTIFY publicKeyChanged)
    Q_PROPERTY(WalletBackend *backend READ backend WRITE setBackend NOTIFY backendChanged)

public:
    WalletItem(QObject *parent = nullptr);
    virtual ~WalletItem();

    QString publicKey() const;
    void setPublicKey(const QString &newPublicKey);

    WalletBackend *backend() const;
    void setBackend(WalletBackend *newBackend);

public Q_SLOTS:
    bool changePassword(const QString &password);

Q_SIGNALS:
    void publicKeyChanged();
    void backendChanged();

    void passwordChangedSuccessfully();
    void passwordChangeFailed(qint32 code, const QString &error);

private:
    QString mPublicKey;
    QPointer<WalletBackend> mBackend;
};

#endif // WALLETITEM_H

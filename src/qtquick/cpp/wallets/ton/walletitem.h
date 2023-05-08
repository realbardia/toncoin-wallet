#ifndef WALLETITEM_H
#define WALLETITEM_H

#include "tontoolkitquickobject.h"
#include "walletbackend.h"

#include <QPointer>

class WalletItem : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString publicKey READ publicKey WRITE setPublicKey NOTIFY publicKeyChanged)
    Q_PROPERTY(WalletBackend *keysManager READ keysManager WRITE setWalletBackend NOTIFY keysManagerChanged)

public:
    WalletItem(QObject *parent = nullptr);
    virtual ~WalletItem();

    QString publicKey() const;
    void setPublicKey(const QString &newPublicKey);

    WalletBackend *keysManager() const;
    void setWalletBackend(WalletBackend *newWalletBackend);

public Q_SLOTS:
    void changePassword(const QString &password);

Q_SIGNALS:
    void publicKeyChanged();
    void keysManagerChanged();

    void passwordChangedSuccessfully();
    void passwordChangeFailed(qint32 code, const QString &error);

private:
    QString mPublicKey;
    QPointer<WalletBackend> mWalletBackend;
};

#endif // WALLETITEM_H

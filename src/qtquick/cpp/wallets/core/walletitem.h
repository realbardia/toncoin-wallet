#ifndef WALLETITEM_H
#define WALLETITEM_H

#include "asemanquickobject.h"
#include "asemanrefresherobject.h"
#include "walletbackend.h"

#include <QPointer>

class WalletItem : public AsemanQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString publicKey READ publicKey WRITE setPublicKey NOTIFY publicKeyChanged)
    Q_PROPERTY(WalletBackend *backend READ backend WRITE setBackend NOTIFY backendChanged)
    Q_PROPERTY(bool hasPassword READ hasPassword NOTIFY hasPasswordChanged)
    Q_PROPERTY(QString address READ address NOTIFY addressChanged)
    Q_PROPERTY(bool loading READ loading NOTIFY loadingChanged)

public:
    WalletItem(QObject *parent = nullptr);
    virtual ~WalletItem();

    QString publicKey() const;
    void setPublicKey(const QString &newPublicKey);

    WalletBackend *backend() const;
    void setBackend(WalletBackend *newBackend);

    QString address() const;
    bool hasPassword() const;
    bool loading() const;

    QByteArray initState() const;

public Q_SLOTS:
    bool changePassword(const QString &password);
    bool testPassword(const QString &password);
    bool unlock(const QString &password);
    void reload();

    QString decodeSecureKey(const QString &secureKey) const;

Q_SIGNALS:
    void publicKeyChanged();
    void backendChanged();

    void passwordChangedSuccessfully(const QString &newPublicKey, const QString &secureKey);
    void passwordChangeFailed(qint32 code, const QString &error);

    void addressChanged();
    void loadingChanged();
    void hasPasswordChanged();

protected:
    void setAddress(const QString &newAddress);
    void setLoading(bool newLoading);
    void setHasPassword(bool newHasPassword);

    void reset();

private:
    QString mAddress;
    QString mPublicKey;
    QPointer<WalletBackend> mBackend;

    AsemanRefresherObject *mRefresher;
    bool mHasPassword = false;
};

#endif // WALLETITEM_H

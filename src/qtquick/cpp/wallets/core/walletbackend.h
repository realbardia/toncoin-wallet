#ifndef WALLETBACKEND_H
#define WALLETBACKEND_H

#include <QObject>
#include <QStringList>

#include "tonqmlglobal.h"
#include "tontoolkitquickobject.h"

class WalletBackend : public TonToolkitQuickObject
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int backend READ backend WRITE setBackend NOTIFY backendChanged)
    Q_PROPERTY(bool initialized READ initialized NOTIFY initializedChanged)
    Q_PROPERTY(bool initializing READ initializing NOTIFY initializingChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(QStringList availableVersions READ availableVersions NOTIFY availableVersionsChanged)
    Q_PROPERTY(QString walletVersion READ walletVersion WRITE setWalletVersion NOTIFY walletVersionChanged)

public:
    WalletBackend(QObject *parent = nullptr);
    virtual ~WalletBackend();

    QString source() const;
    void setSource(const QString &newSource);

    int backend() const;
    void setBackend(int newBackend);

    QSharedPointer<TON::Wallet::AbstractWalletBackend> backendObject() const;

    bool initialized() const;
    bool initializing() const;

    QString walletVersion() const;
    void setWalletVersion(const QString &newWalletVersion);

    QStringList availableVersions() const;
    QString errorString() const;
    qint32 error() const;

Q_SIGNALS:
    void sourceChanged();
    void backendChanged();
    void initializedChanged();
    void errorChanged();
    void initializingChanged();
    void availableVersionsChanged();
    void walletVersionChanged();

protected:
    void reloadBackend();
    void reset();

private:
    QString mSource;
    int mBackend = TonQmlGlobal::None;
    QString mWalletVersion;

    bool mInitializing = false;
    bool mInitialized = false;
    QString mErrorString;
    qint32 mError = 0;

    QSharedPointer<TON::Wallet::AbstractWalletBackend> mBackendObject;
};

#endif // WALLETBACKEND_H

#ifndef BACKENDMANAGER_H
#define BACKENDMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include <QHash>

#include "abstractwalletbackend.h"

namespace TON::Wallet
{

class BackendManager
{
public:
    enum BackendType {
        TonLib = 1,
    };

    typedef std::function<void(bool done, const AbstractWalletBackend::Error &error)> InitializeCallback;

    static QSharedPointer<AbstractWalletBackend> createFreeBackend(BackendType type);

    static QString createHash(BackendType type, const QString &sourcePath);

    static QSharedPointer<AbstractWalletBackend> createBackend(BackendType type, const QString &sourcePath, const InitializeCallback &callback);
    static QSharedPointer<AbstractWalletBackend> getBackend(const QString &hashId);

private:
    struct BackendUnit
    {
        QList<InitializeCallback> callbacks;
        QWeakPointer<AbstractWalletBackend> backend;

        QString hash;
        bool initialized = false;
        bool done;
        AbstractWalletBackend::Error error;
    };

    static QHash<QString, BackendUnit> mBackends;
};

}

#endif // BACKENDMANAGER_H

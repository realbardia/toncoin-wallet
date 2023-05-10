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
        TonLib_V1_R1 = 1,
        TonLib_V2_R1 = 2,
        TonLib_V3_R1 = 3,
        TonLib_V3_R2 = 4,
        TonLib_V4_R2 = 5,
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

#include "backendmanager.h"
#include "tonlibbackend.h"

#include <QUuid>
#include <QDataStream>
#include <QCryptographicHash>
#include <QFile>

using namespace TON::Wallet;

QHash<QString, BackendManager::BackendUnit> BackendManager::mBackends;

QSharedPointer<AbstractWalletBackend> BackendManager::createFreeBackend(BackendType type)
{
    switch (static_cast<int>(type))
    {
    case TonLib_MainNet:
    case TonLib_TestNet:
        return QSharedPointer<AbstractWalletBackend>(new TonLibBackend);
        break;
    }

    return nullptr;
}

QSharedPointer<AbstractWalletBackend> BackendManager::createBackend(BackendType type, const QString &sourcePath, const std::function<void (bool, const AbstractWalletBackend::Error &)> &callback)
{
    const auto hash = createHash(type, sourcePath);
    {
        auto &u = mBackends[hash];
        if (u.initialized)
        {
            callback(u.done, u.error);
            return u.backend;
        }
        if (u.backend)
        {
            u.callbacks << callback;
            return u.backend;
        }
    }

    auto backend = createFreeBackend(type);
    if (!backend)
    {
        mBackends.remove(hash);
        return nullptr;
    }

    QObject::connect(backend.data(), &AbstractWalletBackend::destroyed, [hash](){
        mBackends.remove(hash);
    });

    QByteArray data;
    switch (static_cast<int>(type))
    {
    case TonLib_MainNet:
    {
        QFile f(":/ton/wallet/configs/global.config.json");
        f.open(QFile::ReadOnly);
        data = f.readAll();
        f.close();
    }
        break;

    case TonLib_TestNet:
    {
        QFile f(":/ton/wallet/configs/testnet.config.json");
        f.open(QFile::ReadOnly);
        data = f.readAll();
        f.close();
    }
        break;
    }

    auto &u = mBackends[hash];
    u.backend = backend;
    u.callbacks << callback;
    u.hash = createHash(type, sourcePath);

    backend->init(sourcePath, data, nullptr, [hash](bool done, const AbstractWalletBackend::Error &error){
        const auto &u = mBackends[hash];
        for (const auto &callback: u.callbacks)
            callback(done, error);
    });

    return u.backend;
}

QSharedPointer<AbstractWalletBackend> BackendManager::getBackend(const QString &hashId)
{
    return mBackends.value(hashId).backend.toStrongRef();
}

QString BackendManager::createHash(BackendType type, const QString &sourcePath)
{
    QByteArray d;
    QDataStream stream(&d, QIODevice::WriteOnly);
    stream << static_cast<int>(type);
    stream << sourcePath;

    return QCryptographicHash::hash(d, QCryptographicHash::Md5).toHex();
}

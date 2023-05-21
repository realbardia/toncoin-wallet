#include "walletbackend.h"
#include "core/wallet/backendmanager.h"

using namespace TON::Wallet;

WalletBackend::WalletBackend(QObject *parent)
    : AsemanQuickObject(parent)
{

}

WalletBackend::~WalletBackend()
{

}

QString WalletBackend::source() const
{
    return mSource;
}

void WalletBackend::setSource(const QString &newSource)
{
    if (mSource == newSource)
        return;
    mSource = newSource;
    reloadBackend();
    Q_EMIT sourceChanged();
}

int WalletBackend::backend() const
{
    return mBackend;
}

void WalletBackend::setBackend(int newBackend)
{
    if (mBackend == newBackend)
        return;
    mBackend = newBackend;
    reloadBackend();
    Q_EMIT backendChanged();
}

void WalletBackend::reset()
{
    if (!mBackendObject)
        mBackendObject = nullptr;

    if (mInitialized)
    {
        mInitialized = false;
        Q_EMIT initializedChanged();
    }
    if (!mErrorString.isEmpty())
    {
        mErrorString.clear();
        mError = 0;
        Q_EMIT errorChanged();
    }
    if (mInitializing)
    {
        mInitializing = false;
        Q_EMIT initializingChanged();
    }
}

bool WalletBackend::initializing() const
{
    return mInitializing;
}

QStringList WalletBackend::availableVersions() const
{
    if (!mBackendObject)
        return QStringList();
    return mBackendObject->availableVersions();
}

void WalletBackend::reloadBackend()
{
    reset();
    if (mSource.isEmpty())
        return;

    auto initCallback = [this](bool done, const AbstractWalletBackend::Error &error){
        if (!error.message.isEmpty())
        {
            mErrorString = error.message;
            mError = error.code;
            Q_EMIT errorChanged();
        }

        mInitialized = done;
        mInitializing = false;
        Q_EMIT initializedChanged();
        Q_EMIT initializingChanged();
    };

    if (mBackend == TonQmlGlobal::None)
        return;

    mBackendObject = BackendManager::createBackend(static_cast<BackendManager::BackendType>(mBackend), mSource, initCallback);
    if (!mBackendObject)
        return;

    mBackendObject->setWalletVersion(mWalletVersion);
    mInitializing = true;
    Q_EMIT availableVersionsChanged();
    Q_EMIT initializingChanged();
}

qint32 WalletBackend::error() const
{
    return mError;
}

QString WalletBackend::errorString() const
{
    return mErrorString;
}

bool WalletBackend::initialized() const
{
    return mInitialized;
}

QString WalletBackend::walletVersion() const
{
    return mWalletVersion;
}

void WalletBackend::setWalletVersion(const QString &newWalletVersion)
{
    if (mWalletVersion == newWalletVersion)
        return;
    mWalletVersion = newWalletVersion;
    if (mBackendObject)
        mBackendObject->setWalletVersion(mWalletVersion);
    Q_EMIT walletVersionChanged();
}

QSharedPointer<AbstractWalletBackend> WalletBackend::backendObject() const
{
    return mBackendObject;
}

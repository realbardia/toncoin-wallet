#include "keysmanager.h"

#include <QtQml>

using namespace TON::Wallet;

KeysManager::KeysManager(QObject *parent)
    : AsemanAbstractListModel(parent)
{

}

KeysManager::~KeysManager()
{

}

int KeysManager::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return count();
}

QVariant KeysManager::data(const QModelIndex &index, int role) const
{
    if (!mBackend)
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return QVariant();
    }

    const auto row = index.row();
    switch (role)
    {
    case RolePublicKey:
        return mKeys.at(row).publicKey;
    case RoleHasPassword:
    {
        auto backend = mBackend->backendObject();
        if (backend)
            return backend->hasPassword( QByteArray::fromBase64(mKeys.at(row).publicKey.toLatin1()) );
        else
        {
            qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
            return false;
        }
    }
        break;
    }

    return QVariant();
}

QHash<qint32, QByteArray> KeysManager::roleNames() const
{
    return {
        {RolePublicKey, "publicKey"},
        {RoleHasPassword, "hasPassword"},
    };
}

int KeysManager::count() const
{
    auto backend = mBackend->backendObject();
    if (backend)
        return backend->keys().count();
    else
        return 0;
}

void KeysManager::reload()
{
    beginResetModel();
    mKeys.clear();
    if (!mBackend)
    {
        Q_EMIT countChanged();
        return;
    }

    auto backend = mBackend->backendObject();
    if (backend && mBackend->initialized())
    {
        for (const auto &publicKey: backend->keys())
        {
            Key key;
            key.publicKey = QString::fromLatin1(publicKey.toBase64());

            mKeys << key;
        }
    }
    endResetModel();
    Q_EMIT countChanged();
}

bool KeysManager::createNewWallet()
{
    if (!mBackend)
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return false;
    }

    auto backend = mBackend->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return false;
    }

    mError = 0;
    mErrorString.clear();

    backend->createNewKey(this, [this](const QByteArray &publicKey, const AbstractWalletBackend::Error &error){
        if (publicKey.isEmpty())
        {
            mError = error.code;
            mErrorString = error.message;
            Q_EMIT errorChanged();
            Q_EMIT walletCreationFailed();
            setCreatingNewWallet(false);
            return;
        }

        beginInsertRows(QModelIndex(), count(), count()+1);
        Key key;
        key.publicKey = QString::fromLatin1(publicKey.toBase64());

        mKeys << key;
        endInsertRows();
        Q_EMIT countChanged();
        Q_EMIT walletCreatedSuccessfully(key.publicKey);
        setCreatingNewWallet(false);
    });

    setCreatingNewWallet(true);
    Q_EMIT errorChanged();
    return true;
}

bool KeysManager::importWallet(const QStringList &words)
{
    if (!mBackend)
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return false;
    }

    auto backend = mBackend->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return false;
    }

    mError = 0;
    mErrorString.clear();

    backend->importKeys(words, this, [this](const QByteArray &publicKey, const AbstractWalletBackend::Error &error){
        if (publicKey.isEmpty())
        {
            mError = error.code;
            mErrorString = error.message;
            Q_EMIT errorChanged();
            Q_EMIT walletImportFailed();
            setImportingWallet(false);
            return;
        }

        beginInsertRows(QModelIndex(), count(), count()+1);
        Key key;
        key.publicKey = QString::fromLatin1(publicKey.toBase64());

        mKeys << key;
        endInsertRows();
        Q_EMIT countChanged();
        Q_EMIT walletImportedSuccessfully(key.publicKey);
        setImportingWallet(false);
    });

    setImportingWallet(true);
    Q_EMIT errorChanged();

    return true;
}

bool KeysManager::creatingNewWallet() const
{
    return mCreatingNewWallet;
}

void KeysManager::setCreatingNewWallet(bool newCreatingNewWallet)
{
    if (mCreatingNewWallet == newCreatingNewWallet)
        return;
    mCreatingNewWallet = newCreatingNewWallet;
    Q_EMIT creatingNewWalletChanged();
}

bool KeysManager::importingWallet() const
{
    return mImportingWallet;
}

void KeysManager::setImportingWallet(bool newImportingWallet)
{
    if (mImportingWallet == newImportingWallet)
        return;
    mImportingWallet = newImportingWallet;
    Q_EMIT importingWalletChanged();
}

QString KeysManager::errorString() const
{
    return mErrorString;
}

qint32 KeysManager::error() const
{
    return mError;
}

WalletBackend *KeysManager::backend() const
{
    return mBackend;
}

void KeysManager::setBackend(WalletBackend *newBackend)
{
    if (mBackend == newBackend)
        return;
    if (mBackend)
        mBackend->disconnect(this);

    mBackend = newBackend;
    if (mBackend)
    {
        connect(mBackend, &WalletBackend::initializedChanged, this, &KeysManager::reload);
    }
    reload();
    Q_EMIT backendChanged();
}

#ifndef KEYSMANAGER_H
#define KEYSMANAGER_H

#include "tontoolkitabstractlistmodel.h"
#include "walletbackend.h"

#include <QPointer>

class KeysManager : public TonToolkitAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(WalletBackend *backend READ backend WRITE setBackend NOTIFY backendChanged)
    Q_PROPERTY(bool creatingNewWallet READ creatingNewWallet WRITE setCreatingNewWallet NOTIFY creatingNewWalletChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)

public:
    enum Roles {
        RolePublicKey = Qt::UserRole,
        RoleHasPassword,
    };
    Q_ENUM(Roles)

    KeysManager(QObject *parent = nullptr);
    virtual ~KeysManager();

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;
    int count() const;

    WalletBackend *backend() const;
    void setBackend(WalletBackend *newBackend);

    bool creatingNewWallet() const;

    qint32 error() const;
    QString errorString() const;

public Q_SLOTS:
    void reload();
    bool createNewWallet();

Q_SIGNALS:
    void countChanged();
    void backendChanged();
    void creatingNewWalletChanged();
    void walletCreatedSuccessfully(const QString &publicKey);
    void walletCreationFailed();
    void errorChanged();

protected:
    void setCreatingNewWallet(bool newCreatingNewWallet);

private:
    qint32 mError = 0;
    QString mErrorString;

    struct Key {
        QString publicKey;
    };

    bool mCreatingNewWallet = false;

    QList<Key> mKeys;
    QPointer<WalletBackend> mBackend;
};

#endif // KEYSMANAGER_H

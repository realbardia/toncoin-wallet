#ifndef ABSTRACTWALLETMODEL_H
#define ABSTRACTWALLETMODEL_H

#include "tontoolkitabstractlistmodel.h"
#include "walletbackend.h"

#include <QPointer>

class AbstractWalletModel : public TonToolkitAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(WalletBackend *backend READ backend WRITE setBackend NOTIFY backendChanged)
    Q_PROPERTY(QString publicKey READ publicKey WRITE setPublicKey NOTIFY publicKeyChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorChanged)
    Q_PROPERTY(qint32 error READ error NOTIFY errorChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool refreshing READ refreshing NOTIFY refreshingChanged)

public:
    AbstractWalletModel(QObject *parent = nullptr);
    virtual ~AbstractWalletModel();

    WalletBackend *backend() const;
    void setBackend(WalletBackend *newBackend);

    QString publicKey() const;
    void setPublicKey(const QString &newPublicKey);

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int count() const = 0;

    QString errorString() const;
    qint32 error() const;

    bool refreshing() const;

Q_SIGNALS:
    void backendChanged();
    void publicKeyChanged();
    void countChanged();
    void errorChanged();
    void refreshingChanged();

protected:
    virtual void reset() = 0;
    virtual void reload() = 0;

    void setError(qint32 code, const QString &message);
    void setRefreshing(bool newRefreshing);

private:
    void tryReload();

private:
    QPointer<WalletBackend> mBackend;
    QString mPublicKey;

    QString mErrorString;
    qint32 mError = 0;

    bool mRefreshing = false;
};

#endif // ABSTRACTWALLETMODEL_H

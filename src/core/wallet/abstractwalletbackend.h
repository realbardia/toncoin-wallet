#ifndef ABSTRACTWALLETBACKEND_H
#define ABSTRACTWALLETBACKEND_H

#include <QDateTime>
#include <QObject>

namespace TON::Wallet
{

class AbstractWalletBackend : public QObject
{
    Q_OBJECT
public:
    struct Error {
        qint32 code = 0;
        QString message;
    };

    struct TransactionId {
        qint64 id = 0;
        QByteArray hash;
    };

    struct AccountState {
        QString address;
        qreal balance = 0;
        QDateTime datetime;
        TransactionId lastTransaction;
    };

    struct Transaction {
        TransactionId id;
        QString source;
        QString destination;
        qreal value = 0;
        QDateTime datetime;
        QByteArray body_hash;
        qreal fee = 0;
        qreal storage_fee = 0;
        qreal other_fee = 0;
        QString message;
        QByteArray raw_message;
        bool sent = false;
        bool initializeWallet = false;
    };

    struct Fee {
        qreal in_fwd_fee = 0;
        qreal storage_fee = 0;
        qreal gas_fee = 0;
        qreal fwd_fee = 0;
    };

    AbstractWalletBackend(QObject *parent = nullptr);
    virtual ~AbstractWalletBackend();

    virtual void init(const QString &keysDir, const QByteArray &configs, QObject *receiver, const std::function<void(bool done, const Error &error)> &callback) = 0;

    virtual void createNewKey(QObject *receiver, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;
    virtual void deleteKey(const QByteArray &publicKey, QObject *receiver, const std::function<void(bool done, const Error &error)> &callback) = 0;
    virtual void exportKey(const QByteArray &publicKey, QObject *receiver, const std::function<void(const QStringList &keys, const Error &error)> &callback) = 0;
    virtual void importKeys(const QStringList &words, QObject *receiver, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;

    virtual void getAddress(const QByteArray &publicKey, QObject *receiver, const std::function<void(const QString &address, const Error &error)> &callback) = 0;
    virtual void getAccountState(const QString &address, QObject *receiver, const std::function<void(const AccountState &state, const Error &error)> &callback) = 0;

    virtual void getTransactions(const QByteArray &publicKey, const TransactionId &from, int count, QObject *receiver, const std::function<void(const QList<Transaction> &list, const Error &error)> &callback) = 0;
    virtual void estimateTransfer(const QByteArray &publicKey, const QString &destinationAddress, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void(const Fee &fee, const Error &error)> &callback) = 0;
    virtual void doTransfer(const QByteArray &publicKey, const QString &destinationAddress, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void(const QByteArray &bodyHash, const Error &error)> &callback) = 0;

    virtual void changeLocalPassword(const QByteArray &publicKey, const QString &password, QObject *receiver, const std::function<void(const QByteArray &newPublicKey, const Error &error)> &callback) = 0;

    virtual QList<QByteArray> keys() const = 0;
    virtual QStringList words() const = 0;
    virtual QStringList availableVersions() const = 0;

    virtual void unlockUsingPassword(const QByteArray &publicKey, const QString &password) = 0;
    virtual bool hasPassword(const QByteArray &publicKey) = 0;
    virtual bool testPassword(const QByteArray &publicKey, const QString &password) = 0;

    virtual QString walletVersion() const;
    virtual void setWalletVersion(const QString &newWalletVersion);

private:
    QString mWalletVersion;
};

}

#endif // ABSTRACTWALLETBACKEND_H

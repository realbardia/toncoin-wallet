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
        qreal fee = 0;
        qreal storage_fee = 0;
        qreal other_fee = 0;
        QString message;
        bool sent = false;
    };

    AbstractWalletBackend(QObject *parent = nullptr);
    virtual ~AbstractWalletBackend();

    virtual void init(const QString &keysDir, const QByteArray &configs, const std::function<void(bool done, const Error &error)> &callback) = 0;

    virtual void createNewKey(const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;
    virtual void deleteKey(const QByteArray &publicKey, const std::function<void(bool done, const Error &error)> &callback) = 0;
    virtual void exportKey(const QByteArray &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback) = 0;
    virtual void importKeys(const QStringList &words, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;

    virtual void getAddress(const QByteArray &publicKey, const std::function<void(const QString &address, const Error &error)> &callback) = 0;
    virtual void getAccountState(const QString &address, const std::function<void(const AccountState &state, const Error &error)> &callback) = 0;

    virtual void getTransactions(const QByteArray &publicKey, const TransactionId &from, int count, const std::function<void(const QList<Transaction> &list, const Error &error)> &callback) = 0;

    virtual void changeLocalPassword(const QByteArray &publicKey, const QString &password, const std::function<void(const QByteArray &newPublicKey, const Error &error)> &callback) = 0;

    virtual QList<QByteArray> keys() const = 0;
    virtual QStringList words() const = 0;

    virtual void unlockUsingPassword(const QByteArray &publicKey, const QString &password) = 0;
    virtual bool hasPassword(const QByteArray &publicKey) = 0;
    virtual bool testPassword(const QByteArray &publicKey, const QString &password) = 0;
};

}

#endif // ABSTRACTWALLETBACKEND_H

#ifndef TONLIBBACKEND_H
#define TONLIBBACKEND_H

#include "abstractwalletbackend.h"

#include <QHash>

namespace TON::Wallet
{

class TonLibBackend: public AbstractWalletBackend
{
    class Engine;
    class Private;

public:
    TonLibBackend(QObject *parent = nullptr);
    virtual ~TonLibBackend();

    void init(const QString &keysDir, const QByteArray &configs, QObject *receiver, const std::function<void(bool done, const Error &error)> &callback) override;

    void createNewKey(QObject *receiver, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) override;
    void deleteKey(const QByteArray &publicKey, QObject *receiver, const std::function<void(bool done, const Error &error)> &callback) override;
    void exportKey(const QByteArray &publicKey, QObject *receiver, const std::function<void(const QStringList &keys, const Error &error)> &callback) override;
    void importKeys(const QStringList &words, QObject *receiver, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) override;

    void getAddress(const QByteArray &publicKey, QObject *receiver, const std::function<void(const QString &address, const Error &error)> &callback) override;
    void getAccountState(const QString &address, QObject *receiver, const std::function<void(const AccountState &state, const Error &error)> &callback) override;
    void getPrivateKey(const QByteArray &publicKey, QObject *receiver, const std::function<void(const QByteArray &privateKey, const Error &error)> &callback) override;

    void getTransactions(const QByteArray &publicKey, const TransactionId &from, int count, QObject *receiver, const std::function<void(const QList<Transaction> &list, const Error &error)> &callback) override;
    void estimateTransfer(const QByteArray &publicKey, const QString &destinationAddress, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void(const Fee &fee, const Error &error)> &callback) override;
    void doTransfer(const QByteArray &publicKey, const QString &destinationAddress, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void(const QByteArray &bodyHash, const Error &error)> &callback) override;

    void changeLocalPassword(const QByteArray &publicKey, const QString &password, QObject *receiver, const std::function<void(const QByteArray &newPublicKey, const Error &error)> &callback) override;

    QList<QByteArray> keys() const override;
    QStringList words() const override;
    QStringList availableVersions() const override;
    QByteArray getInitState(const QByteArray &publicKey) const override;

    void unlockUsingPassword(const QByteArray &publicKey, const QString &password) override;
    bool hasPassword(const QByteArray &publicKey) override;
    bool testPassword(const QByteArray &publicKey, const QString &password) override;

protected:
    void storeKeys();
    void loadKeys();

    struct PreparedTransferItem {
        qint64 id;
        QByteArray body_hash;
    };

    void prepareTransfer(const QByteArray &publicKey, const QString &destinationAddress, qreal value, const QString &message, bool encryption, bool force, QObject *receiver, const std::function<void(const PreparedTransferItem &item, const Error &error)> &callback);

private:
    QString mKeysDir;

    Engine *mEngine;
    Private *p;

    const static std::string v4r2_code;
    const static std::string v4r1_code;
};

}

#endif // TONLIBBACKEND_H

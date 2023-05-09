#ifndef ABSTRACTWALLETBACKEND_H
#define ABSTRACTWALLETBACKEND_H

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

    AbstractWalletBackend(QObject *parent = nullptr);
    virtual ~AbstractWalletBackend();

    virtual void init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback) = 0;

    virtual void createNewKey(const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;
    virtual void deleteKey(const QByteArray &publicKey, const std::function<void(bool done, const Error &error)> &callback) = 0;
    virtual void exportKey(const QByteArray &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback) = 0;
    virtual void importKeys(const QStringList &words, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) = 0;
    virtual void getAddress(const QByteArray &publicKey, const std::function<void(const QString &address, const Error &error)> &callback) = 0;

    virtual void changeLocalPassword(const QByteArray &publicKey, const QString &password, const std::function<void(const QByteArray &newPublicKey, const Error &error)> &callback) = 0;

    virtual QList<QByteArray> keys() const = 0;

    virtual void setPassword(const QByteArray &publicKey, const QString &newPassword) = 0;
    virtual bool hasPassword(const QByteArray &publicKey) = 0;
    virtual bool testPassword(const QByteArray &publicKey, const QString &password) = 0;
};

}

#endif // ABSTRACTWALLETBACKEND_H

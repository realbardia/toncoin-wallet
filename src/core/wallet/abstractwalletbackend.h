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

    virtual void createNewKey(const std::function<void(const QString &publicKey, const Error &error)> &callback) = 0;
    virtual void exportKey(const QString &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback) = 0;
    virtual void importKeys(const QStringList &words, const std::function<void(const QString &publicKey, const Error &error)> &callback) = 0;
    virtual void getAddress(const QString &publicKey, const std::function<void(const QString &publicKey, const Error &error)> &callback) = 0;

    virtual void changeLocalPassword(const QString &publicKey, const QString &password, const std::function<void(bool done, const Error &error)> &callback) = 0;

    virtual QStringList keys() const = 0;

    virtual void setPassword(const QString &publicKey, const QString &newPassword) = 0;
    virtual bool hasPassword(const QString &publicKey) = 0;
};

}

#endif // ABSTRACTWALLETBACKEND_H

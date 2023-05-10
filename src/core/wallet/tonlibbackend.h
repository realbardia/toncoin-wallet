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
    TonLibBackend(int version, int revision, QObject *parent = nullptr);
    virtual ~TonLibBackend();

    void init(const QString &keysDir, const QByteArray &configs, const std::function<void(bool done, const Error &error)> &callback) override;

    void createNewKey(const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) override;
    void deleteKey(const QByteArray &publicKey, const std::function<void(bool done, const Error &error)> &callback) override;
    void exportKey(const QByteArray &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback) override;
    void importKeys(const QStringList &words, const std::function<void(const QByteArray &publicKey, const Error &error)> &callback) override;
    void getAddress(const QByteArray &publicKey, const std::function<void(const QString &address, const Error &error)> &callback) override;

    void changeLocalPassword(const QByteArray &publicKey, const QString &password, const std::function<void(const QByteArray &newPublicKey, const Error &error)> &callback) override;

    QList<QByteArray> keys() const override;

    void unlockUsingPassword(const QByteArray &publicKey, const QString &password) override;
    bool hasPassword(const QByteArray &publicKey) override;
    bool testPassword(const QByteArray &publicKey, const QString &password) override;

protected:
    void storeKeys();
    void loadKeys();

private:
    QString mKeysDir;

    Engine *mEngine;
    Private *p;
};

}

#endif // TONLIBBACKEND_H

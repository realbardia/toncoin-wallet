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

    void init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback) override;

    void createNewKey(const std::function<void(const QString &publicKey, const Error &error)> &callback) override;
    void exportKey(const QString &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback) override;
    void importKeys(const QStringList &words, const std::function<void(const QString &publicKey, const Error &error)> &callback) override;
    void getAddress(const QString &publicKey, const std::function<void(const QString &publicKey, const Error &error)> &callback) override;

    void changeLocalPassword(const QString &publicKey, const QString &password, const std::function<void(bool done, const Error &error)> &callback) override;

    QStringList keys() const override;

    void setPassword(const QString &publicKey, const QString &newPassword) override;
    bool hasPassword(const QString &publicKey) override;

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

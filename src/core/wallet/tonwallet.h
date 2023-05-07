#ifndef TONWALLET_H
#define TONWALLET_H

#include "abstractwallet.h"

#include <QHash>

namespace ton::tonlib_api
{
class key;
}

namespace TON::Wallet
{

class TonWallet: public Abstracts::AbstractWallet
{
    class Engine;
    class Private;

public:
    struct Error {
        qint32 code = 0;
        QString message;
    };

    TonWallet(QObject *parent = nullptr);
    virtual ~TonWallet();

    void init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback);

    void createNewKey(const std::function<void(const QString &publicKey, const Error &error)> &callback);
    void exportKey(const QString &publicKey, const std::function<void(const QStringList &keys, const Error &error)> &callback);
    void getAddress(const QString &publicKey, const std::function<void(const QString &publicKey, const Error &error)> &callback);

    void changeLocalPassword(const QString &publicKey, const QString &password, const std::function<void(bool done, const Error &error)> &callback);

    QStringList keys() const;

    QString password(const QString &publicKey) const;
    void setPassword(const QString &publicKey, const QString &newPassword);

protected:
    void storeKeys();
    void loadKeys();

private:
    QString mKeysDir;

    Engine *mEngine;
    Private *p;
};

}

#endif // TONWALLET_H

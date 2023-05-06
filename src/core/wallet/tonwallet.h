#ifndef TONWALLET_H
#define TONWALLET_H

#include "abstractwallet.h"

namespace TON::Wallet
{

class TonWallet: public Abstracts::AbstractWallet
{
    class Engine;

public:
    struct Error {
        qint32 code = 0;
        QString message;
    };

    TonWallet(QObject *parent = nullptr);
    virtual ~TonWallet();

    void init(const QString &keysDir, const std::function<void(bool done, const Error &error)> &callback);

private:
    Engine *mEngine;
};

}

#endif // TONWALLET_H

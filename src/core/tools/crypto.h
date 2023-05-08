#ifndef NEOCRYPTO_H
#define NEOCRYPTO_H

#include <QString>

namespace TON::Tools
{

class CryptoAES
{
public:
    CryptoAES(const QString &key);

    QByteArray encrypt(const QByteArray &data) const;
    QByteArray decrypt(const QByteArray &data) const;

private:
    const QString mKey;
};

}

#endif // NEOCRYPTO_H

#ifndef NEOCRYPTO_H
#define NEOCRYPTO_H

#include <string>
#include <memory>

namespace TON::Tools
{

class CryptoAES
{
public:
    CryptoAES(const std::string &key);

    std::string encrypt(const std::string &data) const;
    std::string decrypt(const std::string &data) const;

private:
    const std::string mKey;
};

}

#endif // NEOCRYPTO_H

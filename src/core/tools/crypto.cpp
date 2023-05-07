#include "crypto.h"

#include <openssl/aes.h>
#include <openssl/pem.h>
#include <openssl/bn.h>
#include <openssl/rand.h>

#include <fstream>
#include <unordered_map>
#include <math.h>
#include <iostream>

#define ENCRYPT_PAYLOAD_SIZE 112
#define DECRYPT_PAYLOAD_SIZE 128
#define RSA_DEFAULT_KEY_SIZE 1024

using namespace std::string_literals;

const std::string publicKeyHeader = "-----BEGIN RSA PUBLIC KEY-----\n"s;
const std::string publicKeyFooter = "\n-----END RSA PUBLIC KEY-----\n"s;
const std::string privateKeyHeader = "-----BEGIN RSA PRIVATE KEY-----\n"s;
const std::string privateKeyFooter = "\n-----END RSA PRIVATE KEY-----\n"s;


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

std::string _aes_encrypt(const std::string& data, const std::string& password)
{
    // Key and IV setup
    const unsigned char* key_data = (const unsigned char*)password.c_str();
    const unsigned char* iv = (const unsigned char*)"0123456789012345";
    EVP_CIPHER_CTX* ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        throw std::runtime_error("EVP_CIPHER_CTX_new failed");
    }
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_data, iv)) {
        throw std::runtime_error("EVP_EncryptInit_ex failed");
    }

    // Encrypt
    std::string ciphertext;
    int len;
    int max_len = data.size() + AES_BLOCK_SIZE;
    ciphertext.resize(max_len);
    if (1 != EVP_EncryptUpdate(ctx, (unsigned char*)&ciphertext[0], &len, (const unsigned char*)data.c_str(), data.size())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_EncryptUpdate failed");
    }
    int ciphertext_len = len;
    if (1 != EVP_EncryptFinal_ex(ctx, (unsigned char*)&ciphertext[0] + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_EncryptFinal_ex failed");
    }
    ciphertext_len += len;
    ciphertext.resize(ciphertext_len);
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

std::string _aes_decrypt(const std::string& ciphertext, const std::string& password) {
    // Key and IV setup
    const unsigned char* key_data = (const unsigned char*)password.c_str();
    const unsigned char* iv = (const unsigned char*)"0123456789012345";
    EVP_CIPHER_CTX* ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        throw std::runtime_error("EVP_CIPHER_CTX_new failed");
    }
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_data, iv)) {
        throw std::runtime_error("EVP_DecryptInit_ex failed");
    }

    // Decrypt
    std::string plaintext;
    int len;
    int max_len = ciphertext.size();
    plaintext.resize(max_len);
    if (1 != EVP_DecryptUpdate(ctx, (unsigned char*)&plaintext[0], &len, (const unsigned char*)ciphertext.c_str(), ciphertext.size())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_DecryptUpdate failed");
    }
    int plaintext_len = len;
    if (1 != EVP_DecryptFinal_ex(ctx, (unsigned char*)&plaintext[0] + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_DecryptFinal_ex failed");
    }
    plaintext_len += len;
    plaintext.resize(plaintext_len);
    EVP_CIPHER_CTX_free(ctx);

    return plaintext;
}

#pragma GCC diagnostic pop

TON::Tools::CryptoAES::CryptoAES(const std::string &key)
    : mKey(key)
{

}

std::string TON::Tools::CryptoAES::encrypt(const std::string &data) const
{
    return _aes_encrypt(data, mKey);
}

std::string TON::Tools::CryptoAES::decrypt(const std::string &data) const
{
    return _aes_decrypt(data, mKey);
}

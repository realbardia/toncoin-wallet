#include "abstractwalletbackend.h"

using namespace TON::Wallet;

AbstractWalletBackend::AbstractWalletBackend(QObject *parent)
    : QObject{parent}
{

}

AbstractWalletBackend::~AbstractWalletBackend()
{

}

QString AbstractWalletBackend::walletVersion() const
{
    return mWalletVersion;
}

void AbstractWalletBackend::setWalletVersion(const QString &newWalletVersion)
{
    mWalletVersion = newWalletVersion;
}

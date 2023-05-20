#include "abstractwalletbackend.h"

using namespace TON::Wallet;

AbstractWalletBackend::AbstractWalletBackend(QObject *parent)
    : QObject{parent}
{

}

AbstractWalletBackend::~AbstractWalletBackend()
{

}

QByteArray AbstractWalletBackend::getInitState(const QByteArray &) const
{
    return QByteArray();
}

QString AbstractWalletBackend::walletVersion() const
{
    return mWalletVersion;
}

void AbstractWalletBackend::setWalletVersion(const QString &newWalletVersion)
{
    mWalletVersion = newWalletVersion;
}

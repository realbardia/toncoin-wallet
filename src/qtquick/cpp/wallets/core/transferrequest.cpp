#include "transferrequest.h"

#include <QtQml>

using namespace TON::Wallet;

TransferRequest::TransferRequest(QObject *parent)
    : AbstractActionItem(parent)
{

}

TransferRequest::~TransferRequest()
{

}

bool TransferRequest::force() const
{
    return mForce;
}

void TransferRequest::setForce(bool newForce)
{
    if (mForce == newForce)
        return;
    mForce = newForce;
    Q_EMIT forceChanged();
}

bool TransferRequest::transfer()
{
    auto backend = beginAction();
    if (!backend)
        return false;

    const auto pkey = QByteArray::fromBase64(wallet()->publicKey().toLatin1());
    backend->doTransfer(pkey, mDestinationAddress, mAmount.toDouble(), mMessage, false, mForce, this, [this](const QByteArray &bodyHash, const AbstractWalletBackend::Error &err){
        endAction();
        if (err.code)
        {
            setError(err.code, err.message);
            Q_EMIT transferFailed();
            return;
        }

        if (bodyHash.size())
            Q_EMIT transferFinishedSucessfully(bodyHash, QString::fromLatin1(bodyHash.toBase64()));
        else
            Q_EMIT transferFailed();
    });

    return true;
}

QString TransferRequest::message() const
{
    return mMessage;
}

void TransferRequest::setMessage(const QString &newMessage)
{
    if (mMessage == newMessage)
        return;
    mMessage = newMessage;
    Q_EMIT messageChanged();
}

QString TransferRequest::amount() const
{
    return mAmount;
}

void TransferRequest::setAmount(const QString &newAmount)
{
    if (mAmount == newAmount)
        return;
    mAmount = newAmount;
    Q_EMIT amountChanged();
}

QString TransferRequest::destinationAddress() const
{
    return mDestinationAddress;
}

void TransferRequest::setDestinationAddress(const QString &newDestinationAddress)
{
    if (mDestinationAddress == newDestinationAddress)
        return;
    mDestinationAddress = newDestinationAddress;
    Q_EMIT destinationAddressChanged();
}

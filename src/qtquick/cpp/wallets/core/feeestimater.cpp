#include "feeestimater.h"

#include <QtQml>

using namespace TON::Wallet;

FeeEstimater::FeeEstimater(QObject *parent) :
    AbstractActionItem(parent)
{

}

FeeEstimater::~FeeEstimater()
{

}

bool FeeEstimater::estimate()
{
    auto backend = beginAction();
    if (!backend)
        return false;

    const auto pkey = QByteArray::fromBase64(wallet()->publicKey().toLatin1());
    backend->estimateTransfer(pkey, mDestinationAddress, mAmount.toDouble(), mMessage, false, mForce, [this](const AbstractWalletBackend::Fee &fee, const AbstractWalletBackend::Error &err){
        endAction();
        mGasFee = fee.gas_fee;
        mStorageFee = fee.storage_fee;
        mInFwdFee = fee.in_fwd_fee;
        mFwdFee = fee.fwd_fee;
        Q_EMIT feeChanged();
    });

    return true;
}

QString FeeEstimater::fwdFee() const
{
    return mFwdFee;
}

QString FeeEstimater::gasFee() const
{
    return mGasFee;
}

QString FeeEstimater::storageFee() const
{
    return mStorageFee;
}

QString FeeEstimater::inFwdFee() const
{
    return mInFwdFee;
}

bool FeeEstimater::force() const
{
    return mForce;
}

void FeeEstimater::setForce(bool newForce)
{
    if (mForce == newForce)
        return;
    mForce = newForce;
    Q_EMIT forceChanged();
}

QString FeeEstimater::message() const
{
    return mMessage;
}

void FeeEstimater::setMessage(const QString &newMessage)
{
    if (mMessage == newMessage)
        return;
    mMessage = newMessage;
    Q_EMIT messageChanged();
}

QString FeeEstimater::amount() const
{
    return mAmount;
}

void FeeEstimater::setAmount(const QString &newAmount)
{
    if (mAmount == newAmount)
        return;
    mAmount = newAmount;
    Q_EMIT amountChanged();
}

QString FeeEstimater::destinationAddress() const
{
    return mDestinationAddress;
}

void FeeEstimater::setDestinationAddress(const QString &newDestinationAddress)
{
    if (mDestinationAddress == newDestinationAddress)
        return;
    mDestinationAddress = newDestinationAddress;
    Q_EMIT destinationAddressChanged();
}

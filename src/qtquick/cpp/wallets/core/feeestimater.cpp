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
    backend->estimateTransfer(pkey, mDestinationAddress, mAmount.toDouble(), mMessage, false, mForce, this, [this](const AbstractWalletBackend::Estimate &fee, const AbstractWalletBackend::Error &err){
        endAction();
        if (err.code)
        {
            setError(err.code, err.message);
            return;
        }

        mGasFee = QString::number(fee.gas_fee, 'f', 9).remove(QRegularExpression("(?:\\.)0+$")).trimmed();
        mStorageFee = QString::number(fee.storage_fee, 'f', 9).remove(QRegularExpression("(?:\\.)0+$"));
        mInFwdFee = QString::number(fee.in_fwd_fee, 'f', 9).remove(QRegularExpression("(?:\\.)0+$"));
        mFwdFee = QString::number(fee.fwd_fee, 'f', 9).remove(QRegularExpression("(?:\\.)0+$"));
        mFee = QString::number(fee.gas_fee + fee.storage_fee + fee.in_fwd_fee + fee.fwd_fee, 'f', 9).remove(QRegularExpression("(?:\\.)0+$"));
        mFinalAddress = fee.finalAddress;
        Q_EMIT feeChanged();
        Q_EMIT finalAddressChanged();
    });

    return true;
}

QString FeeEstimater::finalAddress() const
{
    return mFinalAddress;
}

QString FeeEstimater::fwdFee() const
{
    return mFwdFee;
}

QString FeeEstimater::fee() const
{
    return mFee;
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

#ifndef FEEESTIMATER_H
#define FEEESTIMATER_H

#include "abstractactionitem.h"

class FeeEstimater : public AbstractActionItem
{
    Q_OBJECT
    Q_PROPERTY(QString destinationAddress READ destinationAddress WRITE setDestinationAddress NOTIFY destinationAddressChanged)
    Q_PROPERTY(QString amount READ amount WRITE setAmount NOTIFY amountChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(bool force READ force WRITE setForce NOTIFY forceChanged)
    Q_PROPERTY(QString inFwdFee READ inFwdFee NOTIFY feeChanged)
    Q_PROPERTY(QString storageFee READ storageFee NOTIFY feeChanged)
    Q_PROPERTY(QString gasFee READ gasFee NOTIFY feeChanged)
    Q_PROPERTY(QString fwdFee READ fwdFee NOTIFY feeChanged)
    Q_PROPERTY(QString fee READ fee NOTIFY feeChanged)

public:
    FeeEstimater(QObject *parent = nullptr);
    virtual ~FeeEstimater();

    QString destinationAddress() const;
    void setDestinationAddress(const QString &newDestinationAddress);

    QString amount() const;
    void setAmount(const QString &newAmount);

    QString message() const;
    void setMessage(const QString &newMessage);

    bool force() const;
    void setForce(bool newForce);

    QString inFwdFee() const;
    QString storageFee() const;
    QString gasFee() const;
    QString fwdFee() const;
    QString fee() const;

public Q_SLOTS:
    bool estimate();

Q_SIGNALS:
    void destinationAddressChanged();
    void amountChanged();
    void messageChanged();
    void forceChanged();
    void feeChanged();

protected:

private:
    bool mForce = false;
    QString mDestinationAddress;
    QString mAmount;
    QString mMessage;

    QString mInFwdFee;
    QString mStorageFee;
    QString mGasFee;
    QString mFwdFee;
    QString mFee;
};

#endif // FEEESTIMATER_H

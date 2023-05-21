#ifndef TRANSFERREQUEST_H
#define TRANSFERREQUEST_H

#include "abstractactionitem.h"

class TransferRequest : public AbstractActionItem
{
    Q_OBJECT
    Q_PROPERTY(QString destinationAddress READ destinationAddress WRITE setDestinationAddress NOTIFY destinationAddressChanged)
    Q_PROPERTY(QString amount READ amount WRITE setAmount NOTIFY amountChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(bool force READ force WRITE setForce NOTIFY forceChanged)

public:
    TransferRequest(QObject *parent = nullptr);
    virtual ~TransferRequest();

    QString destinationAddress() const;
    void setDestinationAddress(const QString &newDestinationAddress);

    QString amount() const;
    void setAmount(const QString &newAmount);

    QString message() const;
    void setMessage(const QString &newMessage);

    bool force() const;
    void setForce(bool newForce);

public Q_SLOTS:
    bool transfer();

Q_SIGNALS:
    void destinationAddressChanged();
    void amountChanged();
    void messageChanged();
    void forceChanged();

    void transferFinishedSucessfully(const QByteArray &bodyHash, const QString &bodyHash_base64);
    void transferFailed();

private:
    bool mForce = false;
    QString mDestinationAddress;
    QString mAmount;
    QString mMessage;
};

#endif // TRANSFERREQUEST_H

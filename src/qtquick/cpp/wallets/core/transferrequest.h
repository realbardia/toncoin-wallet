#ifndef TRANSFERREQUEST_H
#define TRANSFERREQUEST_H

#include <QObject>

class TransferRequest : public QObject
{
    Q_OBJECT
public:
    TransferRequest(QObject *parent = nullptr);

Q_SIGNALS:

};

#endif // TRANSFERREQUEST_H

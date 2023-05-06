#ifndef ABSTRACTWALLET_H
#define ABSTRACTWALLET_H

#include <QObject>

namespace TON::Wallet::Abstracts
{

class AbstractWallet : public QObject
{
    Q_OBJECT
public:
    AbstractWallet(QObject *parent = nullptr);
    virtual ~AbstractWallet();

};

}

#endif // ABSTRACTWALLET_H

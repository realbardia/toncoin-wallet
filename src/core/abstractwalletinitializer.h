#ifndef ABSTRACTWALLETINITIALIZER_H
#define ABSTRACTWALLETINITIALIZER_H

#include <QObject>

namespace TON::Wallet::Abstracts
{

class AbstractWalletInitializer : public QObject
{
    Q_OBJECT
public:
    AbstractWalletInitializer(QObject *parent = nullptr);
    virtual ~AbstractWalletInitializer();

Q_SIGNALS:

};

}

#endif // ABSTRACTWALLETINITIALIZER_H

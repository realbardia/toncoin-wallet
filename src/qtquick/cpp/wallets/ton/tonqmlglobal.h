#ifndef TONQMLGLOBAL_H
#define TONQMLGLOBAL_H

#include <QObject>

#include "core/wallet/backendmanager.h"

class TonQmlGlobal : public QObject
{
    Q_OBJECT
public:
    enum WalletBackend {
        None = 0,
        LibTon = TON::Wallet::BackendManager::LibTon,
    };
    Q_ENUM(WalletBackend)

    TonQmlGlobal(QObject *parent = nullptr);
    virtual ~TonQmlGlobal();
};

#endif // TONQMLGLOBAL_H

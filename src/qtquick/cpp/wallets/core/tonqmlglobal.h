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
        TonLib_MainNet = TON::Wallet::BackendManager::TonLib_MainNet,
        TonLib_TestNet = TON::Wallet::BackendManager::TonLib_TestNet,
    };
    Q_ENUM(WalletBackend)

    TonQmlGlobal(QObject *parent = nullptr);
    virtual ~TonQmlGlobal();
};

#endif // TONQMLGLOBAL_H

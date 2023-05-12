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
        TonLib_V1R1 = TON::Wallet::BackendManager::TonLib_V1_R1,
        TonLib_V2_R1 = TON::Wallet::BackendManager::TonLib_V2_R1,
        TonLib_V3_R1 = TON::Wallet::BackendManager::TonLib_V3_R1,
        TonLib_V3_R2 = TON::Wallet::BackendManager::TonLib_V3_R2,
        TonLib_V4_R2 = TON::Wallet::BackendManager::TonLib_V4_R2,
    };
    Q_ENUM(WalletBackend)

    TonQmlGlobal(QObject *parent = nullptr);
    virtual ~TonQmlGlobal();
};

#endif // TONQMLGLOBAL_H

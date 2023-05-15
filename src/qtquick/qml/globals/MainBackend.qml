pragma Singleton

import Toolkit.Core 1.0
import Wallet.Core 1.0

Backend {
    id: dis
    source: TonToolkitApp.homePath + "/ton"
    backend: TonQmlGlobal.TonLib
    walletVersion: AppSettings.walletVersion

    property alias keysManager: keysManager

    function start() {}

    KeysManager {
        id: keysManager
        backend: dis
    }
}

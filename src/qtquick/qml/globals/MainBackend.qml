pragma Singleton

import Wallet.Core 1.0

Backend {
    id: dis
    source: "/home/bardia/Desktop/test"
    backend: TonQmlGlobal.TonLib

    property alias keysManager: keysManager

    function start() {}

    KeysManager {
        id: keysManager
        backend: dis
    }
}

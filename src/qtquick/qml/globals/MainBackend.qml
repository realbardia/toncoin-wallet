pragma Singleton

import Toolkit.Core 1.0
import Wallet.Core 1.0

Backend {
    id: dis
    source: TonToolkitApp.homePath + (Constants.testNet? "/ton-test" : "/ton")
    backend: Constants.testNet? TonQmlGlobal.TonLib_TestNet : TonQmlGlobal.TonLib_MainNet
    walletVersion: AppSettings.walletVersion

    property alias keysManager: keysManager

    function start() {}

    KeysManager {
        id: keysManager
        backend: dis
    }
}

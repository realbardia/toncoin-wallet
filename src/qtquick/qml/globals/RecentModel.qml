pragma Singleton

import Toolkit.Core 1.0
import Wallet.Core 1.0

RecentAddressesModel {
    cachePath: AsemanApp.homePath + "/recents"
    password: GlobalValues.passCode
    limit: 5
}

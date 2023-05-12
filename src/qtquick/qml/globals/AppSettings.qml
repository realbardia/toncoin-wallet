pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

Settings {
    category: "General"
    source: TonToolkitApp.homePath + "/settings.ini"

    property int theme: 0

    property real width: 380
    property real height: 680

    property string loggedInPublicKey
    property string privateKey
    property string publicKey

    property string currency: "usd"
    property string walletVersion: "v3R2"

    property real currencyPrice: 0
    property string balance: "0.00000"
    property string address

    property int passCodeLength
    property bool touchId
}

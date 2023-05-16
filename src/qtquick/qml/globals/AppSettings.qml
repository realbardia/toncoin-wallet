pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

Settings {
    category: "General"
    source: TonToolkitApp.homePath + "/settings.ini"

    property bool darkMode: false
    property string language: "en"

    property real width: 380
    property real height: 680

    property int lockTimeout: 60

    property string loggedInPublicKey
    property string privateKey
    property string publicKey

    property string currency: "usd"
    property string walletVersion: "v4R2"

    property real currencyPrice: 0
    property string balance: "0.00000"
    property string address

    property int passCodeLength
    property bool touchId
    property string touchIdSecureKey
}

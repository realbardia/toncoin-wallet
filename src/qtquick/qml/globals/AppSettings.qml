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

    property bool touchId
}

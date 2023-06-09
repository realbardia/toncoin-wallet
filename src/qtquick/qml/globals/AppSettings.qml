pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

Settings {
    category: "General"
    source: AsemanApp.homePath + (Constants.testNet? "/settings.test.ini" : "/settings.ini")

    property bool darkMode: false
    property string language: "en"
    property bool frameless
    property bool inited

    property real width: 380
    property real height: 680

    property int lockTimeout: 60

    property string loggedInPublicKey

    property string lastEventId

    property string currency: "usd"
    property string walletVersion: "v4R2"

    property real currencyPrice: 0
    property string balance: "0.00000"
    property string address

    property int passCodeLength
    property bool touchId
    property string touchIdSecureKey

    property bool newlyCreatedWallet

    function reset() {
        loggedInPublicKey = "";
        walletVersion = "v4R2";
        balance = "0.00000";
        address = "";
        passCodeLength = 0;
        touchId = false;
        touchIdSecureKey = "";
        newlyCreatedWallet = false;
    }

    Component.onCompleted: {
        if (inited)
            return;

        if (Constants.framelessSupported)
            frameless = true;

        inited = true;
    }
}

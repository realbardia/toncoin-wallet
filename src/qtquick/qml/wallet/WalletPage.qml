import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    id: dis
    color: "#000"

    property alias viewport: viewport
    property string publicKey

    Component.onCompleted: if (GlobalValues.passCode.length) walletLoader.active = true

    function checkLockScreen() {
        var current = Tools.dateToSec(new Date);
        var lastEvent = Tools.dateToSec(keySpy.lastEvent);

        var time = Math.max(30, Math.min(300, AppSettings.lockTimeout))
        if (current - lastEvent < time && current >= lastEvent)
            return false;

        GlobalValues.passCode = "";
        walletLoader.active = false;
        return true;
    }

    Connections {
        target: GlobalValues
        function onPassCodeChanged() {
            unlockTimer.stop();
            if (GlobalValues.passCode.length) {
                keySpy.lastEvent = new Date;
                unlockTimer.start();
            } else {
                walletLoader.active = false;
            }
        }
    }

    Timer {
        id: unlockTimer
        interval: 500
        repeat: false
        onTriggered: walletLoader.active = true
    }

    TViewport {
        id: viewport
        anchors.fill: parent
        mainItem: Loader {
            id: walletLoader
            anchors.fill: parent
            asynchronous: true
            active: false
            sourceComponent: Wallet {
                publicKey: dis.publicKey
                anchors.fill: parent
            }
        }
    }

    Loader {
        id: lockScreen
        anchors.fill: parent
        active: !walletLoader.item
        sourceComponent: LockDialog {
            anchors.fill: parent
            publicKey: dis.publicKey
            busy: GlobalValues.passCode.length
        }
    }

    Timer {
        interval: 500
        repeat: true
        running: true
        onTriggered: checkLockScreen()
    }

    KeyHandler {
        id: keySpy
        window: GlobalValues.mwin
        onMousePositionChanged: if (!checkLockScreen()) lastEvent = new Date
        onKeyChanged: if (!checkLockScreen()) lastEvent = new Date
        onScreenTouched: if (!checkLockScreen()) lastEvent = new Date

        property variant lastEvent: new Date
    }
}

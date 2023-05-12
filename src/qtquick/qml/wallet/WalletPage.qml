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

    Connections {
        target: GlobalValues
        function onPassCodeChanged() {
            unlockTimer.stop();
            if (GlobalValues.passCode.length)
                unlockTimer.start();
            else
                walletLoader.active = false;
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
}

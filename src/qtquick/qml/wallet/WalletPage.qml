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

    TViewport {
        id: viewport
        anchors.fill: parent
        mainItem: Loader {
            anchors.fill: parent
            active: !lockScreen.active
            sourceComponent: Wallet {
                publicKey: dis.publicKey
                anchors.fill: parent
            }
        }
    }

    Loader {
        id: lockScreen
        anchors.fill: parent
        active: !GlobalValues.unlocked
        sourceComponent: LockDialog {
            anchors.fill: parent
            publicKey: dis.publicKey
        }
    }
}

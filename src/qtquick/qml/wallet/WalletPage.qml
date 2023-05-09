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
            id: walletLoader
            anchors.fill: parent
            active: GlobalValues.unlocked
            asynchronous: true
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
        }
    }
}

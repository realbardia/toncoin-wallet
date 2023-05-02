import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    color: wallet.color

    property alias viewport: viewport

    Viewport {
        id: viewport
        anchors.fill: parent
        mainItem: Wallet {
            id: wallet
            anchors.fill: parent
        }
    }
}

import QtQuick 2.15
import Toolkit 1.0
import Viewport 1.0
import "../components"
import "../globals"

TPage {
    color: wallet.color

    property alias viewport: viewport

    TViewport {
        id: viewport
        anchors.fill: parent
        mainItem: Wallet {
            id: wallet
            anchors.fill: parent
        }
    }

    LockDialog {
        anchors.fill: parent
        visible: GlobalValues.locked
    }
}

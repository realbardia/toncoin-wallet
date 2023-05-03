import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
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

    Loader {
        anchors.fill: parent
        active: GlobalValues.locked
        sourceComponent: LockDialog {
            anchors.fill: parent
        }
    }

}

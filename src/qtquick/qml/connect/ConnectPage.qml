import QtQuick 2.15
import "../components"
import "../globals"

TDrawer {
    height: contentHeight + area.height

    mainButton {
        text: qsTr("Connect Wallet")
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        TLabel {
            id: body
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.weight: Font.Light
            opacity: 0.6
            text: qsTr("Connect to Fragment")
        }
    }
}

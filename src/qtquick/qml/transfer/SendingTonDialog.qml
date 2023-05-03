import QtQuick 2.15
import Viewport 1.0
import Toolkit 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Receive TON")
    height: contentHeight + area.height

    mainButton {
        text: qsTr("View My Wallet")
        onClicked: dis.closeRequest()
    }

    property string amount
    property string address

    Timer {
        id: testTimer
        interval: 2000
        running: true
        repeat: false
        onTriggered: TViewport.viewport.append(done_component, {}, "stack")
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        StickerItem {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height: width
            autoPlay: true
            source: "qrc:/ton/common/stickers/Waiting TON.tgs"
        }

        THeaderLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Sending TON")
        }

        TLabel {
            id: body
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.weight: Font.Light
            opacity: 0.6
            text: qsTr("Please wait a few seconds for your transaction to be processed...")
        }
    }

    Component {
        id: done_component
        SendDoneDialog {
            width: parent.width
            closable: true
            amount: dis.amount
            address: dis.address
            onCloseRequest: dis.closeRequest()
        }
    }
}

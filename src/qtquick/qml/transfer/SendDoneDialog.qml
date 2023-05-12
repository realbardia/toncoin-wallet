import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Receive TON")
    height: contentHeight + area.height

    property string amount
    property alias address: addressLabel.text

    mainButton {
        text: qsTr("View My Wallet")
        onClicked: dis.closeRequest()
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
            source: "qrc:/ton/common/stickers/Success.tgs"
        }

        THeaderLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Done!")
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
            text: qsTr("%1 Toncoin have been sent to").arg(dis.amount)
        }

        TItemDelegate {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            radius: Constants.controlsRoundness
            height: addressLabel.contentHeight + addressLabel.y*2
            onClicked: {
                Devices.setClipboard(address);
                GlobalSignals.snackRequest(MaterialIcons.mdi_check, qsTr("Copy"), qsTr("Address copied to clipboard successfully."), Colors.green);
            }

            TLabel {
                id: addressLabel
                x: 5; y: 5
                width: parent.width - 10
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
        }
    }
}

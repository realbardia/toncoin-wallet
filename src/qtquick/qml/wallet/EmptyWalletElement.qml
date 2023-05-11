import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
import "../components"
import "../globals"

TPage {
    id: dis

    property string address

    TColumn {
        id: headerColumn
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 40
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        StickerItem {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height: width
            autoPlay: true
            loops: 1
            source: "qrc:/ton/common/stickers/Created.tgs"
        }

        THeaderLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Wallet Created")
        }

        Item {
            width: 1; height: 1
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            text: qsTr("Your wallet address")
            horizontalAlignment: Text.AlignHCenter
            opacity: 0.6
        }

        TItemDelegate {
            anchors.left: parent.left
            anchors.right: parent.right
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
                text: {
                    var mid = Math.floor(dis.address.length/2);
                    return dis.address.slice(0, mid) + "\n" + dis.address.slice(mid);
                }
            }
        }
    }
}

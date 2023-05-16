import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Receive TON")
    height: contentHeight + area.height

    property string address

    mainButton {
        text: qsTr("Share Wallet Address")
        onClicked: {
            if (Devices.isDesktop)
                addressBtn.clicked(null);
            else
                Devices.share(qsTr("My TON wallet address:"), dis.address);
        }
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
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
            text: qsTr("Share this address with other TON wallet owners to receive TON from them.")
        }

        TItemDelegate {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            height: width
            radius: Constants.roundness
            onClicked: addressBtn.clicked(null)

            Rectangle {
                anchors.fill: parent
                radius: Constants.roundness
            }

            Item {
                anchors.fill: parent
                anchors.margins: 20

                QrCreator {
                    anchors.centerIn: parent
                    width: parent.width * 2
                    height: parent.height * 2
                    scale: 0.5
                    pixels: 20
                    text: "ton://transfer/" + dis.address
                    centerImage: "qrc:/ton/common/icons/gem.png"
                }
            }
        }

        TItemDelegate {
            id: addressBtn
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            radius: Constants.controlsRoundness
            height: addressLabel.contentHeight + addressLabel.y*2
            onClicked: {
                Devices.setClipboard(dis.address);
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

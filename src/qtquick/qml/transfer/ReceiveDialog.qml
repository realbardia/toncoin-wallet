import QtQuick 2.15
import "../components"
import "../globals"

TDrawer {
    title: qsTr("Receive TON")
    height: contentHeight + area.height

    mainButton {
        text: qsTr("Share Wallet Address")
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
            text: qsTr("Share this address with other TON wallet owners to receive TON from them.")
        }

        Image {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            height: width
            source: "qrc:/ton/common/images/qr-test.png"
            mipmap: true
        }

        TItemDelegate {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            radius: Constants.controlsRoundness
            height: addressLabel.contentHeight + addressLabel.y*2

            TLabel {
                id: addressLabel
                x: 5; y: 5
                width: parent.width - 10
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: AppSettings.privateKey
            }
        }
    }
}

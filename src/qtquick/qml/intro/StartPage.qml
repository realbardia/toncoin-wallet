import QtQuick 2.15
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {

    TColumn {
        anchors.bottom: parent.verticalCenter
        anchors.bottomMargin: 7
        anchors.horizontalCenter: parent.horizontalCenter

        TgStickerItem {
            anchors.horizontalCenter: parent.horizontalCenter
            width: headerTitle.width
            height: width
            autoPlay: true
            source: "qrc:/ton/common/stickers/Start.tgs"
        }

        THeaderLabel {
            id: headerTitle
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("TON Wallet")
        }
    }

    TLabel {
        anchors.top: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 50
        anchors.topMargin: 7
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font.weight: Font.Light
        text: qsTr("TON Wallet allows you to make fast and secure blockchian-based payments without intermediaries.")
    }

    TColumn {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 100

        TButton {
            id: createBtn
            anchors.horizontalCenter: parent.horizontalCenter
            width: importBtn.width
            text: qsTr("Create my wallet")
        }

        TButton {
            id: importBtn
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Import existing wallet")
            flat: true
            highlight: true
        }
    }
}

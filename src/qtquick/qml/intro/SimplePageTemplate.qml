import QtQuick 2.15
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {

    property alias sticker: sticker.source
    property alias title: headerTitle.text
    property alias body: body.text
    property alias mainButton: mainBtn
    property alias secondaryButton: secondaryBtn
    property alias checkBox: checkBox

    TColumn {
        anchors.bottom: parent.verticalCenter
        anchors.bottomMargin: 7
        anchors.horizontalCenter: parent.horizontalCenter

        TgStickerItem {
            id: sticker
            anchors.horizontalCenter: parent.horizontalCenter
            width: headerTitle.width
            height: width
            autoPlay: true
        }

        THeaderLabel {
            id: headerTitle
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    TLabel {
        id: body
        anchors.top: parent.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 50
        anchors.topMargin: 7
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font.weight: Font.Light
    }

    TColumn {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 50

        TCheckBox {
            id: checkBox
            anchors.horizontalCenter: parent.horizontalCenter
            width: 160
            visible: text.length
        }

        TButton {
            id: mainBtn
            anchors.horizontalCenter: parent.horizontalCenter
            width: 160
        }

        TButton {
            id: secondaryBtn
            anchors.horizontalCenter: parent.horizontalCenter
            flat: true
            highlight: true
            opacity: enabled? 1 : 0
            enabled: text.length
            width: 160
        }
    }
}

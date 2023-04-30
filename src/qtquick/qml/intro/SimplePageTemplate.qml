import QtQuick 2.15
import AsemanQml.Viewport 2.0
import AsemanQml.Controls 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    id: page
    data: [headerColumn, body, footerColumn]

    property alias sticker: sticker.source
    property alias title: headerTitle.text
    property alias body: body.text
    property alias mainButton: mainBtn
    property alias secondaryButton: secondaryBtn
    property alias backable: backButton.visible

    default property alias sceneData: customColumn.data

    TColumn {
        id: headerColumn
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
        id: footerColumn
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 50

        TColumn {
            id: customColumn
            anchors.left: parent.left
            anchors.right: parent.right
            z: 10
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

    HeaderMenuButton {
        id: backButton
        ratio: 1
        buttonColor: Colors.foreground
        visible: false
        onClicked: page.ViewportType.open = false
    }
}

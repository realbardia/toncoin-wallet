import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
import "../components"
import "../globals"

TPage {
    id: page
    data: [headerColumn, body, customColumn, footerColumn, backButton]

    property alias sticker: sticker.source
    property alias stickerLoop: sticker.loops

    property alias title: headerTitle.text
    property alias body: body.text
    property alias mainButton: mainBtn
    property alias secondaryButton: secondaryBtn
    property alias backable: backButton.visible

    default property alias sceneData: customColumn.data

    signal closeRequest()

    TColumn {
        id: headerColumn
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 40
        anchors.bottom: body.top
        anchors.bottomMargin: 4
        spacing: 10

        StickerItem {
            id: sticker
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height: width
            autoPlay: true
        }

        THeaderLabel {
            id: headerTitle
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }
    }

    TLabel {
        id: body
        y: Math.min(parent.height/2 + 7, customColumn.y - height - 20)
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 50
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font.weight: Font.Light
    }

    TColumn {
        id: customColumn
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: footerColumn.top
        anchors.bottomMargin: 20
        z: 10
    }

    TColumn {
        id: footerColumn
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 64

        TButton {
            id: mainBtn
            anchors.horizontalCenter: parent.horizontalCenter
            width: 160
            opacity: text.length? 1 : 0

            MouseArea {
                anchors.fill: parent
                visible: mainBtn.text.length == 0
            }
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

    THeaderBackButton {
        id: backButton
        visible: false
        onClicked: page.closeRequest()
    }
}

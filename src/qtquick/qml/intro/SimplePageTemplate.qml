import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
import "../components"
import "../globals"

TPage {
    id: page
    data: [headerColumn, body, customColumn, busy, error, footerColumn, backButton]

    property alias sticker: sticker.source
    property alias stickerLoop: sticker.loops

    property alias title: headerTitle.text
    property alias body: body.text
    property alias mainButton: mainBtn
    property alias secondaryButton: secondaryBtn
    property alias backable: backButton.visible
    property alias buttonBusy: buttonBusy.running

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

    TBusyIndicator {
        id: busy
        anchors.centerIn: footerColumn
        width: 42
        height: width
        running: MainBackend.initializing
        accented: true
    }

    TLabel {
        id: error
        anchors.verticalCenter: footerColumn.verticalCenter
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 50
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 9 * Devices.fontDensity
        color: Colors.red
        visible: !MainBackend.initializing && !MainBackend.initialized
        text: qsTr("Error: Could not initialize wallet!") + "\n" + MainBackend.errorString
    }

    TColumn {
        id: footerColumn
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 64
        visible: !MainBackend.initializing && MainBackend.initialized

        TButton {
            id: mainBtn
            anchors.horizontalCenter: parent.horizontalCenter
            width: buttonBusy.running? height : 160
            radius: buttonBusy.running? height/2 : Constants.controlsRoundness
            textVisible: !buttonBusy.running
            opacity: text.length? 1 : 0

            Behavior on width {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
            }
            Behavior on height {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
            }

            MouseArea {
                anchors.fill: parent
                visible: mainBtn.text.length == 0
            }

            TBusyIndicator {
                id: buttonBusy
                anchors.centerIn: parent
                width: 26
                height: 26
                accented: false
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

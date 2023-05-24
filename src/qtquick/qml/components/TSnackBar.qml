import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

Item {
    clip: true

    property bool fullFill: Devices.isIOS

    function open(icon, title, description, color) {
        background.color = color;
        iconLabel.text = icon;
        titleLabel.text = title;
        descriptionLabel.text = description;
        snack.opened = true;
        closeTimer.restart();
    }

    function close() {
        snack.opened = false;
        closeTimer.stop();
    }

    Timer {
        id: closeTimer
        interval: 3000
        repeat: false
        onTriggered: snack.opened = false
    }

    Rectangle {
        id: background
        anchors.top: snack.top
        anchors.left: fullFill? parent.left : snack.left
        anchors.right: fullFill? parent.right : snack.right
        anchors.bottom: fullFill? parent.bottom : snack.bottom
        radius: fullFill? 0 : Constants.controlsRoundness
        color: Colors.foreground
    }

    MouseArea {
        id: snack
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.bottom
        anchors.topMargin: offset
        anchors.margins: 10
        height: mainRow.height + mainRow.y*2
        opacity: opened? 1 : 0

        property bool opened: false
        property real offset: opened? - height - 10 : 0

        Behavior on offset {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }
        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }

        Item {
            id: mainRow
            anchors.left: parent.left
            anchors.right: parent.right
            y: 12
            height: Math.max(iconLabel.height, mainColumn.height)
            anchors.margins: y

            TMaterialIcon {
                id: iconLabel
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 18 * Devices.fontDensity
                text: MaterialIcons.mdi_alert_octagon
                color: Colors.background
            }

            TColumn {
                id: mainColumn
                anchors.left: iconLabel.right
                anchors.right: parent.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                spacing: -2

                TLabel {
                    id: titleLabel
                    width: parent.width
                    font.bold: true
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    maximumLineCount: 1
                    elide: Text.ElideRight
                    color: Colors.background
                }
                TLabel {
                    id: descriptionLabel
                    width: parent.width
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    color: Colors.background
                }
            }
        }
    }
}

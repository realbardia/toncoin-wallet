import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Modern 2.0
import "../globals"

Item {
    data: [openAction, backgroundArea, backgrounMArea, shadow, dialogBackground]

    property alias opened: openAction.active
    default property alias sceneData: mainColumn.data
    property variant buttons: new Array

    property alias title: titleLabel.text

    signal buttonClicked(int index)
    signal accepted()
    signal rejected()

    function open() {
        opened = true;
    }
    function close() {
        opened = false;
    }
    function accept() {
        close();
        accepted();
    }
    function reject() {
        close();
        rejected();
    }

    BackAction {
        id: openAction
    }

    Rectangle {
        id: backgroundArea
        anchors.fill: parent
        opacity: opened? 0.5 : 0
        color: Colors.foreground

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }
    }

    MouseArea {
        id: backgrounMArea
        anchors.fill: parent
        hoverEnabled: true
        onWheel: wheel.accepted = true
        visible: opened
        onClicked: close()
    }

    FastDropShadow {
        id: shadow
        anchors.fill: dialogBackground
        verticalOffset: 4
        source: dialogBackground
        radius: 64
        opacity: 0.6 * dialogBackground.opacity
    }

    Rectangle {
        id: dialogBackground
        anchors.centerIn: parent
        width: clmn.width + clmn.x * 2
        height: clmn.height + clmn.y * 2
        radius: Constants.dialogsRoundness
        color: Colors.background
        opacity: opened? 1 : 0
        scale: opened? 1 : 1.1
        visible: opacity > 0

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onWheel: wheel.accepted = true
        }

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }
        Behavior on scale {
            NumberAnimation { easing.type: Easing.OutBack; duration: 200 }
        }

        TColumn {
            id: clmn
            y: 20
            x: 20

            TLabel {
                id: titleLabel
                anchors.left: parent.left
                anchors.right: parent.right
                font.pixelSize: 12 * Devices.fontDensity
                font.weight: Font.Medium
            }

            TColumn {
                id: mainColumn
            }

            TRow {
                anchors.right: parent.right

                Repeater {
                    model: buttons
                    TButton {
                        highlight: true
                        flat: true
                        text: modelData
                        onClicked: buttonClicked(model.index)
                    }
                }
            }
        }
    }
}

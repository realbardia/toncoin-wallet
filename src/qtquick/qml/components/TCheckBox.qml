import QtQuick 2.15
import QtGraphicalEffects 1.15
import AsemanQml.Base 2.0
import AsemanQml.MaterialIcons 2.0
import "../globals"

TControlElement {
    id: marea
    width: label.width + 20
    height: 38

    onFocusChanged: {
        if (focus) {
            highlightArea.pinX = pressed? marea.mouseX : width/2;
            highlightArea.pinY = pressed? marea.mouseY : height/2;
            highlightArea.opacity = 0.15;
            ratioAnim.start();
        } else {
            opacityAnim.start();
        }
    }
    onClicked: checked = !checked

    property alias text: label.text
    property bool checked

    NumberAnimation {
        id: opacityAnim
        target: highlightArea
        property: "opacity"
        easing.type: Easing.Linear
        duration: 300
        from: 0.15; to: 0
    }
    NumberAnimation {
        id: ratioAnim
        target: highlightArea
        property: "width"
        easing.type: Easing.Linear
        duration: 300
        from: 0; to: marea.width*2
    }

    Rectangle {
        id: background
        anchors.fill: parent
        radius: Constants.controlsRoundness
        visible: false
    }

    Item {
        id: highlightScene
        anchors.fill: parent
        clip: true
        visible: false

        Rectangle {
            id: highlightArea
            x: pinX - width/2
            y: pinY - height/2
            color: Colors.foreground
            height: width
            radius: height / 2

            property real pinX
            property real pinY
        }
    }

    OpacityMask {
        anchors.fill: parent
        maskSource: background
        source: highlightScene
    }

    TRow {
        anchors.centerIn: parent
        spacing: 10
        scale: marea.pressed? 0.97 : 1

        Behavior on scale {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }

        Item {
            anchors.verticalCenter: parent.verticalCenter
            width: 18
            height: width

            Rectangle {
                anchors.fill: parent
                radius: Constants.controlsRoundness/2
                color:  marea.checked? Colors.accent : Colors.foreground
                opacity: marea.checked? 1 : 0.3
            }

            TMaterialIcon {
                anchors.centerIn: parent
                text: MaterialIcons.mdi_check
                color: "#fff"
                opacity: marea.checked? 1 : 0
                scale: marea.checked? 1 : 2

                Behavior on opacity {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
                }
                Behavior on scale {
                    NumberAnimation { easing.type: Easing.OutBack; duration: 200 }
                }
            }
        }

        TLabel {
            id: label
            anchors.verticalCenter: parent.verticalCenter
            color: Colors.foreground
        }
    }
}

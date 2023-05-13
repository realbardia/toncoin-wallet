import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
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

    default property alias sceneData: scene.data

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

    Item {
        id: scene
        height: parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10
        scale: marea.pressed? 0.97 : 1

        Behavior on scale {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }

        TLabel {
            id: label
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            color: Colors.foreground
        }
    }

    Item {
        anchors.right: scene.right
        anchors.verticalCenter: scene.verticalCenter
        width: 30
        height: 22

        Rectangle {
            id: bilbil
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            height: parent.height/2
            radius: height/2
            color:  marea.checked? Colors.accent : Colors.backgroundDeep

            Behavior on color {
                ColorAnimation { easing.type: Easing.OutCubic; duration: 200 }
            }
        }

        Rectangle {
            height: 16
            anchors.verticalCenter: parent.verticalCenter
            x: marea.checked? parent.width - width : 0
            width: height
            radius: height / 2
            color: Colors.background

            Rectangle {
                anchors.fill: parent
                anchors.margins: -2
                radius: height/2
                color: bilbil.color
                z: -1
            }

            Behavior on x {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
            }
        }
    }
}

import QtQuick 2.15
import QtGraphicalEffects 1.15
import AsemanQml.Base 2.0
import AsemanQml.MaterialIcons 2.0
import "../globals"

TControlElement {
    id: marea
    height: 42
    acceptedButtons: Qt.LeftButton | Qt.RightButton
    pressAndHoldInterval: 300
    data: [opacityAnim, ratioAnim, background, highlightScene, opacMask, scene]

    onFocusChanged: {
        if (focus) {
            highlightArea.pinX = pressed? marea.mouseX : width/2;
            highlightArea.pinY = pressed? marea.mouseY : height/2;
            highlightArea.opacity = 0.1;
            ratioAnim.start();
        } else {
            opacityAnim.start();
        }
    }

    default property alias sceneData: scene.data
    property alias highlightColor: highlightArea.color
    property alias radius: background.radius

    NumberAnimation {
        id: opacityAnim
        target: highlightArea
        property: "opacity"
        easing.type: Easing.Linear
        duration: 300
        from: 0.1; to: 0
    }
    NumberAnimation {
        id: ratioAnim
        target: highlightArea
        property: "width"
        easing.type: Easing.Linear
        duration: Devices.isIOS? 0 : 300
        from: 0; to: Math.max(marea.width, marea.height) * 2.1
    }

    Rectangle {
        id: background
        anchors.fill: parent
        visible: false
    }

    Item {
        id: highlightScene
        z: 10
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
        id: opacMask
        anchors.fill: parent
        maskSource: background
        source: highlightScene
    }

    Item {
        id: scene
        anchors.fill: parent
        scale: marea.pressed? 0.97 : 1

        Behavior on scale {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }
    }
}

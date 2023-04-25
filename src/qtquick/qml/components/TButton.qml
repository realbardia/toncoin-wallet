import QtQuick 2.15
import QtGraphicalEffects 1.15
import AsemanQml.Base 2.0
import "../globals"

MouseArea {
    id: marea
    width: label.width + 20
    height: 38
    pressAndHoldInterval: 300
    onPressedChanged: {
        if (pressed) {
            highlightArea.pinX = marea.mouseX;
            highlightArea.pinY = marea.mouseY;
            highlightArea.opacity = 0.15;
            ratioAnim.start();
        } else {
            opacityAnim.start();
        }
    }

    property alias text: label.text
    property bool flat
    property bool highlight

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
        duration: Devices.isIOS? 0 : 300
        from: 0; to: marea.width*2
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: Colors.accent
        radius: Constants.controlsRoundness
        visible: !flat
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

    TLabel {
        id: label
        anchors.centerIn: parent
        color: highlight? Colors.accent : "#fff"
    }
}

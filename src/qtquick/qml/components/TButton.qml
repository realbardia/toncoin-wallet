import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TControlElement {
    id: marea
    width: label.width + 20
    cursorShape: Qt.PointingHandCursor
    hoverEnabled: true
    height: Devices.isIOS? 48 : 42

    onFocusChanged: doHighlight(focus)
    onPressed: doHighlight(pressed)

    function doHighlight(state) {
        if (state) {
            highlightArea.pinX = pressed? marea.mouseX : width/2;
            highlightArea.pinY = pressed? marea.mouseY : height/2;
            highlightArea.opacity = 0.15;
            ratioAnim.start();
        } else {
            opacityAnim.start();
        }
    }

    property alias text: label.text
    property alias font: label.font
    property alias icon: icon
    property bool flat
    property bool highlight
    property alias highlightColor: highlightArea.color
    property alias backgroundColor: background.color
    property color color: highlight? Colors.accent : "#fff"
    property alias radius: background.radius
    property bool textVisible: true

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
        from: 0; to: Math.max(marea.width, marea.height) * 2.1
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: marea.enabled? Colors.accent : Colors.foreground
        radius: Constants.controlsRoundness
        opacity: marea.enabled? 1 : 0.3
        visible: !flat
    }

    Item {
        id: highlightScene
        anchors.fill: parent
        clip: true
        visible: false

        Rectangle {
            anchors.fill: parent
            radius: marea.radius
            color: Colors.foreground
            opacity: marea.containsMouse? (flat? 0.05 : 0.1) : 0
            Behavior on opacity {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
            }
        }

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
        scale: marea.pressed? GlobalMethods.pressedScale(width,height) : 1
        spacing: 2
        visible: textVisible

        Behavior on scale {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }

        TLabel {
            id: icon
            anchors.verticalCenter: parent.verticalCenter
            color: marea.color
            font.family: MaterialIcons.family
            visible: text.length
        }

        TLabel {
            id: label
            anchors.verticalCenter: parent.verticalCenter
            color: marea.color
            visible: text.length
        }
    }
}

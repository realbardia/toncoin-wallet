import QtQuick 2.15
import Toolkit.Core 1.0

Item {
    id: item

    property alias radius: blur.radius
    property alias color: shadowMask.color
    property alias roundRadius: shadowMask.radius
    property real horizontalOffset
    property real verticalOffset
    property bool cached: true

    FastBlur {
        id: blur
        x: parent.width/2 - width/2 + item.horizontalOffset
        y: parent.height/2 - height/2 + item.verticalOffset
        width: shadowScene.width
        height: shadowScene.height
        source: shadowScene
        cached: item.cached
    }

    Item {
        id: shadowScene
        anchors.fill: parent
        anchors.margins: -item.radius*2
        visible: false

        Rectangle {
            id: shadowMask
            width: item.width
            height: item.height
            anchors.centerIn: parent
            color: "#333"
        }
    }
}

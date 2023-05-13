import QtQuick 2.0
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import ".."
import "../private"
import "../../globals"

AbstractViewportType {
    id: item

    foreground.x: foregroundItem? -foregroundItem.x : 0
    foreground.height: foregroundItem? foregroundItem.height : item.height
    foreground.z: 10
    foreground.parent: drawerScene
    foregroundScene.color: "transparent"

    property real openRatio: open? 1 : 0

    Behavior on ratio {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 350 }
    }

    Rectangle {
        anchors.fill: item.background
        color: "#000"
        opacity: item.ratio * 0.3
    }

    NumberAnimation {
        id: foregroundAnim
        target: foregroundArea
        property: "y"
        easing.type: Easing.OutCubic
        duration: 300
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
    }

    MouseArea {
        anchors.fill: parent
        visible: item.touchToCloseIsNull || item.touchToClose
        onClicked: open = false
    }

    MouseArea {
        id: dragArea
        width: foregroundItem? foregroundItem.width : item.width
        x: foregroundItem? foregroundItem.x : 0
        height: item.gestureWidthIsNull? item.foreground.height : item.gestureWidth
        y: parent.height - item.foreground.height * item.ratio
        z: 10
        drag {
            target: foregroundArea
            axis: Drag.YAxis
            minimumY: 0
            maximumY: item.height - 10
            filterChildren: true
            onActiveChanged: {
                if (dragArea.drag.active)
                    return;

                var ratio = 1 - foregroundArea.y / dragArea.height
                if (ratio < 0.7) {
                    open = false
                } else {
                    foregroundAnim.from = foregroundArea.y
                    foregroundAnim.to = 0
                    foregroundAnim.start()
                }
            }
        }

        Item {
            id: foregroundArea
            width: parent.width
            height: parent.height
            z: 20
            clip: true

            TViewport {
                id: slaveViewport
                anchors.fill: parent
                opacity: 0
                mainItem: MouseArea {
                    id: drawerScene
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: maskRect
                radius: Constants.roundness
                anchors.fill: parent
                visible: false

                Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.verticalCenter
                    anchors.bottom: parent.bottom
                    color: Colors.background
                }
            }

            OpacityMask {
                anchors.fill: parent
                maskSource: maskRect
                source: slaveViewport
            }
        }
    }
}

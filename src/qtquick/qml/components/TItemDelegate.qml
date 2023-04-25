import QtQuick 2.15
import QtQuick.Controls 2.15
import "../globals"

MouseArea {
    id: marea
    acceptedButtons: Qt.LeftButton | Qt.RightButton
    pressAndHoldInterval: 300
    data: [rect, scene]

    property alias radius: rect.radius
    default property alias sceneData: scene.data

    Rectangle {
        id: rect
        anchors.fill: parent
        color: Colors.foreground
        opacity: marea.pressed? 0.1 : 0

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }
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

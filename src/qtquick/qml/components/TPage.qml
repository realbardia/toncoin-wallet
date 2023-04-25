import QtQuick 2.15
import "../globals"

Rectangle {
    color: Colors.background

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onWheel: wheel.accepted = true
    }
}

import QtQuick 2.15
import Toolkit 1.0
import "../globals"

Rectangle {
    color: Colors.background

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onWheel: wheel.accepted = true
        onClicked: {
            GlobalSignals.discardMenus();
            Devices.hideKeyboard();
        }
    }
}

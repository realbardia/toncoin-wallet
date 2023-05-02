import QtQuick 2.0
import "../components"
import "../globals"

TPage {
    radius: Constants.roundness
    height: 400

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.verticalCenter
        anchors.bottom: parent.bottom
        color: Colors.background
    }
}

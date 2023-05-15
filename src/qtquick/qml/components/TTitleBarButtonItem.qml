import QtQuick 2.15
import Toolkit.Core 1.0
import QtQuick.Window 2.3
import "../globals"

Item {
    id: tbar_btn
    width: 50 * Devices.density
    height: 32 * Devices.density

    property alias text: titleLabel.text
    property alias font: titleLabel.font
    property alias color: back.color
    signal clicked()

    Rectangle {
        id: back
        anchors.fill: parent
        color: Colors.headerTextColor
        opacity: marea.containsMouse? 0.3 : 0
    }

    TLabel {
        id: titleLabel
        anchors.centerIn: parent
        font.family: MaterialIcons.family
        font.pixelSize: 12 * Devices.fontDensity
        color: Colors.headerTextColor
        text: MaterialIcons.mdi_close
    }

    MouseArea {
        id: marea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: tbar_btn.clicked()
    }
}

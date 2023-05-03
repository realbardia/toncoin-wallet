import QtQuick 2.9
import Toolkit.Core 1.0

Item {
    id: hmb
    width: height
    height: Devices.standardTitleBarHeight
    y: Devices.statusBarHeight
    x: LayoutMirroring.enabled? parent.width - width : 0

    property alias color: rect.color
    property alias buttonColor: menuIcon.color

    property alias ratio: menuIcon.ratio
    property alias pressed: marea.pressed

    signal clicked()

    LayoutMirroring.childrenInherit: true

    Rectangle {
        id: rect
        anchors.fill: parent
        anchors.margins: 10*Devices.density
        color: menuIcon.color
        radius: 3*Devices.density
        opacity: pressed? 0.2 : 0
    }

    MenuIcon {
        id: menuIcon
        anchors.centerIn: parent
    }

    MouseArea {
        id: marea
        anchors.fill: parent
        onClicked: hmb.clicked()
    }
}

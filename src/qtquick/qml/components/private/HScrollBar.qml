import QtQuick 2.9
import Toolkit.Core 1.0

Item {
    id: container
    width: 8 * Devices.density

    property variant scrollArea
    property variant orientation: Qt.Vertical
    property alias color: bilbilak.color
    property bool forceVisible: false

    opacity: movingTimer.running || forceVisible? 1 : 0

    Connections {
        target: scrollArea
        function onContentYChanged() {
            movingTimer.restart();
        }
        function onContentXChanged() {
            movingTimer.restart();
        }
    }

    Timer {
        id: movingTimer
        interval: 500
        repeat: false
    }

    function position()
    {
        var ny = 0;
        if (container.orientation == Qt.Vertical)
            ny = scrollArea.visibleArea.yPosition * container.height;
        else
            ny = scrollArea.visibleArea.xPosition * container.width;
        if (ny > 2) return ny; else return 2;
    }

    function size()
    {
        var nh, ny;

        if (container.orientation == Qt.Vertical)
            nh = scrollArea.visibleArea.heightRatio * container.height;
        else
            nh = scrollArea.visibleArea.widthRatio * container.width;

        if (container.orientation == Qt.Vertical)
            ny = scrollArea.visibleArea.yPosition * container.height;
        else
            ny = scrollArea.visibleArea.xPosition * container.width;

        if (ny > 3) {
            var t;
            if (container.orientation == Qt.Vertical)
                t = Math.ceil(container.height - 3 - ny);
            else
                t = Math.ceil(container.width - 3 - ny);
            if (nh > t) return t; else return nh;
        } else return nh + ny;
    }

    Rectangle {
        id: bilbilak
        color: "#000000"
        smooth: true
        radius: width/2
        x: container.orientation == Qt.Vertical ? 2 : position()
        width: container.orientation == Qt.Vertical ? container.width - 4 : diagonal
        y: container.orientation == Qt.Vertical ? position() : 2
        height: container.orientation == Qt.Vertical ? diagonal : container.height - 4
        opacity: 0.5

        property real diagonal: size()<20*Devices.density? 20*Devices.density : size()
    }

    Behavior on opacity {
        NumberAnimation { duration: 300 }
    }
}

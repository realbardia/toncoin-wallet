import QtQuick 2.0
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../private"

AbstractViewportTypeCore {
    id: item
    anchors.fill: parent

    property ListObject list

    property bool fillForeground: false

    property int index
    property int count
    property string openedType
    property real ratio: open? 1 : 0

    property alias background: background
    property alias backgroundScene: backgroundScene
    property alias foreground: foreground
    property alias foregroundScene: foregroundScene

    onOpenChanged: {
        if (open)
            BackHandler.pushHandler(this, back)
        else
            BackHandler.removeHandler(this)
    }
    onRatioChanged: if (ratio <= 0 && !open) { foregroundItem.destroy(); item.destroy();}

    RoundedItem {
        id: background
        width: parent.width
        height: parent.height

        Rectangle {
            id: backgroundScene
            anchors.fill: parent
        }
    }

    RoundedItem {
        id: foreground
        width: parent.width
        height: parent.height

        Rectangle {
            id: foregroundScene
            anchors.fill: parent
        }
    }

    function back() {
        if (!item.blockBackIsNull && item.blockBack)
            return false;

        open = false
        return true;
    }
}

import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Modern 2.0
import "../globals"

Item {
    id: menuItem
    height: Math.min(listv.count * Constants.itemsHeight, 200)
    visible: false

    property alias model: listv.model
    property alias currentIndex: listv.currentIndex
    property alias count: listv.count

    signal itemClicked(int index)

    function open() {
        visible = true;
    }
    function close() {
        visible = false;
    }

    Component.onCompleted: {
        BackHandler.pushHandler(menuItem, menuItem.destroy);
    }

    Connections {
        target: GlobalSignals
        function onDiscardMenus() {
            menuItem.close();
        }
    }

    FastDropShadow {
        anchors.fill: parent
        anchors.margins: 1
        radius: 5
        color: Colors.foreground
        source: menuBack
    }

    Rectangle {
        id: menuBack
        anchors.fill: parent
        radius: Constants.controlsRoundness
        color: Colors.background
    }

    ListView {
        id: listv
        anchors.fill: parent
        clip: true
        delegate: TItemDelegate {
            width: listv.width
            height: Constants.itemsHeight
            onClicked: select()
            radius: menuBack.radius

            function select() {
                itemClicked(model.index);
                menuItem.close();
            }

            TLabel {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.margins: 10 * Devices.density
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: modelData
            }
        }
    }
}

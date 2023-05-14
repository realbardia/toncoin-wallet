import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

Item {
    id: menuItem
    height: Math.min(listv.count * Constants.itemsHeight, 200)
    visible: opened

    property alias model: listv.model
    property alias currentIndex: listv.currentIndex
    property alias count: listv.count
    property alias shadow: shadow.visible
    property string textRole
    property alias opened: openedAction.active

    signal itemClicked(int index)

    function open() {
        opened = true;
    }
    function close() {
        opened = false;
    }

    Component.onCompleted: {
        BackHandler.pushHandler(menuItem, menuItem.destroy);
    }

    BackAction {
        id: openedAction
    }

    Connections {
        target: GlobalSignals
        function onDiscardMenus() {
            menuItem.close();
        }
    }

    FastDropShadow {
        id: shadow
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

    TScrollView {
        anchors.fill: parent

        ListView {
            id: listv
            clip: true
            delegate: TItemDelegate {
                width: listv.width
                height: Constants.itemsHeight
                onClicked: select()
                radius: menuBack.radius

                function select() {
                    menuItem.close();
                    itemClicked(model.index);
                }

                TLabel {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.margins: 10 * Devices.density
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    maximumLineCount: 1
                    elide: Text.ElideRight
                    text: textRole.length? model[textRole] : modelData
                }
            }
        }
    }
}

import QtQuick 2.15
import AsemanQml.Base 2.0
import TonToolkit.private 1.0
import "../globals"

TextInput {
    id: dis
    font.family: Fonts.globalFont
    font.pixelSize: Fonts.globalFontSize
    selectByMouse: true
    selectedTextColor: "#fff"
    selectionColor: Colors.accent
    color: Colors.foreground
    leftPadding: 2
    rightPadding: 2
    bottomPadding: 10
    topPadding: 8
    clip: true
    scale: marea.pressed? 0.97 : 1

    Behavior on scale {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }

    Item {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 2

        Rectangle {
            anchors.fill: parent
            color: Colors.foreground
            opacity: 0.1
        }

        Rectangle {
            anchors.centerIn: parent
            height: parent.height
            width: dis.focus || marea.pressed? parent.width : 0
            radius: height/2
            color: Colors.accent

            Behavior on width {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
            }
        }
    }

    MouseArea {
        id: marea
        hoverEnabled: true
        acceptedButtons: Qt.RightButton
        cursorShape: Qt.IBeamCursor
        anchors.fill: parent
        onClicked: {
            dis.focus = true;
            dis.forceActiveFocus();

            if (Devices.isDesktop) {
                menu.x = mouseX;
                menu.y = mouseY;
                menu.open();
            }
        }
    }

    QmlWidgetMenu {
        id: menu

        QmlWidgetMenuItem {
            text: qsTr("Select All") + Translations.refresher
            shortcut: "Ctrl+A"
            onClicked: dis.selectAll()
        }
        QmlWidgetMenuItem {
            text: qsTr("Deselect") + Translations.refresher
            onClicked: dis.deselect()
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Copy") + Translations.refresher
            shortcut: "Ctrl+C"
            onClicked: dis.copy()
        }
        QmlWidgetMenuItem {
            text: qsTr("Cut") + Translations.refresher
            shortcut: "Ctrl+X"
            onClicked: dis.cut()
        }
        QmlWidgetMenuItem {
            text: qsTr("Paste") + Translations.refresher
            shortcut: "Ctrl+V"
            onClicked: dis.paste()
            enabled: dis.canPaste
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Undo") + Translations.refresher
            shortcut: "Ctrl+Z"
            onClicked: dis.cut()
            enabled: dis.canUndo
        }
        QmlWidgetMenuItem {
            text: qsTr("Redo") + Translations.refresher
            shortcut: "Ctrl+Shift+Z"
            onClicked: dis.paste()
            enabled: dis.canRedo
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Delete") + Translations.refresher
            shortcut: "Delete"
        }
    }
}

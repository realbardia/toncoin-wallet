import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TControlElement {
    id: dis
    scale: marea.pressed? 0.97 : 1
    height: Constants.itemsHeight

    property alias font: input.font
    property alias color: input.color
    property alias text: input.text
    property alias contentHeight: input.contentHeight
    property alias horizontalAlignment: input.horizontalAlignment
    property alias placeholderText: placeholder.text

    property real leftPadding
    property real rightPadding
    property real topPadding
    property real bottomPadding

    onFocusChanged: {
        if (focus) {
            input.focus = true;
            input.forceActiveFocus();
        }
    }

    TextEdit {
        id: input
        anchors.fill: parent
        anchors.leftMargin: dis.leftPadding
        anchors.rightMargin: dis.rightPadding
        anchors.topMargin: dis.topPadding
        anchors.bottomMargin: dis.bottomPadding
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
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

        Keys.onTabPressed: dis.tabPressed()

        TLabel {
            id: placeholder
            anchors.fill: parent
            font: input.font
            leftPadding: input.leftPadding
            rightPadding: input.rightPadding
            bottomPadding: input.bottomPadding
            topPadding: input.topPadding
            horizontalAlignment: input.horizontalAlignment
            color: input.color
            wrapMode: input.wrapMode
            opacity: 0.4
            visible: input.text.length == 0
        }
    }

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
            width: input.focus || marea.pressed? parent.width : 0
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
            input.focus = true;
            input.forceActiveFocus();

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
            text: qsTr("Select All")
            shortcut: "Ctrl+A"
            onClicked: input.selectAll()
        }
        QmlWidgetMenuItem {
            text: qsTr("Deselect")
            onClicked: input.deselect()
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Copy")
            shortcut: "Ctrl+C"
            onClicked: input.copy()
        }
        QmlWidgetMenuItem {
            text: qsTr("Cut")
            shortcut: "Ctrl+X"
            onClicked: input.cut()
        }
        QmlWidgetMenuItem {
            text: qsTr("Paste")
            shortcut: "Ctrl+V"
            onClicked: input.paste()
            enabled: input.canPaste
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Undo")
            shortcut: "Ctrl+Z"
            onClicked: input.cut()
            enabled: input.canUndo
        }
        QmlWidgetMenuItem {
            text: qsTr("Redo")
            shortcut: "Ctrl+Shift+Z"
            onClicked: input.paste()
            enabled: input.canRedo
        }
        QmlWidgetMenuItem{}
        QmlWidgetMenuItem {
            text: qsTr("Delete")
            shortcut: "Delete"
            enabled: input.selectionStart && input.selectionStart != input.selectionEnd
            onClicked: input.remove(input.selectionStart, input.selectionEnd)
        }
    }
}

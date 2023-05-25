import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TControlElement {
    id: dis
    scale: marea.pressed? GlobalMethods.pressedScale(width,height) : 1
    height: Constants.itemsHeight

    property alias length: input.length
    property alias font: input.font
    property alias color: input.color
    property alias text: input.text
    property alias placeholderText: placeholder.text
    property alias validator: input.validator
    property alias contentWidth: input.contentWidth
    property alias highlightArea: highlightArea.visible
    property alias input: input

    property real leftPadding
    property real rightPadding
    property real topPadding
    property real bottomPadding

    property variant suggestionsMenu
    property variant suggestions: new Array

    signal accepted()

    onFocusChanged: {
        if (focus) {
            input.focus = true;
            input.forceActiveFocus();
        }
    }

    function closeMenu() {
        if (suggestionsMenu)
            suggestionsMenu.destroy();
    }

    TextInput {
        id: input
        anchors.fill: parent
        anchors.leftMargin: dis.leftPadding
        anchors.rightMargin: dis.rightPadding
        anchors.topMargin: dis.topPadding
        anchors.bottomMargin: dis.bottomPadding
        verticalAlignment: Text.AlignVCenter
        font.family: Fonts.globalFont
        font.pixelSize: Fonts.globalFontSize
        selectByMouse: true
        selectedTextColor: "#fff"
        selectionColor: Colors.accent
        color: Colors.foreground
        leftPadding: 2
        rightPadding: 2
        bottomPadding: 10
        inputMethodHints: Devices.isAndroid? Qt.ImhNoPredictiveText : 0
        topPadding: 8
        clip: true

        onFocusChanged: {
            if (focus)
                checkMenu()
            else
                closeMenu()
        }
        onTextChanged: checkMenu()

        Keys.onTabPressed: dis.tabPressed()
        Keys.onDownPressed: if (suggestionsMenu) suggestionsMenu.list.currentIndex = Math.min(suggestionsMenu.list.count-1, suggestionsMenu.list.currentIndex+1)
        Keys.onUpPressed: if (suggestionsMenu) suggestionsMenu.list.currentIndex = Math.max(0, suggestionsMenu.list.currentIndex-1)
        Keys.onReturnPressed: if (suggestionsMenu) suggestionsMenu.list.currentItem.select()
        Keys.onEnterPressed: if (suggestionsMenu) suggestionsMenu.list.currentItem.select()

        TLabel {
            id: placeholder
            anchors.fill: parent
            horizontalAlignment: input.horizontalAlignment
            verticalAlignment: input.verticalAlignment
            font: input.font
            leftPadding: input.leftPadding
            rightPadding: input.rightPadding
            bottomPadding: input.bottomPadding
            topPadding: input.topPadding
            color: input.color
            wrapMode: input.wrapMode
            opacity: 0.4
            visible: input.text.length == 0
            lineHeight: 1
        }

        function checkMenu() {
            if (signalBlocker)
                return;
            if (focus && suggestions.total && text.length) {
                suggestions.keyword = text
                if (suggestionsMenu)
                    return;

                suggestionsMenu = suggestionsMenu_component.createObject(dis);
            } else if (suggestionsMenu) {
                closeMenu();
            }
        }

        property bool signalBlocker

        SamsungInputBugFixer { id: samsung }
    }

    Connections {
        target: GlobalSignals
        function onDiscardMenus() {
            if (suggestionsMenu)
                suggestionsMenu.destroy();
        }
    }

    Behavior on scale {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }

    Item {
        id: highlightArea
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
            width: input.activeFocus || marea.pressed? parent.width : 0
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
            samsung.poke();

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

    Component {
        id: suggestionsMenu_component

        Item {
            id: suggestionsMenuItem
            x: 0
            y: dis.height
            width: dis.width
            height: Math.min(suggestionsList.count * Constants.itemsHeight, 100)
            visible: suggestionsList.count > 0

            property alias list: suggestionsList

            Component.onCompleted: {
                BackHandler.pushHandler(suggestionsMenuItem, suggestionsMenuItem.destroy);
            }

            FastDropShadow {
                anchors.fill: parent
                anchors.margins: 1
                radius: 5
                color: Colors.foreground
                source: suggestionsMenuBack
            }

            Rectangle {
                id: suggestionsMenuBack
                anchors.fill: parent
                radius: Constants.controlsRoundness
                color: Colors.background

                Rectangle {
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.verticalCenter
                    color: Colors.background
                }
            }

            ListView {
                id: suggestionsList
                anchors.fill: parent
                model: suggestions

                clip: true

                highlightMoveDuration: 200
                highlightRangeMode: Devices.isMobile? ListView.NoHighlightRange : ListView.StrictlyEnforceRange
                preferredHighlightBegin: 0
                preferredHighlightEnd: height
                highlight: Rectangle {
                    width: suggestionsList.width
                    height: Constants.itemsHeight
                    opacity: Devices.isMobile? 0 : 0.1
                    color: Colors.foreground
                }

                delegate: TItemDelegate {
                    width: suggestionsList.width
                    height: Constants.itemsHeight
                    focusOnPress: false // !Devices.isMobile
                    onClicked: select()

                    function select() {
                        suggestionsMenuItem.destroy();
                        input.text = modelData;
                        dis.accepted();
                    }

                    TLabel {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.margins: 10 * Devices.density
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        text: model.text
                    }
                }
            }
        }
    }
}

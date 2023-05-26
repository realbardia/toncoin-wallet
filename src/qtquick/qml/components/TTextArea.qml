import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TControlElement {
    id: dis
    scale: marea.pressed? GlobalMethods.pressedScale(width,height) : 1
    height: Constants.itemsHeight

    property alias font: input.font
    property alias color: input.color
    property alias text: input.text
    property alias contentHeight: input.contentHeight
    property alias horizontalAlignment: input.horizontalAlignment
    property alias placeholderText: placeholder.text
    property alias input: input

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
        inputMethodHints: Devices.isAndroid? Qt.ImhNoPredictiveText : 0
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

            if (Devices.isDesktop) {
                menuMap.x = mouseX;
                menuMap.y = mouseY;
                newMenu.open();
            }
        }
    }

    Item {
        id: menuScene
        parent: GlobalValues.mainScene
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: Colors.foreground
            opacity: {
                if (newMenu.visible)
                    return newMenu.opacity * 0.4;
                return 0
            }
            visible: opacity > 0

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    newMenu.close();
                }
            }
        }

        PointMapListener {
            id: menuMap
            source: dis
            dest: GlobalValues.mainScene
        }

        TMenu {
            id: newMenu
            y: menuMap.result.y
            x: menuMap.result.x + (menuMap.result.x < menuScene.width/2? 0 : -width)
            width: 160
            model: [
                qsTr("Select All"),
                qsTr("Copy"),
                qsTr("Cut"),
                qsTr("Paste"),
                qsTr("Delete"),
            ]
            transformOrigin: menuMap.result.x < menuScene.width/2? Item.TopLeft : Item.TopRight
            opacity: opened? 1 : 0
            scale: 0.8 + opacity*0.2
            visible: opacity > 0
            shadow: false
            highlightedIndex: model.indexOf(AppSettings.lockTimeout + "s")

            Behavior on opacity {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
            }

            onItemClicked: {
                switch (index) {
                case 0:
                    input.selectAll();
                    break;
                case 1:
                    input.copy();
                    break;
                case 2:
                    input.cut();
                    break;
                case 3:
                    input.paste();
                    break;
                case 4:
                    input.remove(input.selectionStart, input.selectionEnd)
                    break;
                }
            }
        }
    }
}

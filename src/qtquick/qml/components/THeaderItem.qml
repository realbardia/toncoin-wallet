import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import AsemanQml.Base 2.0
import AsemanQml.MaterialIcons 2.0
import "../globals"

ToolBar {
    id: dis
    height: Devices.standardTitleBarHeight + Devices.statusBarHeight
    Material.elevation: 0
    Material.primary: Colors.headerColor

    signal clicked()

    default property alias sceneData: scene.data
    property alias title: titleLabel.text
    property alias description: descLabel.text
    property alias backIcon: backLabel.text

    property alias backable: backButton.visible

    Rectangle {
        width: parent.width
        anchors.bottom: parent.bottom
        height: 1
        color: Material.foreground
        opacity: 0.1
    }

    MouseArea {
        id: scene
        anchors.fill: parent
        anchors.topMargin: Devices.statusBarHeight
        onClicked: dis.clicked()

        Button {
            id: backButton
            flat: true
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            width: 50
            visible: false
            onClicked: BackHandler.back()

            RowLayout {
                anchors.centerIn: parent

                Label {
                    id: backLabel
                    font.family: MaterialIcons.family
                    font.pixelSize: 22
                    text: MaterialIcons.mdi_chevron_left
                }
            }
        }

        Label {
            id: titleLabel
            anchors.centerIn: parent
            font.weight: Font.Medium
            font.pixelSize: 16

            Label {
                id: descLabel
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.bottom
                anchors.topMargin: -2
                font.pixelSize: 11
                color: Material.accentColor
            }
        }
    }
}

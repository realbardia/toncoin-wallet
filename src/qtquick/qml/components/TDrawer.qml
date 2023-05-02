import QtQuick 2.0
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import "../globals"

TPage {
    id: dis
    height: contentHeight

    readonly property real contentHeight: clmn.height + 2*clmn.y + mainButton.height + clmn.spacing

    default property alias sceneData: mainColumn.data

    property alias title: titleLabel.text
    property alias mainButton: mainButton
    property bool backable

    TColumn {
        id: clmn
        y: 20
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: y
        spacing: 30

        TLabel {
            id: titleLabel
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: backable? 36 : 0
            font.pixelSize: 12 * Devices.fontDensity
            font.weight: Font.Medium

            THeaderBackButton {
                visible: backable
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -3
                anchors.right: parent.left
                onClicked: dis.ViewportType.open = false
            }
        }
    }

    Item {
        id: mainColumn
        anchors.top: clmn.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: mainButton.top
        anchors.margins: 20
    }

    TButton {
        id: mainButton
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: clmn.y
        visible: text.length
    }
}

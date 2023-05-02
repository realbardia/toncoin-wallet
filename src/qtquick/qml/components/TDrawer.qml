import QtQuick 2.0
import AsemanQml.Base 2.0
import "../globals"

TPage {
    height: clmn.height + 2*clmn.y

    default property alias sceneData: mainColumn.data

    property alias title: titleLabel.text
    property alias mainButton: mainButton

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
            font.pixelSize: 12 * Devices.fontDensity
            font.weight: Font.Medium
        }

        TColumn {
            id: mainColumn
            anchors.left: parent.left
            anchors.right: parent.right
        }

        TButton {
            id: mainButton
            anchors.left: parent.left
            anchors.right: parent.right
            visible: text.length
        }
    }
}

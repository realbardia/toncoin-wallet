import QtQuick 2.0
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../globals"

TPage {
    id: dis
    height: contentHeight

    readonly property real contentHeight: clmn.height + 3*clmn.y + mainButton.height + clmn.spacing + Devices.navigationBarHeight

    default property alias sceneData: mainColumn.data

    property alias title: titleLabel.text
    property alias mainButton: mainButton
    property alias header: clmn.visible
    property bool backable
    property bool closable

    signal closeRequest()

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: Devices.hideKeyboard()
    }

    TColumn {
        id: clmn
        y: 20
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: y
        spacing: 30

        TLabel {
            id: titleLabel
            horizontalAlignment: Text.AlignLeft
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: backable || closable? 36 : 0
            font.pixelSize: 12 * Devices.fontDensity
            font.weight: Font.Medium

            THeaderBackButton {
                visible: backable
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -3
                anchors.right: parent.left
                onClicked: dis.ViewportType.open = false
            }

            THeaderCloseButton {
                visible: closable
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -1
                anchors.right: parent.left
                onClicked: dis.closeRequest()
            }
        }
    }

    Item {
        id: mainColumn
        anchors.top: clmn.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: mainButton.top
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        clip: true
    }

    TButton {
        id: mainButton
        width: parent.width - clmn.y*2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Devices.navigationBarHeight + clmn.y
        visible: text.length
    }
}

import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TPage {
    id: dis

    signal tagFound(string tag)

    THeaderItem {
        id: header
        anchors.left: parent.left
        anchors.right: parent.right
        title: qsTr("QR Scanner")
    }

    THeaderCloseButton {
        onClicked: dis.ViewportType.open = false
    }

    Item {
        id: scene
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        clip: true

        ZXingCamera {
            width: parent.width
            height: parent.height
            onTagFound: {
                dis.tagFound(tag);
            }
        }

        Rectangle {
            id: focusBorder
            width: parent.width * 0.6
            height: width
            color: "#00000000"
            radius: 12 * Devices.density
            border.width: 1 * Devices.density
            border.color: Colors.accent
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Item {
                id: focusEffectBorder
                anchors.fill: parent
                visible: false

                Rectangle {
                    id: focusInnerBorder
                    color: "#00000000"
                    radius: 12 * Devices.density
                    anchors.fill: parent
                    anchors.margins: 40 * Devices.density
                    border.color: Colors.accent
                    border.width: 1 * Devices.density
                }
            }

            Item {
                id: focusMaskBorder
                anchors.fill: parent
                visible: false

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: 96
                    color: "#ffffff"
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }
            }

            OpacityMask {
                anchors.fill: parent
                source: focusEffectBorder
                maskSource: focusMaskBorder
            }
        }
    }
}

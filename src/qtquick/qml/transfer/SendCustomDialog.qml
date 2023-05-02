import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")

    mainButton {
        text: qsTr("Continue")
        onClicked: Viewport.viewport.append(Qt.createComponent("ReceiveDialog.qml"), {}, "stack")
    }

    TScrollView {
        width: parent.width
        height: Math.min(210 + Math.max(0, recentsList.count*50), Constants.mwin.height-300)

        TListView {
            id: recentsList
            model: 2

            Component.onCompleted: Tools.jsDelayCall(10, recentsList.positionViewAtBeginning)

            header: Item {
                width: recentsList.width
                height: headerColumn.height

                TColumn {
                    id: headerColumn
                    anchors.left: parent.left
                    anchors.right: parent.right

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        font.bold: true
                        text: qsTr("Wallet address or Domain")
                    }

                    TTextArea {
                        width: parent.width
                        placeholderText: qsTr("Enter Wallet Address or Domain...")
                        height: Math.max(contentHeight+18, 50)
                    }

                    TLabel {
                        width: parent.width
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        opacity: 0.4
                        text: qsTr("Paste the 24-letter wallet address of the recipient here or TON DNS, or ask them to send you a ton:// link.")
                    }

                    Item { width: 1; height: 1 }

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        font.bold: true
                        text: qsTr("Recent")
                        visible: recentsList.count > 0
                    }
                }
            }

            delegate: Item {
                width: recentsList.width
                height: clmn.height + 20

                TItemDelegate {
                    anchors.fill: parent

                    TColumn {
                        id: clmn
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 0

                        TLabel {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            text: "ABcd...ef76"
                        }

                        TLabel {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            font.pixelSize: 8 * Devices.fontDensity
                            text: "September 6"
                            opacity: 0.5
                        }
                    }
                }

                Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    height: 1
                    color: Colors.foreground
                    opacity: 0.1
                    visible: model.index > 0
                }
            }
        }
    }
}

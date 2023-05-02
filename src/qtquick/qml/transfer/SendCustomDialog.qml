import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")
    height: contentHeight + scrollArea.height

    property string selectedAddress

    property Item valueItem

    mainButton {
        text: qsTr("Continue")
        onClicked: valueItem = Viewport.viewport.append(send_component, {"address": selectedAddress}, "stack")
        enabled: selectedAddress.length > 0? true : false
    }

    TScrollView {
        id: scrollArea
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
                        onTextChanged: selectedAddress = text
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
                id: item
                width: recentsList.width
                height: clmn.height + 20

                property string address: "5efb8db1-f64f-4a90-a748-e5e9217067db"

                TItemDelegate {
                    anchors.fill: parent
                    onClicked: valueItem = Viewport.viewport.append(send_component, {"address": item.address, "domain": domain.text}, "stack")

                    TColumn {
                        id: clmn
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 0

                        TLabel {
                            id: address
                            anchors.left: parent.left
                            anchors.right: parent.right
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            text: item.address.slice(0,4) + "..." + item.address.slice(item.address.length-4)
                        }

                        TLabel {
                            id: domain
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

    Component {
        id: send_component
        SendValueDialog {
            width: parent.width
            backable: true
            onCloseRequest: dis.ViewportType.open = false
        }
    }
}

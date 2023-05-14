import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")
    height: contentHeight + Math.max(300, scrollArea.height)

    property string selectedAddress
    property variant transactionsModel

    onTransactionsModelChanged: {
        if (!transactionsModel)
            return;

        var added = new Array;
        var items = new Array;
        for (var i=0; i<transactionsModel.count; i++) {
            var t = transactionsModel.get(i);
            var address = t.sent? t.destination : t.source;
            if (added.indexOf(address) >= 0)
                continue;

            var m = {
                "address": address,
                "domain": "",
                "datetime": t.datetime,
            };

            added[added.length] = address;
            items[items.length] = m;
            recentsModel.data = items;
        }
    }

    mainButton {
        text: qsTr("Continue")
        onClicked: TViewport.viewport.append(send_component, {"address": selectedAddress}, "stack")
        enabled: selectedAddress.length > 0? true : false
    }

    TScrollView {
        id: scrollArea
        width: parent.width
        height: Math.min(210 + Math.max(0, recentsList.count*50), GlobalValues.mwin.height-300)

        TListView {
            id: recentsList
            model: ToolkitListModel { id: recentsModel }

            Component.onCompleted: Tools.jsDelayCall(10, recentsList.positionViewAtBeginning)

            header: MouseArea {
                width: recentsList.width
                height: headerColumn.height
                onClicked: Devices.hideKeyboard()

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

                TItemDelegate {
                    anchors.fill: parent
                    onClicked: TViewport.viewport.append(send_component, {"address": model.address, "domain": model.domain}, "stack")

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
                            text: model.address.slice(0,4) + "..." + model.address.slice(model.address.length-4)
                        }

                        TLabel {
                            id: domain
                            anchors.left: parent.left
                            anchors.right: parent.right
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            font.pixelSize: 8 * Devices.fontDensity
                            text: model.domain.length? model.domain : Tools.dateToString(model.datetime, "MMMM dd")
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

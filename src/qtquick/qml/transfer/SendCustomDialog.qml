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

    mainButton {
        anchors.bottomMargin: keyboardPadding + 20
        text: qsTr("Continue")
        onClicked: TViewport.viewport.append(send_component, {"address": selectedAddress}, "stack")
        enabled: selectedAddress.length > 0? true : false
    }

    property real keyboardPadding: Constants.keyboardedView? Devices.keyboardHeight - GlobalValues.keyboardGlobalBottomPadding : Devices.navigationBarHeight

    Behavior on keyboardPadding {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
    }

    TScrollView {
        id: scrollArea
        width: parent.width
        height: Math.min(210 + Math.max(0, recentsList.count*50), GlobalValues.mwin.height-300)

        TListView {
            id: recentsList
            model: RecentModel

            Component.onCompleted: Tools.jsDelayCall(10, recentsList.positionViewAtBeginning)

            header: MouseArea {
                width: recentsList.width
                height: headerColumn.height
                onClicked: Devices.hideKeyboard()

                TColumn {
                    id: headerColumn
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: 20

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Wallet address or Domain")
                    }

                    TTextArea {
                        id: addressField
                        width: parent.width
                        placeholderText: qsTr("Enter Wallet Address or Domain...")
                        horizontalAlignment: Text.AlignLeft
                        height: Math.max(contentHeight+18, 50)
                        onTextChanged: {
                            if (text.indexOf("\n") >= 0) {
                                var pos = input.cursorPosition-1;
                                text = Tools.stringRemove(text, "\n", false);
                                input.cursorPosition = Math.min(pos, text.length);
                                return;
                            }

                            selectedAddress = text
                        }
                        input.onActiveFocusChanged: {
                            if (input.activeFocus) {
                                GlobalValues.keyboardGlobalBottomPadding = Qt.binding(function(){
                                    let minimumAllowedHeight = dis.contentHeight + addressField.height + 50;
                                    let heightWithKeyboard = dis.height - Devices.keyboardHeight;
                                    if (minimumAllowedHeight > heightWithKeyboard)
                                        return (minimumAllowedHeight - heightWithKeyboard);
                                    else
                                        return 0;
                                });
                            } else {
                                GlobalValues.keyboardGlobalBottomPadding = 0;
                            }

                            if (input.activeFocus)
                                GlobalValues.keyboardPaddingMode = input;
                            else if (GlobalValues.keyboardPaddingMode == input)
                                GlobalValues.keyboardPaddingMode = null
                        }
                        Component.onCompleted: {
                            Devices.setupImEventFilter(addressField.input);
                        }
                        Component.onDestruction: if (GlobalValues.keyboardPaddingMode == input) GlobalValues.keyboardPaddingMode = null
                    }

                    TLabel {
                        width: parent.width
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        opacity: 0.4
                        text: qsTr("Paste the 24-letter wallet address of the recipient here or TON DNS, or ask them to send you a ton:// link.")
                    }

                    Item { width: 1; height: 1 }

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
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
                    onClicked: {
                        var m = {
                            "address": model.domain.length? model.domain : model.address,
                            "domain": model.domain,
                            "finalAddress": model.address,
                        };
                        TViewport.viewport.append(send_component, m, "stack");
                    }

                    TColumn {
                        id: clmn
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 20
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 0

                        TLabel {
                            id: address
                            anchors.left: parent.left
                            anchors.right: parent.right
                            horizontalAlignment: Text.AlignLeft
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            text: model.address.slice(0,4) + "..." + model.address.slice(model.address.length-4)
                        }

                        TLabel {
                            id: domain
                            anchors.left: parent.left
                            anchors.right: parent.right
                            horizontalAlignment: Text.AlignLeft
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
                    anchors.margins: 20
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

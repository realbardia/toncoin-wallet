import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")
    height: contentHeight + 300

    mainButton {
        text: qsTr("Continue")
        anchors.bottomMargin: keyboardPadding + 20
        enabled: amountField.text*1 > 0 && !insufficientLabel.visible? true : false
        onClicked: TViewport.viewport.append(confirm_component, {"address": address, "amount": amountField.text}, "stack")
    }

    property real keyboardPadding: Constants.keyboardedView? Devices.keyboardHeight - GlobalValues.keyboardGlobalBottomPadding : Devices.navigationBarHeight

    Behavior on keyboardPadding {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
    }

    property string address
    property string domain
    property string finalAddress: address

    Item {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        height: 30

        TRow {
            spacing: 4
            anchors.left: parent.left
            anchors.right: editBtn.left
            anchors.verticalCenter: parent.verticalCenter

            TLabel {
                opacity: 0.6
                text: qsTr("Send to:")
            }

            TLabel {
                text: finalAddress.slice(0,4) + "..." + finalAddress.slice(finalAddress.length-4)
            }

            TLabel {
                opacity: 0.6
                text: domain
            }
        }

        TButton {
            id: editBtn
            height: 30
            anchors.right: parent.right
            highlight: true
            flat: true
            text: qsTr("Edit")
            onClicked: dis.ViewportType.open = false
        }
    }

    MouseArea {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 40
        anchors.verticalCenter: parent.verticalCenter
        height: 100
        onClicked: {
            amountField.focus = true;
            amountField.input.cursorPosition = amountField.text.length;
        }

        TTextField {
            id: amountField
            anchors.centerIn: parent
            height: 54
            width: Math.max(100, contentWidth + 56)
            highlightArea: false
            placeholderText: "0"
            validator: RegularExpressionValidator { regularExpression: /\d+(?:\.\d+)/ }
            font.pixelSize: 20 * Devices.fontDensity
            color: insufficientLabel.visible? Colors.red : Colors.foreground
            input.inputMethodHints: Qt.ImhDigitsOnly
            iosStyle: false
            input.onActiveFocusChanged: {
                if (input.activeFocus) {
                    GlobalValues.keyboardGlobalBottomPadding = Qt.binding(function(){
                        let minimumAllowedHeight = dis.contentHeight + 150;
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
                Devices.setupImEventFilter(amountField.input);
                focus = true;
            }
            Component.onDestruction: if (GlobalValues.keyboardPaddingMode == input) GlobalValues.keyboardPaddingMode = null

            onTextChanged: {
                if (text == "00") {
                    text = "0.";
                    input.cursorPosition = 2;
                } else if (text.length > lastLength && text == "0") {
                    text += '.';
                    input.cursorPosition = 2;
                }
                lastLength = text.length;
            }

            property int lastLength

            LayoutMirroring.enabled: false
            LayoutMirroring.childrenInherit: true

            leftPadding: 46

            StickerItem {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -3
                anchors.left: parent.left
                width: 44
                height: width
                autoPlay: true
                source: "qrc:/ton/common/stickers/Main.tgs"
            }

            TLabel {
                id: insufficientLabel
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.bottom
                color: Colors.red
                font.pixelSize: 8 * Devices.fontDensity
                text: qsTr("Insufficient funds")
                visible: amountField.text*1 > balance.text*1? true : false
            }
        }
    }

    TSwitch {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        onCheckedChanged: if (checked) amountField.text = balance.text

        TRow {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            spacing: 4

            TLabel {
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Send all")
            }

            StickerItem {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -2
                width: 22
                loops: 0
                height: width
                autoPlay: true
                source: "qrc:/ton/common/stickers/Main.tgs"
            }

            TLabel {
                id: balance
                anchors.verticalCenter: parent.verticalCenter
                text: AppSettings.balance
            }
        }
    }

    Component {
        id: confirm_component
        SendConfirmDialog {
            width: parent.width
            backable: true
            onCloseRequest: dis.closeRequest()
        }
    }
}

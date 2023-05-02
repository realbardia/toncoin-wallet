import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")

    mainButton {
        text: qsTr("Continue")
        onClicked: Viewport.viewport.append(confirm_component, {"address": address, "domain": domain, "value": valueField.text}, "stack")
    }

    property string address
    property string domain

    Item {
        anchors.left: parent.left
        anchors.right: parent.right
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
                text: address.slice(0,4) + "..." + address.slice(address.length-4)
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

    TTextField {
        id: valueField
        anchors.centerIn: parent
        height: 54
        width: Math.max(100, contentWidth + 56)
        highlightArea: false
        placeholderText: "0"
        validator: RegularExpressionValidator { regularExpression: /\d+(?:\.\d+)/ }
        font.pixelSize: 20 * Devices.fontDensity
        color: insufficientLabel.visible? Colors.red : Colors.foreground
        Component.onCompleted: {
            focus = true;
        }

        leftPadding: 46

        TgStickerItem {
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
            visible: valueField.text*1 > balance.text*1? true : false
        }
    }

    TSwitch {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onCheckedChanged: if (checked) valueField.text = balance.text

        TRow {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            spacing: 4

            TLabel {
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Send all")
            }

            TgStickerItem {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -2
                width: 22
                height: width
                autoPlay: true
                source: "qrc:/ton/common/stickers/Main.tgs"
            }

            TLabel {
                id: balance
                anchors.verticalCenter: parent.verticalCenter
                text: "12.3456"
            }
        }
    }

    Component {
        id: confirm_component
        SendConfirmDialog {
            width: parent.width
            backable: true
        }
    }
}

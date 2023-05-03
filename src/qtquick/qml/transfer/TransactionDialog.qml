import QtQuick 2.15
import Toolkit 1.0
import Viewport 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Transaction")
    height: contentHeight + area.height

    mainButton {
        text: canceled? qsTr("Retry to send TON to this address") : qsTr("Send TON to this address")
        onClicked: TViewport.viewport.append(send_component, {"address": address, "domain": domain}, "stack")
    }

    property bool pending
    property bool canceled
    property string amount: "5.1234"
    property string fee: "0.00003434"
    property bool send
    property string comment
    property string address
    property string domain
    property string transaction

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        TRow {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 0

            StickerItem {
                anchors.verticalCenter: parent.verticalCenter
                width: 34
                height: width
                autoPlay: true
                source: "qrc:/ton/common/stickers/Main.tgs"
            }

            TRow {
                spacing: 2

                TLabel {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: 4
                    font.pixelSize: 16 * Devices.fontDensity
                    color: send? Colors.red : Colors.green
                    font.weight: Font.Medium
                    text: {
                        var idx = amount.indexOf(".");
                        if (idx < 0)
                            return amount;
                        return amount.slice(0, idx);
                    }
                }

                TLabel {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: 6
                    font.pixelSize: 12 * Devices.fontDensity
                    color: send? Colors.red : Colors.green
                    visible: text.length
                    text: {
                        var idx = amount.indexOf(".");
                        if (idx < 0)
                            return "";
                        return amount.slice(idx);
                    }
                }
            }
        }

        TColumn {
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 0
            opacity: 0.6

            TLabel {
                anchors.left: parent.left
                anchors.right: parent.right
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 8 * Devices.fontDensity
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: qsTr("%1 transaction fee").arg(fee)
            }

            TLabel {
                anchors.left: parent.left
                anchors.right: parent.right
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 8 * Devices.fontDensity
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: "Sept 6, 2022 at 22:22"
                visible: !canceled
            }

            TLabel {
                anchors.left: parent.left
                anchors.right: parent.right
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 8 * Devices.fontDensity
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                color: Colors.red
                text: qsTr("Canceled")
                visible: canceled
            }

            TRow {
                id: connectionRow
                anchors.horizontalCenter: parent.horizontalCenter
                visible: pending
                spacing: 4

                Loader {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: -2
                    width: 14
                    height: width
                    active: connectionRow.visible
                    sourceComponent: StickerItem {
                        anchors.fill: parent
                        autoPlay: true
                        source: "qrc:/ton/common/stickers/Material Busy Accented.tgs"
                    }
                }

                TLabel {
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 8 * Devices.fontDensity
                    color: Colors.accent
                    text: qsTr("Pending")
                }
            }
        }

        Item {
            anchors.right: parent.right
            anchors.left: parent.left
            height: commentLabel.height + commentLabel.y*2
            visible: commentLabel.text.length

            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: commentLabel.contentWidth + 2*commentLabel.x
                height: parent.height
                color: Colors.foreground
                radius: Constants.controlsRoundness
                opacity: 0.1
            }

            TLabel {
                id: commentLabel
                horizontalAlignment: Text.AlignHCenter
                y: 8
                x: 10
                width: parent.width - 2*x
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                opacity: 0.8
                text: comment
            }
        }

        TLabel {
            width: parent.width
            color: Colors.accent
            font.pixelSize: 8 * Devices.fontDensity
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.bold: true
            text: qsTr("Details")
        }

        Item {
            height: Constants.itemsHeight
            width: parent.width
            visible: domain.length

            TLabel {
                anchors.left: parent.left
                anchors.right: domainLabel.left
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                maximumLineCount: 1
                elide: Text.ElideRight
                text: qsTr("Recipient")
            }

            TLabel {
                id: domainLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: domain
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 1
                color: Colors.foreground
                opacity: 0.1
            }
        }

        Item {
            height: Constants.itemsHeight
            width: parent.width
            visible: address.length

            TLabel {
                anchors.left: parent.left
                anchors.right: addressLabel.left
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                maximumLineCount: 1
                elide: Text.ElideRight
                text: qsTr("Recipient address")
            }

            TLabel {
                id: addressLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: address.slice(0,4) + "..." + address.slice(address.length-4)
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 1
                color: Colors.foreground
                opacity: 0.1
            }
        }

        Item {
            height: Constants.itemsHeight
            width: parent.width
            visible: transaction.length

            TLabel {
                anchors.left: parent.left
                anchors.right: transactionLabel.left
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                maximumLineCount: 1
                elide: Text.ElideRight
                text: qsTr("Transaction")
            }

            TLabel {
                id: transactionLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: transaction.slice(0,6) + "..." + transaction.slice(transaction.length-6)
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 1
                color: Colors.foreground
                opacity: 0.1
            }
        }

        TButton {
            flat: true
            highlight: true
            height: 36
            text: qsTr("View in explorer")
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

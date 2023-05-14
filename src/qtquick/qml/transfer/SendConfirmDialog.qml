import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")
    backable: true
    height: contentHeight + 300

    mainButton {
        text: qsTr("Continue and send")
        enabled: !estimater.running
        onClicked: TViewport.viewport.append(sending_component, {}, "stack")
    }

    property alias address: estimater.destinationAddress
    property string domain
    property alias amount: estimater.amount
    property alias message: comment.text

    FeeEstimater {
        id: estimater
        message: dis.message
        wallet: WalletItem {
            backend: MainBackend
            publicKey: AppSettings.loggedInPublicKey
        }
        force: false
        Component.onCompleted: {
            estimate();
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: -20
        anchors.topMargin: -8
        height: 1
        color: Colors.foreground
        opacity: 0.1
    }

    TBusyIndicator {
        anchors.centerIn: parent
        width: 42
        height: width
        running: estimater.running
        accented: true
    }

    TScrollView {
        anchors.fill: parent
        visible: !estimater.running

        TFlickable {
            id: flick
            contentWidth: scene.width
            contentHeight: scene.height
            flickableDirection: Flickable.VerticalFlick

            MouseArea {
                id: scene
                width: flick.width
                height: Math.max(flick.height, clmn.height + 2*clmn.y)
                onClicked: Devices.hideKeyboard()

                TColumn {
                    id: clmn
                    y: 0
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: y
                    spacing: 8

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Comment (Optional)")
                    }

                    TTextArea {
                        id: comment
                        width: parent.width
                        height: Math.max(50, contentHeight + 20)
                        horizontalAlignment: Text.AlignLeft
                        placeholderText: qsTr("Comment")
                    }

                    TColumn {
                        width: parent.width
                        spacing: 0

                        TLabel {
                            width: parent.width
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            font.pixelSize: 8 * Devices.fontDensity
                            opacity: 0.6
                            text: qsTr("The comment is visible to everyone. You must include the note when sending to an exchange.")
                        }

                        TLabel {
                            width: parent.width
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            font.pixelSize: 8 * Devices.fontDensity
                            color: comment.text.length > Constants.commentLimit? Colors.red : Colors.warnings
                            visible: comment.text.length + 32 > Constants.commentLimit
                            text: {
                                if (comment.text.length > Constants.commentLimit)
                                    return qsTr("Message size has been exceeded by %1 charcaters.").arg(comment.text.length - Constants.commentLimit)
                                else
                                    return qsTr("%1 characters left.").arg(Constants.commentLimit - comment.text.length);
                            }
                        }
                    }

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Details")
                    }

                    Item {
                        height: Constants.itemsHeight
                        width: parent.width

                        TLabel {
                            anchors.left: parent.left
                            anchors.right: addressLabel.left
                            anchors.verticalCenter: parent.verticalCenter
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            maximumLineCount: 1
                            elide: Text.ElideRight
                            text: qsTr("Recipient")
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

                        TLabel {
                            anchors.left: parent.left
                            anchors.right: amountRow.left
                            anchors.verticalCenter: parent.verticalCenter
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            maximumLineCount: 1
                            elide: Text.ElideRight
                            text: qsTr("Amount")
                        }

                        TRow {
                            id: amountRow
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            spacing: 2

                            StickerItem {
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.verticalCenterOffset: -1
                                width: 18
                                height: width
                                autoPlay: true
                                loops: 1
                                source: "qrc:/ton/common/stickers/Main.tgs"
                            }

                            TLabel {
                                anchors.verticalCenter: parent.verticalCenter
                                text: amount
                            }
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

                        TLabel {
                            anchors.left: parent.left
                            anchors.right: feeRow.left
                            anchors.verticalCenter: parent.verticalCenter
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            horizontalAlignment: Text.AlignLeft
                            maximumLineCount: 1
                            elide: Text.ElideRight
                            text: qsTr("Fee")
                        }

                        TRow {
                            id: feeRow
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            spacing: 2

                            StickerItem {
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.verticalCenterOffset: -1
                                width: 18
                                height: width
                                autoPlay: true
                                loops: 1
                                source: "qrc:/ton/common/stickers/Main.tgs"
                            }

                            TLabel {
                                anchors.verticalCenter: parent.verticalCenter
                                text: "≈ " + estimater.fee
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: sending_component
        SendingTonDialog {
            ViewportType.gestureWidth: 0
            ViewportType.blockBack: true
            width: parent.width
            closable: true
            backable: false
            amount: dis.amount
            address: dis.address
            message: comment.text
            feeEstimater: estimater
            onCloseRequest: dis.closeRequest()
        }
    }
}

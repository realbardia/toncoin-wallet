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
        onClicked: TViewport.viewport.append(sending_component, {}, "stack")
    }

    property alias address: estimater.destinationAddress
    property string domain
    property string amount//: estimater.amount
    property alias message: comment.text

    WalletItem {
        id: wallet
        backend: MainBackend
        publicKey: AppSettings.loggedInPublicKey
    }

    FeeEstimater {
        id: estimater
        message: dis.message
        wallet: WalletItem {
            backend: MainBackend
            publicKey: AppSettings.loggedInPublicKey
        }
        amount: "0.000001"
        force: false
        onRunningChanged: console.debug(running)
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

    TScrollView {
        anchors.fill: parent

        TFlickable {
            id: flick
            contentWidth: scene.width
            contentHeight: scene.height
            flickableDirection: Flickable.VerticalFlick

            Item {
                id: scene
                width: flick.width
                height: Math.max(flick.height, clmn.height + 2*clmn.y)

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
                        font.bold: true
                        text: qsTr("Comment (Optional)")
                    }

                    TTextArea {
                        id: comment
                        width: parent.width
                        height: Math.max(50, contentHeight + 20)
                        placeholderText: qsTr("Comment")
                    }

                    TColumn {
                        width: parent.width
                        spacing: 0

                        TLabel {
                            width: parent.width
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                            font.pixelSize: 8 * Devices.fontDensity
                            opacity: 0.6
                            text: qsTr("The comment is visible to everyone. You must include the note when sending to an exchange.")
                        }

                        TLabel {
                            width: parent.width
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
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
                                text: "≈ 0.007"
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
            onCloseRequest: dis.closeRequest()
        }
    }
}

import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import AsemanQml.MaterialIcons 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TListView {
    id: listv

    section.property: "date"
    section.delegate: Item {
        width: listv.width
        height: 36

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 16
            anchors.rightMargin: 16
            anchors.bottom: parent.bottom
            font.bold: true
            text: section
        }
    }

    delegate: Item {
        width: listv.width
        height: clmn.height + clmn.y*2.5

        TItemDelegate {
            anchors.fill: parent

            TColumn {
                id: clmn
                y: 10
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: y
                spacing: 4

                TRow {
                    spacing: 2
                    anchors.left: parent.left

                    TgStickerItem {
                        anchors.verticalCenter: parent.verticalCenter
                        width: 18
                        height: width
                        autoPlay: true
                        loops: 1
                        source: "qrc:/ton/common/stickers/Main.tgs"
                    }

                    TRow {
                        spacing: 0

                        TLabel {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.verticalCenterOffset: 2
                            font.pixelSize: 11 * Devices.fontDensity
                            font.weight: Font.Medium
                            color: model.send? Colors.red : Colors.green
                            text: {
                                var idx = model.value.indexOf(".");
                                if (idx < 0)
                                    return model.value;
                                return model.value.slice(0, idx);
                            }
                        }

                        TLabel {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.verticalCenterOffset: 3
                            font.pixelSize: 8 * Devices.fontDensity
                            color: model.send? Colors.red : Colors.green
                            visible: text.length
                            text: {
                                var idx = model.value.indexOf(".");
                                if (idx < 0)
                                    return "";
                                return model.value.slice(idx);
                            }
                        }
                    }

                    TLabel {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.verticalCenterOffset: 3
                        font.pixelSize: 8 * Devices.fontDensity
                        opacity: 0.6
                        text: model.send? qsTr("to") : qsTr("from")
                    }
                }

                TWalletAddress {
                    anchors.left: parent.left
                    anchors.leftMargin: -6
                    height: 20
                    address: model.address
                    font.pixelSize: 8 * Devices.fontDensity
                    elideCount: 6
                }

                TLabel {
                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    opacity: 0.6
                    font.pixelSize: 8 * Devices.fontDensity
                    text: qsTr("-%1 storage fee").arg(model.fee)
                }

                Item {
                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.leftMargin: 2
                    height: comment.height + comment.y*2
                    visible: comment.text.length

                    Rectangle {
                        width: comment.contentWidth + 2*comment.x
                        height: parent.height
                        color: Colors.foreground
                        radius: Constants.controlsRoundness
                        opacity: 0.1
                    }

                    TLabel {
                        id: comment
                        y: 8
                        x: y
                        width: parent.width - 2*x
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        text: model.comment
                        opacity: 0.8
                    }
                }
            }

            TLabel {
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.margins: 18
                opacity: 0.6
                text: model.time
            }
        }

        Rectangle {
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.leftMargin: 16
            anchors.rightMargin: 16
            anchors.bottom: parent.bottom
            width: parent.width
            height: 1
            opacity: 0.1
            color: Colors.foreground
            visible: model.index != listv.count
        }
    }
}

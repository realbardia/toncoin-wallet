import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TDrawer {
    height: contentHeight + area.height
    title: qsTr("TON Transfer")

    property string amount: "0.05"
    property string fee: "0.005"
    property string address: "223f7e11-e403-449f-8744-3bd7cb8d61d2"
    property bool done

    mainButton {
        height: 1
        anchors.bottomMargin: -5
    }

    Timer {
        id: testTimer
        repeat: false
        interval: 2000
        onTriggered: {
            Devices.triggerVibrateFeedback();
            busyIndicator.running = false;
            done = true;
        }
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        anchors.verticalCenter: parent.verticalCenter
        spacing: 8

        Item {
            width: 1
            height: 20
        }

        TRow {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 2

            StickerItem {
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: -1
                width: 32
                height: width
                autoPlay: true
                loops: 1
                source: "qrc:/ton/common/stickers/Main.tgs"
            }

            TLabel {
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 16 * Devices.fontDensity
                text: amount
            }
        }

        Item {
            width: 1
            height: 20
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
                anchors.right: feeLabel.left
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                horizontalAlignment: Text.AlignLeft
                maximumLineCount: 1
                elide: Text.ElideRight
                text: qsTr("Fee")
            }

            TLabel {
                id: feeLabel
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                text: "≈ " + fee + " TON"
            }
        }

        Item {
            width: 1
            height: 20
        }

        Item {
            width: parent.width
            height: 42

            TButton {
                width: parent.width/2 - 6
                text: qsTr("Cancel")
                color: Colors.accent
                backgroundColor: "#e6f0f8"
                opacity: done? 0 : 1
                scale: done? 0.5 : 1
                visible: opacity > 0

                Behavior on opacity {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
                }
                Behavior on scale {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
                }
            }

            TButton {
                x: ratio * (parent.width/2 - width/2) + (1 - ratio)*(parent.width - width)
                width: ratio * height + (1 - ratio)*(parent.width/2 - 6)
                radius: done? height/2 : Constants.controlsRoundness
                text: done? "" : qsTr("Confirm")
                visible: true
                icon.text: done? MaterialIcons.mdi_check : ""
                icon.font.pixelSize: 12 * Devices.fontDensity
                onClicked: {
                    if (busyIndicator.running)
                        return;

                    busyIndicator.running = true;
                    testTimer.restart()
                }

                property real ratio: done? 1 : 0

                Behavior on radius {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
                }
                Behavior on ratio {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
                }

                TBusyIndicator {
                    id: busyIndicator
                    width: 26
                    height: 26
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 8
                    accented: false
                }
            }
        }
    }
}

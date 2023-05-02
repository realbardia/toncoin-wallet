import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import AsemanQml.MaterialIcons 2.0
import TonToolkit 1.0
import "../transfer" as Transfer
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    readonly property real headerHeight: 240
    readonly property real headerRatio: Math.max(0, (headerHeight + mapListener.result.y)/headerHeight)

    property string balance: "56.2322"
    property string balanceUSD: "89.6"

    ListModel {
        id: testModel
        ListElement {
            value: "1.091"
            send: false
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 5"
        }
        ListElement {
            value: "10"
            send: true
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 5"
        }
        ListElement {
            value: "2"
            send: false
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 4"
        }
        ListElement {
            value: "1.091"
            send: false
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 2"
        }
        ListElement {
            value: "10"
            send: true
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 2"
        }
        ListElement {
            value: "2"
            send: false
            address: "58d6a9d1-ea4c-4619-93a0-8fdbbe9b964d"
            fee: "0.000012345"
            comment: "Testing peyments, D."
            time: "12:55"
            date: "September 1"
        }
    }

    PointMapListener {
        id: mapListener
        source: listv.headerItem
        dest: page
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: headerArea.bottom
        anchors.bottom: parent.bottom
        radius: Constants.roundness
        color: Colors.background

        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.verticalCenter
            anchors.bottom: parent.bottom
            color: Colors.background
        }

        Loader {
            anchors.centerIn: parent
            width: 120
            height: width
            active: loadingTimer.counter == 0
            sourceComponent: TgStickerItem {
                anchors.fill: parent
                autoPlay: true
                source: "qrc:/ton/common/stickers/Loading.tgs"
            }
        }

        Loader {
            anchors.fill: parent
            active: loadingTimer.counter < 4 && loadingTimer.counter != 0
            sourceComponent: EmptyWalletElement {
                anchors.fill: parent
                anchors.margins: 20
            }
        }
    }

    Timer {
        id: loadingTimer
        interval: 1500
        repeat: true
        running: true
        onTriggered: {
            counter++
            switch (counter) {
            case 1:
                break;
            case 4:
                listv.model = testModel;
                break;
            }

        }

        property int counter
    }

    Item {
        anchors.fill: parent
        anchors.topMargin: Devices.standardTitleBarHeight + Devices.statusBarHeight
        clip: true

        TScrollView {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: page.height
            clip: true

            TransactionsList {
                id: listv
                anchors.fill: parent
                header: Item {
                    width: listv.width
                    height: headerHeight
                }
            }
        }
    }

    Item {
        id: headerArea
        width: parent.width
        height: Math.max(Devices.standardTitleBarHeight, mapListener.result.y + headerHeight)

        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            transform: Item.Top
            height: headerHeight - Devices.standardTitleBarHeight + Devices.statusBarHeight
            scale: 0.8 + 0.2 * Math.min(1, headerRatio)
            opacity: scale

            TColumn {
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -54 * Devices.density
                spacing: 0

                TWalletAddress {
                    anchors.horizontalCenter: parent.horizontalCenter
                    highlightColor: "#fff"
                    color: "#fff"
                    address: AppSettings.privateKey
                }

                TRow {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 0

                    TgStickerItem {
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
                            color: "#fff"
                            font.weight: Font.Medium
                            text: {
                                var idx = balance.indexOf(".");
                                if (idx < 0)
                                    return balance;
                                return balance.slice(0, idx);
                            }
                        }

                        TLabel {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.verticalCenterOffset: 6
                            font.pixelSize: 12 * Devices.fontDensity
                            color: "#fff"
                            visible: text.length
                            text: {
                                var idx = balance.indexOf(".");
                                if (idx < 0)
                                    return "";
                                return balance.slice(idx);
                            }
                        }
                    }
                }
            }

            TButton {
                anchors.left: parent.left
                anchors.right: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.margins: 20
                anchors.rightMargin: 6
                text: qsTr("Receive")
                icon.text: MaterialIcons.mdi_arrow_bottom_left
                icon.font.pixelSize: 12 * Devices.fontDensity
                onClicked: Viewport.viewport.append(receive_component, {}, "tdrawer")
            }

            TButton {
                anchors.left: parent.horizontalCenter
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 20
                anchors.leftMargin: 6
                text: qsTr("Send")
                icon.text: MaterialIcons.mdi_arrow_top_right
                icon.font.pixelSize: 12 * Devices.fontDensity
                onClicked: Viewport.viewport.append(send_component, {}, "tdrawer")
            }
        }

        Rectangle {
            anchors.fill: parent
            opacity: 1 - Math.pow(Math.min(1, headerRatio), 2)
            gradient: Gradient {
                GradientStop { position: 0.0; color: page.color }
                GradientStop { position: 0.7; color: page.color }
                GradientStop { position: 1.0; color: "transparent" }
            }
        }

        Item {
            anchors.left: parent.left
            anchors.right: parent.right
            height: Devices.standardTitleBarHeight
            y: Devices.statusBarHeight

            TColumn {
                anchors.centerIn: parent
                spacing: 0
                opacity: 1 - Math.min(1, headerRatio)

                TRow {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 0

                    TgStickerItem {
                        anchors.verticalCenter: parent.verticalCenter
                        width: 18
                        height: width
                        autoPlay: true
                        source: "qrc:/ton/common/stickers/Main.tgs"
                        loops: 0
                    }

                    TLabel {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.verticalCenterOffset: 2
                        font.pixelSize: 9 * Devices.fontDensity
                        text: balance
                        color: "#fff"
                    }
                }

                TLabel {
                    anchors.horizontalCenter: parent.horizontalCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    maximumLineCount: 1
                    elide: Text.ElideRight
                    color: "#fff"
                    text: "≈ $" + balanceUSD
                    font.pixelSize: 7 * Devices.fontDensity
                    opacity: 0.6
                }
            }

            TButton {
                flat: true
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.margins: 6 * Devices.density
                width: height
                icon.text: MaterialIcons.mdi_settings_outline
                icon.font.pixelSize: 15 * Devices.fontDensity
                highlightColor: "#fff"
            }
        }
    }

    Component {
        id: receive_component
        Transfer.ReceiveDialog {
            width: page.width
        }
    }

    Component {
        id: send_component
        Transfer.SendCustomDialog {
            width: page.width
        }
    }
}

import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    id: recovertPage

    property alias dialogOpened: warnDialog.opened
    property bool doneVisible: true
    property alias publicKey: rmodel.publicKey

    QtObject {
        id: prv

        property variant startDate
        property int retryCount: 0

        Component.onCompleted: startDate = new Date
    }

    Item {
        id: recoveryScene
        anchors.fill: parent
        anchors.topMargin: Devices.statusBarHeight
        clip: true

        TScrollView {
            anchors.fill: parent

            TGridView {
                id: gridv
                cellWidth: width / Math.floor(width/150)
                cellHeight: 40
                model: RecoveryPhrasesModel {
                    id: rmodel
                    backend: MainBackend
                }
                header: Item {
                    width: gridv.width
                    height: headerScene.height
                    onHeightChanged: gridv.positionViewAtBeginning()
                }

                footer: Item {
                    width: gridv.width
                    height: 180

                    TColumn {
                        anchors.centerIn: parent
                        anchors.verticalCenterOffset: -15

                        TBusyIndicator {
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 42
                            running: rmodel.refreshing
                            accented: true
                            visible: running
                        }

                        TButton {
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 160
                            visible: doneVisible && !rmodel.refreshing
                            text: qsTr("Done")
                            onClicked: {
                                let msecs = (new Date).getTime() - prv.startDate.getTime();
                                prv.retryCount++;
                                if (msecs < 30000)
                                    warnDialog.open();
                                else
                                    TViewport.viewport.append(test_time_component, {}, "stack")
                            }
                        }
                    }
                }

                delegate: Item {
                    width: gridv.cellWidth
                    height: gridv.cellHeight

                    TRow {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.leftMargin: 50
                        anchors.verticalCenter: parent.verticalCenter

                        TLabel {
                            opacity: 0.4
                            text: (model.index+1)  + "."
                        }
                        TLabel {
                            text: model.text
                        }
                    }
                }
            }
        }

        Item {
            id: headerBackground
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: Math.max(headerScene.height + mapListener.result.y - bodyLabel.height - 40, Devices.standardTitleBarHeight)

            property real ratio: Math.min(1, (height - Devices.standardTitleBarHeight) / (headerScene.height - Devices.standardTitleBarHeight - bodyLabel.height - 40))

            PointMapListener {
                id: mapListener
                source: gridv.headerItem
                dest: recoveryScene
            }

            Item {
                id: headerScene
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 50
                height: stickerItem.height + bodyLabel.height + headerLabel.height + 100

                TLabel {
                    id: bodyLabel
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 30 - mapListener.result.y
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    font.weight: Font.Light
                    text: qsTr("Write down these 24 words in this exact order and keep them in a secret place. Do not share this list with anyone. If you lose it, you will irrevocably lose access to your TON account.")
                }

                Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    height: Math.max(headerLabel.y + headerLabel.height, Devices.standardTitleBarHeight)
                    color: Colors.background
                }

                StickerItem {
                    id: stickerItem
                    transformOrigin: Item.Top
                    anchors.top: parent.top
                    anchors.topMargin: 30
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: 100
                    height: width
                    autoPlay: true
                    source: "qrc:/ton/common/stickers/Recovery Phrase.tgs"
                    scale: headerBackground.ratio
                    opacity: headerBackground.ratio
                }

                THeaderLabel {
                    id: headerLabel
                    y: ((1 - headerBackground.ratio) * (Devices.standardTitleBarHeight - height)/2) + (stickerItem.height + 14 + stickerItem.y) * (headerBackground.ratio)
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Your Recovery Phrase")
                    transformOrigin: Item.Left
                    scale: 0.6 + headerBackground.ratio * 0.4
                }
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 1
                color: Colors.foreground
                opacity: 0.1 * (1 - headerBackground.ratio)
            }
        }
    }

    THeaderBackButton {
        onClicked: recovertPage.ViewportType.open = false
    }

    TDialog {
        id: warnDialog
        anchors.fill: parent
        title: qsTr("Sure done?")
        buttons: prv.retryCount < 2? [qsTr("Ok, sorry")] : [qsTr("Skip"), qsTr("Ok, sorry")]
        onButtonClicked: {
            if (prv.retryCount < 2) {
                warnDialog.close();
                return;
            }

            switch (index) {
            case 0:
                TViewport.viewport.append(test_time_component, {}, "stack");
                warnDialog.close();
                break;
            case 1:
                warnDialog.close();
                break;
            }
        }

        TLabel {
            width: Math.min(recovertPage.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("You didn't have enough time to write these words down.")
        }
    }

    Component {
        id: test_time_component
        TestTimePage {
            id: tpage
            anchors.fill: parent
            publicKey: recovertPage.publicKey
        }
    }
}


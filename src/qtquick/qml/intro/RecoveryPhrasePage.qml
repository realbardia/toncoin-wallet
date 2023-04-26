import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Controls 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    id: recovertPage

    property alias dialogOpened: warnDialog.opened

    QtObject {
        id: prv

        property variant startDate
        property int retryCount: 0

        Component.onCompleted: startDate = new Date
    }

    TScrollView {
        anchors.fill: parent

        TGridView {
            id: gridv
            cellWidth: width / Math.floor(width/150)
            cellHeight: 50
            model: 24
            header: Item {
                width: gridv.width
                height: headerScene.height
                onHeightChanged: gridv.positionViewAtBeginning()
            }

            footer: Item {
                width: gridv.width
                height: 180

                TButton {
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: -15
                    width: 160
                    text: qsTr("Done")
                    onClicked: {
                        let msecs = (new Date).getTime() - prv.startDate.getTime();
                        prv.retryCount++;
                        if (msecs < 30000)
                            warnDialog.open();
                        else
                            Viewport.viewport.append(test_time_component, {}, "page")
                    }
                }
            }

            delegate: Item {
                width: gridv.cellWidth
                height: gridv.cellHeight

                TRow {
                    anchors.centerIn: parent

                    TLabel {
                        opacity: 0.4
                        text: (model.index+1)  + "."
                    }
                    TLabel {
                        text: qsTr("Word %1").arg(model.index+1)
                    }
                }
            }
        }
    }

    Item {
        id: headerBackground
        anchors.left: parent.left
        anchors.right: parent.right
        height: Math.max(headerScene.height + mapListener.result.y - bodyLabel.height - 40, Devices.standardTitleBarHeight)

        property real ratio: Math.min(1, (height - Devices.standardTitleBarHeight) / (headerScene.height - Devices.standardTitleBarHeight - bodyLabel.height - 40))

        PointMapListener {
            id: mapListener
            source: gridv.headerItem
            dest: recovertPage
        }

        Item {
            id: headerScene
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            height: stickerItem.height + 200

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

            TgStickerItem {
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

    HeaderMenuButton {
        ratio: 1
        buttonColor: Colors.foreground
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
                Viewport.viewport.append(test_time_component, {}, "page");
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
        }
    }
}


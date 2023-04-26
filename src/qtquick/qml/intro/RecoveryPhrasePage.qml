import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Controls 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    id: recovertPage

    TGridView {
        id: gridv
        anchors.fill: parent
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
                onClicked: Viewport.viewport.append(success_component, {}, "page")
            }
        }

        delegate: Item {
            width: gridv.cellWidth
            height: gridv.cellHeight

            TRow {
                anchors.centerIn: parent

                TLabel {
                    opacity: 0.7
                    text: (model.index+1)  + "."
                }
                TLabel {
                    text: qsTr("Word %1").arg(model.index+1)
                }
            }
        }
    }

    HScrollBar {
        scrollArea: gridv
        color: Colors.foreground
        anchors.right: parent.right
        height: gridv.height
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

    Component {
        id: success_component
        SuccessPage {
            anchors.fill: parent
        }
    }
}


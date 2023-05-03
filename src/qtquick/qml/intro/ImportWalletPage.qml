import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TPage {
    id: recovertPage

    property alias dialogOpened: warnDialog.opened

    MapObject {
        id: wordsMap
    }

    TScrollView {
        anchors.fill: parent

        TListView {
            id: listv
            model: 24
            spacing: 8

            highlightMoveDuration: 200
            highlightRangeMode: ListView.ApplyRange
            preferredHighlightBegin: 0
            preferredHighlightEnd: height - 100

            signal focusOn(int index)

            header: Item {
                width: listv.width
                height: headerScene.height
                onHeightChanged: listv.positionViewAtBeginning()
            }

            footer: Item {
                width: listv.width
                height: 100

                onFocusChanged: {
                    if (!focus)
                        return;

                    continueBtn.focus = true;
                    continueBtn.forceActiveFocus();
                }

                TButton {
                    id: continueBtn
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: -15
                    width: 200
                    text: qsTr("Continue")
                    enabled: wordsMap.count == listv.count
                    onClicked: {
                        if (!wordsMap.contains(0) || wordsMap.value(0).length == 0)
                            warnDialog.open()
                        else
                            TViewport.viewport.append(wallet_success_component, {}, "stack")
                    }
                }
            }

            delegate: Item {
                width: listv.width
                height: Constants.itemsHeight

                property alias text: textField.text

                onFocusChanged: {
                    if (!focus)
                        return;

                    textField.focus = true;
                    textField.forceActiveFocus();
                }

                TTextField {
                    id: textField
                    width: 200
                    anchors.centerIn: parent
                    leftPadding: 24
                    onTextChanged: {
                        wordsMap.remove(model.index);
                        if (text.length)
                            wordsMap.insert(model.index, text);
                    }
                    onTabPressed: {
                        if (model.index < listv.count-1)
                            listv.currentIndex = model.index+1;
                        else
                            listv.footerItem.focus = true;
                    }
                    Component.onCompleted: if (wordsMap.contains(model.index)) text = wordsMap.value(model.index);

                    TLabel {
                        id: label
                        anchors.right: parent.left
                        anchors.rightMargin: -20
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0.4
                        text: model.index + ":"
                    }
                }
            }
        }
    }

    Item {
        id: headerBackground
        anchors.left: parent.left
        anchors.right: parent.right
        height: Math.max(headerScene.height + mapListener.result.y - bodyColumn.height - 40, Devices.standardTitleBarHeight)

        property real ratio: Math.min(1, (height - Devices.standardTitleBarHeight) / (headerScene.height - Devices.standardTitleBarHeight - bodyColumn.height - 40))

        PointMapListener {
            id: mapListener
            source: listv.headerItem
            dest: recovertPage
        }

        Item {
            id: headerScene
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 50
            height: stickerItem.height + bodyColumn.height + headerLabel.height + 100

            TColumn {
                id: bodyColumn
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30 - mapListener.result.y
                spacing: 0

                TLabel {
                    width: parent.width
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    font.weight: Font.Light
                    text: qsTr("You can restore access to your wallet by entering 24 words you wrote when down you creating the wallet.")
                }

                TButton {
                    flat: true
                    highlight: true
                    width: 160
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("I don't have those")
                    onClicked: TViewport.viewport.append(wallet_error_component, {}, "stack")
                }
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
                text: qsTr("24 Secret Words")
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

    THeaderBackButton {
        onClicked: recovertPage.ViewportType.open = false
    }

    TDialog {
        id: warnDialog
        anchors.fill: parent
        title: qsTr("Incorrect words")
        buttons: [qsTr("Ok")]
        onButtonClicked: warnDialog.close();

        TLabel {
            width: Math.min(recovertPage.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("Sorry, you have entered incorrect secret words. Please double check and try again.")
        }
    }

    Component {
        id: wallet_success_component
        WalletImportSuccessPage {
            id: wpage
            anchors.fill: parent
            ViewportType.gestureWidth: 0
            ViewportType.blockBack: true
        }
    }

    Component {
        id: wallet_error_component
        WalletImportErrorPage {
            id: wpage
            anchors.fill: parent
            ViewportType.gestureWidth: 0
            ViewportType.blockBack: true
        }
    }
}


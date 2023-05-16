import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    id: recovertPage

    property alias dialogOpened: warnDialog.opened

    Connections {
        target: MainBackend.keysManager

        function onWalletImportedSuccessfully(publicKey) {
            TViewport.viewport.append(wallet_success_component, {"publicKey": publicKey}, "stack")
        }

        function onWalletImportFailed() {
            GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Import Failed"), MainBackend.keysManager.errorString, Colors.foreground)
            warnDialog.open();
        }
    }

    WalletItem {
        id: walletItem
        backend: MainBackend
    }

    RecoveryWordsModel {
        id: wordsModel
        wallet: walletItem
    }

    MapObject {
        id: wordsMap
    }

    Item {
        id: recoveryScene
        clip: true
        anchors.fill: parent
        anchors.topMargin: Devices.statusBarHeight
        anchors.bottomMargin: keyboardPadding

        property real keyboardPadding: Constants.keyboardedView? Devices.keyboardHeight : 0

        Behavior on keyboardPadding {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }

        NumberAnimation {
            id: scrollAnim
            easing.type: Easing.OutCubic
            duration: 300
            target: listv
            properties: "contentY"
        }

        TScrollView {
            id: scrollView
            anchors.fill: parent
            scrollMarginTop: Devices.standardTitleBarHeight

            TListView {
                id: listv
                model: 24
                spacing: 8

                highlightMoveDuration: 200
                highlightRangeMode: Devices.isMobile? ListView.NoHighlightRange : ListView.ApplyRange
                preferredHighlightBegin: 0
                preferredHighlightEnd: height - 100

                signal focusOn(int index)

                header: MouseArea {
                    width: listv.width
                    height: headerScene.height
                    onHeightChanged: listv.positionViewAtBeginning()
                    onClicked: Devices.hideKeyboard()
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

                    TColumn {
                        anchors.centerIn: parent
                        anchors.verticalCenterOffset: -15

                        TBusyIndicator {
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: 42
                            running: MainBackend.keysManager.importingWallet
                            accented: true
                            visible: running
                        }

                        TButton {
                            id: continueBtn
                            anchors.horizontalCenter: parent.horizontalCenter
                            visible: !MainBackend.keysManager.importingWallet
                            width: 200
                            text: qsTr("Continue")
                            enabled: wordsMap.count == listv.count
                            onClicked: MainBackend.keysManager.importWallet(wordsMap.values)
                        }
                    }
                }

                delegate: MouseArea {
                    id: marea
                    width: listv.width
                    height: Constants.itemsHeight
                    z: textField.suggestionsMenu? 100 : 0
                    onClicked: Devices.hideKeyboard()

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
                        suggestions: wordsModel
                        onTextChanged: {
                            wordsMap.remove(uniqueIdx);
                            if (text.length)
                                wordsMap.insert(uniqueIdx, text);
                        }
                        onTabPressed: accepted()
                        onAccepted: {
                            if (model.index < listv.count-1)
                                listv.currentIndex = model.index+1;
                            else
                                listv.footerItem.focus = true;
                        }
                        input.onFocusChanged: {
                            if (input.focus) {
                                var idx = model.index;
                                Tools.jsDelayCall(10, function(){
                                    scrollAnim.from = listv.contentY;
                                    listv.positionViewAtIndex(idx, ListView.Center);
                                    scrollAnim.to = listv.contentY;
                                    scrollAnim.start();
                                });

                                GlobalValues.keyboardPaddingMode = input;
                            } else if (GlobalValues.keyboardPaddingMode == input) {
                                GlobalValues.keyboardPaddingMode = null;
                            }
                        }

                        Component.onCompleted: {
                            if (wordsMap.contains(uniqueIdx)) text = wordsMap.value(uniqueIdx);
                            Devices.setupImEventFilter(input);
                            if (model.index == 0) {
                                focus = true;
                                forceActiveFocus();
                            }
                        }
                        Component.onDestruction: if (GlobalValues.keyboardPaddingMode == input) GlobalValues.keyboardPaddingMode = null

                        readonly property string uniqueIdx: GlobalMethods.justifyNumber(model.index, 10)

                        TLabel {
                            id: label
                            anchors.right: parent.left
                            anchors.rightMargin: -20
                            anchors.verticalCenter: parent.verticalCenter
                            opacity: 0.4
                            text: (model.index+1) + ":"
                        }
                    }
                }
            }
        }

        TScrollBar {
            color: Colors.darkMode? "#ffffff" : "#000000"
            scrollArea: listv
            visible: Devices.isDesktop
            anchors.topMargin: scrollView.scrollMarginTop
            anchors.right: scrollView.right
            anchors.top: scrollView.top
            anchors.bottom: scrollView.bottom
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
                dest: recoveryScene
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
                    transformOrigin: headerLabel.LayoutMirroring.enabled? Item.Right : Item.Left
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


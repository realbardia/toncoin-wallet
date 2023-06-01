import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    id: dis

    property alias publicKey: walletItem.publicKey

    MapObject {
        id: resultsMap
    }

    WalletItem {
        id: walletItem
        backend: MainBackend
    }

    RecoveryWordsModel {
        id: wordsModel
        wallet: walletItem
    }

    SimplePageTemplate {
        id: simplePage
        anchors.fill: parent
        anchors.bottomMargin: keyboardPadding
        sticker: "qrc:/ton/common/stickers/Test Time.tgs"
        title: qsTr("Test Time!")
        body: qsTr("Let's check that you wrote them down correctly. Please enter the words <b>%1</b>, <b>%2</b> and <b>%3</b>.").arg(5).arg(15).arg(18)
        backable: true
        busy.running: qmodel.refreshing
        bottomPadding: Constants.keyboardedView? -40 : 64

        Behavior on bottomPadding {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }

        property real keyboardPadding
        property bool keyboardedView: Constants.keyboardedView
        onKeyboardedViewChanged: {
            keyboardViewTimer.stop();
            if (keyboardedView)
                keyboardPadding = Qt.binding(function(){ return Devices.keyboardHeight; });
            else
                keyboardViewTimer.start();
        }

        Behavior on keyboardPadding {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
        }

        Timer {
            id: keyboardViewTimer
            interval: 100
            repeat: false
            onTriggered: simplePage.keyboardPadding = 0
        }

        onCloseRequest: dis.ViewportType.open = false

        mainButton {
            text: qsTr("Continue")
            enabled: (resultsMap.count == qmodel.count && !qmodel.refreshing) || testMode
            onClicked: {
                if (qmodel.test(resultsMap.values) || testMode) {
                    TViewport.viewport.append(success_component, {}, "stack")
                } else {
                    errorDialog.open();
                }
            }
            onTabPressed: {
                var first = repeater.itemAt(0);
                first.input.focus = true;
                first.input.forceActiveFocus();
            }
        }

        TColumn {
            width: 160
            height: Constants.itemsHeight * qmodel.quizLength + (spacing * (qmodel.quizLength-1))
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6
            z: 10

            Repeater {
                id: repeater
                model: PhrasesQuizModel {
                    id: qmodel
                    quizLength: 3
                    wallet: walletItem
                    onCountChanged: resultsMap.clear()
                }

                TTextField {
                    id: textField
                    width: 160
                    leftPadding: textField.iosStyle? 34 : 24
                    suggestions: wordsModel
                    z: suggestionsMenu? 100 : 0

                    onTextChanged: {
                        var uniqueIdx = GlobalMethods.justifyNumber(model.index, 10);
                        resultsMap.remove(uniqueIdx);
                        if (text.length)
                            resultsMap.insert(uniqueIdx, text.toLowerCase());
                    }
                    onAccepted: {
                        if (model.index+1 < repeater.count) {
                            var next = repeater.itemAt(model.index+1);
                            next.input.focus = true;
                            next.input.forceActiveFocus();
                        } else {
                            simplePage.mainButton.focus = true;
                            simplePage.mainButton.forceActiveFocus();
                        }
                    }
                    input.onFocusChanged: {
                        if (input.focus)
                            GlobalValues.keyboardPaddingMode = input;
                        else if (GlobalValues.keyboardPaddingMode == input)
                            GlobalValues.keyboardPaddingMode = null
                    }

                    Component.onCompleted: {
                        Devices.setupImEventFilter(input);
                        if (model.index == 0) {
                            focus = true;
                            forceActiveFocus();
                        }
                    }
                    Component.onDestruction: if (GlobalValues.keyboardPaddingMode == input) GlobalValues.keyboardPaddingMode = null

                    TLabel {
                        id: label
                        anchors.right: parent.left
                        anchors.rightMargin: textField.iosStyle? -30 : -20
                        anchors.verticalCenter: parent.verticalCenter
                        opacity: 0.4
                        text: model.itemIndex + ":"
                    }
                }
            }
        }
    }

    TDialog {
        id: errorDialog
        anchors.fill: parent
        title: qsTr("Incorrect words")
        buttons: [qsTr("See words"), qsTr("Try again")]
        onButtonClicked: {
            switch (index) {
            case 0:
                dis.ViewportType.open = false;
                errorDialog.close();
                break;
            case 1:
                errorDialog.close();
                break;
            }
        }

        TLabel {
            width: Math.min(dis.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("The secret words you have entered do not match the ones in the list.")
        }
    }

    Component {
        id: success_component
        SuccessPage {
            id: spage
            anchors.fill: parent
            publicKey: dis.publicKey
        }
    }
}


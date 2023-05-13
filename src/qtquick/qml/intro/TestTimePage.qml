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
        sticker: "qrc:/ton/common/stickers/Test Time.tgs"
        title: qsTr("Test Time!")
        body: qsTr("Let's check that you wrote them down correctly. Please enter the words <b>%1</b>, <b>%2</b> and <b>%3</b>.").arg(5).arg(15).arg(18)
        backable: true
        busy.running: qmodel.refreshing

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
                first.focus = true;
                first.forceActiveFocus();
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
                    width: 160
                    leftPadding: 24
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
                            next.focus = true;
                            next.forceActiveFocus();
                        } else {
                            simplePage.mainButton.focus = true;
                            simplePage.mainButton.forceActiveFocus();
                        }
                    }
                    Component.onCompleted: {
                        if (model.index == 0) {
                            focus = true;
                            forceActiveFocus();
                        }
                    }

                    TLabel {
                        id: label
                        anchors.right: parent.left
                        anchors.rightMargin: -20
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


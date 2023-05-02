import QtQuick 2.15
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    id: page

    property alias backable: spage.backable
    property alias digitsCount: passField.digitsCount

    property string confirmMode

    SimplePageTemplate {
        id: spage
        anchors.fill: parent
        backable: true
        sticker: "qrc:/ton/common/stickers/Password.tgs"
        title: confirmMode.length? qsTr("Confirm a Passcode") : qsTr("Set a Passcode")
        body: qsTr("Enter the %1 digitis in the passcode.").arg(digitsCount)

        onCloseRequest: page.ViewportType.open = false

        secondaryButton {
            z: 20
            text: qsTr("Passcode options")
            onClicked: menu.open()
        }

        Item {
            width: 160
            height: spage.height * 0.4 - 120

            TPasswordField {
                id: passField
                width: parent.width
                onTextChanged: {
                    if (text.length != digitsCount)
                        return;

                    if (confirmMode.length) {
                        if (confirmMode != text) {
                            vibrateTimer.restart();
                        } else {
                            confirmItem = Viewport.viewport.append(doneComponent, {}, "stack")
                        }
                    } else {
                        var cmp = Qt.createComponent("PasscodePage.qml");
                        confirmItem = Viewport.viewport.append(cmp, {"confirmMode": passField.text, "digitsCount": digitsCount}, "stack");
                    }
                }

                property Item confirmItem
                onConfirmItemChanged: {
                    if (!confirmItem) {
                        passField.text = "";
                        passField.focus = true;
                        passField.forceActiveFocus();
                    }
                }

                Component.onCompleted: {
                    focus = true;
                    forceActiveFocus();
                }

                Timer {
                    id: vibrateTimer
                    interval: 50
                    running: false
                    repeat: true
                    triggeredOnStart: true
                    onTriggered: {
                        passField.x = (counter % 2 == 0? 1 : -1) * 10;

                        counter++;
                        if (counter == 6) {
                            passField.x = 0;
                            counter = 0;
                            stop();
                        }
                    }

                    property int counter: 0
                }

                Behavior on x {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: vibrateTimer.interval }
                }
            }
        }
    }

    TMenu {
        id: menu
        y: -height
        width: spage.secondaryButton.width
        parent: spage.secondaryButton
        model: [qsTr("4-digit code"), qsTr("6-digit code")]
        onVisibleChanged: {
            if (!visible) {
                passField.focus = true;
                passField.forceActiveFocus();
            }
        }
        onItemClicked: {
            switch (index) {
            case 0:
                digitsCount = 4;
                break;
            case 1:
                digitsCount = 6;
                break;
            }
        }
    }

    Component {
        id: doneComponent
        DonePage {
            anchors.fill: parent
            backable: true
        }
    }
}

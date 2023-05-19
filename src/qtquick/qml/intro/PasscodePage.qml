import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    id: page

    property alias backable: spage.backable
    property alias digitsCount: passField.digitsCount
    property alias publicKey: wallet.publicKey
    property bool closeAtEnd

    property string confirmMode

    signal closeRequest()
    signal success()

    WalletItem {
        id: wallet
        backend: MainBackend
        onPasswordChangedSuccessfully: {
            spage.busy.running = false;
            GlobalValues.passCode = passField.text;
            AppSettings.passCodeLength = passField.text.length;
            AppSettings.touchIdSecureKey = secureKey;
            if (closeAtEnd) {
                page.success()
                page.closeRequest();
            } else {
                TViewport.viewport.append(doneComponent, {"publicKey": newPublicKey}, "stack");
            }
        }
        onPasswordChangeFailed: {
            GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Failed to change password"), error, Colors.foreground)
            spage.busy.running = false;
        }
    }

    SimplePageTemplate {
        id: spage
        anchors.fill: parent
        backable: true
        sticker: "qrc:/ton/common/stickers/Password.tgs"
        title: confirmMode.length? qsTr("Confirm a Passcode") : qsTr("Set a Passcode")
        body: qsTr("Enter the %1 digits in the passcode.").arg(digitsCount)

        onCloseRequest: {
            if (closeAtEnd && confirmMode.length == 0)
                page.closeRequest();
            else
                page.ViewportType.open = false;
        }

        secondaryButton {
            z: 20
            text: qsTr("Passcode options")
            onClicked: menu.open()
        }

        Item {
            width: 160
            height: spage.height * 0.4 - 120
            opacity: spage.busy.running? 0 : 1

            TPasswordField {
                id: passField
                width: parent.width
                onTextChanged: {
                    if (text.length != digitsCount)
                        return;

                    if (confirmMode.length) {
                        if (confirmMode != text) {
                            vibrate();
                        } else {
                            spage.busy.running = true;
                            wallet.changePassword(passField.text)
                        }
                    } else {
                        spage.focus = true;
                        spage.forceActiveFocus();

                        var cmp = Qt.createComponent("PasscodePage.qml");
                        var properties = {
                            "confirmMode": passField.text,
                            "digitsCount": digitsCount,
                            "closeAtEnd": closeAtEnd,
                            "publicKey": publicKey
                        };
                        confirmItem = TViewport.viewport.append(cmp, properties, "stack");
                        confirmItem.closeRequest.connect(page.closeRequest)
                        confirmItem.success.connect(page.success)
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

                Timer {
                    running: true
                    interval: 300
                    repeat: false
                    onTriggered: {
                        passField.focus = true;
                        passField.forceActiveFocus();
                    }
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
        onOpenedChanged: {
            if (!opened) {
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

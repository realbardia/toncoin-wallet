import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    id: page
    sticker: "qrc:/ton/common/stickers/Success.tgs"
    title: qsTr("Perfect!")
    body: qsTr("Now set up a passcode to secure transactions.")
    backable: true

    property alias publicKey: wallet.publicKey

    onCloseRequest: page.ViewportType.open = false

    WalletItem {
        id: wallet
        backend: MainBackend
        onPasswordChangedSuccessfully: {
            TViewport.viewport.append(doneComponent, {"publicKey": newPublicKey}, "stack");
            GlobalValues.passCode = Constants.touchIdPass;
        }
        onPasswordChangeFailed: {
            GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Failed to active biometric."), error, Colors.foreground)
        }
    }

    mainButton {
        text: qsTr("Set a Passcode")
        onTabPressed: {
            touchIdCheck.focus = true;
            touchIdCheck.forceActiveFocus();
        }
        onClicked: TViewport.viewport.append(passcode_component, {}, "stack");
    }

    TCheckBox {
        id: touchIdCheck
        anchors.horizontalCenter: parent.horizontalCenter
        width: 160
        text: qsTr("Enable Touch ID")
        visible: Devices.hasBiometric
        onClicked: {
            AppSettings.touchId = true;
            if (GlobalMethods.biometricCheck())
                wallet.changePassword(Constants.touchIdPass);
            else {
                AppSettings.touchId = false;
                checked = false
            }
        }

        onTabPressed: {
            mainButton.focus = true;
            mainButton.forceActiveFocus();
        }
    }

    Component {
        id: passcode_component
        PasscodePage {
            id: ppage
            anchors.fill: parent
            publicKey: page.publicKey
        }
    }

    Component {
        id: doneComponent
        DonePage {
            anchors.fill: parent
            backable: true
            publicKey: page.publicKey
        }
    }
}

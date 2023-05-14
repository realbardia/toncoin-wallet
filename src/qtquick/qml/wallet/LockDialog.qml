import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TPage {
    color: "#000"

    property alias publicKey: wallet.publicKey
    property alias busy: busyIndicator.running

    function checkBiometric() {
        if (!Devices.biometricCheck())
            return;

        if (wallet.unlock(Constants.touchIdPass))
            GlobalValues.passCode = Constants.touchIdPass;
        else
            GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Failed"), qsTr("Failed to unlock wallet. Secure key changed."), Colors.foreground)
    }

    Timer {
        interval: 300
        running: AppSettings.touchId
        repeat: false
        onTriggered: checkBiometric()
    }

    WalletItem {
        id: wallet
        backend: MainBackend
    }

    TColumn {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 40
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -50

        StickerItem {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height: width
            autoPlay: true
            loops: 1
            source: "qrc:/ton/common/stickers/Password.tgs"
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("Use Touch ID or enter passcode.")
            color: "#fff"
        }

        Item {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 200
            height: 50

            TBusyIndicator {
                id: busyIndicator
                anchors.centerIn: parent
                width: 42
                height: width
                accented: false
                visible: busyIndicator.running
            }

            TPasswordField {
                width: 160
                anchors.centerIn: parent
                color: "#fff"
                visible: !busyIndicator.running && !AppSettings.touchId
                digitsCount: AppSettings.passCodeLength
                onTextChanged: {
                    if (text.length != digitsCount)
                        return;

                    if (wallet.unlock(text)) {
                        GlobalValues.passCode = text;
                    } else {
                        vibrate();
                        text = "";
                    }
                }
                Component.onCompleted: {
                    if (AppSettings.touchId)
                        return;
                    focus = true;
                    forceActiveFocus();
                }
            }
        }
    }

    TButton {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 12 * Devices.density
        flat: true
        height: 60
        width: height
        visible: AppSettings.touchId && Devices.hasBiometric
        icon.text: MaterialIcons.mdi_fingerprint
        icon.font.pixelSize: 20 * Devices.fontDensity
        highlightColor: "#fff"
        onClicked: checkBiometric()
    }
}

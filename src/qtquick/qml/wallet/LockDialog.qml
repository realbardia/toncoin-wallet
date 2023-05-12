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

        TBusyIndicator {
            id: busyIndicator
            anchors.horizontalCenter: parent.horizontalCenter
            width: 42
            height: width
            accented: false
            visible: busyIndicator.running
        }

        TPasswordField {
            width: 160
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#fff"
            visible: !busyIndicator.running
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
                focus = true;
                forceActiveFocus();
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
        visible: AppSettings.touchId
        icon.text: MaterialIcons.mdi_fingerprint
        icon.font.pixelSize: 20 * Devices.fontDensity
        highlightColor: "#fff"
    }
}

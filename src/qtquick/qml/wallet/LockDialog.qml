import QtQuick 2.15
import Toolkit 1.0
import Viewport 1.0
import TonQml 1.0
import "../components"
import "../globals"

TPage {
    color: "#000"

    TColumn {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 40
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -50

        TgStickerItem {
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

        TPasswordField {
            width: 160
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#fff"
            onTextChanged: {
                if (text.length != digitsCount)
                    return;

                if (text == "1234")
                    GlobalValues.locked = false;
                else {
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
        icon.text: MaterialIcons.mdi_fingerprint
        icon.font.pixelSize: 20 * Devices.fontDensity
        highlightColor: "#fff"
    }
}

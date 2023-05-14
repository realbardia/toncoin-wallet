import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    signal success()

    function checkBiometric() {
        if (!Devices.biometricCheck())
            return;

        page.success();
    }

    Timer {
        interval: 300
        running: AppSettings.touchId
        repeat: false
        onTriggered: checkBiometric()
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

            TPasswordField {
                width: 160
                anchors.centerIn: parent
                color: "#fff"
                visible: !AppSettings.touchId
                digitsCount: AppSettings.passCodeLength
                onTextChanged: {
                    if (text.length != digitsCount)
                        return;

                    if (GlobalValues.passCode == text) {
                        page.success()
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

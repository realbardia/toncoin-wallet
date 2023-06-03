import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    property bool allowBiometric: Devices.hasBiometric

    signal success()
    signal closeRequest()

    function checkBiometric() {
        if (!GlobalMethods.biometricCheck()) {
            passField.focus = true;
            passField.forceActiveFocus();
            return;
        }

        Devices.triggerVibrateFeedback();
        page.success();
    }

    Timer {
        interval: 300
        running: AppSettings.touchId && allowBiometric
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
                id: passField
                width: 160
                anchors.centerIn: parent
                color: "#fff"
                digitsCount: AppSettings.passCodeLength
                onTextChanged: {
                    if (text.length != digitsCount)
                        return;

                    if (GlobalValues.passCode == text) {
                        Devices.triggerVibrateFeedback();
                        Qt.callLater(function(){
                            page.success();
                        })
                    } else {
                        vibrate();
                        text = "";
                    }
                }
                Component.onCompleted: {
                    if (AppSettings.touchId && allowBiometric)
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
        visible: AppSettings.touchId && allowBiometric
        icon.text: MaterialIcons.mdi_fingerprint
        icon.font.pixelSize: 20 * Devices.fontDensity
        highlightColor: "#fff"
        onClicked: checkBiometric()
    }

    THeaderCloseButton {
        id: closeBtn
        color: "#fff"
        onClicked: page.closeRequest()
    }
}

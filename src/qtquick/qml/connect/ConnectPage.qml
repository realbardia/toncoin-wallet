import QtQuick 2.15
import Toolkit.Core 1.0
import "../components"
import "../globals"

TDrawer {
    height: contentHeight + area.height

    property string domain: "fraement.io"
    property string address: "223f7e11-e403-449f-8744-3bd7cb8d61d2"
    property bool done

    mainButton {
        width: mainButtonWidth
        radius: mainButtonRadius
        text: done? "" : qsTr("Connect Wallet")
        visible: true
        icon.text: done? MaterialIcons.mdi_check : ""
        icon.font.pixelSize: 12 * Devices.fontDensity
        onClicked: {
            if (busyIndicator.running)
                return;

            busyIndicator.running = true;
            testTimer.restart()
        }
    }

    property real mainButtonWidth: done? mainButton.height : width - 40
    property real mainButtonRadius: done? mainButton.height/2 : Constants.controlsRoundness

    Behavior on mainButtonRadius {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }
    Behavior on mainButtonWidth {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }

    Timer {
        id: testTimer
        repeat: false
        interval: 2000
        onTriggered: {
            Devices.triggerVibrateFeedback();
            busyIndicator.running = false;
            done = true;
        }
    }

    TBusyIndicator {
        id: busyIndicator
        parent: mainButton
        width: 26
        height: 26
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 8
        accented: false
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        anchors.verticalCenter: parent.verticalCenter
        spacing: 4

        Image {
            id: img
            anchors.left: parent.left
            anchors.right: parent.right
            height: 92
            sourceSize: Qt.size(128, 128)
            fillMode: Image.PreserveAspectFit
            asynchronous: true
            source: "qrc:/ton/common/icons/icon.png"
            mipmap: true

            TBusyIndicator {
                width: 32
                height: 32
                anchors.centerIn: parent
                running: img.status == Image.Loading
                accented: true
            }
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 14 * Devices.fontDensity
            font.weight: Font.Medium
            text: qsTr("Connect to Fragment")
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 9 * Devices.fontDensity
            text: qsTr("%1 is requesting access to your wallet address <u>%2</u> v4R2.").arg(domain).arg(address.slice(0,4) + "..." + address.slice(address.length-4))
        }

        Item {
            width: 1
            height: 10
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 9 * Devices.fontDensity
            opacity: 0.6
            text: qsTr("Be sure to check the service address before connecting the wallet.")
        }
    }
}

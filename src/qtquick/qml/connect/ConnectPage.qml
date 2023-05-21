import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import Wallet.TonConnect 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    height: contentHeight + area.height
    closable: true

    property string address: AppSettings.address
    property bool done
    property bool errorOccured

    property TonConnect tonConnect
    property alias serviceId: service.serviceId
    property alias manifestUrl: service.manifestUrl
    property alias items: service.items

    readonly property bool openState: dis.ViewportType.open
    onOpenStateChanged: {
        if (openState)
            return;
        if (done || errorOccured)
            return;

        tonConnect.reject(serviceId, TonConnect.ConnectDeclinedConnectionError);
    }

    TonConnectService {
        id: service
        onError: {
            errorOccured = true;
            tonConnect.reject(serviceId, TonConnect.ConnectDeclinedConnectionError);
        }
    }

    Connections {
        target: tonConnect
        function onConnectedSuccessfully() {
            dis.done = true;
            Tools.jsDelayCall(1000, function() {
                dis.closeRequest();
            });
        }
    }

    mainButton {
        width: mainButtonWidth
        radius: mainButtonRadius
        text: done || busyIndicator.running? "" : qsTr("Connect Wallet")
        visible: !service.loading
        icon.text: done? MaterialIcons.mdi_check : ""
        icon.font.pixelSize: 16 * Devices.fontDensity
        icon.anchors.verticalCenterOffset: 2
        onClicked: {
            if (busyIndicator.running)
                return;

            tonConnect.accept(service);
        }
    }

    property real mainButtonWidth: done || busyIndicator.running? mainButton.height : width - 40
    property real mainButtonRadius: done || busyIndicator.running? mainButton.height/2 : Constants.controlsRoundness

    Behavior on mainButtonRadius {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }
    Behavior on mainButtonWidth {
        NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
    }

    TBusyIndicator {
        id: busyIndicator
        parent: mainButton
        width: 26
        height: 26
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 8
        running: tonConnect.connecting
        accented: false
    }

    TBusyIndicator {
        width: 42
        height: 42
        anchors.centerIn: parent
        running: service.loading
        accented: true
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        anchors.verticalCenter: parent.verticalCenter
        spacing: 4
        visible: !service.loading

        Item {
            width: height
            height: 92
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: img
                anchors.fill: parent
                anchors.margins: 6
                fillMode: Image.PreserveAspectFit
                asynchronous: true
                source: service.serviceIcon
                mipmap: true
                visible: false
            }

            Rectangle {
                id: mask
                anchors.fill: img
                color: Colors.backgroundDeep
                radius: Constants.roundness
            }

            OpacityMask {
                anchors.fill: img
                source: img
                maskSource: mask
            }

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
            text: qsTr("Connect to %1").arg(service.serviceName)
        }

        TLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.pixelSize: 9 * Devices.fontDensity
            text: qsTr("%1 is requesting access to your wallet address <u>%2</u> v4R2.").arg(service.serviceName).arg(address.slice(0,4) + "..." + address.slice(address.length-4))
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

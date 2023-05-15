import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
import Wallet.Core 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Receive TON")
    height: contentHeight + area.height

    mainButton {
        text: qsTr("View My Wallet")
        onClicked: dis.closeRequest()
    }

    property alias amount: transferReq.amount
    property alias address: transferReq.destinationAddress
    property alias message: transferReq.message
    property FeeEstimater feeEstimater

    TransferRequest {
        id: transferReq
        wallet: WalletItem {
            backend: MainBackend
            publicKey: AppSettings.loggedInPublicKey
        }
        force: true
        Component.onCompleted: {
            transfer();
        }

        onTransferFinishedSucessfully: {
            TViewport.viewport.append(done_component, {}, "stack");
            GlobalSignals.pendingTransactionSubmited(transferReq, feeEstimater)
            GlobalSignals.reloadTransactionsRequest();
        }
        onTransferFailed: {
            GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Failed to transfer"), errorString, Colors.foreground)
            dis.ViewportType.open = false;
        }
    }

    TColumn {
        id: area
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        StickerItem {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 120
            height: width
            autoPlay: true
            source: "qrc:/ton/common/stickers/Waiting TON.tgs"
        }

        THeaderLabel {
            anchors.left: parent.left
            anchors.right: parent.right
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Sending TON")
        }

        TLabel {
            id: body
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.weight: Font.Light
            opacity: 0.6
            text: qsTr("Please wait a few seconds for your transaction to be processed...")
        }
    }

    Component {
        id: done_component
        SendDoneDialog {
            ViewportType.gestureWidth: 0
            ViewportType.blockBack: true
            width: parent.width
            closable: true
            backable: false
            amount: dis.amount
            address: dis.address
            onCloseRequest: dis.closeRequest()
        }
    }
}

import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import "../transfer" as Transfer
import "../settings" as Settings
import "../connect" as Connect
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    property bool opened

    readonly property real headerHeight: 240
    readonly property real headerRatio: Math.max(0, (headerHeight + mapListener.result.y)/headerHeight)

    property alias publicKey: walletItem.publicKey
    readonly property bool connecting: walletItem.loading || walletState.running
    readonly property bool loading: tmodel.refreshing && tmodel.count

    readonly property string balanceStr: {
        var num = (AppSettings.currencyPrice * AppSettings.balance);
        return GlobalMethods.fixNum(num, 4) + AppSettings.currency.toUpperCase()
    }

    WalletItem {
        id: walletItem
        backend: MainBackend
        onAddressChanged: AppSettings.address = address;
    }

    WalletState {
        id: walletState
        wallet: walletItem
        onBalanceChanged: AppSettings.balance = (balance.length? balance : "0.00000");
        onErrorStringChanged: if (errorString.length) GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Faild to load state"), errorString, Colors.foreground)
    }

    WalletUrlParser {
        id: urlParser
    }

    Timer {
        interval: 50
        repeat: false
        running: true
        onTriggered: opened = true
    }

    Component.onCompleted: {
        if (GlobalValues.tempLinkToOpen.length) {
            sendTon(GlobalValues.tempLinkToOpen);
            GlobalValues.tempLinkToOpen = "";
        }
    }

    Connections {
        target: GlobalValues
        function onTempLinkToOpenChanged() {
            if (GlobalValues.tempLinkToOpen.length == 0)
                return;

            sendTon(GlobalValues.tempLinkToOpen);
            GlobalValues.tempLinkToOpen = "";
        }
    }

    Connections {
        target: GlobalSignals
        function onReloadTransactionsRequest() {
            tmodel.refresh();
        }
        function onPendingTransactionSubmited(req, fee) {
            tmodel.addPending(req, fee);
        }
    }

    property Item sendDialog
    function sendTon(address) {
        if (sendDialog)
            return;
        if (address.slice(0,15) != "ton://transfer/")
            address = "ton://transfer/" + address;

        urlParser.url = address;
        if (urlParser.address.length == 0)
            return;

        if (urlParser.amount.length == 0)
            sendDialog = TViewport.viewport.append(send_value_component, {"address": urlParser.address}, "drawer");
        else
            sendDialog = TViewport.viewport.append(send_confirm_component, {"address": urlParser.address, "amount": urlParser.amount, "message": urlParser.comment}, "drawer");

        GlobalValues.mwin.show();
        GlobalValues.mwin.requestActivate();
        GlobalValues.mwin.alert(0);
    }

    CurrencyPrice {
        id: currenyPrice
        token: "the-open-network"
        currency: AppSettings.currency
        onPriceChanged: {
            AppSettings.currencyPrice = price
        }
    }

    PointMapListener {
        id: mapListener
        source: listv.headerItem
        dest: walletScene
    }

    Rectangle {
        width: parent.width
        color: Colors.background
        anchors.top: walletScene.bottom
        anchors.bottom: parent.bottom

        Rectangle {
            anchors.fill: parent
            color: "#000"
            opacity: opened? 0 : 1

            Behavior on opacity {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 400 }
            }
        }
    }

    Item {
        id: walletScene
        width: parent.width
        height: parent.height - Devices.statusBarHeight
        y: opened? Devices.statusBarHeight : -headerHeight
        clip: true

        Behavior on y {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 400 }
        }

        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headerArea.bottom
            anchors.bottom: parent.bottom
            radius: Constants.roundness
            color: Colors.background

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.verticalCenter
                anchors.bottom: parent.bottom
                color: Colors.background
            }

            Item {
                anchors.left: parent.left
                anchors.right: parent.right
                height: walletScene.height - headerHeight - Devices.statusBarHeight

                Loader {
                    id: walletLoading
                    anchors.centerIn: parent
                    width: 120
                    height: width
                    active: (page.connecting || tmodel.refreshing) && tmodel.count == 0
                    sourceComponent: StickerItem {
                        anchors.fill: parent
                        autoPlay: true
                        source: "qrc:/ton/common/stickers/Loading.tgs"
                    }
                }

                Loader {
                    anchors.fill: parent
                    active: tmodel.count == 0 && !walletLoading.active
                    sourceComponent: EmptyWalletElement {
                        anchors.fill: parent
                        anchors.margins: 20
                        address: AppSettings.address
                    }
                }
            }
        }

        Item {
            anchors.fill: parent
            anchors.topMargin: Devices.standardTitleBarHeight
            clip: true

            TScrollView {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: walletScene.height
                clip: true

                TransactionsList {
                    id: listv
                    anchors.fill: parent
                    onMoreRequest: tmodel.more()
                    model: TransactionsModel {
                        id: tmodel
                        cachePath: TonToolkitApp.homePath + "/transactions"
                        password: GlobalValues.passCode
                        wallet: walletItem
                    }
                    header: Item {
                        width: listv.width
                        height: headerHeight
                    }
                    footer: Item {
                        width: listv.width
                        height: 150

                        TBusyIndicator {
                            anchors.centerIn: parent
                            width: 32
                            height: 32
                            accented: true
                            running: tmodel.refreshing && tmodel.count > 10
                        }
                    }
                }
            }
        }

        Item {
            id: headerArea
            width: parent.width
            height: Math.max(Devices.standardTitleBarHeight, mapListener.result.y + headerHeight)

            TRow {
                id: connectionRow
                anchors.horizontalCenter: parent.horizontalCenter
                opacity: page.connecting || page.loading? 1 : 0
                y: (opacity - 1) * height + 8
                visible: opacity > 0
                spacing: 4

                Behavior on opacity {
                    NumberAnimation { easing.type: Easing.OutCubic; duration: 250 }
                }

                TBusyIndicator {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: -2
                    width: 12
                    height: width
                    running: connectionRow.visible
                    accented: false
                }

                TLabel {
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 7 * Devices.fontDensity
                    color: "#fff"
                    text: page.connecting? qsTr("Connecting...") : qsTr("Loading...")
                }
            }

            Item {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                transform: Item.Top
                height: headerHeight - Devices.standardTitleBarHeight
                scale: 0.8 + 0.2 * Math.min(1, headerRatio)
                opacity: scale

                TColumn {
                    anchors.centerIn: parent
                    anchors.verticalCenterOffset: -54 * Devices.density
                    spacing: 0

                    TWalletAddress {
                        anchors.horizontalCenter: parent.horizontalCenter
                        highlightColor: "#fff"
                        color: "#fff"
                        address: AppSettings.address
                        onClicked: {
                            Devices.setClipboard(address);
                            GlobalSignals.snackRequest(MaterialIcons.mdi_check, qsTr("Copy"), qsTr("Address copied to clipboard successfully."), Colors.green);
                        }
                    }

                    Item {
                        id: balanceArea
                        width: headerArea.width
                        height: balanceColumn.height
                    }
                }

                TButton {
                    anchors.left: parent.left
                    anchors.right: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.margins: 20
                    anchors.rightMargin: 6
                    text: qsTr("Receive")
                    icon.text: MaterialIcons.mdi_arrow_bottom_left
                    icon.font.pixelSize: 12 * Devices.fontDensity
                    onClicked: TViewport.viewport.append(receive_component, {}, "drawer")
                }

                TButton {
                    anchors.left: parent.horizontalCenter
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.margins: 20
                    anchors.leftMargin: 6
                    text: qsTr("Send")
                    icon.text: MaterialIcons.mdi_arrow_top_right
                    icon.font.pixelSize: 12 * Devices.fontDensity
                    onClicked: TViewport.viewport.append(send_component, {}, "drawer")
                }
            }

            Rectangle {
                anchors.fill: parent
                opacity: 1 - Math.pow(Math.min(1, headerRatio), 2)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: page.color }
                    GradientStop { position: 0.7; color: page.color }
                    GradientStop { position: 1.0; color: "transparent" }
                }
            }

            PointMapListener {
                id: balanceMapLinstener
                source: balanceArea
                dest: headerArea
            }

            TColumn {
                id: balanceColumn
                y: Math.max(-5, balanceMapLinstener.result.y + balanceArea.height/2 - height/2)
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 0

                LayoutMirroring.enabled: false
                LayoutMirroring.childrenInherit: true

                TRow {
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 0
                    transformOrigin: Item.Bottom
                    scale: Math.min(1, Math.max(0.7, 0.2 + headerRatio*0.8))

                    StickerItem {
                        anchors.verticalCenter: parent.verticalCenter
                        width: 34
                        height: width
                        autoPlay: true
                        source: "qrc:/ton/common/stickers/Main.tgs"
                    }

                    TRow {
                        spacing: 2

                        TLabel {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.verticalCenterOffset: 4
                            font.pixelSize: 16 * Devices.fontDensity
                            color: "#fff"
                            font.weight: Font.Medium
                            text: {
                                var b = AppSettings.balance;
                                var idx = b.indexOf(".");
                                if (idx < 0)
                                    return b;
                                return b.slice(0, idx);
                            }
                        }

                        TLabel {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.verticalCenterOffset: 6
                            font.pixelSize: 12 * Devices.fontDensity
                            color: "#fff"
                            visible: text.length
                            text: {
                                var b = AppSettings.balance;
                                var idx = b.indexOf(".");
                                if (idx < 0)
                                    return "";
                                return b.slice(idx);
                            }
                        }
                    }
                }

                TLabel {
                    anchors.horizontalCenter: parent.horizontalCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    maximumLineCount: 1
                    elide: Text.ElideRight
                    color: "#fff"
                    text: currenyPrice.refreshing && AppSettings.currencyPrice == 0? qsTr("Loading...") : "≈ " + balanceStr
                    font.pixelSize: 7 * Devices.fontDensity
                    opacity: 0.6
                    transformOrigin: Item.Top
                    scale: Math.min(1, Math.max(0.9, 0.7 + headerRatio*0.3))
                }
            }

            MouseArea {
                anchors.left: parent.left
                anchors.right: parent.right
                height: Devices.standardTitleBarHeight
                onClicked: {
                    transactionsListAnim.from = listv.contentY;
                    listv.positionViewAtBeginning();
                    transactionsListAnim.to = listv.contentY;
                    transactionsListAnim.start();
                }

                NumberAnimation {
                    id: transactionsListAnim
                    easing.type: Easing.OutCubic
                    duration: 300
                    target: listv
                    properties: "contentY"
                }

                TButton {
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.margins: 6 * Devices.density
                    flat: true
                    width: height
                    icon.text: MaterialIcons.mdi_qrcode_scan
                    icon.font.pixelSize: 13 * Devices.fontDensity
                    highlightColor: "#fff"
                    visible: qzxing
                    onClicked: TViewport.viewport.append(qrscanner_component, {}, "popup")
                }

                TButton {
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.margins: 6 * Devices.density
                    flat: true
                    width: height
                    icon.text: MaterialIcons.mdi_settings_outline
                    icon.font.pixelSize: 15 * Devices.fontDensity
                    highlightColor: "#fff"
                    onClicked: TViewport.viewport.append(settings_component, {}, "activity")
                }
            }
        }

        Rectangle {
            width: parent.width
            height: opened? parent.height - headerHeight + Constants.roundness : parent.height + Constants.roundness
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -Constants.roundness
            opacity: opened? 0 : 1
            radius: Constants.roundness
            color: "#000"

            Behavior on height {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 400 }
            }
            Behavior on opacity {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 400 }
            }
        }
    }

    Component {
        id: settings_component
        Settings.SettingsPage {
        }
    }

    Component {
        id: qrscanner_component
        QRScanner {
            onTagFound: {
                Devices.triggerVibrateFeedback();
                GlobalValues.tempLinkToOpen = tag;
                ViewportType.open = false
            }
        }
    }

    Component {
        id: connect_component
        Connect.ConnectPage {
            width: page.width
            closable: true
            onCloseRequest: ViewportType.open = false
        }
    }

    Component {
        id: receive_component
        Transfer.ReceiveDialog {
            width: page.width
            closable: true
            address: AppSettings.address
            onCloseRequest: ViewportType.open = false
        }
    }

    Component {
        id: send_component
        Transfer.SendCustomDialog {
            width: page.width
            closable: true
            transactionsModel: tmodel
            onCloseRequest: ViewportType.open = false
        }
    }

    Component {
        id: send_value_component
        Transfer.SendValueDialog {
            width: page.width
            closable: true
            backable: false
            onCloseRequest: ViewportType.open = false
        }
    }

    Component {
        id: send_confirm_component
        Transfer.SendConfirmDialog {
            width: page.width
            closable: true
            backable: false
            onCloseRequest: ViewportType.open = false
        }
    }
}

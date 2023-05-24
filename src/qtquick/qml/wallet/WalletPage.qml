import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import Wallet.TonConnect 1.0
import "../settings" as Settings
import "../connect" as Connect
import "../components"
import "../globals"

TPage {
    id: dis
    color: "#000"

    property alias viewport: viewport
    property string publicKey

    Component.onCompleted: if (GlobalValues.passCode.length) { walletLoader.active = true; viewport.visible = true }

    function checkLockScreen() {
        var current = Tools.dateToSec(new Date);
        var lastEvent = Tools.dateToSec(keySpy.lastEvent);

        var time = Math.max(30, Math.min(300, AppSettings.lockTimeout))
        if (current - lastEvent < time && current >= lastEvent)
            return false;

        GlobalValues.passCode = "";
        return true;
    }

    TonConnect {
        id: _tonConnect
        appName: AsemanApp.applicationName
        appVersion: AsemanApp.applicationVersion
        password: GlobalValues.passCode
        cachePath: AsemanApp.homePath + "/tokens"
        network: Constants.testNet? TonConnect.Testnet : TonConnect.Mainnet
        bridgeUrl: "https://bridge.tonapi.io/bridge"
        baseUrls: ["ton://connect"]
        lastEventId: AppSettings.lastEventId
        locked: !walletLoader.item || AppSettings.walletVersion != "v4R2"
        onFailed: GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, title, message, Colors.foreground)
        wallet: WalletItem {
            backend: MainBackend
            publicKey: AppSettings.loggedInPublicKey
        }
        onNewEventArrived: AppSettings.lastEventId = eventId
        onNewServiceRequest: {
            var m = {
                "serviceId": id,
                "manifestUrl": manifestUrl,
                "items": items,
            };

            if (walletItem) {
                viewport.append(connect_page_component, m, "drawer");
            } else {
                lastQueuedItem = m;
            }
        }

        onWalletItemChanged: {
            if (walletItem && lastQueuedItem) {
                viewport.append(connect_page_component, lastQueuedItem, "drawer");
                lastQueuedItem = null;
            }
        }

        property Item walletItem: walletLoader.item
        property variant lastQueuedItem
    }

    Connections {
        target: GlobalValues
        function onPassCodeChanged() {
            unlockTimer.stop();
            if (GlobalValues.passCode.length) {
                keySpy.lastEvent = new Date;
                unlockTimer.start();
            } else {
                viewport.visible = false;
            }
        }
    }

    Connections {
        target: GlobalSignals

        function onLogoutRequest() {
            viewport.append(secure_logout_component, {}, "popup");
        }
    }

    Timer {
        id: unlockTimer
        interval: 500
        repeat: false
        onTriggered: {
            walletLoader.active = true;
            viewport.visible = true;
        }
    }

    TViewport {
        id: viewport
        anchors.fill: parent
        visible: false
        mainItem: Loader {
            id: walletLoader
            anchors.fill: parent
            asynchronous: true
            active: false
            sourceComponent: Wallet {
                publicKey: dis.publicKey
                anchors.fill: parent
                tonConnect: _tonConnect
            }
        }
    }

    Loader {
        id: lockScreen
        anchors.fill: parent
        active: opacity > 0
        opacity: !walletLoader.item || !viewport.visible || !walletLoader.item.opened? 1 : 0

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 200 }
        }

        sourceComponent: LockDialog {
            anchors.fill: parent
            publicKey: dis.publicKey
            busy: GlobalValues.passCode.length
            Component.onCompleted: viewport.closeAll()
        }
    }

    Timer {
        interval: 500
        repeat: true
        running: true
        onTriggered: checkLockScreen()
    }

    KeyHandler {
        id: keySpy
        window: GlobalValues.mwin
        onMousePositionChanged: if (!checkLockScreen()) lastEvent = new Date
        onKeyChanged: if (!checkLockScreen()) lastEvent = new Date
        onScreenTouched: if (!checkLockScreen()) lastEvent = new Date

        property variant lastEvent: new Date
    }

    Component {
        id: secure_logout_component
        Settings.SettingsLockDialog {
            id: logoutDlg
            anchors.fill: parent
            allowBiometric: false
            onSuccess: {
                viewport.closeAll();
                AppSettings.reset();
                GlobalValues.passCode = "";
                Tools.deleteFile(RecentModel.cachePath);
                Tools.deleteFile(AsemanApp.homePath + "/transactions");
            }
            onCloseRequest: logoutDlg.ViewportType.open = false
        }
    }

    Component {
        id: connect_page_component
        Connect.ConnectPage {
            id: con
            width: dis.width
            tonConnect: _tonConnect
            onCloseRequest: con.ViewportType.open = false
        }
    }
}

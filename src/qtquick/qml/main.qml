import QtQuick 2.12
import Toolkit.Core 1.0
import "components"
import "globals"

TApplication {
    id: app
    applicationName: "TON Wallet"
    applicationDisplayName: qsTr("TON Wallet")
    applicationVersion: "1.0.0"
    statusBarStyle: {
        if (mWin.currentViewport.currentType == "popup" || AppSettings.privateKey.length)
            return TonToolkitApp.StatusBarStyleLight;
        else
        if (Colors.darkMode)
            return TonToolkitApp.StatusBarStyleLight;
        else
            return TonToolkitApp.StatusBarStyleDark;
    }

    Component.onCompleted: {
        if (Devices.isDesktop) Devices.fontScale = 1.1;
        if (Devices.isAndroid) Devices.fontScale = 1;
        if (Devices.isIOS) Devices.fontScale = 1.15;

        Fonts.init();
        MainBackend.start();
        GlobalValues.mwin = mWin;
    }

    onMessageReceived: if (msg.slice(0,6) == "ton://") GlobalValues.tempLinkToOpen = msg

    onApplicationStateChanged: {
        switch (applicationState) {
        case 4:
            break;
        }
    }

    MainWindow {
        id: mWin
        visible: true
    }
}

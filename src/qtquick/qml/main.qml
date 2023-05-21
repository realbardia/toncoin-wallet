import QtQuick 2.12
import Toolkit.Core 1.0
import "components"
import "globals"

TApplication {
    id: app
    applicationDisplayName: qsTr("Tonium Wallet")
    statusBarStyle: {
        if (mWin.currentViewport.currentType == "popup" || AppSettings.loggedInPublicKey.length)
            return AsemanApp.StatusBarStyleLight;
        else
        if (Colors.darkMode)
            return AsemanApp.StatusBarStyleLight;
        else
            return AsemanApp.StatusBarStyleDark;
    }

    Component.onCompleted: {
        if (Devices.isDesktop) Devices.fontScale = 1.1;
        if (Devices.isAndroid) Devices.fontScale = 1;
        if (Devices.isIOS) Devices.fontScale = 1.15;

        Fonts.init();
        MainBackend.start();
        GTranslations.init();
        GlobalValues.mwin = mWin;
    }

    onMessageReceived: GlobalValues.tempLinkToOpen = msg

    MainWindow {
        id: mWin
        visible: true
    }
}

import QtQuick 2.12
import AsemanQml.Base 2.0
import AsemanQml.Controls 2.0
import "globals"

AsemanApplication {
    id: app
    applicationName: "TON Wallet"
    applicationDisplayName: qsTr("TON Wallet")
    applicationVersion: "1.0.0"
    statusBarStyle: {
        if ((mWin.currentViewport.currentType == "float" || mWin.currentViewport.currentType == "popup"))
            return AsemanApplication.StatusBarStyleLight;
        else
        if (Colors.darkMode)
            return AsemanApplication.StatusBarStyleLight;
        else
            return AsemanApplication.StatusBarStyleDark;
    }

    Component.onCompleted: {
        if (Devices.isDesktop) Devices.fontScale = 1.1;
        if (Devices.isAndroid) Devices.fontScale = 1;
        if (Devices.isIOS) Devices.fontScale = 1.15;

        Fonts.init();
        Constants.mwin = mWin;
    }

    onApplicationStateChanged: {
        switch (applicationState) {
        case 4:
            break;
        }
    }

    MainWindow {
        id: mWin
        visible: true
        font.family: Fonts.globalFont
        font.letterSpacing: -0.5
    }
}

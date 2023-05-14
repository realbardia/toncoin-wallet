import QtQuick 2.15
import QtQuick.Window 2.15
import Toolkit.Core 1.0
import Wallet.Core 1.0
import "intro" as Intro
import "wallet" as Wallet
import "components"
import "globals"

TWindow {
    id: win
    width: AppSettings.width
    height: AppSettings.height
    visible: true
    title: TonToolkitApp.applicationName

    maximumWidth: 450
    minimumWidth: 250

    maximumHeight: 2000
    minimumHeight: 400

    LayoutMirroring.enabled: GTranslations.reverseLayout
    LayoutMirroring.childrenInherit: true

    readonly property bool portrait: width<height
    readonly property TViewport currentViewport: {
        if (introLoader.item)
            return introLoader.item.viewport;
        if (walletLoader.item)
            return walletLoader.item.viewport;
        return null;
    }

    onWidthChanged: AppSettings.width = width
    onHeightChanged: AppSettings.height = height

    Item {
        id: mainScene
        anchors.fill: parent

        Loader {
            id: introLoader
            anchors.fill: parent
            active: AppSettings.loggedInPublicKey.length == 0
            sourceComponent: Intro.IntroPage {
                anchors.fill: parent
                Component.onCompleted: Devices.setupWindowColor(Colors.headerColor)
            }
        }

        Loader {
            id: walletLoader
            anchors.fill: parent
            active: AppSettings.loggedInPublicKey.length
            sourceComponent: Wallet.WalletPage {
                anchors.fill: parent
                publicKey: AppSettings.loggedInPublicKey
                Component.onCompleted: Devices.setupWindowColor(color)
            }
        }
    }

    Connections {
        target: GlobalSignals
        function onSnackRequest(icon, title, description, color) {
            snackBar.open(icon, title, description, color);
        }
    }

    TSnackBar {
        id: snackBar
        anchors.fill: parent
    }
}

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
    flags: AppSettings.frameless? Qt.FramelessWindowHint | Qt.Window : Qt.Window
    color: AppSettings.frameless? "#00000000" : Colors.background
    visible: true
    title: AsemanApp.applicationName

    maximumWidth: 450
    minimumWidth: 250

    maximumHeight: 2000
    minimumHeight: 400

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

    Component.onCompleted: {
        win.LayoutMirroring.enabled = GTranslations.reverseLayout
        GTranslations.reverseLayoutChanged.connect(function(){
            win.LayoutMirroring.enabled = GTranslations.reverseLayout;
        })
    }

    Connections {
        target: GlobalValues
        function onTempLinkToOpenChanged() {
            win.requestActivate();
            win.show();
            win.alert(0);
        }
    }

    FastRectengleShadow {
        anchors.fill: windowScene
        anchors.margins: 2
        radius: 10
        horizontalOffset: 1
        verticalOffset: 1
        visible: AppSettings.frameless && win.visibility != Window.Maximized
    }

    Item {
        id: windowScene
        anchors.margins: AppSettings.frameless && win.visibility != Window.Maximized? 5 * Devices.density : 0
        anchors.fill: parent

        Item {
            id: mainScene
            anchors.fill: parent
            anchors.bottomMargin: keyboardPadding
            anchors.topMargin: framelessPad.height

            Component.onCompleted: GlobalValues.mainScene = mainScene;

            property real keyboardPadding: Constants.keyboardedView? GlobalValues.keyboardGlobalBottomPadding : 0

            Behavior on keyboardPadding {
                NumberAnimation { easing.type: Easing.OutCubic; duration: 300 }
            }

            Loader {
                id: introLoader
                anchors.fill: parent
                active: AppSettings.loggedInPublicKey.length == 0
                sourceComponent: Intro.IntroPage {
                    anchors.fill: parent
                    Component.onCompleted: Devices.setupWindowColor(Colors.background)
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

        FastBlur {
            anchors.fill: parent
            source: visible? mainScene : null
            cached: true
            radius: 64
            visible: AsemanApp.applicationState != 4 && !GlobalMethods.checkingBiometric && Devices.isIOS
        }

        Rectangle {
            id: framelessPad
            anchors.left: parent.left
            anchors.right: parent.right
            height: AppSettings.frameless? 30 * Devices.density : 0
            color: Colors.headerColor
            visible: AppSettings.frameless

            MouseArea {
                id: marea
                anchors.fill: parent
                visible: AppSettings.frameless
                onPressed: {
                    pin = Qt.point(mouseX, mouseY);
                }
                onPositionChanged: {
                    moveCheckTimer.start()
                }

                property point pin

                Timer {
                    id: moveCheckTimer
                    interval: 10
                    repeat: false
                    onTriggered: {
                        win.x = win.x + marea.mouseX - marea.pin.x;
                        win.y = win.y + marea.mouseY - marea.pin.y;
                    }
                }
            }
        }

        TTitleBarButtons {
            visible: AppSettings.frameless
        }

        TSnackBar {
            id: snackBar
            anchors.fill: parent
        }

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.color: Colors.foreground
            border.width: 1
            opacity: 0.2
            visible: AppSettings.frameless
        }
    }

    TWindowMovable {
        anchors.fill: parent
        visible: AppSettings.frameless
        mWin: win
    }

    Connections {
        target: GlobalSignals
        function onSnackRequest(icon, title, description, color) {
            snackBar.open(icon, title, description, color);
        }
    }
}

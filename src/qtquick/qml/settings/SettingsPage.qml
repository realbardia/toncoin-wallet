import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../intro" as Intro
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    component SettingItem: TItemDelegate {
        height: 50
        width: parent.width

        property alias title: titleLabel.text
        property alias spacer: spacerItem.visible

        TLabel {
            id: titleLabel
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            maximumLineCount: 1
            elide: Text.ElideRight
        }

        Rectangle {
            id: spacerItem
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: 1
            color: Colors.foreground
            opacity: 0.1
        }
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
    }

    TScrollView {
        anchors.fill: parent
        anchors.topMargin: Devices.standardTitleBarHeight + Devices.statusBarHeight
        clip: true

        TFlickable {
            id: flick
            anchors.fill: parent
            contentWidth: scene.width
            contentHeight: scene.height
            flickableDirection: Flickable.VerticalFlick

            Item {
                id: scene
                width: flick.width
                height: Math.max(flick.height, clmn.height + 2*clmn.y)

                TColumn {
                    id: clmn
                    y: 20
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.margins: y
                    spacing: 8

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        font.bold: true
                        text: qsTr("General")
                    }

                    TColumn {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: 0

                        SettingItem {
                            title: qsTr("Active Address")
                            onClicked: walletMenu.open()

                            TLabel {
                                id: walletItem
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.accent
                                text: AppSettings.walletVersion
                            }
                        }
                        SettingItem {
                            title: qsTr("Primary Currency")
                            onClicked: currencyMenu.open()

                            TLabel {
                                id: currencyItem
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.accent
                                text: AppSettings.currency.toUpperCase()
                            }
                        }
                        SettingItem {
                            title: qsTr("List of tokens")
                            spacer: false
                            visible: false
                        }
                    }

                    Item { width: 1; height: 10 }

                    TLabel {
                        width: parent.width
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        font.bold: true
                        text: qsTr("Security")
                    }

                    TColumn {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: 0

                        SettingItem {
                            title: qsTr("Show recovery phrase")
                            onClicked: TViewport.viewport.append(recoverPhrase_component, {}, "popup")
                        }
                        SettingItem {
                            title: qsTr("Change passcode")
                            onClicked: TViewport.viewport.append(passCode_component, {}, "popup")
                        }
                        SettingItem {
                            title: qsTr("Touch ID")
                            onClicked: {
                                GlobalValues.locked = false;
                                AppSettings.touchId = !AppSettings.touchId;
                            }

                            TSwitch {
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                z: -1
                                checked: AppSettings.touchId
                            }
                        }
                    }
                }
            }
        }
    }

    Item {
        id: headerArea
        anchors.left: parent.left
        anchors.right: parent.right
        height: Devices.standardTitleBarHeight
        y: Devices.statusBarHeight


        TLabel {
            anchors.centerIn: parent
            font.pixelSize: 9 * Devices.fontDensity
            text: qsTr("Settings")
            color: "#fff"
        }
    }

    PointMapListener {
        id: currencyMap
        source: currencyItem
        dest: page
    }
    PointMapListener {
        id: walletMap
        source: walletItem
        dest: page
    }

    Rectangle {
        anchors.fill: parent
        color: Colors.foreground
        opacity: {
            if (currencyMenu.visible)
                return currencyMenu.opacity * 0.4;
            if (walletMenu.visible)
                return walletMenu.opacity * 0.4;
            return 0
        }
        visible: opacity > 0

        MouseArea {
            anchors.fill: parent
            onClicked: {
                walletMenu.close();
                currencyMenu.close();
            }
        }
    }

    THeaderCloseButton {
        onClicked: page.ViewportType.open = false
        color: "#fff"
        opacity: 1
    }

    TMenu {
        id: currencyMenu
        y: currencyMap.result.y + currencyItem.height
        x: currencyMap.result.x + currencyItem.width - width
        width: 160
        textRole: "name"
        model: CurrenciesModel { id: cmodel }
        transformOrigin: Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        shadow: false

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.currency = cmodel.get(index).key.toLowerCase();
            AppSettings.currencyPrice = 0;
        }
    }

    TMenu {
        id: walletMenu
        y: walletMap.result.y + walletItem.height
        x: walletMap.result.x + walletItem.width - width
        width: 160
        model: ["v3R2", "v4R2"]
        transformOrigin: Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        shadow: false

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.walletVersion = walletMenu.model[index];
        }
    }

    Component {
        id: recoverPhrase_component
        Intro.RecoveryPhrasePage {
            anchors.fill: parent
            doneVisible: false
            publicKey: AppSettings.loggedInPublicKey
        }
    }

    Component {
        id: passCode_component
        TViewport {
            id: viewport
            anchors.fill: parent
            mainItem: Intro.PasscodePage {
                anchors.fill: parent
                closeAtEnd: true
                publicKey: AppSettings.loggedInPublicKey
                onCloseRequest: viewport.ViewportType.open = false
            }
        }
    }
}

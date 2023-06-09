import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.Core 1.0
import Wallet.TonConnect 1.0
import "../intro" as Intro
import "../components"
import "../globals"

TPage {
    id: page
    color: "#000"

    property TonConnect tonConnect

    component SettingItem: TItemDelegate {
        height: 50
        width: parent.width

        property alias title: titleLabel.text
        property alias titleColor: titleLabel.color
        property alias spacer: spacerItem.visible

        TLabel {
            id: titleLabel
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            maximumLineCount: 1
            elide: Text.ElideRight
        }

        Rectangle {
            id: spacerItem
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 20
            anchors.rightMargin: 20
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
        id: scrollView
        anchors.fill: parent
        anchors.topMargin: Devices.standardTitleBarHeight + Devices.statusBarHeight
        scrollMarginTop: Constants.roundness
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
                    spacing: 8

                    TLabel {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 20
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Interface")
                    }

                    TColumn {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: 0

                        SettingItem {
                            title: qsTr("Dark mode")
                            onClicked: AppSettings.darkMode = !AppSettings.darkMode

                            TSwitch {
                                anchors.right: parent.right
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                z: -1
                                checked: AppSettings.darkMode
                            }
                        }
                        SettingItem {
                            title: qsTr("Language")
                            spacer: Constants.framelessSupported
                            onClicked: languageMenu.open()

                            TLabel {
                                id: languageItem
                                anchors.right: parent.right
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.accent
                                text: {
                                    var res = "";
                                    for (var i=0; i<GTranslations.model.count; i++)
                                        if (GTranslations.model.get(i).key == AppSettings.language) {
                                            res = GTranslations.model.get(i).title;
                                            break;
                                        }
                                    return res;
                                }
                            }
                        }
                        SettingItem {
                            title: qsTr("Frameless")
                            visible: Constants.framelessSupported
                            spacer: false
                            onClicked: {
                                AppSettings.frameless = !AppSettings.frameless
                                Tools.jsDelayCall(10, function(){
                                    GlobalValues.mwin.hide();
                                    Tools.jsDelayCall(10, function(){
                                        GlobalValues.mwin.width += 1;
                                        GlobalValues.mwin.height += 1;
                                        GlobalValues.mwin.show();
                                    });
                                });
                            }

                            TSwitch {
                                anchors.right: parent.right
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                z: -1
                                checked: AppSettings.frameless
                            }
                        }
                    }

                    Item { width: 1; height: 10 }

                    TLabel {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 20
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
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
                                anchors.rightMargin: 20
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
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.accent
                                text: AppSettings.currency.toUpperCase()
                            }
                        }
                        SettingItem {
                            title: qsTr("List of tokens")
                            spacer: false
                            onClicked: TViewport.viewport.append(tokens_component, {}, "popup")
                        }
                    }

                    Item { width: 1; height: 10 }

                    TLabel {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 20
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Security")
                    }

                    TColumn {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: 0

                        SettingItem {
                            title: qsTr("Auto lock")
                            onClicked: autoLockMenu.open()

                            TLabel {
                                id: autoLockItem
                                anchors.right: parent.right
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.accent
                                text: qsTr("After %1s").arg(AppSettings.lockTimeout)
                            }
                        }
                        SettingItem {
                            title: qsTr("Show recovery phrase")
                            onClicked: TViewport.viewport.append(recoverPhrase_component, {}, "popup")
                        }
                        SettingItem {
                            title: qsTr("Change passcode")
                            spacer: Devices.hasBiometric
                            onClicked: {
                                TViewport.viewport.append(passCode_component, {}, "popup");
                            }
                        }
                        SettingItem {
                            title: qsTr("Touch ID")
                            visible: Devices.hasBiometric
                            spacer: false
                            onClicked: {
                                if (AppSettings.touchId) {
                                    AppSettings.touchId = false;
                                } else if (GlobalMethods.biometricCheck()) {
                                    AppSettings.touchId = true;
                                }
                            }

                            TSwitch {
                                anchors.right: parent.right
                                anchors.verticalCenter: parent.verticalCenter
                                z: -1
                                checked: AppSettings.touchId
                            }
                        }
                    }

                    Item { width: 1; height: 10 }

                    TLabel {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.margins: 20
                        color: Colors.accent
                        font.pixelSize: 8 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        horizontalAlignment: Text.AlignLeft
                        font.bold: true
                        text: qsTr("Actions")
                    }

                    TColumn {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: 0

                        SettingItem {
                            title: qsTr("Logout")
                            titleColor: Colors.red
                            spacer: false
                            onClicked: logoutDialog.open()

                            TMaterialIcon {
                                anchors.right: parent.right
                                anchors.rightMargin: 20
                                anchors.verticalCenter: parent.verticalCenter
                                color: Colors.red
                                text: MaterialIcons.mdi_logout
                                font.pixelSize: 12 * Devices.fontDensity
                            }
                        }
                    }

                    TColumn {
                        anchors.horizontalCenter: parent.horizontalCenter
                        spacing: 0

                        Item {
                            width: 1
                            height: 40
                        }

                        TLabel {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: qsTr("%1 v%2").arg(AsemanApp.applicationName).arg(AsemanApp.applicationVersion)
                            font.pixelSize: 7 * Devices.fontDensity
                            opacity: 0.6
                        }
                        TLabel {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: qsTr("Developed by Bardia Daneshvar")
                            font.pixelSize: 7 * Devices.fontDensity
                            opacity: 0.6
                        }
                        TLabel {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: (new Date).getFullYear()
                            font.pixelSize: 7 * Devices.fontDensity
                            opacity: 0.6
                        }

                        Item {
                            width: 1
                            height: 40 + Devices.navigationBarHeight
                        }
                    }
                }
            }
        }
    }

    TScrollBar {
        color: Colors.darkMode? "#ffffff" : "#000000"
        scrollArea: flick
        visible: Devices.isDesktop
        anchors.topMargin: scrollView.scrollMarginTop
        anchors.right: scrollView.right
        anchors.top: scrollView.top
        anchors.bottom: scrollView.bottom
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
        id: languageMap
        source: languageItem
        dest: page
    }
    PointMapListener {
        id: walletMap
        source: walletItem
        dest: page
    }
    PointMapListener {
        id: autoLockMap
        source: autoLockItem
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
            if (languageMenu.visible)
                return languageMenu.opacity * 0.4;
            if (autoLockMenu.visible)
                return autoLockMenu.opacity * 0.4;
            return 0
        }
        visible: opacity > 0

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                walletMenu.close();
                currencyMenu.close();
                languageMenu.close();
                autoLockMenu.close();
            }
        }
    }

    THeaderCloseButton {
        onClicked: page.ViewportType.open = false
        color: "#fff"
        opacity: 1
    }

    TMenu {
        id: languageMenu
        y: languageMap.result.y + languageItem.height
        x: languageMap.result.x + (languageMenu.LayoutMirroring.enabled? 0 : languageItem.width - width)
        width: 160
        textRole: "title"
        model: GTranslations.model
        transformOrigin: languageMenu.LayoutMirroring.enabled? Item.TopLeft : Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        splitter: true
        shadow: false
        highlightedIndex: {
            for (var i=0; i<GTranslations.model.count; i++)
                if (GTranslations.model.get(i).key == AppSettings.language)
                    return i;
            return -1;
        }

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.language = GTranslations.model.get(index).key;
        }
    }

    TMenu {
        id: currencyMenu
        y: currencyMap.result.y + currencyItem.height
        x: currencyMap.result.x + (currencyMenu.LayoutMirroring.enabled? 0 : currencyItem.width - width)
        width: 160
        textRole: "name"
        model: CurrenciesModel { id: cmodel }
        transformOrigin: currencyMenu.LayoutMirroring.enabled? Item.TopLeft : Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        splitter: true
        shadow: false
        highlightedIndex: {
            for (var i=0; i<cmodel.count; i++)
                if (cmodel.get(i).key.toLowerCase() == AppSettings.currency)
                    return i;
            return -1;
        }

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
        x: walletMap.result.x + (walletMenu.LayoutMirroring.enabled? 0 : walletItem.width - width)
        width: 160
        model: MainBackend.availableVersions
        transformOrigin: walletMenu.LayoutMirroring.enabled? Item.TopLeft : Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        splitter: true
        shadow: false
        highlightedIndex: MainBackend.availableVersions.indexOf(AppSettings.walletVersion)

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.walletVersion = walletMenu.model[index];
        }
    }

    TMenu {
        id: autoLockMenu
        y: autoLockMap.result.y + autoLockItem.height
        x: autoLockMap.result.x + (autoLockMenu.LayoutMirroring.enabled? 0 : autoLockItem.width - width)
        width: 160
        model: ["30s", "60s", "120s", "300s"]
        transformOrigin: autoLockMenu.LayoutMirroring.enabled? Item.TopLeft : Item.TopRight
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        shadow: false
        highlightedIndex: model.indexOf(AppSettings.lockTimeout + "s")

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.lockTimeout = Tools.stringRemove(autoLockMenu.model[index], "s", false);
        }
    }

    TDialog {
        id: logoutDialog
        anchors.fill: parent
        title: qsTr("Logout")
        buttons: [qsTr("Cancel"), qsTr("Logout")]
        lastButtonColor: Colors.red
        onButtonClicked: {
            switch (index) {
            case 0:
                logoutDialog.close();
                break;
            case 1:
                GlobalSignals.logoutRequest()
                logoutDialog.close();
                break;
            }
        }

        TLabel {
            width: Math.min(dis.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("Do you realy want to logout?")
        }
    }

    Component {
        id: recoverPhrase_component
        Intro.RecoveryPhrasePage {
            id: rpPage
            anchors.fill: parent
            doneVisible: false
            backable: false
            publicKey: AppSettings.loggedInPublicKey

            SettingsLockDialog {
                anchors.fill: parent
                z: 100
                onSuccess: visible = false
                onCloseRequest: rpPage.ViewportType.open = false
            }
        }
    }

    Component {
        id: tokens_component
        TokensPage {
            anchors.fill: parent
            tonConnect: page.tonConnect
        }
    }

    Component {
        id: passCode_component
        TViewport {
            id: viewport
            anchors.fill: parent

            signal success()

            mainItem: Loader {
                anchors.fill: parent
                active: !lockDialog.visible
                sourceComponent: Intro.PasscodePage {
                    anchors.fill: parent
                    closeAtEnd: true
                    publicKey: AppSettings.loggedInPublicKey
                    onCloseRequest: viewport.ViewportType.open = false
                    onSuccess: viewport.success()
                }
            }

            SettingsLockDialog {
                id: lockDialog
                anchors.fill: parent
                z: 100
                onSuccess: visible = false
                onCloseRequest: viewport.ViewportType.open = false
            }
        }
    }
}

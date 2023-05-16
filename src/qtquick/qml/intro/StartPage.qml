import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

Item {
    id: page

    SimplePageTemplate {
        id: dis
        anchors.fill: parent
        sticker: "qrc:/ton/common/stickers/Start.tgs"
        title: qsTr("TON Wallet")
        body: qsTr("TON Wallet allows you to make fast and secure blockchain-based payments without intermediaries.")

        buttonBusy: MainBackend.keysManager.creatingNewWallet
        mainButton {
            text: qsTr("Create my wallet")
            onClicked: if (!buttonBusy) MainBackend.keysManager.createNewWallet()
        }

        secondaryButton {
            text: qsTr("Import existing wallet")
            onClicked: if (!buttonBusy)  TViewport.viewport.append(import_component, {}, "stack")
        }

        Connections {
            target: MainBackend.keysManager
            function onWalletCreatedSuccessfully(publicKey) {
                 TViewport.viewport.append(congratulation_component, {"publicKey": publicKey}, "stack");
            }
            function onWalletCreationFailed(error) {
                GlobalSignals.snackRequest(MaterialIcons.mdi_alert_octagon, qsTr("Failed to create wallet"), MainBackend.keysManager.errorString, Colors.foreground)
            }
        }

        Component {
            id: congratulation_component
            CongratulationPage {
                id: cpage
                anchors.fill: parent
                ViewportType.gestureWidth: 0
                ViewportType.blockBack: true
            }
        }

        Component {
            id: import_component
            ImportWalletPage {
                id: ipage
                anchors.fill: parent
            }
        }
    }

    TButton {
        id: languageBtn
        parent: dis.bodyElement
        anchors.top: parent.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        width: 160
        color: Colors.foreground
        flat: true
        font.underline: true
        text: {
            var res = "";
            for (var i=0; i<GTranslations.model.count; i++)
                if (GTranslations.model.get(i).key == AppSettings.language) {
                    res = GTranslations.model.get(i).title;
                    break;
                }
            return res;
        }
        onClicked: languageMenu.open()
    }

    PointMapListener {
        id: languageMap
        source: languageBtn
        dest: page
    }

    Rectangle {
        anchors.fill: parent
        color: Colors.foreground
        opacity: {
            if (languageMenu.visible)
                return languageMenu.opacity * 0.4;
            return 0
        }
        visible: opacity > 0

        MouseArea {
            anchors.fill: parent
            onClicked: {
                languageMenu.close();
            }
        }
    }

    TMenu {
        id: languageMenu
        y: languageMap.result.y + languageBtn.height
        x: languageMap.result.x + languageBtn.width/2 - width/2
        width: 160
        textRole: "title"
        model: GTranslations.model
        transformOrigin: Item.Top
        opacity: opened? 1 : 0
        scale: 0.8 + opacity*0.2
        visible: opacity > 0
        splitter: true
        shadow: false

        Behavior on opacity {
            NumberAnimation { easing.type: Easing.OutCubic; duration: 150 }
        }

        onItemClicked: {
            AppSettings.language = GTranslations.model.get(index).key;
        }
    }
}

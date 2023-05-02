import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Too Bad.tgs"
    title: qsTr("Too Bad!")
    body: qsTr("Without the secret words you can't restore access to the wallet")

    mainButton {
        text: qsTr("View my wallet")
        onClicked: AppSettings.privateKey = "1a8a1190-441b-49dd-815c-ef9ef0295846"
    }

    secondaryButton {
        text: qsTr("Import existing wallet")
        onClicked: {
            var import_component = Qt.createComponent("ImportWalletPage.qml");
            Viewport.viewport.append(import_component, {}, "stack")
        }
    }
}
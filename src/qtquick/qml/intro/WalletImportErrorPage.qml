import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    id: dis
    sticker: "qrc:/ton/common/stickers/Too Bad.tgs"
    title: qsTr("Too Bad!")
    body: qsTr("Without the secret words you can't restore access to the wallet")

    mainButton {
        text: qsTr("View my wallet")
        onClicked: dis.ViewportType.open = false
    }

    secondaryButton {
        text: qsTr("Import existing wallet")
        onClicked: {
            var import_component = Qt.createComponent("ImportWalletPage.qml");
            TViewport.viewport.append(import_component, {}, "stack")
        }
    }
}

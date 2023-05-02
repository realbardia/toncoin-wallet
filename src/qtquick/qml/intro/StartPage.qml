import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Start.tgs"
    title: qsTr("TON Wallet")
    body: qsTr("TON Wallet allows you to make fast and secure blockchian-based payments without intermediaries.")

    mainButton {
        text: qsTr("Create my wallet")
        onClicked: Viewport.viewport.append(congratulation_component, {}, "stack")
    }

    secondaryButton {
        text: qsTr("Import existing wallet")
        onClicked: Viewport.viewport.append(import_component, {}, "stack")
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

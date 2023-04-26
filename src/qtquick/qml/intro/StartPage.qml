import QtQuick 2.15
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
        onClicked: Viewport.viewport.append(congratulation_component, {}, "page")
    }

    secondaryButton {
        text: qsTr("Import existing wallet")
    }

    Component {
        id: congratulation_component
        CongratulationPage {
            anchors.fill: parent
        }
    }
}

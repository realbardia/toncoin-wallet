import QtQuick 2.15
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Success.tgs"
    title: qsTr("Perfect!")
    body: qsTr("Now set up a passcode to secure transactions.")

    mainButton {
        text: qsTr("Set a Passcode")
    }

    checkBox {
        text: qsTr("Enable Touch ID")
    }
}

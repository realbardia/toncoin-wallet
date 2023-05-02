import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    id: dis
    sticker: "qrc:/ton/common/stickers/Success.tgs"
    title: qsTr("Your wallet has just been imported!")

    mainButton {
        text: qsTr("View my wallet")
        onClicked: AppSettings.privateKey = "1a8a1190-441b-49dd-815c-ef9ef0295846"
    }
}
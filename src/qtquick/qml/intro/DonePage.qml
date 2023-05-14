import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    id: dis
    sticker: "qrc:/ton/common/stickers/Success.tgs"
    title: qsTr("Ready to go!")
    body: qsTr("You are all set. Now you have a wallet that only yout control -- directly, without middlemen or bankers.")
    backable: true

    property string publicKey

    Component.onCompleted: Devices.triggerVibrateFeedback()
    onCloseRequest: dis.ViewportType.open = false

    mainButton {
        text: qsTr("View my wallet")
        onClicked: AppSettings.loggedInPublicKey = publicKey
    }
}

import QtQuick 2.15
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Password.tgs"
    title: qsTr("Set a Passcode")
    body: qsTr("Enter the %1 digitis in the passcode.").arg(digitsCount)

    property int digitsCount

    secondaryButton {
        text: qsTr("Passcode options")
    }

    TPasswordField {
        width: 160
        Component.onCompleted: {
            focus = true;
            forceActiveFocus();
        }
    }
}

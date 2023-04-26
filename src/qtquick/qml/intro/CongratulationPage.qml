import QtQuick 2.15
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Congratulations.tgs"
    title: qsTr("Congratulations")
    body: qsTr("Your TON wallet has just been created Only you control it.\n\n" +
               "To be able to always have access to it, please write own secret words and set up a secure passcode.")

    mainButton {
        text: qsTr("Proceed")
        onClicked: Viewport.viewport.append(success_component, {}, "page")
    }

    Component {
        id: success_component
        SuccessPage {
            anchors.fill: parent
        }
    }
}

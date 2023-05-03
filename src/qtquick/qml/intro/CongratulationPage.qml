import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Congratulations.tgs"
    title: qsTr("Congratulations")
    body: qsTr("Your TON wallet has just been created Only you control it.\n\n" +
               "To be able to always have access to it, please write own secret words and set up a secure passcode.")

    mainButton {
        text: qsTr("Proceed")
        onClicked: TViewport.viewport.append(recovery_phrase_component, {}, "stack")
    }

    Component {
        id: recovery_phrase_component
        RecoveryPhrasePage {
            ViewportType.gestureWidth: dialogOpened? 0 : width
            anchors.fill: parent
        }
    }
}

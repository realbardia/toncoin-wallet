import QtQuick 2.0
import Toolkit 1.0
import "../components"
import "../globals"

THeaderMenuButton {
    id: btn
    ratio: 1
    buttonColor: "transparent"
    color: Colors.foreground

    TMaterialIcon {
        anchors.centerIn: parent
        text: MaterialIcons.mdi_close
        font.pixelSize: 18 * Devices.fontDensity
        color: btn.color
    }
}

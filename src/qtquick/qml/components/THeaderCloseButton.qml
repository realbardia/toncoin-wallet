import QtQuick 2.0
import AsemanQml.Base 2.0
import AsemanQml.Controls 2.0
import AsemanQml.MaterialIcons 2.0
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

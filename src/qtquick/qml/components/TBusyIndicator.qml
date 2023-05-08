import QtQuick 2.15
import Toolkit.Core 1.0

Item {
    id: dis
    width: 22
    height: width

    property bool running
    property bool accented

    Loader {
        anchors.fill: parent
        active: dis.running && dis.visible
        sourceComponent: StickerItem {
            anchors.fill: parent
            autoPlay: true
            source: accented? "qrc:/ton/common/stickers/Material Busy Accented.tgs" : "qrc:/ton/common/stickers/Material Busy.tgs"
        }
    }
}

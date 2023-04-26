import QtQuick 2.15
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {

    property alias viewport: viewport

    Viewport {
        id: viewport
        anchors.fill: parent
        mainItem: StartPage {
            anchors.fill: parent
        }
    }
}

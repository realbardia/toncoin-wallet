import QtQuick 2.15
import Viewport 1.0
import Toolkit 1.0
import "../components"
import "../globals"

TPage {

    property alias viewport: viewport

    TViewport {
        id: viewport
        anchors.fill: parent
        mainItem: StartPage {
            anchors.fill: parent
        }
    }
}

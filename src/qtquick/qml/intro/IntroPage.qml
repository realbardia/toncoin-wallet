import QtQuick 2.15
import Toolkit.Viewport 1.0
import Toolkit.Core 1.0
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

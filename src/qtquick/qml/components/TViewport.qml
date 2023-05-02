import QtQuick 2.0
import AsemanQml.Viewport 2.0
import "viewporttypes"

Viewport {

    items: [
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/TViewportDrawer.qml")
            name: "tdrawer"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/TViewportDialog.qml")
            name: "tdialog"
        }
    ]
}

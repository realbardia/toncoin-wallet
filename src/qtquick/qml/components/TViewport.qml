import QtQuick 2.0
import Viewport 1.0
import "viewporttypes"
import "private"

Viewport {

    items: [
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/DrawerViewport.qml")
            name: "drawer"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/DialogViewport.qml")
            name: "dialog"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/ActivityViewport.qml")
            name: "activity"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/PageViewport.qml")
            name: "page"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/StackViewport.qml")
            name: "stack"
        },
        ViewportItem {
            component: Qt.resolvedUrl("viewporttypes/PopupViewport.qml")
            name: "popup"
        }
    ]
}

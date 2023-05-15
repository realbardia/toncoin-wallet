import QtQuick 2.0
import Toolkit.Core 1.0
import QtQuick.Window 2.3

Row {
    x: parent.width - width - 2 * Devices.density
    anchors.top: parent.top
    anchors.margins: 2 * Devices.density

    LayoutMirroring.enabled: false
    LayoutMirroring.childrenInherit: false

    TTitleBarButtonItem {
        width: 50 * Devices.density
        height: 32 * Devices.density
        text: MaterialIcons.mdi_window_minimize
        font.pixelSize: 11 * Devices.fontDensity
        onClicked: Window.window.showMinimized()
    }

    TTitleBarButtonItem {
        width: 50 * Devices.density
        height: 32 * Devices.density
        text: MaterialIcons.mdi_window_close
        color: "#ff0000"
        onClicked: TonToolkitApp.exit(0)
    }
}

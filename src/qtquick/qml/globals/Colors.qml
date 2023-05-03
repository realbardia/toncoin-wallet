pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

TonToolkitObject {
    SystemPalette { id: desktopPallete; colorGroup: SystemPalette.Active }

    property bool darkMode: AppSettings.theme == 1? true : false

    readonly property color backgroundLight: darkMode? "#111111" : "#ffffff"
    readonly property color backgroundDeep: darkMode? "#000" : "#e0e0e0"
    readonly property color background: darkMode? "#000000" : "#ffffff"

    readonly property color headerColor: darkMode? "#222222" : "#ffffff"
    readonly property color footerColor: headerColor

    readonly property color foreground: darkMode? "#fff" : "#222"

    readonly property color accent: "#339cec"
    readonly property color primary: "#000000"

    readonly property color red: "#F44336"
    readonly property color green: "#4CAF50"
    readonly property color warnings: "#FFC107"

    onHeaderColorChanged: Devices.setupWindowColor(headerColor);
}

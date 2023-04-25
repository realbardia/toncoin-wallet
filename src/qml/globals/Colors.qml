pragma Singleton

import QtQuick 2.12
import QtQuick.Controls.Material 2.3
import AsemanQml.Base 2.0

QtObject {
    Material.theme: darkMode? Material.Dark : Material.Light

    property bool darkMode: AppSettings.theme == 1? true : false

    readonly property color backgroundLight: darkMode? "#111111" : "#ffffff"
    readonly property color backgroundDeep: darkMode? "#000" : "#f0f0f0"
    readonly property color background: darkMode? "#1a1a1a" : "#f8f7f8"

    readonly property color headerColor: darkMode? "#222222" : "#ffffff"
    readonly property color footerColor: headerColor

    readonly property color foreground: darkMode? "#fff" : "#222"

    readonly property color red: "#F44336"
    readonly property color green: "#4CAF50"
    readonly property color warnings: "#FFC107"

    onHeaderColorChanged: Devices.setupWindowColor(headerColor);
}

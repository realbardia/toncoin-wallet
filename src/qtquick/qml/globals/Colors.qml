pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

TonToolkitObject {
    property bool darkMode: AppSettings.darkMode

    readonly property color backgroundLight: darkMode? "#111111" : "#ffffff"
    readonly property color backgroundDeep: darkMode? "#666666" : "#e0e0e0"
    readonly property color background: darkMode? "#222222" : "#ffffff"

    readonly property color headerColor: {
        if ((GlobalValues.mwin && GlobalValues.mwin.currentViewport.currentType == "popup") || AppSettings.loggedInPublicKey.length)
            return "#000";
        else
        if (Colors.darkMode)
            return "#000";
        else
            return "#fff";
    }
    readonly property color headerTextColor: {
        if ((GlobalValues.mwin && GlobalValues.mwin.currentViewport.currentType == "popup") || AppSettings.loggedInPublicKey.length)
            return "#fff";
        else
        if (Colors.darkMode)
            return "#fff";
        else
            return "#000";
    }

    readonly property color foreground: darkMode? "#fff" : "#222"

    readonly property color accent: "#339cec"
    readonly property color primary: "#000000"

    readonly property color red: "#F44336"
    readonly property color green: "#4CAF50"
    readonly property color warnings: "#FFC107"
}

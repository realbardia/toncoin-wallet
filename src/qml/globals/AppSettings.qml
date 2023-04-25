pragma Singleton

import QtQuick 2.12
import AsemanQml.Base 2.0

Settings {
    category: "General"
    source: AsemanApp.homePath + "/settings.ini"

    property int theme: 0

    property real width: 440
    property real height: 720
}

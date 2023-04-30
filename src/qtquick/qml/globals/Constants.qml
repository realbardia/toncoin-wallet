pragma Singleton

import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import AsemanQml.Base 2.0

QtObject {
    readonly property real dialogsRoundness: 8
    readonly property real roundness: 16
    readonly property real controlsRoundness: 6

    readonly property bool mobileView: mwin && mwin.width < mwin.height? true : false
    readonly property real panelWidth: 320

    readonly property real itemsHeight: 40

    property ApplicationWindow mwin
}

pragma Singleton

import QtQuick 2.12
import Toolkit.Core 1.0

QtObject {
    readonly property string touchIdPass: "F33A9156-1FD3-4E4D-9C9D-34123CCC437B"

    readonly property real dialogsRoundness: 8
    readonly property real roundness: 16
    readonly property real controlsRoundness: 6

    readonly property bool mobileView: GlobalValues.mwin && GlobalValues.mwin.width < GlobalValues.mwin.height? true : false
    readonly property real panelWidth: 320

    readonly property real itemsHeight: 40

    readonly property int commentLimit: 128
}

import QtQuick 2.15
import Toolkit.Core 1.0

MouseArea {
    id: marea
    pressAndHoldInterval: 300

    property bool focusOnPress: true

    onPressedChanged: {
        if (!focusOnPress)
            return;
        focus = pressed;
        if (focus)
            forceActiveFocus();
    }

    Keys.onEnterPressed: if (marea.enabled) marea.clicked(null)
    Keys.onReturnPressed: if (marea.enabled) marea.clicked(null)
    Keys.onTabPressed: tabPressed()

    signal tabPressed()
}

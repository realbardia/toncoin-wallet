import QtQuick 2.15

MouseArea {
    pressAndHoldInterval: 300

    onPressedChanged: {
        focus = pressed;
        if (focus)
            forceActiveFocus();
    }
    onWheel: wheel.accepted = true

    Keys.onEnterPressed: marea.clicked(null)
    Keys.onReturnPressed: marea.clicked(null)
    Keys.onTabPressed: tabPressed()

    signal tabPressed()
}

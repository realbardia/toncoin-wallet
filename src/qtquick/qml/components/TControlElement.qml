import QtQuick 2.15

MouseArea {
    id: marea
    pressAndHoldInterval: 300

    onPressedChanged: {
        focus = pressed;
        if (focus)
            forceActiveFocus();
    }

    Keys.onEnterPressed: marea.clicked(null)
    Keys.onReturnPressed: marea.clicked(null)
    Keys.onTabPressed: tabPressed()

    signal tabPressed()
}

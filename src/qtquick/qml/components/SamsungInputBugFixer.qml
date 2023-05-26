import QtQuick 2.0
import Toolkit.Core 1.0

MouseArea {
    id: dis
    anchors.fill: parent
    visible: {
        if (!Devices.isAndroid)
            return false;
        if (Devices.deviceName.toLowerCase().indexOf("samsung") >= 0)
            return true;
        if (Devices.deviceName.toLowerCase().indexOf("galaxy") >= 0)
            return true;
        return false;
    }
    onPressed: {
        mouse.accepted = false;
        poke();
    }

    function poke() {
        if (visible)
            timerDisabled.restart();
    }

    Connections {
        target: dis.parent
        function onInputMethodComposingChanged() {
            if (!dis.visible)
                return;
            if (timerDisabled.running)
                return;
            if (!dis.parent.inputMethodComposing)
                timer.restart();
        }
    }

    Timer {
        id: timerDisabled
        interval: 1000
        repeat: false
    }

    Timer {
        id: timer
        interval: 100
        repeat: false
        onTriggered: {
            if (!dis.visible)
                return;
            if (timerDisabled.running)
                return;
            if (dis.parent.inputMethodComposing) {
                dis.focus = true;
            }
        }
    }
}

import QtQuick 2.15
import QtQuick.Controls 2.3
import QtQuick.Templates 2.0
import AsemanQml.Base 2.0
import "../globals"

Dialog {
    id: dlg
    modal: true
    dim: true

    Overlay.modal: Item {
        Rectangle {
            anchors.fill: parent
            color: Colors.foreground
            opacity: dlg.dim? 0.25 : 0
        }
    }
    background: Rectangle {
        radius: 14
        color: Colors.background

        MouseArea {
            anchors.fill: parent
            onClicked: {
                focus = true;
                forceActiveFocus();
                Devices.hideKeyboard();
            }
        }
    }
    header: Label {
        text: dlg.title
        font.pixelSize: 20
        font.weight: Font.Medium
        leftPadding: 20
        topPadding: 30
        rightPadding: 20
        color: Colors.foreground
    }
}

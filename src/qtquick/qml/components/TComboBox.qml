import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import "../globals"

ComboBox {
    id: control
    font.pixelSize: 14
    popup.modal: true
    popup.dim: true
    delegate: ItemDelegate {
        width: parent? parent.width : control.popup.width

        Label {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.margins: 10
            font.pixelSize: 14
            text: control.textRole ? (Array.isArray(control.model) ? modelData[control.textRole] : model[control.textRole]) : modelData
        }
    }
}

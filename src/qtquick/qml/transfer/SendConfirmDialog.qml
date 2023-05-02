import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TDrawer {
    id: dis
    title: qsTr("Send TON")

    mainButton {
        text: qsTr("Continue and send")
    }

    property string address
    property string domain
    property string value
}

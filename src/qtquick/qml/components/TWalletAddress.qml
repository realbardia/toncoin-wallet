import QtQuick 2.0
import "../globals"

TButton {
    flat: true
    height: 26
    text: address.slice(0, elideCount) + "..." + address.slice(address.length-elideCount)
    color: Colors.foreground

    property int elideCount: 4
    property string address
}

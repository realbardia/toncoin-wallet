pragma Singleton

import QtQuick 2.12
import QtQuick.Window 2.15
import Toolkit.Core 1.0

QtObject {
    property bool unlocked: false
    property Window mwin

    property string balance: "0.00000"
    property string address
}

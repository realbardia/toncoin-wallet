pragma Singleton

import QtQuick 2.10
import Toolkit.Core 1.0

QtObject {
    signal discardMenus()
    signal snackRequest(string icon, string title, string description, string color)
}

pragma Singleton

import QtQuick 2.12
import QtQuick.Window 2.15
import Toolkit.Core 1.0

QtObject {
    property string passCode
    property Window mwin

    property string tempLinkToOpen: linkToOpen
}

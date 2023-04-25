pragma Singleton

import QtQuick 2.12
import Neo.Core 1.0 as Neo

Neo.NetworkLogsModel {
    network: AppSettings.consoleEnabled? Neo.Network : null

    function init() {}
}

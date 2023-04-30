pragma Singleton

import QtQuick 2.10
import AsemanQml.Base 2.0

Item {

    readonly property string globalFontSize: 9 * Devices.fontDensity
    readonly property string globalFont: ubuntu.name + ", " + vazir.name

    FontLoader { id: ubuntu; source: "fonts/Ubuntu-R.ttf"}
    FontLoader { source: "fonts/Ubuntu-B.ttf"}
    FontLoader { source: "fonts/Ubuntu-L.ttf"}
    FontLoader { source: "fonts/Ubuntu-M.ttf"}
    FontLoader { source: "fonts/UbuntuMono-R.ttf"}
    FontLoader { source: "fonts/UbuntuMono-B.ttf"}
    FontLoader { id: vazir; source: "fonts/Vazir-Regular-FD.ttf" }

    function init() {}
}

pragma Singleton

import QtQuick 2.15
import Toolkit.Core 1.0

TonToolkitObject {
    id: translationManager

    property alias model: model
    property alias localeName: mgr.localeName
    property alias textDirection: mgr.textDirection
    readonly property bool reverseLayout: textDirection == Qt.RightToLeft

    ToolkitListModel {
        id: model
        data: {
            var res = new Array;
            var list = mgr.translations;
            for (var i in list) {
                res[res.length] = {
                    "title": list[i],
                    "key": i
                }
            }
            return res
        }
    }

    TranslationManager {
        id: mgr
        sourceDirectory: "translations/"
        delimiters: "-"
        fileName: "lang"
        localeName: AppSettings.language
    }

    function init() {}
}

pragma Singleton

import QtQuick 2.10
import Toolkit.Core 1.0

QtObject {

    function justifyNumber(num, len) {
        num = num + "";
        while (num.length < len)
            num = "0" + num;
        return num;
    }

    function fixNum(num, len) {
        var res = num + "";
        var idx = res.indexOf('.');
        if (idx > 0 && (res.length-idx+1) > (len? len+1 : 0));
            res = res.slice(0,idx + (len? len+1 : 0));

        res = Tools.stringReplace(res, "0+$", "", true);
        return res
    }
}

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
}

pragma Singleton

import QtQuick 2.10
import Toolkit.Core 1.0

TonToolkitObject {

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

    Timer {
        id: checkingBiometricTimer
        interval: 2000
        repeat: false
        onTriggered: checkingBiometric = false
    }

    property bool checkingBiometric
    function biometricCheck() {
        checkingBiometric = true;
        var res = Devices.biometricCheck();
        checkingBiometricTimer.restart();
        return res;
    }

    function pressedScale(width,height) {
        let m = Math.max(width, height);
        var res = (m-4) / m;
        return Math.max(res, 0.95);
    }
}

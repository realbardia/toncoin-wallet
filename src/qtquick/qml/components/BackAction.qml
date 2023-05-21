import QtQuick 2.9
import Toolkit.Core 1.0

AsemanObject {
    id: backAction
    property bool active: false
    property var callback
    property bool disableBack: false

    onActiveChanged: {
        if(active)
            BackHandler.pushHandler(backAction, function(){
                if(callback)
                    callback()
                else
                    active = false
            })
        else
            BackHandler.removeHandler(backAction)
    }
}

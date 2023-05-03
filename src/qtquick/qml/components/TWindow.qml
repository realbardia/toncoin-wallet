import QtQuick 2.9
import QtQuick.Window 2.15
import Toolkit 1.0

Window {
    id: appWin

    property bool backController: true
    property bool try_close: false

    signal closeRequest()

    onCloseRequest: if(backController) TonToolkitApp.back()

    Timer {
        id: timer_delayer
        interval: 300
        repeat: false
    }

    Connections {
        target: TonToolkitApp
        onBackRequest: {
            if(timer_delayer.running)
                return

            timer_delayer.start()
            var res = BackHandler.back()
            if( !res && !Devices.isDesktop )
                appWin.tryClose()
        }
    }

    function tryClose() {
        try_close = true
        close()
    }

    Component.onCompleted: {
        View.registerWindow(appWin)
        View.root = appWin
    }
}

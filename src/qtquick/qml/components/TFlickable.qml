import QtQuick 2.15
import Toolkit.Core 1.0

Flickable {
    id: flick
    maximumFlickVelocity: View.flickVelocity
    boundsBehavior: !Devices.isAndroid? Flickable.DragAndOvershootBounds : Flickable.StopAtBounds

    property bool allTimeMode: true
    readonly property real tabBarRatio: prv.tabBarExtra/tabBarHeight
    property real tabBarHeight: 50*Devices.density

    onTabBarHeightChanged: prv.tabBarExtra = tabBarHeight
    onContentYChanged: prv.optimizeTabBar()
    onContentHeightChanged: if(contentHeight<height) anim.start()

    NumberAnimation {
        id: anim
        target: prv
        property: "tabBarExtra"
        from: prv.tabBarExtra
        to: tabBarHeight
        easing.type: !Devices.isAndroid? Easing.OutBack : Easing.OutCubic
        duration: !Devices.isAndroid? 350 : 250
    }

    Transition {
        id: android_transition
        NumberAnimation {
            properties: "x,y"
            duration: 0
        }
    }

    QtObject {
        id: prv

        property real lastContentY: flick.contentY+1
        property real tabBarExtra: flick.tabBarHeight

        function optimizeTabBar() {
            var minFlick = -tabBarHeight
            var maxFlick = flick.contentHeight - flick.height + minFlick
            if(flick.contentY > maxFlick || flick.contentY<=0) {
                tabBarExtra = tabBarHeight
                return
            }
            if(flick.contentY > tabBarHeight && !allTimeMode) {
                tabBarExtra = 0
                return
            }

            var newExtra = tabBarExtra - (flick.contentY-prv.lastContentY)
            if(newExtra<0)
                newExtra = 0
            if(flick.contentY < minFlick)
                newExtra = -flick.contentY
            else
            if(newExtra>tabBarHeight)
                newExtra = tabBarHeight

            tabBarExtra = newExtra
            prv.lastContentY = flick.contentY
        }
    }

    Component.onCompleted: if(Devices.isAndroid) rebound = android_transition
}

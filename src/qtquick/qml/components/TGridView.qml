import QtQuick 2.15
import Toolkit.Core 1.0

GridView {
    id: gridv

    readonly property real tabBarRatio: prv.tabBarExtra/tabBarHeight
    property real tabBarHeight: 50*Devices.density

    onTabBarHeightChanged: prv.tabBarExtra = tabBarHeight
    onContentYChanged: prv.optimizeTabBar()

    maximumFlickVelocity: View.flickVelocity
    boundsBehavior: !Devices.isAndroid? Flickable.DragAndOvershootBounds : Flickable.StopAtBounds
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

        property real lastContentY: gridv.contentY+1
        property real tabBarExtra: gridv.tabBarHeight

        function optimizeTabBar() {
            var minFlick = -tabBarHeight
            var maxFlick = gridv.contentHeight - gridv.height + minFlick
            if(gridv.contentY > maxFlick || gridv.contentY < 0)
                return

            var newExtra = tabBarExtra - (gridv.contentY-prv.lastContentY)
            if(newExtra<0)
                newExtra = 0
            if(gridv.contentY < minFlick)
                newExtra = -gridv.contentY
            else
            if(newExtra>tabBarHeight)
                newExtra = tabBarHeight

            tabBarExtra = newExtra
            prv.lastContentY = gridv.contentY
        }
    }

    Component.onCompleted: if(Devices.isAndroid) rebound = android_transition
}

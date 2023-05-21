import QtQuick 2.15
import Toolkit.Core 1.0

ListView {
    id: listv

    maximumFlickVelocity: View.flickVelocity
    boundsBehavior: !Devices.isAndroid? Flickable.DragAndOvershootBounds : Flickable.StopAtBounds

    property bool allTimeMode: true
    readonly property real tabBarRatio: {
        if( prv.tabBarExtra < tabBarMargin )
            return 0
        if( prv.tabBarExtra > tabBarMargin + tabBarHeight )
            return 1
        else
            return (prv.tabBarExtra - tabBarMargin)/tabBarHeight
    }
    property real tabBarHeight: 50*Devices.density
    property real tabBarMargin: tabBarHeight

    onTabBarHeightChanged: prv.tabBarExtra = tabBarHeight + tabBarMargin*2
    onContentHeightChanged: if(contentHeight<height) anim.start()

    NumberAnimation {
        id: anim
        target: prv
        property: "tabBarExtra"
        from: prv.tabBarExtra
        to: tabBarHeight + listv.tabBarMargin*2
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

        property real contentY: heightRatio? yPosition*listv.height/heightRatio - tabBarHeight - tabBarMargin*2 : 0
        property real lastContentY: contentY+1
        property real tabBarExtra: listv.tabBarHeight + listv.tabBarMargin*2

        property real yPosition: listv.visibleArea.yPosition
        property real heightRatio: listv.visibleArea.heightRatio

        onContentYChanged: prv.optimizeTabBar()

        function optimizeTabBar() {
            var minFlick = -tabBarHeight - tabBarMargin*2
            var maxFlick = listv.contentHeight - listv.height + minFlick
            if(contentY > maxFlick || contentY<0)
                return
            if(contentY > tabBarHeight + tabBarMargin*2 && !allTimeMode) {
                tabBarExtra = 0
                return
            }

            var newExtra = tabBarExtra - (contentY-prv.lastContentY)
            if(newExtra<0)
                newExtra = 0
            if(contentY < minFlick)
                newExtra = -contentY
            else
            if(newExtra>tabBarHeight + tabBarMargin*2)
                newExtra = tabBarHeight + tabBarMargin*2
            if(newExtra == NaN)
                return

            tabBarExtra = newExtra
            prv.lastContentY = contentY
        }
    }

    Component.onCompleted: if(Devices.isAndroid) rebound = android_transition
}

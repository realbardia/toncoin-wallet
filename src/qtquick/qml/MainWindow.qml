import QtQuick 2.15
import QtQuick.Window 2.15
import AsemanQml.Base 2.0
import AsemanQml.Controls 2.0
import AsemanQml.Viewport 2.0
import "intro" as Intro
import "components"
import "globals"

AsemanWindow {
    id: win
    width: AppSettings.width
    height: AppSettings.height
    visible: true
    title: AsemanApp.applicationName
    font.family: Fonts.globalFont

    readonly property bool portrait: width<height
    readonly property Viewport currentViewport: introLoader.item? introLoader.item.viewport : null

    onWidthChanged: AppSettings.width = width
    onHeightChanged: AppSettings.height = height

    Item {
        id: mainScene
        anchors.fill: parent

        Loader {
            id: introLoader
            anchors.fill: parent
            active: true
            sourceComponent: Intro.IntroPage {
                anchors.fill: parent
            }
        }
    }
}

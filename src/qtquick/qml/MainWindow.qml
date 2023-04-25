import QtQuick 2.15
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQuick.Window 2.15
import QtQuick.Controls.Material 2.3
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

    Material.theme: Colors.darkMode? Material.Dark : Material.Light
    Material.accent: Colors.accent
    Material.primary: Colors.accent
    Material.background: Colors.background

    readonly property bool portrait: width<height
    property alias viewport: viewport

    onWidthChanged: AppSettings.width = width
    onHeightChanged: AppSettings.height = height

    Viewport {
        id: viewport
        anchors.fill: parent
        mainItem: Item {
            id: mainScene
            anchors.fill: parent

            Intro.StartPage {
                anchors.fill: parent
            }
        }
    }
}

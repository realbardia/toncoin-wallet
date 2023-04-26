import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

SimplePageTemplate {
    sticker: "qrc:/ton/common/stickers/Test Time.tgs"
    title: qsTr("Test Time!")
    body: qsTr("Let's check that you wrote them down correctly. Please enter the words <b>%1</b>, <b>%2</b> and <b>%3</b>.").arg(5).arg(15).arg(18)
    backable: true

    mainButton {
        text: qsTr("Continue")
        onClicked: Viewport.viewport.append(success_component, {}, "page")
    }

    Component {
        id: success_component
        SuccessPage {
            id: spage
            ViewportType.gestureWidth: 0
            anchors.fill: parent
            Component.onCompleted: {
                Qt.callLater(function(){
                    BackHandler.pushHandler(spage, function(){ return false; })
                })
            }
        }
    }
}

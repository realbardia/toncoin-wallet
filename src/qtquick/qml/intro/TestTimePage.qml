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

    component CustomTextField: TTextField {
        width: 160
        leftPadding: 24

        property alias label: label.text

        TLabel {
            id: label
            anchors.right: parent.left
            anchors.rightMargin: -20
            anchors.verticalCenter: parent.verticalCenter
            opacity: 0.4
        }
    }

    TColumn {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 6

        CustomTextField {
            id: field_1
            label: "5:"
            Keys.onTabPressed: {
                field_2.focus = true;
                field_2.forceActiveFocus();
            }
        }
        CustomTextField {
            id: field_2
            label: "15:"
            Keys.onTabPressed: {
                field_3.focus = true;
                field_3.forceActiveFocus();
            }
        }
        CustomTextField {
            id: field_3
            label: "18:"
        }
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

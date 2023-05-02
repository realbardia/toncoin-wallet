import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import TonToolkit 1.0
import "../components"
import "../globals"

TPage {
    id: dis

    SimplePageTemplate {
        id: simplePage
        anchors.fill: parent
        sticker: "qrc:/ton/common/stickers/Test Time.tgs"
        title: qsTr("Test Time!")
        body: qsTr("Let's check that you wrote them down correctly. Please enter the words <b>%1</b>, <b>%2</b> and <b>%3</b>.").arg(5).arg(15).arg(18)
        backable: true

        onCloseRequest: dis.ViewportType.open = false

        mainButton {
            text: qsTr("Continue")
            enabled: field_1.length && field_2.length && field_3.length
            onClicked: {
                if (field_1.text.length == 0) {
                    errorDialog.open();
                } else {
                    Viewport.viewport.append(success_component, {}, "stack")
                }
            }
            onTabPressed: {
                field_1.focus = true;
                field_1.forceActiveFocus();
            }
        }

        component CustomTextField: TTextField {
            width: 160
            leftPadding: 24
            suggestions: ["Test 1", "Test 2", "Test 3", "Test 4", "Test 5"]
            z: suggestionsMenu? 100 : 0

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
            z: 10

            CustomTextField {
                id: field_1
                label: "5:"
                onTabPressed: {
                    field_2.focus = true;
                    field_2.forceActiveFocus();
                }
            }
            CustomTextField {
                id: field_2
                label: "15:"
                onTabPressed: {
                    field_3.focus = true;
                    field_3.forceActiveFocus();
                }
            }
            CustomTextField {
                id: field_3
                label: "18:"
                onTabPressed: {
                    simplePage.mainButton.focus = true;
                    simplePage.mainButton.forceActiveFocus();
                }
            }
        }
    }

    TDialog {
        id: errorDialog
        anchors.fill: parent
        title: qsTr("Incorrect words")
        buttons: [qsTr("See words"), qsTr("Try again")]
        onButtonClicked: {
            switch (index) {
            case 0:
                dis.ViewportType.open = false;
                errorDialog.close();
                break;
            case 1:
                errorDialog.close();
                break;
            }
        }

        TLabel {
            width: Math.min(dis.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("The secret words you have entered do not match the ones in the list.")
        }
    }

    Component {
        id: success_component
        SuccessPage {
            id: spage
            ViewportType.gestureWidth: 0
            anchors.fill: parent
        }
    }
}


import QtQuick 2.15
import "../globals"

TControlElement {
    id: element
    height: Constants.itemsHeight

    property alias digitsCount: input.maximumLength
    property alias text: input.text

    onDigitsCountChanged: input.clear()

    onFocusChanged: {
        if (focus) {
            input.focus = true;
            input.forceActiveFocus();
        }
    }

    TextInput {
        id: input
        anchors.fill: parent
        opacity: 0
        clip: true
        maximumLength: 4
        validator: RegularExpressionValidator {
            regularExpression: /\d+/
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            input.focus = true;
            input.forceActiveFocus();
        }
    }

    Repeater {
        model: element.digitsCount

        Rectangle {
            width: 14
            x: model.index * (element.width / element.digitsCount) + (element.width / element.digitsCount)/2 - width/2
            anchors.verticalCenter: parent.verticalCenter
            height: width
            radius: width / 2
            opacity: model.index < input.length? 1 : 0.4
            color: model.index < input.length? Colors.foreground : "transparent"
            border.width: 1
            border.color: Colors.foreground
        }
    }
}

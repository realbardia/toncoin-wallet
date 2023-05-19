import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import "../components"

TPage {
    id: dis

    signal tagFound(string tag)

    THeaderItem {
        id: header
        anchors.left: parent.left
        anchors.right: parent.right
        title: qsTr("QR Scanner")
    }

    THeaderCloseButton {
        onClicked: dis.ViewportType.open = false
    }

    PointMapListener {
        id: mapListener
        source: scene
        dest: windowScene
    }

    Item {
        id: scene
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        clip: true

        ZXingCamera {
            y: -1 * mapListener.result.y + windowScene.height - height
            width: parent.width
            height: parent.height
            onTagFound: {
                dis.tagFound(tag);
            }
        }
    }
}

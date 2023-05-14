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

        THeaderCloseButton {
            onClicked: dis.ViewportType.open = false
        }
    }

    ZXingCamera {
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        onTagFound: {
            dis.tagFound(tag);
        }
    }
}

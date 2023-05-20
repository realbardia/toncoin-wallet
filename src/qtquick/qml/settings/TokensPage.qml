import QtQuick 2.15
import Toolkit.Core 1.0
import Toolkit.Viewport 1.0
import Wallet.TonConnect 1.0
import "../globals"
import "../components"

TPage {
    id: dis

    signal tagFound(string tag)

    property TonConnect tonConnect

    THeaderItem {
        id: header
        anchors.left: parent.left
        anchors.right: parent.right
        title: qsTr("Tokens")
    }

    THeaderCloseButton {
        onClicked: dis.ViewportType.open = false
    }

    TLabel {
        anchors.centerIn: scene
        text: qsTr("There is no token")
        opacity: 0.6
        visible: listv.count == 0
    }

    TScrollView {
        id: scene
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        clip: true

        TListView {
            id: listv
            model: ToolkitListModel {
                data: tonConnect.tokens
            }
            delegate: TItemDelegate {
                height: 50
                width: listv.width
                onClicked: Qt.openUrlExternally(model.domain)

                Item {
                    id: icon
                    anchors.left: parent.left
                    anchors.leftMargin: 20 * Devices.density
                    anchors.verticalCenter: parent.verticalCenter
                    width: height
                    height: 34

                    Image {
                        id: img
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        asynchronous: true
                        source: model.iconUrl
                        mipmap: true
                        visible: false
                        cache: true
                    }

                    Rectangle {
                        id: mask
                        anchors.fill: img
                        color: Colors.backgroundDeep
                        radius: Constants.controlsRoundness
                    }

                    OpacityMask {
                        anchors.fill: img
                        source: img
                        maskSource: mask
                    }

                    TBusyIndicator {
                        width: 22
                        height: 22
                        anchors.centerIn: parent
                        running: img.status == Image.Loading
                        accented: true
                    }
                }

                TColumn {
                    anchors.left: icon.right
                    anchors.right: revokeBtn.left
                    anchors.rightMargin: 10 * Devices.density
                    anchors.leftMargin: 10 * Devices.density
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 0

                    TLabel {
                        width: parent.width
                        font.pixelSize: 9 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        elide: Text.ElideRight
                        maximumLineCount: 1
                        text: model.name
                    }
                    TLabel {
                        text: Tools.dateToString(model.datetime, "yyyy/MM/dd hh:mm")
                        font.pixelSize: 7 * Devices.fontDensity
                        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                        elide: Text.ElideRight
                        maximumLineCount: 1
                        opacity: 0.6
                    }
                }

                TButton {
                    id: revokeBtn
                    width: 36
                    height: 36
                    anchors.right: parent.right
                    anchors.rightMargin: 20 * Devices.density
                    anchors.verticalCenter: parent.verticalCenter
                    icon.text: MaterialIcons.mdi_close
                    icon.font.pixelSize: 14 * Devices.fontDensity
                    icon.anchors.verticalCenterOffset: 2 * Devices.density
                    flat: true
                    color: Colors.red
                    onClicked: {
                        revokeDialog.revokeId = model.id;
                        revokeDialog.revokeName = model.name;
                        revokeDialog.open();
                    }
                }

                Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    height: 1 * Devices.density
                    color: Colors.foreground
                    opacity: 0.1
                    visible: model.index != listv.count-1
                }
            }
        }
    }

    TDialog {
        id: revokeDialog
        anchors.fill: parent
        title: qsTr("Revoke")
        buttons: [qsTr("Cancel"), qsTr("Revoke")]
        lastButtonColor: Colors.red
        onButtonClicked: {
            switch (index) {
            case 0:
                revokeDialog.close();
                break;
            case 1:
                tonConnect.revoke(revokeId)
                revokeDialog.close();
                break;
            }
        }

        TLabel {
            width: Math.min(dis.width - 40, 300)
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("Do you realy want to revoke \"%1\" dapp?").arg(revokeDialog.revokeName)
        }

        property string revokeId
        property string revokeName
    }
}

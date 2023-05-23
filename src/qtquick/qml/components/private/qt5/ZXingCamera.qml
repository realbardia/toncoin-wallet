import QtQuick 2.15
import QtMultimedia 5.12
import Toolkit.Core 1.0
import QZXing 3.3
import "../../../globals"
import "../.."

Item {
    id: dis

    signal tagFound(string tag)

    Camera {
        id: camera
        focus.focusMode: Camera.FocusContinuous
        captureMode: Camera.CaptureViewfinder
        viewfinder.resolution: {
            var list = imageCapture.supportedResolutions
            for(var i in list) {
                var sz = list[i]
                if(sz.width >= 800)
                    return sz
            }

            var idx = Math.floor(list.length/2)
            if(list.length >= idx)
                return Qt.size(0, 0)
            return list[idx]
        }
    }

    VideoOutput {
        id: cameraOutput
        anchors.fill: parent
        source: camera
        fillMode: VideoOutput.PreserveAspectCrop
        autoOrientation: true
        filters: [zxingFilter]

        Rectangle {
            id: focusBorder
            width: parent.width * 0.6
            height: width
            color: "#00000000"
            radius: 12 * Devices.density
            border.width: 1 * Devices.density
            border.color: Colors.accent
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Item {
                id: focusEffectBorder
                anchors.fill: parent
                visible: false

                Rectangle {
                    id: focusInnerBorder
                    color: "#00000000"
                    radius: 12 * Devices.density
                    anchors.fill: parent
                    anchors.margins: 40 * Devices.density
                    border.color: Colors.accent
                    border.width: 1 * Devices.density
                }
            }

            Item {
                id: focusMaskBorder
                anchors.fill: parent
                visible: false

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: width
                    color: "#ffffff"
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }

                Rectangle {
                    width: parent.width * 0.35
                    height: 96
                    color: "#ffffff"
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                }
            }

            OpacityMask {
                anchors.fill: parent
                source: focusEffectBorder
                maskSource: focusMaskBorder
            }

            TLabel {
                id: cameraLoading
                text: qsTr("Please wait")
                font.capitalization: Font.AllUppercase
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                visible: camera.cameraStatus != Camera.ActiveStatus
            }
        }
    }

    QZXingFilter {
        id: zxingFilter
        captureRect: cameraOutput.sourceRect
        decoder {
            enabledDecoders: QZXing.DecoderFormat_QR_CODE
            onTagFound: dis.tagFound(tag)
            tryHarder: true
        }
    }
}

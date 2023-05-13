import QtQuick 2.15
import QtMultimedia 5.12
import Toolkit.Core 1.0
import QZXing 3.3

Item {
    id: dis

    property Camera camera

    signal tagFound(string tag)

    function stop() {
        camera.stop();
    }

    Component.onCompleted: {
        if (!Devices.isMacX)
            camera = camera_component.createObject(dis)
    }

    VideoOutput {
        id: cameraOutput
        anchors.fill: parent
        source: dis.camera
        fillMode: VideoOutput.PreserveAspectCrop
        autoOrientation: true
        filters: [zxingFilter]
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

    Component {
        id: camera_component
        Camera {
            id: camera
            focus.focusMode: Camera.FocusContinuous
            captureMode: Camera.CaptureViewfinder
            viewfinder.resolution: {
                if (!imageCapture)
                    return Qt.size(0,0);

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
    }
}

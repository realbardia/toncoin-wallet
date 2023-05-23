import QtQuick 2.15
import QtMultimedia 5.12
import Toolkit.Core 1.0
import QZXing 3.3

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

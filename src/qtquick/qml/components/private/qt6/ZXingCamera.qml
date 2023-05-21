import QtQuick 2.15
import QtMultimedia 6.4
import QZXing 3.3

Item {
    id: dis

    signal tagFound(string tag)

    function stop() {
        camera.stop();
    }

    Component.onDestruction: stop()

    Camera {
        id:camera
        active: true
        focusMode: Camera.FocusModeAutoNear
        Component.onCompleted: start()
    }

    CaptureSession {
        camera: camera
        videoOutput: videoOutput
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        fillMode: VideoOutput.PreserveAspectCrop
    }

    QZXingFilter {
        id: zxingFilter
        videoSink: videoOutput.videoSink
        orientation: videoOutput.orientation

        captureRect: videoOutput.sourceRect
        decoder {
            enabledDecoders: QZXing.DecoderFormat_QR_CODE
            onTagFound: dis.tagFound(tag)
            tryHarder: true
        }
    }
}

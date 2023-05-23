import QtQuick 2.15
import QtMultimedia 6.4

// This file created because camera crashes on Qt6 when destroyed. So we prevent from destroy
Item {
    anchors.fill: parent

    property alias videoOutput: videoOutput

    function start() {
        camera.start();
    }
    function stop() {
        camera.stop();
    }

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
}

import QtQuick 2.15
import Toolkit.Core 1.0
import QtMultimedia 6.4
import QZXing 3.3
import "../../../globals"

Item {
    id: dis

    signal tagFound(string tag)

    property CrashSafeCameraSession camera

    Component.onCompleted: {
        if (GlobalValues.crashSafeCamera) {
            camera = GlobalValues.crashSafeCamera;
        } else {
            camera = Tools.createObject("qrc:/components/private/qt6/CrashSafeCameraSession.qml");
            GlobalValues.crashSafeCamera = camera;
        }

        camera.parent = dis;
        camera.visible = true;
        camera.start();
    }
    Component.onDestruction: {
        camera.parent = GlobalValues.mainScene;
        camera.visible = false;
        camera.stop();
    }

    QZXingFilter {
        id: zxingFilter
        videoSink: camera.videoOutput.videoSink
        orientation: camera.videoOutput.orientation

        captureRect: camera.videoOutput.sourceRect
        decoder {
            enabledDecoders: QZXing.DecoderFormat_QR_CODE
            onTagFound: dis.tagFound(tag)
            tryHarder: true
        }
    }
}

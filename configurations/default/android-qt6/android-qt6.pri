
android {
    TARGET = Tonium

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD

    OTHER_FILES += \
        $$PWD/AndroidManifest.xml \
        $$PWD/build.gradle \
        $$files($$PWD/*.png, true) \
        $$files($$PWD/*.xml, true)

    error(Android on Qt6 not supported)
}


DISTFILES += \
    $$PWD/src/com/hmkcode/android/image/RealPathUtilTonium.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumActivity.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumApplication.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumJavaLayer.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumQtService.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumService.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumServiceDelegate.java

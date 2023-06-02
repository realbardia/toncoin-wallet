
android {
    TARGET = Tonium

    lessThan(QT_MAJOR_VERSION, 5) QT += androidextras
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD

    OTHER_FILES += \
        $$PWD/AndroidManifest.xml \
        $$PWD/build.gradle \
        $$files($$PWD/*.png, true) \
        $$files($$PWD/*.xml, true)
}

DISTFILES += \
    $$PWD/src/com/hmkcode/android/image/RealPathUtilTonium.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumActivity.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumApplication.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumJavaLayer.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumQtService.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumService.java \
    $$PWD/src/io/asemantonium/android/AsemanToniumServiceDelegate.java

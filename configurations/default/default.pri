DEFINES += CONFIG_DEFAULT

include(ios/ios.pri)
greaterThan(QT_MAJOR_VERSION, 5) {
    include(android-qt6/android-qt6.pri)
} else {
    include(android/android.pri)
}
include(linux/linux.pri)
include(macos/macos.pri)
include(windows/windows.pri)
include(globals/globals.pri)


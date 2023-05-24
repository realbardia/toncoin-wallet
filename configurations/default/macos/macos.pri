
macx {
    TARGET = Tonium

    ICON = $$PWD/logo.icns

    Q_ENTITLEMENTS.name = CODE_SIGN_ENTITLEMENTS
    Q_ENTITLEMENTS.value = $$PWD/Entitlements.plist
    QMAKE_MAC_XCODE_SETTINGS += Q_ENTITLEMENTS

    Q_ENABLE_BITCODE.name = ENABLE_BITCODE
    Q_ENABLE_BITCODE.value = NO
    QMAKE_MAC_XCODE_SETTINGS += Q_ENABLE_BITCODE

    DISTFILES += \
        $$PWD/logo.icns

    QMAKE_INFO_PLIST = $$PWD/Info.plist
}

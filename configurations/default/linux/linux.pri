linux: !android {
    TARGET = tonium

    isEmpty(PREFIX): PREFIX = /usr

    SHORTCUT = tonium

    shortcut.input = $$PWD/share/Tonium.desktop.in
    shortcut.output = $$PWD/share/Tonium.desktop
    shortcut.path = $$PREFIX/share/applications/
    shortcut.files = $$shortcut.output
    icons.path = $$PREFIX/share/icons
    icons.files = $$PWD/share/hicolor
    pixmaps.path = $$PREFIX/share/pixmaps
    pixmaps.files = $$PWD/share/tonium.png
    target.path = $$PREFIX/bin

    QMAKE_SUBSTITUTES += shortcut

    INSTALLS = target shortcut icons pixmaps

    DISTFILES += \
        $$PWD/share/Tonium.desktop.in \
        $$PWD/share/hicolor/128x128/apps/tonium.png \
        $$PWD/share/hicolor/16x16/apps/tonium.png \
        $$PWD/share/hicolor/256x256/apps/tonium.png \
        $$PWD/share/hicolor/32x32/apps/tonium.png \
        $$PWD/share/hicolor/48x48/apps/tonium.png \
        $$PWD/share/hicolor/64x64/apps/tonium.png \
        $$PWD/share/hicolor/96x96/apps/tonium.png \
        $$PWD/share/tonium.png \
}

linux: !android {

    SHORTCUT = xton

    shortcut.input = $$PWD/share/XTon.desktop.in
    shortcut.output = $$PWD/share/XTon.desktop
    shortcut.path = $$PREFIX/share/applications/
    shortcut.files = $$shortcut.output
    icons.path = $$PREFIX/share/icons
    icons.files = $$PWD/share/hicolor
    pixmaps.path = $$PREFIX/share/pixmaps
    pixmaps.files = $$PWD/share/xton.png
    target.path = $$PREFIX/bin

    QMAKE_SUBSTITUTES += shortcut

    INSTALLS += target shortcut icons pixmaps

    DISTFILES += \
        $$PWD/share/XTon.desktop.in \
        $$PWD/share/hicolor/128x128/apps/xton.png \
        $$PWD/share/hicolor/16x16/apps/xton.png \
        $$PWD/share/hicolor/256x256/apps/xton.png \
        $$PWD/share/hicolor/32x32/apps/xton.png \
        $$PWD/share/hicolor/48x48/apps/xton.png \
        $$PWD/share/hicolor/64x64/apps/xton.png \
        $$PWD/share/hicolor/96x96/apps/xton.png \
        $$PWD/share/xton.png \
}

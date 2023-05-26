INCLUDEPATH += $$PWD

VERSION = 1.0.2

QTPLUGIN.qmltooling += qmldbg_debugger
QTPLUGIN.imageformats += qsvg qjpeg

include (core/core.pri)
include (thirdparty/thirdparty.pri)
include (qtquick/qtquick.pri)
include (widgets/widgets.pri)
include (common/common.pri)

macx {
    LIBS += -framework Cocoa
    SOURCES += \
        $$PWD/macappdelegate.mm
    HEADERS += \
        $$PWD/macappdelegate.h
}
ios {
    SOURCES += \
        $$PWD/iosappdelegate.mm
    HEADERS += \
        $$PWD/iosappdelegate.h
}

SOURCES += \
    $$PWD/main.cpp

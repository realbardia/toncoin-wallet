QT += qml \
    quick

include (toolkit/toolkit.pri)
include (viewport/viewport.pri)

HEADERS += \
    $$PWD/tonqtquick.h

SOURCES += \
    $$PWD/tonqtquick.cpp

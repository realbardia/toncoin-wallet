QT += quick widgets

INCLUDEPATH += $$PWD

include (core/core.pri)
include (thirdparty/thirdparty.pri)
include (qml/qml.pri)

SOURCES += \
    $$PWD/main.cpp
 

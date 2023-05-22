INCLUDEPATH += $$PWD

VERSION = 1.0.1

include (core/core.pri)
include (thirdparty/thirdparty.pri)
include (qtquick/qtquick.pri)
include (widgets/widgets.pri)
include (common/common.pri)

SOURCES += \
    $$PWD/main.cpp
 

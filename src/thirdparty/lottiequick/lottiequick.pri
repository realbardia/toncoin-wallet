INCLUDEPATH += \
    $$PWD \
    $$PWD/lottiequick/lib/

HEADERS += \
    $$PWD/lottieanimation.h \
    $$PWD/lottiequick/lib/lottiequickglobal.h \
    $$PWD/lottierenderthread.h \
    $$PWD/lottiequick/lib/qtcompat.h

SOURCES += \
    $$PWD/lottierenderthread.cpp \
    $$PWD/lottiequickanimation.cpp \
    $$PWD/vdrawhelper_neon.cpp

DEFINES += \
    RLOTTIE_BUILD \
    LOTTIE_QUICK_BUILD_LIBRARY

include(rlottie.pri)

INCLUDEPATH += \
    $$PWD \
    $$PWD/lottiequick/lib/

HEADERS += \
    $$PWD/lottiequick/lib/lottieanimation.h \
    $$PWD/lottiequick/lib/lottiequickglobal.h \
    $$PWD/lottiequick/lib/lottierenderthread.h \
    $$PWD/lottiequick/lib/qtcompat.h

SOURCES += \
    $$PWD/lottiequick/lib/lottierenderthread.cpp \
    $$PWD/lottiequickanimation.cpp \
    $$PWD/vdrawhelper_neon.cpp

include(rlottie.pri)

LIBS += -lrlottie
INCLUDEPATH +=  $$PWD

HEADERS += \
    $$PWD/lottiequick/lib/lottieanimation.h \
    $$PWD/lottiequick/lib/lottiequickglobal.h \
    $$PWD/lottiequick/lib/lottierenderthread.h \
    $$PWD/lottiequick/lib/qtcompat.h

SOURCES += \
    $$PWD/lottiequick/lib/lottieanimation.cpp \
    $$PWD/lottiequick/lib/lottierenderthread.cpp

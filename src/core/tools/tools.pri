win32 {
    isEmpty(ZLIB_PATH): !android: ZLIB_PATH = /usr
    exists($$ZLIB_PATH/include/zlib.h) {
        message(Zlib found on $$ZLIB_PATH)
    } else {
        ZLIB_PATH = $$getenv(ZLIB_PATH)
        exists($$ZLIB_PATH/include/zlib.h) {
            message(Zlib found on $$ZLIB_PATH)
        } else {
            error(Could not find Zlib directory. Please set it using ZLIB_PATH argument)
        }
    }
    LIBS += -L$$ZLIB_PATH/lib -lz
    INCLUDEPATH += \
        $$ZLIB_PATH/include
} else {
    LIBS += -lz
}

HEADERS += \
    $$PWD/crypto.h \
    $$PWD/ziptools.h

SOURCES += \
    $$PWD/crypto.cpp \
    $$PWD/ziptools.cpp

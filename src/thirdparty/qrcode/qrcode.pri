INCLUDEPATH += \
    $$PWD \
    $$PWD/qr-code-generator/cpp/ \
    $$PWD/lib_qr/

HEADERS += \
    $$PWD/qr-code-generator/cpp/qrcodegen.hpp \
    $$PWD/lib_qr/qr/qr_generate.h

SOURCES += \
    $$PWD/qr-code-generator/cpp/qrcodegen.cpp \
    $$PWD/lib_qr/qr/qr_generate.cpp


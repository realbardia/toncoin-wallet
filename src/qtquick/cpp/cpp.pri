QT += qml \
    quick

include (toolkit/toolkit.pri)
include (wallets/wallets.pri)

HEADERS += \
    $$PWD/tonqtquick.h

SOURCES += \
    $$PWD/tonqtquick.cpp

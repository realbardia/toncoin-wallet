isEmpty(TON_LIB_PATH): TON_LIB_PATH = /opt/develop/ton/

exists($$TON_LIB_PATH/include/tonlib/Client.h) {
    message(TON libs found on $$TON_LIB_PATH)
} else {
    error(Could not find TON lib directory. Please set it using TON_LIB_PATH argument)
}

isEmpty(TON_SOURCE_PATH): TON_SOURCE_PATH = /home/bardia/Programs/Sources/ton

exists($$TON_SOURCE_PATH/crypto/common/bitstring.h) {
    message(TON source directory found on $$TON_SOURCE_PATH)
} else {
    error(Could not find TON source directory. Please set it using TON_SOURCE_PATH argument. You can clone it from https://github.com/ton-blockchain/ton git repository)
}

INCLUDEPATH += \
    $$TON_LIB_PATH/include/ \
    $$TON_LIB_PATH/include/crypto \
    $$TON_SOURCE_PATH \
    $$TON_SOURCE_PATH/crypto \
    $$TON_SOURCE_PATH/tdutils

LIBS += -L$$TON_LIB_PATH/lib/ \
    -ltonlib \
    -ladnllite \
    -lkeys \
    -ltdactor \
    -ltdutils \
    -lcrc32c \
    -lemulator_static \
    -lsmc-envelope \
    -ltl_api \
    -ltl_tonlib_api \
    -ltl-utils \
    -ltl_lite_api \
    -ltl-lite-utils \
    -llite-client-common \
    -lton_block \
    -lton_crypto

LIBS += -lssl -lcrypto

SOURCES += \
    $$PWD/abstractwallet.cpp \
    $$PWD/abstractwalletinitializer.cpp \
    $$PWD/tonwallet.cpp

HEADERS += \
    $$PWD/abstractwallet.h \
    $$PWD/abstractwalletinitializer.h \
    $$PWD/tonwallet.h
 

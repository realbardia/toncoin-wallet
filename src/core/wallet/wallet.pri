isEmpty(TON_LIB_PATH): !android: TON_LIB_PATH = /opt/develop/ton/
exists($$TON_LIB_PATH/include/tonlib/Client.h) {
    message(TON libs found on $$TON_LIB_PATH)
} else {
    TON_LIB_PATH = $$getenv(TON_LIB_PATH)
    exists($$TON_LIB_PATH/include/tonlib/Client.h) {
        message(TON libs found on $$TON_LIB_PATH)
    } else {
        error(Could not find TON lib directory. Please set it using TON_LIB_PATH argument)
    }
}

isEmpty(TON_SOURCE_PATH): TON_SOURCE_PATH = /home/bardia/Programs/Sources/ton
exists($$TON_SOURCE_PATH/crypto/common/bitstring.h) {
    message(TON source directory found on $$TON_SOURCE_PATH)
} else {
    TON_SOURCE_PATH = $$getenv(TON_SOURCE_PATH)
    exists($$TON_SOURCE_PATH/crypto/common/bitstring.h) {
        message(TON source directory found on $$TON_SOURCE_PATH)
    } else {
        error(Could not find TON source directory. Please set it using TON_SOURCE_PATH argument. You can clone it from https://github.com/ton-blockchain/ton git repository)
    }
}

linux: !android {
    isEmpty(OPENSSL_LIB_PATH): OPENSSL_LIB_PATH = /usr
} else {
    isEmpty(OPENSSL_LIB_PATH): OPENSSL_LIB_PATH = $$[QT_INSTALL_DATA]
}
isEmpty(OPENSSL_LIB_PATH): OPENSSL_LIB_PATH = $$OPENSS_LIB_PATH
exists($$OPENSSL_LIB_PATH/include/openssl/conf.h) {
    message(OpenSSL libs found on $$OPENSSL_LIB_PATH)
} else {
    OPENSSL_LIB_PATH = $$getenv(OPENSSL_LIB_PATH)
    exists($$OPENSSL_LIB_PATH/include/openssl/conf.h) {
        message(OpenSSL libs found on $$OPENSSL_LIB_PATH)
    } else {
        error(Could not find OpenSSL lib directory. Please set it using OPENSSL_LIB_PATH argument)
    }
}

isEmpty(KEYS_DB_FILE_AES_PASS) {
    KEYS_DB_FILE_AES_PASS = $$getenv(KEYS_DB_FILE_AES_PASS)
    isEmpty(KEYS_DB_FILE_AES_PASS) {
        KEYS_DB_FILE_AES_PASS = YWQ4NjdhYTJlOTcxODFmNmNi
        warning(You use default password to encrypt and store keys. Its better to set your own and secure key using KEYS_DB_FILE_AES_PASS argument.)
    }
}
isEmpty(KEYS_DB_SECRET_AES_SALT) {
    KEYS_DB_SECRET_AES_SALT = $$getenv(KEYS_DB_SECRET_AES_SALT)
    isEmpty(KEYS_DB_SECRET_AES_SALT) {
        KEYS_DB_SECRET_AES_SALT = GVhOGI4MGQ1ZTU4Nzc2MmFkZ
        warning(You use default password to encrypt every single key. Its better to set your own and secure key using KEYS_DB_SECRET_AES_SALT argument.)
    }
}

DEFINES += KEYS_DB_FILE_AES_PASS=\\\"$$KEYS_DB_FILE_AES_PASS\\\"
DEFINES += KEYS_DB_SECRET_AES_SALT=\\\"$$KEYS_DB_SECRET_AES_SALT\\\"

INCLUDEPATH += \
    $$TON_LIB_PATH/include/ \
    $$TON_LIB_PATH/include/crypto \
    $$TON_SOURCE_PATH \
    $$TON_SOURCE_PATH/tdactor \
    $$TON_SOURCE_PATH/crypto \
    $$TON_SOURCE_PATH/tddb \
    $$TON_SOURCE_PATH/tdutils \
    $$OPENSSL_LIB_PATH/include

message($$TON_LIB_PATH/lib/)
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

win32-msvc* {
    LIBS += -L$$[QT_INSTALL_LIBS] -L$$OPENSSL_LIB_PATH/lib -llibssl -llibcrypto
} else {
    LIBS += -L$$[QT_INSTALL_LIBS] -L$$OPENSSL_LIB_PATH/lib -lssl -lcrypto
}

win32 {
    LIBS += -lws2_32 -lpsapi
    win32-msvc*: LIBS += -lnormaliz
}

SOURCES += \
    $$PWD/abstractwalletbackend.cpp \
    $$PWD/backendmanager.cpp \
    $$PWD/tonlibbackend.cpp

HEADERS += \
    $$PWD/abstractwalletbackend.h \
    $$PWD/backendmanager.h \
    $$PWD/tonlibbackend.h
 

RESOURCES += \
    $$PWD/wallet.qrc

QT += core network
CONFIG += c++17

DEFINES += \
    VERSION_STR=\\\"$$VERSION\\\"

include(tools/tools.pri)
include(wallet/wallet.pri)
 

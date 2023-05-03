QT += qml \
    quick

include (qtsingleapplication/qtsingleapplication.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/materialicons.h \
    $$PWD/tontoolkit_macros.h \
    $$PWD/tontoolkitabstractlistmodel.h \
    $$PWD/tontoolkitapplication.h \
    $$PWD/tontoolkitapplicationitem.h \
    $$PWD/tontoolkitapplicationsingleton.h \
    $$PWD/tontoolkitbackhandler.h \
    $$PWD/tontoolkitdevices.h \
    $$PWD/tontoolkitdevicesitem.h \
    $$PWD/tontoolkitgui_global.h \
    $$PWD/tontoolkitlistmodel.h \
    $$PWD/tontoolkitlistobject.h \
    $$PWD/tontoolkitmapobject.h \
    $$PWD/tontoolkitquickobject.h \
    $$PWD/tontoolkitquickview.h \
    $$PWD/tontoolkitquickviewwrapper.h \
    $$PWD/tontoolkitsettings.h \
    $$PWD/tontoolkittools.h \
    $$PWD/tontoolkittoolsitem.h \
    $$PWD/tontoolkittranslationmanager.h \
    $$PWD/qmlwidgetmenu.h \
    $$PWD/qmlwidgetmenuitem.h \
    $$PWD/tgstickeritem.h

SOURCES += \
    $$PWD/materialicons.cpp \
    $$PWD/tontoolkitabstractlistmodel.cpp \
    $$PWD/tontoolkitapplication.cpp \
    $$PWD/tontoolkitapplicationitem.cpp \
    $$PWD/tontoolkitapplicationsingleton.cpp \
    $$PWD/tontoolkitbackhandler.cpp \
    $$PWD/tontoolkitdevices.cpp \
    $$PWD/tontoolkitdevicesitem.cpp \
    $$PWD/tontoolkitlistmodel.cpp \
    $$PWD/tontoolkitlistobject.cpp \
    $$PWD/tontoolkitmapobject.cpp \
    $$PWD/tontoolkitquickobject.cpp \
    $$PWD/tontoolkitquickview.cpp \
    $$PWD/tontoolkitquickviewwrapper.cpp \
    $$PWD/tontoolkitsettings.cpp \
    $$PWD/tontoolkittools.cpp \
    $$PWD/tontoolkittoolsitem.cpp \
    $$PWD/tontoolkittranslationmanager.cpp \
    $$PWD/qmlwidgetmenu.cpp \
    $$PWD/qmlwidgetmenuitem.cpp \
    $$PWD/tgstickeritem.cpp

android {
    HEADERS += \
        $$PWD/tontoolkitjavalayer.h
    SOURCES += \
        $$PWD/tontoolkitjavalayer.cpp
}
ios {
    HEADERS += \
        $$PWD/tontoolkitobjectiveclayer.h
    SOURCES += \
        $$PWD/tontoolkitobjectiveclayer.mm
}
macx {
    HEADERS += \
        $$PWD/tontoolkitmacmanager.h
    SOURCES += \
        $$PWD/tontoolkitmacmanager.mm
}

RESOURCES += \
    $$PWD/toolkit.qrc


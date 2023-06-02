QT += qml \
    quick

include (qtsingleapplication/qtsingleapplication.pri)

CONFIG += unicode

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/materialicons.h \
    $$PWD/aseman_macros.h \
    $$PWD/asemanabstractlistmodel.h \
    $$PWD/asemanapplication.h \
    $$PWD/asemanapplicationitem.h \
    $$PWD/asemanapplicationsingleton.h \
    $$PWD/asemanbackhandler.h \
    $$PWD/asemandevices.h \
    $$PWD/asemandevicesitem.h \
    $$PWD/asemankeyhandler.h \
    $$PWD/asemanlistmodel.h \
    $$PWD/asemanlistobject.h \
    $$PWD/asemanmapobject.h \
    $$PWD/asemanqrcreator.h \
    $$PWD/asemanquicklistmodel.h \
    $$PWD/asemanquickobject.h \
    $$PWD/asemanquickview.h \
    $$PWD/asemanquickviewwrapper.h \
    $$PWD/asemanrefresherobject.h \
    $$PWD/asemansettings.h \
    $$PWD/asemanstickeritem.h \
    $$PWD/asemantools.h \
    $$PWD/asemantoolsitem.h \
    $$PWD/asemantranslationmanager.h

SOURCES += \
    $$PWD/materialicons.cpp \
    $$PWD/asemanabstractlistmodel.cpp \
    $$PWD/asemanapplication.cpp \
    $$PWD/asemanapplicationitem.cpp \
    $$PWD/asemanapplicationsingleton.cpp \
    $$PWD/asemanbackhandler.cpp \
    $$PWD/asemandevices.cpp \
    $$PWD/asemandevicesitem.cpp \
    $$PWD/asemankeyhandler.cpp \
    $$PWD/asemanlistmodel.cpp \
    $$PWD/asemanlistobject.cpp \
    $$PWD/asemanmapobject.cpp \
    $$PWD/asemanqrcreator.cpp \
    $$PWD/asemanquicklistmodel.cpp \
    $$PWD/asemanquickobject.cpp \
    $$PWD/asemanquickview.cpp \
    $$PWD/asemanquickviewwrapper.cpp \
    $$PWD/asemanrefresherobject.cpp \
    $$PWD/asemansettings.cpp \
    $$PWD/asemanstickeritem.cpp \
    $$PWD/asemantools.cpp \
    $$PWD/asemantoolsitem.cpp \
    $$PWD/asemantranslationmanager.cpp

android {
    lessThan(QT_MAJOR_VERSION, 5) QT += androidextras
    HEADERS += \
        $$PWD/asemanjavalayer.h
    SOURCES += \
        $$PWD/asemanjavalayer.cpp
}
ios {
    include(private/quickios/quickios.pri)
    HEADERS += \
        $$PWD/asemanobjectiveclayer.h
    SOURCES += \
        $$PWD/asemanobjectiveclayer.mm

    LIBS += -lobjc
    LIBS += -framework LocalAuthentication
}
macx {
    HEADERS += \
        $$PWD/asemanmacmanager.h
    SOURCES += \
        $$PWD/asemanmacmanager.mm

    LIBS += -framework LocalAuthentication
}

RESOURCES += \
    $$PWD/core.qrc


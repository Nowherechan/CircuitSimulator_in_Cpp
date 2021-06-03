QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analog-gate/baseelement.cpp \
    analog-gate/currentsource.cpp \
    analog-gate/resistance.cpp \
    analog-gate/switchclose.cpp \
    analog-gate/switchopen.cpp \
    analog-gate/voltagesource.cpp \
    animation_btn.cpp \
    circuitmap.cpp \
    circuitwindow.cpp \
    logical-gate/andlogicgate.cpp \
    logical-gate/andornotlogicgate.cpp \
    logical-gate/baselogicgate.cpp \
    logical-gate/highlevel.cpp \
    logical-gate/nandlogicgate.cpp \
    logical-gate/nonlogicgate.cpp \
    logical-gate/norlogicgate.cpp \
    logical-gate/orlogicgate.cpp \
    logical-gate/xnorlogicgate.cpp \
    logical-gate/xorlogicgate.cpp \
    main.cpp \
    pin-to-node/G_Wire.cpp \
    pin-to-node/Graph.cpp \
    pin-to-node/Matrix.cpp \
    qgraphicsview_map.cpp \
    startwindow.cpp \
    wire.cpp

HEADERS += \
    analog-gate/baseelement.h \
    analog-gate/currentsource.h \
    analog-gate/resistance.h \
    analog-gate/switchclose.h \
    analog-gate/switchopen.h \
    analog-gate/voltagesource.h \
    animation_btn.h \
    circuitmap.h \
    circuitwindow.h \
    logical-gate/andlogicgate.h \
    logical-gate/andornotlogicgate.h \
    logical-gate/baselogicgate.h \
    logical-gate/highlevel.h \
    logical-gate/nandlogicgate.h \
    logical-gate/nonlogicgate.h \
    logical-gate/norlogicgate.h \
    logical-gate/orlogicgate.h \
    logical-gate/xnorlogicgate.h \
    logical-gate/xorlogicgate.h \
    pin-to-node/G_Wire.h \
    pin-to-node/Graph.h \
    pin-to-node/Matrix.h \
    pin-to-node/pch.h \
    qgraphicsview_map.h \
    startwindow.h \
    wire.h

FORMS += \
    circuitmap.ui \
    circuitwindow.ui \
    qgraphicsview_map.ui \
    startwindow.ui

TRANSLATIONS += \
    CircuitSimulator_in_Cpp_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc

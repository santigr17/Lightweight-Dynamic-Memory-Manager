TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += thread

SOURCES += \
    vRef.cpp \
    vHeap.cpp \
    vGarbageCollector.cpp \
    Main.cpp \
    DataManager.cpp \
    crazythread.cpp \
    DataInfo.cpp \
    vint.cpp \
    binaryfiles.cpp \
    vThread.cpp \
    vlong.cpp \
    vfloat.cpp \
    vchar.cpp

OTHER_FILES += \
    LightWeight-Dynamic-Memory-Manager.pro.user \
    vGarbageCollector.txt

HEADERS += \
    vRef.h \
    vHeap.h \
    vGarbageCollector.h \
    nodo.h \
    lista_enlazada.h \
    DataManager.h \
    DataInfo.h \
    crazythread.h \
    vobject.h \
    vint.h \
    binaryfiles.h \
    vThread.h \
    vlong.h \
    vfloat.h \
    vchar.h


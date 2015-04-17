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
    vObject.cpp \
    vreflist.cpp \
    docXML.cpp \
    pugixml.cpp \
    socketcliente.cpp \
    vchar.cpp \
    vlong.cpp \
    MainHeap.cpp

OTHER_FILES += \
    LightWeight-Dynamic-Memory-Manager.pro.user \
    vGarbageCollector.txt \
    vheap.xml

HEADERS += \
    vRef.h \
    vHeap.h \
    vGarbageCollector.h \
    nodo.h \
    lista_enlazada.h \
    DataManager.h \
    DataInfo.h \
    crazythread.h \
    vint.h \
    binaryfiles.h \
    vThread.h \
    vObject.h \
    vreflist.h \
    docXML.h \
    pugiconfig.hpp \
    pugixml.hpp \
    socketcliente.h \
    vchar.h \
    vlong.h \
    MainHeap.h


#ifndef VGARBAGECOLLECTOR_H_
#define VGARBAGECOLLECTOR_H_
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <DataInfo.h>
#include <vThread.h>
#include <lista_enlazada.h>
#include <nodo.h>
#include <vRef.h>

class vGarbageCollector {
private:
    int _gcFrecuency;
    vThread *gcThread;
public:
    vGarbageCollector(int);
    void avoidMemoryLeak(lista_enlazada<DataInfo>*,lista_enlazada<vRef>*);
};

#endif

#ifndef VGARBAGECOLLECTOR_H_
#define VGARBAGECOLLECTOR_H_

#include <iostream>
#include "nodo.h"
#include "vRef.h"
#include "vHeap.h"
#include "DataManager.h"
#include "vThread.h"
#include "lista_enlazada.h"
#include "docXML.h"


using namespace std;

class vGarbageCollector {
private:
    unsigned int _gcFrecuency;
    docXML* _xml;
    //vThread* _gcThread;
public:
    vGarbageCollector(docXML *);
    void avoidMemoryLeak();
};

#endif

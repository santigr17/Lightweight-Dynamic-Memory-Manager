#ifndef VGARBAGECOLLECTOR_H_
#define VGARBAGECOLLECTOR_H_

#include <DataInfo.h>
#include <vThread.h>
#include <lista_enlazada.h>
#include <nodo.h>
#include <vRef.h>
#include "vHeap.h"

class vGarbageCollector {
private:
	unsigned int _gcFrecuency;
public:
	vGarbageCollector(int);
	void avoidMemoryLeak(lista_enlazada<DataInfo>*);
};

#endif

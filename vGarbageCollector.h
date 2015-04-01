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
	vHeap* _heap;
public:
	vGarbageCollector(int, vHeap&);
	void avoidMemoryLeak(lista_enlazada<DataInfo>*);
};

#endif

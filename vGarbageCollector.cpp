#include <vGarbageCollector.h>

vGarbageCollector::vGarbageCollector(int pFrecuency)
{
	_gcFrecuency = pFrecuency;
}

void vGarbageCollector::avoidMemoryLeak(lista_enlazada<DataInfo>* pMetadata)
{
//	vThread* gcThread = new vThread((void *)vGarbageCollector::avoidMemoryLeak(pMetadata),nullptr);
    //gcThread->run();

	Nodo<DataInfo>* tmpMetadata = pMetadata->getHead();

	for (int i = 0; i<pMetadata->length(); i++)
	{
		if (tmpMetadata->getData().getReferenceCounter() == 0)
		{
			vHeap* _heap = vHeap::getInstace();
			_heap->vFree(tmpMetadata->getData().getID());
		}
		tmpMetadata = tmpMetadata->getNext();
	}
    //usleep(_gcFrecuency);
}


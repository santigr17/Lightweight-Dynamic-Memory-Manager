#include <vGarbageCollector.h>

vGarbageCollector::vGarbageCollector(int pFrecuency, vHeap& pHeap)
{
	this->_gcFrecuency = pFrecuency;
	this->_heap = pHeap;
}

void vGarbageCollector::avoidMemoryLeak(lista_enlazada<DataInfo>* pMetadata)
{
	vThread* gcThread = new vThread((void *)vGarbageCollector::avoidMemoryLeak(pMetadata),nullptr);
	gcThread->run();

	Nodo<DataInfo>* tmpMetadata = pMetadata->getHead();

	for (int i = 0; i<pMetadata->length(); i++)
	{
		if (tmpMetadata->getData().getReferenceCounter() == 0)
		{
			_heap->vFree(tmpMetadata->getData().getID());
		}
		tmpMetadata = tmpMetadata->getNext();
	}
	usleep(_gcFrecuency);
}


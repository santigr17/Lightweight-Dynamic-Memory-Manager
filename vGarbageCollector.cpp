#include <vGarbageCollector.h>

/*vGarbageCollector::vGarbageCollector(int pFrecuency)
{
	_gcFrecuency = pFrecuency;
    gcThread = new vThread();
}

void vGarbageCollector::avoidMemoryLeak(lista_enlazada<DataInfo>* pMetadatos,lista_enlazada<vRef>* pListData)
{
	gcThread->vThread((void *)vGarbageCollector::avoidMemoryLeak(pMetadatos,pListData),nullptr);
	gcThread->run();

	Nodo<DataInfo>* tmpMetadatos = pMetadatos->getHead();
	Nodo<vRef>* tmpListData = pListData->getHead();

	for (int i = 0; i<pMetadatos->length(); i++)
	{
		if (tmpMetadatos->getData().getReferenceCounter() == 0)
		{
			for (int j = 0; j<pListData->length(); j++)
			{
				//Cuando coincida el ID del metadato y el vRef, se libera de memoria.
				if((tmpMetadatos->getData().getID()) == (tmpListData->getData().getId()))
				{
					void free((void*) tmpListData->getData().getReferencePointer()); //getRef o algo asi (el dato a eliminar)

				}
				tmpListData = tmpListData->getNext();
			}
		}
		tmpMetadatos = tmpMetadatos->getNext();
	}
	usleep(_gcFrecuency);
}
*/

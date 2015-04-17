#include "vGarbageCollector.h"
/*!
 * \brief vGarbageCollector::vGarbageCollector
 * \param pXML
 */
vGarbageCollector::vGarbageCollector(docXML* pXML)
{ 
    _xml = pXML;
    _gcFrecuency = _xml->getGCFrecuency();
    //_gcThread = new vThread((void *)avoidMemoryLeak(),nullptr);
}
/*!
 * \brief vGarbageCollector::avoidMemoryLeak
 */
void vGarbageCollector::avoidMemoryLeak()
{
    cout << "avoid memory leak - garbage collector" << endl;
   // _gcThread->run();

    DataManager* _manage = DataManager::getInstace();
    vHeap* _heap = vHeap::getInstace();

    Nodo<DataInfo>* tmpMetadata = _manage->getMetaDatosList()->getHead();
    Nodo<vRef>* tmpvRefList = _heap->getvRefList()->getHead();

    for (int i = 0; i < _manage->getMetaDatosList()->length(); i++)
    {
        if (tmpMetadata->getData().getReferenceCounter() == 0)
        {
            for (int j = 0; j < _heap->getvRefList()->length(); j++)
            {
                if (tmpMetadata->getData().getID() == tmpvRefList->getData().getObjectID())
                {
                    if (_xml->getvDebug())
                    {
                        cout << "ID del vRef a eliminar: " << tmpvRefList->getData().getObjectID() << endl;
                        cout << "counter: " << tmpMetadata->getData().getReferenceCounter() << endl;
                    }

                    _heap->vFree(tmpvRefList->getData());

                    if (_xml->getvDebug())
                    {
                        cout << "ID del vRef a eliminar: " << tmpMetadata->getData().getSize() << endl;
                        cout << "counter: " << tmpMetadata->getData().getOffset() << endl;
                    }
                }
                tmpvRefList = tmpvRefList->getNext();
            }
        }
        tmpMetadata = tmpMetadata->getNext();
    }
   // usleep(_gcFrecuency);
}

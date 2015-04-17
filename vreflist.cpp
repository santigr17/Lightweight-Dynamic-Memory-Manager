#include "vreflist.h"


/**
 * @brief vRefList::vRefList
 */
vRefList::vRefList()
{
_vRefList = new lista_enlazada<vRef>();
}
/**
 * @brief vRefList::getVrefList
 * @return
 */
lista_enlazada<vRef> *vRefList::getVrefList()
{
    return this->_vRefList;
}
/**
 * @brief vRefList::findDato
 * @param pID
 * @return
 */
vRef vRefList::findDato(int pID)
{
    Nodo<vRef>* tmp = _vRefList->getHead();

    for(int i=0;i<_vRefList->length();i++)
    {
        if (tmp->getData().getObjectID() == pID)
        {
            break;
        }
        tmp = tmp->getNext();
    }
    return tmp->getData();
}
/**
 * @brief vRefList::addDato
 * @param pDato
 */
void vRefList::addDato(vRef pDato)
{
    cout << "caaaa" << endl;
    _vRefList->add_Dato_Atras(pDato);


}

#ifndef VREFLIST_H
#define VREFLIST_H

#include "vRef.h"
#include "lista_enlazada.h"
#include "nodo.h"

class vRefList
{
private:
    lista_enlazada<vRef>* _vRefList;
public:
    vRefList();
    ~vRefList();
    lista_enlazada<vRef> *getVrefList();
    vRef findDato(int pID);
    void addDato(vRef pDato);
};

#endif // VREFLIST_H

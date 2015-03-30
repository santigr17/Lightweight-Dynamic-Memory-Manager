/*
 * vRef.h
 *
 *  Created on: Mar 19, 2015
 *      Author: santii
 */

#ifndef VREF_H_
#define VREF_H_
#include "vHeap.h"

class vRef {
protected:
    int ID;
    vHeap *heap;
public:
    vRef(int id);
    virtual ~vRef();
    //Sets & gets
    void setId(int id);
    int getId();
    //Sobrecarga de operadores
    void *operator =(void* a);
    void *operator *(void* a);
    void *operator ==(void* a);
    void *operator --();
    void *operator ++();

};

#endif /* VREF_H_ */

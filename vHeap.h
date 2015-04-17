/*
 * vHeaps.h
 *
 *  Created on: Mar 18, 2015
 *      Author: David Monestel
 */
#ifndef VHEAP_H_
#define VHEAP_H_
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include "vRef.h"
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include "DataManager.h"
#include "binaryfiles.h"
#include "vreflist.h"
#include "vGarbageCollector.h"
#include "docXML.h"
#include <fstream>
#include <iostream>


using namespace std;

#define Int 0
#define String 1
#define Char 2
#define Array 3
#define TamanoHeap 100
#define pesoOverweight 10


class vHeap {
public:
	~vHeap();
    vRef *vMalloc(size_t pSize, string pType); // debe de devolver un vRef
    void vFree(vRef needToFree);
	static vHeap* getInstace();
    DataManager* _dataManager;
    void needThis();
    lista_enlazada<vRef> *getvRefList();

    void makePagination(vRef pDato);

    int getOffset();
    int getTotalSize();


private:
    int _Overweight;
    int _vRefID=0;
    int _offSet=0;
    int _heapTOTALsize;
    int _dumpFrecuency;
    //vThread* _frecuencyThread;
    //vGarbageCollector* _GC;

    vObject* _Size;
    vObject* begin_Size;
    BinaryFiles* _binFILE;
    vHeap(int pSize , int pOverweight);
	static bool instanceFlag;
	static vHeap * memoryManager;
    static docXML* XML;
    vRef readFromPagination(int pID);
    void freeSpace();
    void reArrangeData();
    vRef findVRef(int pID);


    ofstream out;



     lista_enlazada<vRef>* _vRefList;



};

#endif /* VHEAP_H_ */


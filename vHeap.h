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

using namespace std;

#define Int 0
#define String 1
#define Char 2
#define Array 3
#define TamanoHeap 400


class vHeap 	{
public:

	~vHeap();
    vRef *vMalloc(size_t pSize, string pType); // debe de devolver un vRef
    void vFree(int needToFree);
	void expandVHeap();
	static vHeap* getInstace();
    DataManager* _dataManager;



private:
    int _vRefID=0;
    int _offSet=0;
    int* _Size;
    BinaryFiles* _binFILE;
    static int _Overweight;
    vHeap(int pSize , int pOverweight);
	static bool instanceFlag;
	static vHeap * memoryManager;
    void makePagination(vRef pDato);
    vRef readFromPagination(int pID);
    void freeSpace();
    void reArrangeData();




};

#endif /* VHEAP_H_ */


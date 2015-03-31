/*
 * Main.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */
#include "vHeap.h"
#include "vint.h"
#include "iostream"

using namespace std;

int main(){

    vHeap *heap;

    heap = vHeap::getInstace();
    heap->vMalloc(100,"int");
    heap->vMalloc(200, "char");
    heap->vMalloc(100,"int");
    heap->vMalloc(30, "int");


    vInt vint = 2;
    vInt vint2 = vint;

    cout << vint2.getVData()<<endl;

	return 0;
};



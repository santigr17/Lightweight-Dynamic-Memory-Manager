/*
 * Main.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */
#include "vHeap.h"
#include "vint.h"
#include "vlong.h"
#include "vfloat.h"
#include "vchar.h"
#include "iostream"

using namespace std;

int main(){

  /*  vHeap *heap;

    heap = vHeap::getInstace();
    heap->vMalloc(100,"int");
    heap->vMalloc(200, "char");
    heap->vMalloc(100,"int");
    heap->vMalloc(110, "int");*/

    const char *hola = "hola";
    vChar vchar = "a";
    cout << hola << endl;

    float a = 123.123;
    cout << a << endl;



	return 0;
};



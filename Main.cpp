/*
 * Main.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: david
 */
#include "vHeap.h"
#include "vint.h"
#include "iostream"
#include "docXML.h"
#include "vchar.h"
#include "pthread.h"
#include "vThread.h"
using namespace std;

void* runn(void * obj){
    pthread_mutex_t    mutex= PTHREAD_MUTEX_INITIALIZER;


    while(true){
        pthread_mutex_lock(&mutex);

        std::cout << "hola2" << endl;
        pthread_mutex_unlock(&mutex);
        sleep(1);

    }

}


int main(){
    DataManager* d = DataManager::getInstace();

    vHeap *heap = vHeap::getInstace();

    //vRef* primerObjeto;
    vObject* segundoObjeto;
    vObject* tercerObjeto;


    vInt primerObjeto = heap->vMalloc(100,"int");

    segundoObjeto = heap->vMalloc(96, "char");
    tercerObjeto = heap->vMalloc(200, "int");

    heap->vFree(primerObjeto);








    vThread *p = new vThread((void*)d->dumpFrecuency,nullptr);
    p->run();

    while (true)
    {

    }






   /* docXML* doc = new docXML();
    cout << "size: "<< doc->getSize() << endl;
    cout << "gcfrec: "<< doc->getGCFrecuency() << endl;
    cout << "overw: "<< doc->getOverweight() << endl;
    cout << "vdebug: "<< doc->getvDebug() << endl;
    cout << "vdebugfilepath: "<< doc->getvDebugFilePath() << endl;
    doc->setvDebugFilePath(doc->getvDebugFilePath()+2);
    cout << "vdebugfilepath: "<< doc->getvDebugFilePath() << endl;



    vHeap *heap;


    heap = vHeap::getInstace();



    vRef* primerObjeto;
    vObject* segundoObjeto;
    vObject* tercerObjeto;


    primerObjeto = heap->vMalloc(100,"int");

    segundoObjeto = heap->vMalloc(30, "char");
    tercerObjeto = heap->vMalloc(200, "int");


    heap->makePagination(*primerObjeto);
    primerObjeto[3] = 23;

    cout << "primerObjeto holaaaa: " << primerObjeto << endl;
    cout << "datoContenido en PrimerObjeto: "<< (primerObjeto+3)->getObjectData() << endl;*/






    //vInt vchar = (void*)1;


   // cout <<"El dato del objeto " << vchar.getObjectData() <<endl;


    /*vRef* d = new vRef(123);
    cout<< "d1: " << d << endl;
    vObject* s = (vObject*)malloc(15);
    s[4] = 222;
    vObject* q =s;
    q[3]= 323;

    vObject* k = d ;
    k = q;


    cout<< "q: " << q <<endl;
    cout<< "qDato: " << (q+3)->getData() << endl;
    cout<< "s: " << s  << endl;
    cout<< "k=q donde notese que k = d: " << k << endl;
    cout<< "dDato: " << (k+3)->getData() << endl;*/


    return 0;
}



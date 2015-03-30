/*
 * vHeap.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: David Monestel
 */

#include "vHeap.h"

bool vHeap::instanceFlag = false; // Variable static para hacer la clase singleton
vHeap* vHeap::memoryManager = NULL; // Inicializar el vHeap static

int vHeap:: _Overweight= 0; // Variable static Tamaño del archivo para paginacion

/**
 * @brief vHeap::vMalloc
 * @param pSize El tamaño que el usuario quiere para utilizar de la memoria
 * @param pType El tipo de dato que el usuario almacenara
 * @return un vRef que apuntara al pedazo de memoria que el usuario solicito
 */
vRef* vHeap::vMalloc(size_t pSize, string pType)
{
    if(_offSet > 400)
    {
       // expandVHeap();
    }

    _Size += _offSet;

   if(pType=="int")
   {
       _dataManager->insertNewObject(Int,_vRefID,_offSet);
       _offSet+=sizeof(int);
   }
   if(pType=="string")
   {
       _dataManager->insertNewObject(String,_vRefID,_offSet);
       _offSet+=sizeof(string);
   }
   if(pType=="char")
   {
       _dataManager->insertNewObject(Char,_vRefID,_offSet);
       _offSet+=sizeof(char);
   }
   if(pType=="array")
   {
       _dataManager->insertNewObject(Array,_vRefID,_offSet);
       _offSet+=sizeof(Array); // Establecer el tamaño del array
   }
   cout << "offset:" << _offSet <<endl;

   vRef* memoryReference = new vRef(_vRefID);
   _vRefID++;

   cout << "size: " << _Size-(_offSet)<<endl;

   return memoryReference;
}

void vHeap::vFree(int needToFree)
{
    //needToFree.getID;
    _dataManager->deleteData(needToFree);
}

void vHeap::makePagination(vRef pDato)
{
    _binFILE->writeToAFile(pDato);
    this->vFree(pDato.getId());
    //hacer reacomodo del HEAP!
}

vRef vHeap::readFromPagination(int pID)
{
    vRef tmpVRef = _binFILE->readFromFile(pID);// sobrecargar igual del vref para que apunte a lo que se le iguala
    //vRef.s // establecer a este vref el id
    return tmpVRef;
}






/**
 * @brief vHeap::vHeap
 * @param pSize El tamaño de la memoria virtualvoid
 * @param pOverWeight El tamaño del archivo que se utilizara para la paginacion
 */

vHeap::vHeap(int pSize, int pOverWeight)
{
    _binFILE = new BinaryFiles(); //le debe de entrar el overweight para la paginacion;
    _Size  = ( int* ) calloc(1,pSize);

    cout << _Size << endl;

    if (_Size == 0)
	{
		printf("ERROR: Out of memory\n");
	}

    /*for(int i= 0; i<400;i++)
        _Size[i] = 0;
    cout << _Size[400] << endl;*/

    _dataManager = DataManager::getInstace();
}

/**
 * @brief vHeap::~vHeap
 * Al terminar vuelve a habilitar la instancia de la clase
 */
vHeap::~vHeap() { free(memoryManager); instanceFlag = false; }

vHeap* vHeap::getInstace()
{
	if(! instanceFlag)
	    {
        /*
         * ARREGLAR EL SIZEEEE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         */
            memoryManager = new vHeap(400,_Overweight);// 400 = Size ARREGLARLO!.
	        instanceFlag = true;
	        return memoryManager;
	    }
    else
    {
        return memoryManager;
    }
}

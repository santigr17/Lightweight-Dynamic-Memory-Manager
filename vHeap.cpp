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
    if(_offSet+pSize > TamanoHeap && _offSet+pSize > 500)
    {
       cout << "No hay suficiente espacio en el vheap"<< endl;
       exit(1);
    }

    if (_offSet+pSize > TamanoHeap)
    {
        freeSpace();
    }

     vRef* memoryReference = new vRef(_vRefID);
    _vRefID++;

    //memoryReference = _Size[_offSet]; // Se le asigna el pedazo de memoria al vRef;

   if(pType=="int")
   {
       _dataManager->insertNewObject(Int,_vRefID,_offSet,memoryReference);

   }
   if(pType=="string")
   {
       _dataManager->insertNewObject(String,_vRefID,_offSet,memoryReference);

   }
   if(pType=="char")
   {
       _dataManager->insertNewObject(Char,_vRefID,_offSet,memoryReference);

   }
   if(pType=="array")
   {
       _dataManager->insertNewObject(Array,_vRefID,_offSet,memoryReference);
   }


   _offSet+=pSize;
   _Size += _offSet;

   cout << "offset:" << _offSet <<endl;
   cout << "size: " << _Size-(_offSet)<<endl;

   return memoryReference;
}

/**
 * @brief vHeap::freeSpace
 * Manda los archivos que no esten en uso a paginar.
 */
void vHeap::freeSpace()
{
    lista_enlazada<DataInfo>* MetaDatoList = _dataManager->getMetaDatosList();
    Nodo<DataInfo>* tmp = MetaDatoList->getHead();
    for(int i= 0; i< MetaDatoList->length(); i++)
    {
        cout << "llega al for" << endl;
        if (!tmp->getData().isFlaginUse())
        {
            makePagination(*tmp->getData().getVRefPointer());
            cout<< "tmp ID: " << tmp->getData().getID()<< endl;
            _offSet= _offSet-tmp->getData().getSize();
            vFree(tmp->getData().getID());
        }
        else
        tmp = tmp->getNext();
    }
    reArrangeData();

}

void vHeap::reArrangeData()
{
    for(int* i =0; i<_Size; i++)
    {
        if(_Size[*i]==0)
        {
            for(int* j = i+1; j<_Size; j++)
            {
                if(_Size[*j]!=0)
                {
                    _Size[*i] = _Size[*j];
                    _Size[*j] = 0;
                    break;
                }
            }
        }
    }
}




/**
 * @brief vHeap::vFree
 * @param needToFree: ID del objeto a liberar
 */
void vHeap::vFree(int needToFree)
{
    int deleteOffset = _dataManager->findDataInfo(needToFree).getOffset();

    for(int i=0; i< _dataManager->findDataInfo(needToFree).getSize();i++)
    {
        _Size[deleteOffset+i] = 0;
    }
    reArrangeData();
}

/**
 * @brief vHeap::makePagination
 * @param pDato
 */
void vHeap::makePagination(vRef pDato)
{
    _binFILE->writeToAFile(pDato);
    this->vFree(pDato.getId());
    reArrangeData();
}

/**
 * @brief vHeap::readFromPagination
 * @param pID
 * @return
 */
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
            memoryManager = new vHeap(TamanoHeap,_Overweight);// 400 = Size ARREGLARLO!.
	        instanceFlag = true;
	        return memoryManager;
	    }
    else
    {
        return memoryManager;
    }
}

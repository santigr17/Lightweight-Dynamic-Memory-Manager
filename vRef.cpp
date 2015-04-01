
#include "vRef.h"

vRef::vRef()
{
	_usageFlag = true;
}

void vRef::setId(int pId)
{
	this->_ID = pId;
}
int vRef::getId()
{
	return _ID;
}

vRef* vRef::getReference()
{
	return this;
}


vObject* vRef::operator *()
{
	_usageFlag = true;
	//Falta hacer varas aqui
}

void vRef::operator=(vObject* pData)
{
	vHeap* _heap = vHeap::getInstace();
	_heap->vMalloc(sizeof(pData), pData->getType());
	// Ese & esta mal ahí, solo que no se como poner para que el
	//vRef (this->getReference()) guarde la direccion de pData->getData()
	this->getReference() = &(pData->getData());
}

void vRef::operator=(vRef* pVRef)
{
	this->getId() = pVRef->getId();
}

void vRef::operator =(int* pInt)
{
	//aritmetica de punteros
}
//Se verifican si los ID son iguales para saber si apuntan al
//mismo espacio en memoria
bool vRef::operator==(vRef* pVRef)
{
    if (this->getId() == pVRef->getId())
	{
		return true;
	}
	return false;
}

void vRef::operator++()
{
	DataManager* _manage = DataManager::getInstace();
	Nodo<DataInfo>* tmpMetadata = _manage->getMetaDatosList()->getHead();
	for (int i=0 ; i < _manage->getMetaDatosList()->length() ; i++)
	{
		if(this->getId() == tmpMetadata->getData().getID())
		{
			//Se le suma al offset
			//tmpMetadata->getData().setOffset();
		}
	}
}

void vRef::operator--()
{
	DataManager* _manage = DataManager::getInstace();
	Nodo<DataInfo>* tmpMetadata = _manage->getMetaDatosList()->getHead();
	for (int i=0 ; i < _manage->getMetaDatosList()->length() ; i++)
	{
		if(this->getId() == tmpMetadata->getData().getID())
		{
			//Se le resta al offset
			//tmpMetadata->getData().setOffset();
		}
	}

}


vRef::~vRef()
{
	_usageFlag = false;
}


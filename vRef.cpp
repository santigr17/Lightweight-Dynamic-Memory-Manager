
#include "vRef.h"

/*vRef::vRef(int pId)
{
	_usageFlag = true;
	_ID = pId;
}

int vRef::getId()
{
	return _ID;
}

vRef* vRef::getReference()
{
	return this;
}
*/
/*vObject* vRef::operator *()
{
	_usageFlag = true;
	vObject* obj = new vObject();
	return obj;
}*/
/*
void vRef::operator =(void *pData)
{
	if (pData == (vRef*) pData)
	{
		//pRef->getId() == pData->getId();
	}
	else if (pData == (vObject*) pData)
	{
		//Se hace una escritura en el heap
		// !!!!!!!!!!!!!!!!!!!
	}
	else if (pData == (int*) pData)
	{
		//aritmetica de punteros
	}

}

//Compara si dos vRef apuntan al mismo espacio de memoria, en este caso
//se comparan las direcciones de memoria de ambos objetos
bool vRef::operator ==(vRef *pRef2)
{
    vRef *pRef1;
	if (pRef1->getReference() == pRef2->getReference())
	{
		return true;
	}
	return false;
}

vRef::~vRef()
{
	_usageFlag = false;
}
*/
/*int main()
{
	vRef ref1;
	vRef ref2;

	cout << ref1.getReferencePointer() << endl;
	cout << ref2.getReferencePointer() << endl;
	ref1 = ref2;
}*/

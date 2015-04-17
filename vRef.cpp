
#include "vRef.h"
/**
 * @brief vRef::vRef
 */
vRef::vRef()
{

    this->setObjectUsageFlag(true);
    //this->setID(pID);
    _dataManager = DataManager::getInstace();
}

/*!
 * \brief vRef::operator *
 * \return
 */
vObject vRef::operator *()
{
    this->setObjectUsageFlag(true);
    //_dataManager->findDataInfo(this->getID()).setUsageFlag(true);
    //_dataManager->findDataInfo(this->getID()).raiseCounter();

    vObject* tmp = new vObject();
    tmp = (vObject*)this->getObjectData();
    tmp->setObjectID(this->getObjectID());


    return *tmp;
}

/*!
 * \brief vRef::operator =
 * \param pVRef
 */
void vRef::operator =(vRef* pVRef)
{
    this->setObjectID(pVRef->getObjectID());
}
/*!
 * \brief vRef::operator =
 * \param pVObject
 */
void vRef::operator =(vObject* pVObject)
{
    //verificar Tamaños
    if(pVObject->getObjectType() == 0)
    {
        this->setObjectData((pVObject->getObjectData()));
        this->setObjectType(0);
    }
    if(pVObject->getObjectType() == 1)
    {
        this->setObjectData((pVObject->getObjectData()));
        this->setObjectType(1);
    }
    if(pVObject->getObjectType() == 2)
    {
        this->setObjectData((pVObject->getObjectData()));
        this->setObjectType(2);
    }
    if(pVObject->getObjectType() == 3)
    {
        this->setObjectData((pVObject->getObjectData()));
        this->setObjectType(3);
    }
    //this->setData( *pVObject);
}
/*!
 * \brief vRef::operator =
 * \param pInt
 */
void vRef::operator =(int pInt)
{
    this->setObjectData((void*)(&pInt));
}


/*!
 * \brief vRef::operator ==
 * \param pVRef
 * \return
 */
bool vRef::operator==(vRef* pVRef)
{
    if(this->_dataManager->findDataInfo(this->getObjectID()).getOffset() ==
            _dataManager->findDataInfo(pVRef->getObjectID()).getOffset())
    {
        return true;
    }
}



//Se verifican si los ID son iguales para saber si apuntan al
//mismo espacio en memoria

/*!
 * \brief vRef::operator ++
 */
void vRef::operator++()
{
   this->setObjectData(this->getObjectData() + _dataManager->findDataInfo(this->getObjectID()).getSize());
}
/*!
 * \brief vRef::operator --
 */
void vRef::operator--()
{

}


vRef::~vRef()
{
    this->setObjectUsageFlag(false);
}
/**
 * @brief vRef::getBehindOffset: este metodo busca el id del vref que se encuentra anterior a este
 * @return id del vref anterior
 */

int vRef::getBehindOffset()
{
    Nodo<DataInfo>* tmp = _dataManager->getMetaDatosList()->getHead();
    for(int i=0; _dataManager->getMetaDatosList()->length(); i++)
    {
        if ((tmp->getData().getOffset()+tmp->getData().getSize()) ==(_dataManager->findDataInfo(this->getObjectID()).getOffset()))
        {
            return tmp->getData().getID();
        }
    }
    throw ("No hay ninguno antes");
}


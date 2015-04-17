#include "vObject.h"
/*!
 * \brief vObject::vObject
 */
vObject::vObject()
{
}

void vObject::setObjectUsageFlag(bool pUse){this->_usageFlag = pUse;}
bool vObject::getObjectUsageFlag(){return this->_usageFlag;}

void vObject::setObjectData(void* pData){this->_Data = pData;}
void* vObject::getObjectData(){return _Data;}


void vObject::setObjectID(int pID){this->_ID = pID;}
int vObject::getObjectID(){return this->_ID;}

void vObject::setObjectType(int ptype){this->data_type = ptype;}
int vObject::getObjectType(){return this->data_type;}
/*!
 * \brief vObject::operator =
 * \param pdata
 */
void vObject:: operator =(int pdata)
{
    this->data2 = pdata;
}

/*vHeap* vObject::getHeap(){return this->_heap;}
DataManager* vObject::getDataManager(){return this->_dataManager;}*/

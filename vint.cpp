#include "vint.h"
/*!
 * \brief vInt::vInt
 * \param pdata
 */
vInt::vInt(void* pdata):vRef()
{
    this->setObjectData((int*)(&pdata));
    this->setObjectType(0);
}
/*!
 * \brief vInt::operator =
 * \param pdata
 * \return
 */
vObject vInt::operator =(void* pdata)
{
    vObject* vobj = new vInt(pdata);
    return *vobj;
}


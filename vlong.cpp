#include "vlong.h"
/*!
 * \brief vLong::vLong
 * \param pdata
 */
vLong::vLong(long pdata)
{
    this->setObjectData((void*)(&pdata));
    this->setObjectType(2);
}
/*!
 * \brief vLong::operator =
 * \param pdata
 * \return
 */
vObject vLong::operator =(long &pdata)
{
    vObject* vobj = new vLong(pdata);
    return *vobj;
}

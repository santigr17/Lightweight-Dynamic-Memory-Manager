#include "vchar.h"
/*!
 * \brief vChar::vChar
 * \param pdata
 */
vChar::vChar(const char* pdata)
{
    this->setObjectData((void*)(&pdata));
    this->setObjectType(1);
}
/*!
 * \brief vChar::operator =
 * \param pdata
 * \return
 */
vObject vChar::operator =(const char* pdata)
{
    vObject* vobj = new vChar(pdata);
    return *vobj;
}


#ifndef VINT_H
#define VINT_H
#include "vRef.h"

class vInt : public vRef
{
public:
    vInt(void* pdata);
    vObject operator =(void*);
};

#endif // VINT_H

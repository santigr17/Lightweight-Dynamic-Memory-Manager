#ifndef VFLOAT_H
#define VFLOAT_H

#include "vobject.h"

class vFloat : public vObject<float>
{
public:
    vFloat(float);
    ~vFloat();
};

#endif // VFLOAT_H

#ifndef VLONG_H
#define VLONG_H

#include "vobject.h"

class vLong :public vObject<long>
{
public:
    vLong(long);
    ~vLong();
};

#endif // VLONG_H

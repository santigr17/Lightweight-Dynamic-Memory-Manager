#ifndef VLONG_H
#define VLONG_H

#include "vObject.h"

class vLong : public vObject
{
public:
    vLong(long);
    vObject operator=(long&);
};

#endif // VLONG_H

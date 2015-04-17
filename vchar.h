#ifndef VCHAR_H
#define VCHAR_H

#include "vObject.h"

class vChar : public vObject
{
public:
    vChar(const char*);
    vObject operator =(const char*);
};

#endif // VCHAR_H

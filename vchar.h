#ifndef VCHAR_H
#define VCHAR_H

#include "vobject.h"

class vChar : public vObject<const char *>
{
public:
    vChar(const char*);
    ~vChar();
};

#endif // VCHAR_H

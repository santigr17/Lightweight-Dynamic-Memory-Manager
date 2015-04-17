#ifndef MAINHEAP_H
#define MAINHEAP_H

#include "vHeap.h"
#include "socketcliente.h"
#include "vint.h"
#include "vchar.h"
#include "vlong.h"

class MainHeap
{
private:
    vHeap* _heap;
    SocketCliente* _socket;
    void initHeap();

public:
    MainHeap();
};

#endif // SENDDATASOCKET_H

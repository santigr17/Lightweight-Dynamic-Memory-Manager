#ifndef SOCKETCLIENTE_H
#define SOCKETCLIENTE_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "crazythread.h"

#define IP "192.168.1.104"

using namespace std;

class SocketCliente
{
public:
    SocketCliente();
    bool connectar();
    void setMensaje(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    static void * controlador(void *obj);
};

#endif // SOCKETCLIENTE_H

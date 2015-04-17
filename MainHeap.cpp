#include "MainHeap.h"
/**
 * @brief MainHeap::MainHeap
 */
MainHeap::MainHeap()
{
    _heap = vHeap::getInstace();
    _socket = new SocketCliente();
    _socket->connectar();

    int totalSize = _heap->getOffset();
    int currentSize = _heap->getTotalSize();

    string dataTOsend = std::to_string (totalSize) + "#" + std::to_string (totalSize) + "#";

    _socket->setMensaje(dataTOsend.c_str());
}
/**
 * @brief MainHeap::initHeap
 */
void MainHeap::initHeap()
{
    for (int i= 0; i< 40;i++)
    {
       //vInt a  = new vInt((int*)3);

    }

}

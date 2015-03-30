#include <vThread.h>

vThread::vThread(void *func, void *arg)
{
    _func = func;
    _arg = arg;
    _thread = new pthread_t;
}

vThread::~vThread()
{

}

void vThread::run()
{
    pthread_create(_thread, nullptr, (void*(*)(void*))_func, _arg);
}


void vThread::join()
{
    pthread_join(*_thread, NULL);
}

std::string vThread::getId()
{
    return _id;
}

void vThread::setId(std::string id)
{
    _id = id;
}

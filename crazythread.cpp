#include <crazythread.h>
/**
 * @brief CrazyThread::CrazyThread
 * @param func
 * @param arg
 */
CrazyThread::CrazyThread(void *func, void *arg)
{
    _func = func;
    _arg = arg;
    _thread = new pthread_t;
}
/**
 * @brief CrazyThread::~CrazyThread
 */
CrazyThread::~CrazyThread()
{

}
/**
 * @brief CrazyThread::run
 */
void CrazyThread::run()
{
    pthread_create(_thread, nullptr, (void*(*)(void*))_func, _arg);
    //pthread_create(_thread, nullptr, _func, _arg);
}

/**
 * @brief CrazyThread::join
 */
void CrazyThread::join()
{
    pthread_join(*_thread, NULL);
}
/**
 * @brief CrazyThread::getId
 * @return
 */
std::string CrazyThread::getId()
{
    return _id;
}
/**
 * @brief CrazyThread::setId
 * @param id
 */
void CrazyThread::setId(std::string id)
{
    _id = id;
}

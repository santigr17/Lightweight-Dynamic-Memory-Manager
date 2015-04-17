#include "vThread.h"
/*!
 * \brief vThread::vThread
 * \param func
 * \param arg
 */
vThread::vThread(void *func, void *arg)
{
    _func = func;
    _arg = arg;
    _thread = new pthread_t;
}
/*!
 * \brief vThread::~vThread
 */
vThread::~vThread()
{

}
/*!
 * \brief vThread::run
 */
void vThread::run()
{
    pthread_create(_thread, nullptr, (void*(*)(void*))_func, _arg);
}

/*!
 * \brief vThread::join
 */
void vThread::join()
{
    pthread_join(*_thread, NULL);
}
/*!
 * \brief vThread::getId
 * \return
 */
std::string vThread::getId()
{
    return _id;
}
/*!
 * \brief vThread::setId
 * \param id
 */
void vThread::setId(std::string id)
{
    _id = id;
}

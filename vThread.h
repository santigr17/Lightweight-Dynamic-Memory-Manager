#ifndef CRAZYTHREAD_H
#define CRAZYTHREAD_H

#include <pthread.h>
#include <string>

class vThread
{
private:
    std::string _id;
    void* _func;
    void *_arg;
    pthread_t * _thread;

public:
    vThread(void *func, void *arg);

    ~vThread();

    std::string getId();
    void setId(std::string id);
    void run();
    void join();
};

#endif // THREAD_H

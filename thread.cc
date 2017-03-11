#include "thread.h"

Thread::Thread(threadCallBack cb) : threadId(0), callBack(std::move(cb))
{

}

Thread::~Thread()
{
    pthread_detach(threadId);
}

void Thread::start()
{
    pthread_create(&threadId, NULL, threadFunc, this);
}

void Thread::join()
{
    pthread_join(threadId, NULL);
}

void *Thread::threadFunc(void *arg)
{
    Thread *pt = static_cast<Thread*>(arg);
    pt->callBack();
    return NULL;
}

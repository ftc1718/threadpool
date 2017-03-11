#ifndef __THREAD_H__
#define __THREAD_H__

#include "noncopyable.h"
#include <pthread.h>
#include <functional>

class Thread : private NonCopyable
{
public:
    typedef std::function<void ()> threadCallBack;

    Thread(threadCallBack);
    ~Thread();
    void start();
    void join();

private:
    static void *threadFunc(void *);

    pthread_t threadId;
    threadCallBack callBack;

};
#endif

#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "noncopyable.h"
#include <pthread.h>

class MutexLock;

class Condition : private NonCopyable
{
public:
    Condition(MutexLock &);
    ~Condition();

    void wait();
    void signal();
private:
    pthread_cond_t cond;
    MutexLock &mutex;
};

#endif

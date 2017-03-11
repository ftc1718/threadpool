#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "noncopyable.h"
#include <pthread.h>

class MutexLock : private NonCopyable
{
public:
    MutexLock();
    ~MutexLock();

    void lock();
    void unlock();

    pthread_mutex_t *getMutexPtr();

private:
    pthread_mutex_t mutex;

};

#endif

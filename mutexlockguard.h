#ifndef __MUTEXLOCKGUARD_H__
#define __MUTEXLOCKGUARD_H__ 

#include "noncopyable.h"
#include "mutexlock.h"

class MutexLockGuard : private NonCopyable
{
public:
    MutexLockGuard(MutexLock &m) : mutex(m)
    {
        mutex.lock();
    }
    ~MutexLockGuard()
    {
        mutex.unlock();
    }
private:
     MutexLock &mutex;
};

#endif

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "noncopyable.h"
#include "mutexlock.h"
#include "condition.h"
#include <queue>

class Task;

class Buffer : private NonCopyable
{
public:
    Buffer(std::size_t);

    bool full()const;
    bool empty()const;

    void push(Task *);
    Task *pop();

private:
    MutexLock mutex;
    Condition notEmpty;
    Condition notFull;

    std::size_t buffSize;
    std::queue<Task*> buffQueue;
};

#endif

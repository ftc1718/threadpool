#include "buffer.h"
#include "mutexlockguard.h"

Buffer::Buffer(std::size_t s)
    : mutex(),
    notEmpty(mutex),
    notFull(mutex),
    buffSize(s)
{

}

bool Buffer::full()const
{
    return buffQueue.size() == buffSize;
}

bool Buffer::empty()const
{
    return buffQueue.empty();
}

void Buffer::push(Task *task)
{
   MutexLockGuard guard(mutex);
   while(full())
   {
       notFull.wait();
   }
   buffQueue.push(task);
   notEmpty.signal();
}

Task *Buffer::pop()
{
    MutexLockGuard guard(mutex);
    while(empty())
    {
        notEmpty.wait();
    }
    Task *task = buffQueue.front();
    buffQueue.pop();
    notFull.signal();
    return task;
}

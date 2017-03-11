#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "buffer.h"
#include <functional>
#include <vector>
#include <memory>


class Thread;

class Threadpool : private NonCopyable
{
public:
    Threadpool(std::size_t buffSize, std::size_t threadNum);
    ~Threadpool();

    void start();
    void stop();

    void addTask(Task *task);
    Task *getTask();

    void threadFunc();

private:
    Buffer buffer;
    std::size_t threadNum;
    std::vector<std::unique_ptr<Thread> > threadVec;

};

#endif

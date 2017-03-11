#include "threadpool.h"
#include "task.h"
#include "thread.h"

Threadpool::Threadpool(std::size_t bs, std::size_t tn)
    : buffer(bs),
    threadNum(tn)
{

}

Threadpool::~Threadpool()
{
    stop();
}

void Threadpool::start()
{
    for(std::size_t ix = 0; ix != threadNum; ++ix)
    {
        Thread *pthread = new Thread(std::bind(&Threadpool::threadFunc, this));
        threadVec.push_back(std::unique_ptr<Thread>(pthread));
        pthread->start();
    }
}

void Threadpool::stop()
{
    for(std::size_t ix = 0; ix != threadNum; ++ix)
    {
        threadVec[ix]->join();
    }
    threadVec.clear();
}

void Threadpool::addTask(Task *task)
{
    buffer.push(task);
}

Task *Threadpool::getTask()
{
    return buffer.pop();
}

void Threadpool::threadFunc()
{
    while(1)
    {
        Task *task = getTask();
        if(task)
        {
            task->excute();
        }
    }
}

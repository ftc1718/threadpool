#include "condition.h"
#include "mutexlock.h"

Condition::Condition(MutexLock &m) : mutex(m)
{
    pthread_cond_init(&cond, NULL);
}

Condition::~Condition()
{
    pthread_cond_destroy(&cond);
}

void Condition::wait()
{
    pthread_cond_wait(&cond, mutex.getMutexPtr());
}

void Condition::signal()
{
    pthread_cond_signal(&cond);
}

#include "mutexlock.h"

MutexLock::MutexLock()
{
    pthread_mutex_init(&mutex, NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&mutex);
}

void MutexLock::lock()
{
    pthread_mutex_lock(&mutex);
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(&mutex);
}

pthread_mutex_t *MutexLock::getMutexPtr()
{
    return &mutex;
}

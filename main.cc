#include "threadpool.h"
#include "task.h"
#include <iostream>

/* void test(int n) */
/* { */
/*     n++; */
/*     std::cout << n << std::endl; */
/* } */
/* int main(void) */
/* { */

/*     Thread testThread(std::bind(test, 2));//bind(test, 2)的类型为std::function<void ()> */
/*     testThread.start(); */
/*     testThread.join(); */

/*     return 0; */
/* } */


int main()
{
    Threadpool pool(100, 4);
    Task task;
    pool.start();
    while(1)
    {
        pool.addTask(&task);
    }

    return 0;
}

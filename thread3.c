// What happens if the child thread does not complete in 2 seconds? 
// After executing the for loop 2 times, the main thread terminates and all other threads will also be terminated.
// Output : My Thread, MyThread (2 times only)

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *arg)
{
        for(int i = 0 ; i < 5 ; i++)
        {
                printf("My Thread \n");
                sleep(1);
        }
        return NULL;
}

int main()
{
        pthread_t t1;
        pthread_create(&t1 , NULL, myfunc , NULL);

        sleep(2);
        return 0;
}

// There is a problem in this code as the main thread completes before the thread t1.

#include<stdio.h>
#include<pthread.h>

void *myfunc(void *arg){
    printf("My Thread \n");
    return NULL;
}

int main(){
    pthread_t t1;
    pthread_create(&t1, NULL, myfunc, NULL);

    return 0;
}

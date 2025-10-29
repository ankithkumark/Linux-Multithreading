#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *myfunc(void *arg){
    printf("My Thread\n");
    return NULL;
}

int main(){
    pthread_t t1;
    pthread_create(&t1, NULL, myfunc, NULL);
    sleep(2);
    return 0;
}

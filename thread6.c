// Program to determine the id of current thread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *arg){
  
        printf("My Thread, ID = %ld \n",(long int)(pthread_self()));
        return NULL;
}

int main(){
        pthread_t t1;
        pthread_create(&t1 , NULL, myfunc , NULL);

        printf("Main: New thread with %ld created \n", (long int)t1);
        pthread_exit(NULL);

        return 0;
}

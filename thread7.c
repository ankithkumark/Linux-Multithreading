// Argument passing to threads

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *arg){
  
        printf("Thread received arg = %s \n" , (char *)arg);
        return NULL;
}

int main(){
  
        pthread_t t1;
        pthread_create(&t1, NULL, myfunc, "AnKith");

        pthread_exit(NULL);

        return 0;
}

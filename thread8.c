// Passing integer arguments to thread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *arg){
  
    printf("Thread received arg = %d \n", *(int *)arg);
    return NULL;
}

int main(){
  
    int num;
    printf("Enter the number to pass as argument to thread: ");
    scanf("%d", &num);
    
    pthread_t t1;
    pthread_create(&t1 , NULL, myfunc , &num );
    pthread_exit(NULL);

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *ptr){
        return (void *)5;
}

int main(){
  pthread_t mythread;
  pthread_create(&mythread , NULL , fun , NULL);

  void *result ;

  pthread_join(mythread,&result);
  printf("result = %ld \n",(long int)result);
  
  return 0;
}

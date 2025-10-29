// Controlling the number of times a thread loop runs using argument.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *ptr){
  for(int i = 0 ; i < *(int *)ptr ; i++){
    printf("Thread i = %d \n" , i);
    sleep(1);
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t mythread;
  int x = 0;
  printf("Enter a number : ");
  scanf("%d", &x);

  pthread_create(&mythread , NULL , fun , &x);

  for(int i = 0; i < x; i++){
    printf("Main %d \n",i);
    sleep(1);
  }
  pthread_exit(NULL);

  return 0;
}

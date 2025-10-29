//Mutex (Mutual Exclusion lock)

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define MUTEX
int global = 0;

#ifdef MUTEX
//This line declares and initializes a mutex (mutual exclusion lock) named mut_global.
pthread_mutex_t mut_global = PTHREAD_MUTEX_INITIALIZER;
#endif

void *fun1(void *arg){
  printf("Thread-1 starts %d\n", global);

  #ifdef MUTEX
    pthread_mutex_lock(&mut_global);
    printf("t1 Lock obtained \n");
  #endif

  int temp = global;
  sleep(1);
  temp = temp + 1;
  global = temp;

  #ifdef MUTEX
    pthread_mutex_unlock(&mut_global);
    printf("T1- Lock is released \n");
  #endif

  pthread_exit(NULL);
}

void *fun2(void *arg){
    printf("Thread-2 starts %d\n", global);

  #ifdef MUTEX
    pthread_mutex_lock(&mut_global);
    printf("t2 Lock obtained \n");
  #endif

  int temp = global;
  sleep(1);
  temp = temp + 1;
  global = temp;

  #ifdef MUTEX
    pthread_mutex_unlock(&mut_global);
    printf("T2- Lock is released \n");
  #endif

  pthread_exit(NULL);
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, fun1, NULL);
    pthread_create(&t2, NULL, fun2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of global = %d\n", global);

    return 0;
}

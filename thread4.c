// If main() finishes before the created thread (t1) completes, the entire process is terminated, including all threads.
// Solution: Wait for the child thread to complete or only terminate main thread allowing other threads to continue.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myfunc(void *arg){
  
  for(int i = 0 ; i < 5 ; i++){
    printf("My Thread \n");
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t t1;
  pthread_create(&t1 , NULL, myfunc , NULL);
  pthread_exit(NULL);
  
  return 0;
}

// pthread_exit() prevents the main thread from terminating allowing other threads (like t1) to continue executing independently. 
// It exits only the main thread, not the entire process.

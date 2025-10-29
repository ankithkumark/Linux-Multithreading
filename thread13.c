/* 	pthread_join:
		  Used to wait for a thread to finish
		  Returns control to the calling thread after the target thread terminates
	  Function signature:
		  int pthread_join(pthread_t thread, void **retval);
		  thread: The ID of the thread to wait for.
		  retval: Pointer to store the return value of the terminated thread.
		  Ensures proper resource cleanup
*/

//Demonstrate pthread_join.

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *ptr){
  for(int i = 0; i < *(int *)ptr; i++){
    printf("Thread i = %d \n", i);
    sleep(1);
  }
  pthread_exit(NULL);
  return NULL;
}

int main(){
  pthread_t mythread;
  int x = 0;
  printf("Enter a number : ");
  scanf(" %d",&x);

  pthread_create(&mythread , NULL , fun , &x);

  // Wait till threads are complete before main continues.
  pthread_join(mythread,NULL);

  for(int i = 0 ; i < x ; i++){
    printf("Main %d \n",i);
    sleep(1);
  }
  pthread_exit(NULL);

  return 0;
}

// pthread_exit() → "I'm done working, I'll stop now."
// pthread_join() → "I'll wait here until you finish."

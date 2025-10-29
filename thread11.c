// Running multiple threads with same function.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg){
  int i;
  for(i = 0 ; i < 5 ; i++){
    printf("Thread-id = %ld | %s \n",(long int)pthread_self(), (char *)arg);
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t t1, t2;
  pthread_create(&t1, NULL, fun, "Ankith");
  pthread_create(&t2, NULL, fun, "Kumar");
  pthread_exit(NULL);

  return 0;
}

// Running multiple threads parallel with different code

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *fun1(void *arg){
  for(int i = 0 ; i < 5 ; i++){
    printf("From func1 \n");
    sleep(1);
  }
  return NULL;
}

void *fun2(void *arg){
  for(int i = 0 ; i < 5 ; i++){
    printf("From func2 \n");
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t t1, t2;
  pthread_create(&t1 , NULL , fun1 , 0);
  pthread_create(&t2 , NULL , fun2 , 0);
  pthread_exit(NULL);

  return 0;
}

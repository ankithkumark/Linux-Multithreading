#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *myfunc(void *arg){
  
	for(int i=0; i<5; i++){
		printf("My Thread\n");
		sleep(1);
	}
	return NULL;
}

int main(){
	pthread_t t1;
	pthread_create(&t1, NULL, myfunc, NULL);
	printf("Statement from main thread\n");
  
	pthread_exit(NULL);
	printf("This code will not executed as main thread has exited \n");
  
	return 0;
}

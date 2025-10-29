// Multiple threads woking on shared(data segment) resource
// Race condition

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int global = 5;

void *func1(void *arg){
		printf("Thread-1 starts %d\n", global);
		//simulating global++
		int tmp = global;
		sleep(1);
		tmp = tmp + 1;
		global = tmp;
		printf("thread-1 ends \n");
		return NULL;
}

void *func2(void *arg){
	printf("Thread-2 starts %d\n", global);
	int tmp = global;
	sleep(1);
	tmp = tmp + 1;
	global = tmp;
	printf("thread-2 ends\n");
	return NULL;
}

int main(){
	pthread_t t1, t2;
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Main - global = %d\n", global);
	return 0;
}

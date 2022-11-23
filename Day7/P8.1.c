#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *func(void *p){
	int i = 1;
	printf("Thread Starts\n");
	while (i <= 10 ){
		printf("Count %d times\n",i++);
		//sleep(1);
	}
}
int main(){
	printf("Main Starts\n");
	pthread_t th;
	printf("Thread Created\n");
	pthread_create (&th , NULL , func , NULL);
	sleep(1);
	printf("Main Ends\n");
	return 0;
}

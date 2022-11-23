#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *func(void *p){
	long int t = (long) p;
	printf("Thread Called for = %ld\n",t);
	pthread_exit(NULL);
}
int main(){
	printf("Main Starts\n");
	pthread_t tn[5];
	long i;
	for(i = 0 ; i < 5 ; i++){
		pthread_create (&tn[i] , NULL , func , (void *) i);
		pthread_join(tn[i],NULL);
	}
	//sleep(1);
	printf("Main Ends\n");
	return 0;
}

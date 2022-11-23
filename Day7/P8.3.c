#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <semaphore.h>
int c = 10 , counter = 0 , c1 , c2;
int temp;
sem_t mutex;
int sem_type = 0 , sm = 1;//1
void *fun(void *p){
	long int t ;
	while(1){
		sem_wait(&mutex);//2
		t = (long) p;
		counter++;
		temp = rand();
		c1 = temp + c;
		c2 = temp - c;
		sem_post(&mutex);//3
		if(c1-c2 != 2 * c)
			break;
		printf("Thread %ld in CS ,C1 is = %d C2 = %d\n",t , c1 , c2);
		//sleep(1);
		}
	printf("Loop Breaks in iteration %d ,C1 is = %d C2 = %d\n",counter , c1 , c2); 
	}
int main(){
	printf("Main Starts\n");
	pthread_t th1 , th2;
	long a = 1 , b = -1;
	pthread_attr_t att;
	pthread_attr_init(&att);
	pthread_attr_setschedpolicy(&att,SCHED_RR);
	sem_init(&mutex,sem_type,sm);//4
	pthread_create(&th1,&att,(void*) fun , (void*) a);
	pthread_create(&th2,&att,(void*) fun , (void*) b);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	sem_destroy(&mutex);//5
	return 0;
}

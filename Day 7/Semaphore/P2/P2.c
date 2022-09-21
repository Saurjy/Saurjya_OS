#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int id ;
	char *q;
    id = shmget(1234,1024,0666 | IPC_CREAT);
    q = (char*) shmat(id,(void*)0,0);
    do{
    printf("%c",*q);
    q++;
    }while(*q!='\0');
    printf("\n");
    shmdt(q);
    shmctl(id,IPC_RMID,NULL);
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int id , i= 0;
	char *p;
    char Name[20];
    printf("Enter Your First Name ");
    scanf("%s",Name);
    id = shmget(1234,1024,0666 | IPC_CREAT);
    p = (char*) shmat(id,(void*)0,0);
    memcpy(p,Name,20);
    //*p = Name[i];
    printf("Your First Name is : %s\n",Name);
    shmdt(p);
}

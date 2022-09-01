#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
	{
	int id , temp, i;
	id = fork();
	if(id == 0)
		{
		printf("This is From Child Process\nThe PID of Child Process is %d and PPID of Child Process %d\n",getpid(),getppid());
		printf("Lets Kill the parent process after 5 secs\n");
		temp = getppid();
		sleep(10);
		if(temp != getppid())
			printf("This is From Child Process : My Parent %d died So now I am an Orphan Process under %d\n",temp,getppid());
			
		}
	else
		{
		printf("This is From Parent Process\nThe PID of Parent Process is %d and PPID of Parent Process %d\n",getpid(),getppid());
		sleep(5);
		exit (0);
		}
		sleep(10);
	}

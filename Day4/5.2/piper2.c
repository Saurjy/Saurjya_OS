#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
int main()
{
	int fd[2],w ,r,p,c , arr[3] , arr2[3], temp , t1 , t2;
	p = pipe(fd);
	c = fork();
	if(c == 0)
	{
		printf("I am Child Process\n");
		printf("Please Enter an Integer : \n");
		scanf("%d",&arr[0]);
		printf("Please Enter an Integer : \n");
		scanf("%d",&arr[1]);
		w = write(fd[1],arr,sizeof(arr));
		sleep(3);
		r = read(fd[0],arr,sizeof(arr));
		printf("Printing from Child \n Power of %d raised to the power of %d is %d",arr[0],arr[1],arr[2]);
		}
	else
	{
		printf("I am Parent Process\n");
		r = read(fd[0],arr2,sizeof(arr2));
		t1 = arr2[0];
		t2 = arr2[1];
		temp = arr2[0];
		for(int i = 1 ; i < arr2[1]; i++)
			temp = temp * arr2[0];
		arr2[2] = temp;
		w = write(fd[1],arr2,sizeof(arr2));
		}
	return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
int main()
{
	char S[32],S1[32],Rev[32],Rev2[32] ;
	int fd[2],w ,r,p,c ,i = 0, j,size;
	p = pipe(fd);
	c = fork();
	if(c == 0)
	{
		printf("I am Child Process\n");
		printf("Please Enter a String withing 32 Characters : \n");
		fgets(S,32,stdin);
		w = write(fd[1],S,sizeof(S));
		sleep(10);
		r = read(fd[0],Rev2,sizeof(S));
		printf("Reverse String = %s",Rev2);
		}
	else
	{
		printf("I am Parent Process\n");
		r = read(fd[0],S1,sizeof(S1));
		printf("Input String = %s",S1);
		j = strlen(S1)-1;
	    size = j;
		printf("%d",j);
		sleep(5);
		while ( i <= size)   
			Rev[i++] = S1[j--];
			Rev[i]='\0';
		w = write(fd[1],Rev,sizeof(S1));
		}
	return 0;
}

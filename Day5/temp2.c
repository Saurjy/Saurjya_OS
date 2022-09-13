#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int signo){
static int i = 0;
if(signo == SIGINT && i < 5)
	printf("\nSignal Received\n");
else
	exit(0) ;
i++;
}
int main(){
	if(signal(SIGINT,sig_handler)==SIG_ERR)
		printf("\nNo Signal\n");
	while(1)
		sleep(1);
	return 0;
}

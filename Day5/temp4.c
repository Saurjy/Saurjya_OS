#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int flag = 0;
void sig_handler(int signo){
  if(signo == SIGALRM)
  	flag = 1;
  	printf("ALARM!!!!!!!!!!!\n");
}

int main(){
 
  signal(SIGALRM,sig_handler);
  signal(SIGALRM,SIG_IGN);
  for(int i=1;i<=10;i++){

    alarm(1);
    sleep(2);  // Delay for 2 seconds
    if(flag == 0)
    	printf("ALARM not Triggered\n");
}
return 0;
}

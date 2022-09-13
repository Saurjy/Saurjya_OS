#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signo){
  if(signo == SIGALRM) 
  	printf("ALARM!!!!!!!!!!!\n");
}
 
int main(){
 
  signal(SIGALRM,sig_handler);
  for(int i=1;i<=10;i++){

    alarm(1);
    sleep(2);  // Delay for 2 seconds
}
return 0;
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd1 , size  =5 , r , w;
    char * myfifo = "/tmp/myfifo58";
    mkfifo(myfifo, 0666);
    int array[5]={0,0,0,0,0};
    fd1 = open(myfifo,O_RDONLY);
    for (int i = 0; i < 5; ++i)
    	{
    		printf("\nTrying to Receive Data for %d secs ",i+1);
    		sleep(1);
    		r = read(fd1, array, sizeof(array));
    	}
    close(fd1);
	for (int step = 0; step < size - 1; ++step) {
              for (int i = 0; i < size - step - 1; ++i) {
                    if (array[i] > array[i + 1]) {
		   	    int temp = array[i];
	       		    array[i] = array[i + 1];
	      		    array[i + 1] = temp;
      		    	    }
    		    }
 	      }
    if(r != -1)
    	printf("\nMessage Received and Sorted");
    fd1 = open(myfifo,O_WRONLY);
    for (int i = 0; i < 5; ++i)
    	{
    		printf("\nTrying to Send back the Sorted Data for %d secs ",i+1);
    		sleep(1);
    		w = write(fd1, array, sizeof(array));
    	}
    if(w != -1)
    	printf("\nMessage Sent\n");
     close(fd1);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd1 , size  =5 , r=-1 , w=-1 , i =0;
    char * myfifo = "/tmp/myfifo1";
    mkfifo(myfifo, 0666);
    int temp[2];
    fd1 = open(myfifo,O_RDONLY);
    while(r == -1)
    {
    		printf("\nTrying to Receive Array Size Data for %d secs ",++i);
    		r = read(fd1, temp, sizeof(temp));	
    }
    close(fd1);
    r = -1;
    size = temp[0];
    int array[size];
    fd1 = open(myfifo,O_RDONLY);
    while(r == -1)
    {
    		printf("\nTrying to Receive Array Elements Data for %d secs ",++i);
    		r = read(fd1, array, sizeof(array));	
    }
    close(fd1);
    if(r != -1)
    	printf("\nArray Received and Sorting Started");
	for (int step = 0; step < size - 1; ++step) {
              for (int i = 0; i < size - step - 1; ++i) {
                    if (array[i] > array[i + 1]) {
		   	    int temp = array[i];
	       		    array[i] = array[i + 1];
	      		    array[i + 1] = temp;
      		    	    }
    		    }
 	      }
    fd1 = open(myfifo,O_WRONLY);
    while(w == -1)
    {
    		printf("\nTrying to Send back the Sorted Array Elements Data for %d secs ",++i);
    		w = write(fd1, array, sizeof(array));
    }
    if(w != -1)
    	printf("\nMessage Sent\n");
     close(fd1);
    return 0;
}

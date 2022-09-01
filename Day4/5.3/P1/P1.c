#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd , size = 5 , r ,w;
    char * myfifo = "/tmp/myfifo58";
    mkfifo(myfifo, 0666);
    int arr[5]={5,3,6,9,8};
    int arr1[5]={0,0,0,0,0};
    fd = open(myfifo, O_WRONLY);
    printf("Unsorted Array = ");
    for (int i = 0; i < size ; ++i)
   	 printf("%d ",arr[i]);
    for (int i = 0; i < 5; ++i)
    	{
    		printf("\nTrying to Send Data for %d secs ",i+1);
    		sleep(1);
    		w = write(fd, arr, sizeof(arr));
    	}
    if(w != -1)
    	printf("\nMessage Sent");
    close(fd);
    fd = open(myfifo, O_RDONLY);
    for (int i = 0; i < 7; ++i)
    	{
    		r = read(fd, arr1, sizeof(arr1));
    		printf("\nTrying to Receive Data for %d secs ",i+1);
    		sleep(1);
    		
    	}
    if(r != -1)
    	printf("\nMessage Received and Sorted");
    printf("\nSorted Array = ");
    for (int i = 0; i < size ; ++i)
   	 printf("%d ",arr1[i]);
    printf("\n");
    close(fd);
    return 0;
}

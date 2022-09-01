#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd , size = 5 , r=-1 ,w=-1 , i = 0;
    char * myfifo = "/tmp/myfifo1";
    mkfifo(myfifo, 0666);
    //int arr[5]={5,3,6,9,8};
    //int arr1[5]={0,0,0,0,0};
    printf("Enter The No of Elements of the Array ");
    	scanf("%d",&size);
    int arr[size] , arr1[size] , temp[2];
    temp[0] = size;
    printf("Enter The %d Elements of the Array in a single line with spaces ",size);
    for (int i = 0; i < size ; ++i)
   	 scanf("%d",&arr[i]);
    printf("Unsorted Array = ");
    for (int i = 0; i < size ; ++i)
   	 printf("%d ",arr[i]);
    fd = open(myfifo, O_WRONLY);
    while(w == -1)
        {	
        	w = write(fd, temp, sizeof(temp));
    		printf("\nTrying to Send Array Size Data for %d secs ",++i);
    		
    	}
    close(fd);
    sleep(1);
    w = -1;
    fd = open(myfifo, O_WRONLY);
    while(w == -1)
        {	
        	w = write(fd, arr, sizeof(arr));
    		printf("\nTrying to Send Array Elements Data for %d secs ",++i);
    		
    	}
    if(w != -1)
    	printf("\nMessage Sent");
    close(fd);
    fd = open(myfifo, O_RDONLY);
    while(r == -1)
    	{
    		r = read(fd, arr1, sizeof(arr1));
    		printf("\nTrying to Receive Sorted Array Data for %d secs ",++i);
    		
    	}
    if(r != -1)
    	printf("\nSorted Array Data Received");
    printf("\nSorted Array = ");
    for (int i = 0; i < size ; ++i)
   	 printf("%d ",arr1[i]);
    printf("\n");
    close(fd);
    return 0;
}

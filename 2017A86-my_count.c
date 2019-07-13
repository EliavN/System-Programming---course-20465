#include <stdio.h>
unsigned int my_count(void *arr, int arrLen, int sizeOfType) 
{
    unsigned int counter = 0, curByte=0;
    unsigned char *arrPtr = arr;
    while(arrLen--)
        for(curByte=0; curByte<sizeOfType;curByte++, arrPtr++)
            while (*arrPtr){ 
                *arrPtr &= ((*arrPtr)-1) ; 
                counter++; 
	    }
    return counter; 
}

int main()
{
	int arr[3]={1,2,3};
	printf("counter is: %d\n",my_count(arr,3,sizeof(int)));
	return 0;
}

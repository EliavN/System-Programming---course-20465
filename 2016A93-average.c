#include <stdio.h>
#define BITS_IN_CHAR 8

#define AVERAGE(arr,arrLen,average,sum)\
{\
	int tempSize=arrLen;\
	while(tempSize--)\
		sum+=arr[tempSize];\
	average=sum/(double)arrLen;\
}

int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int arrLen=10 , sum=0;
	double average=0;
	AVERAGE(arr,arrLen,average,sum); 
	printf("average: %f\n" , average);	
	return 0;
}

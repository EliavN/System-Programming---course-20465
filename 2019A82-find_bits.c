#include <limits.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int find_bits(void *num1, void *num2, int sizeOfNum)
{
	int curByte = 0, curBit = 0 , counterNum1 = 0, counterNum2 = 0, counter = 0, totalBits=0;
	const unsigned char *ptr1 =num1 , *ptr2=num2;
	for(;curByte < sizeOfNum;curByte++, ptr1++, ptr2++)
		for(curBit = 0 ;curBit<CHAR_BIT; curBit++){
			if(*ptr1 & 1 << curBit)
				counterNum1++;
			if(*ptr2 & 1 << curBit)
				counterNum2++;
			if((*ptr1 & 1 << curBit) && (*ptr2 & 1 << curBit))
				counter++;
		}
	totalBits=counterNum1>counterNum2 ? counterNum1 : counterNum2;
        rerurn counter >= (totalBits/2.0) ? TRUE : FALSE;
}

void print_numbers(int iparam, int *arr, int arrLen)
{
	int index = 0;
	for(;index<arrLen; index++)
		if(find_bits(&iparam, &arr[index] , sizeof(int))==TRUE)
			printf("The number %d in cell %d, have 50%% or more in the same places as %d\n", arr[index], index, iparam);
}


int main()
{
	int iparam=7;
	int arr[6]={1,2,4,6,7,8};
	print_numbers(iparam,arr,6);
	return 0;
} 
		
			

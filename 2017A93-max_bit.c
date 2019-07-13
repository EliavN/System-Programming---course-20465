#include <stdio.h>
#include <limits.h>

int count_zero(void *num, int sizeOfNum)
{
	const unsigned char *ptr=num;
	int curByte=0 , curBit=0 , counter=0 ;
	for(;curByte<sizeOfNum; curByte++ , ptr++)
		for(curBit=0 ; curBit<CHAR_BIT;curBit++)
			if(!(*ptr & (1 << curBit)))
				counter++;
	return counter;
}

int find_zero(void *num1 , void *num2, void *result, int sizeOfNum)
{
	int num1Counter , num2Counter;
	num1Counter=count_zero(num1, sizeOfNum);
	num2Counter=count_zero(num2, sizeOfNum);
	result = num1Counter > num2Counter ? num1 : num2;
	return num1Counter > num2Counter ? num1Counter : num2Counter;
}

int bytes_needed(unsigned long num)
{
	int bitsNeeded = sizeof(num)*CHAR_BIT - __builtin_clzll(num);
	if(bitsNeeded==0)
		return 1;
	else
		return (bitsNeeded+7)/8;
}

void scanArray(int *arr, int sizeArray, int *cellNumber, int *maxZero)
{
	int i = 0, howManyZero = 0, result = 0;
	*maxxZero=-1;
	for(;i<sizeArray;i++){
		howManyZero=find_zero(&arr[i],&arr[i],&result,bytes_needed(arr[i]));
		if(*maxZero<howManyZero){
			*maxZero=howManyZero;
			*cellNumber=i;
		}
	}
}	
int main()
{
	int arr[11]={1,2,3,4,5,6,7,8,9,10,11};
	int cellNumber=0 , numOfZero=0 , sizeArray=11;
	scanArray(arr,sizeArray,&cellNumber,&numOfZero);
	printf("The number with the max zero bits in the array is%d\nit founded in cell number %d\nit has %d bits off\n", arr[cellNumber],cellNumber, numOfZero);  
	return 0;
}

	
	

#include <stdio.h>
#include <string.h>
#define NOT_FOUND -1
/*The search function receive an array and a varible of any type you need, the function checks whether the number is in the array or not.*/
int search(void *array, void *var, int arrLength, int typeSize ) 
{
	int index = 0;
	const unsigned char *ptr = array;
	for(index = 0; index < arrLength; ptr += typeSize, index++)
		if(memcmp(ptr, var, typeSize) == 0)
			return index;
	return NOT_FOUND;
}

int main(void)
{
	int intArray[] = {244,3,61,2,59,4,5,6,7};
	int intNum = 59;
	double doubleArray[] = {720.0,45.0,53.0,1,51.0,57.0,2,1,52.5};
	double doubleNum = 52.5;

	int result = search(intArray, &intNum, 9, sizeof(int));
	if(result == NOT_FOUND)
		printf("Cannot find the requested number in the given array\n");
	else
		printf("The number %d is founded in cell %d\n", intNum, result);

	result = search(doubleArray, &doubleNum, 9, sizeof(double));
	if(result == NOT_FOUND)
		printf("Cannot find the requested number in the given array\n");
	else
		printf("The number %f is founded in cell %d\n", doubleNum, result);

	return 0;
}

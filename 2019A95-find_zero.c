#define ARR_LEN 30
#include <stdio.h>
#include <limits.h>

int count_zero(void *param, int sizeOfParam)
{
	int curBit = 0, counter = 0, curByte = 0;
	const unsigned char *ptrToParam = param;
	for(; curByte < sizeOfParam; curByte++, ptrToParam++)
		for(curBit = 0; curBit < CHAR_BIT; curBit++)
			if(!(*ptrToParam & (1 << curBit)))
				counter++;
	return counter;
}

int find_zero(void *param1, void *param2, void *result, int sizeOfParam)
{
	int param1Counter, param2Counter;
	param1Counter = count_zero(param1, sizeOfParam);
	param2Counter = count_zero(param2, sizeOfParam);
	result = param1Counter > param2Counter ? param1 : param2;
	return param1Counter > param2Counter ? param1Counter : param2Counter;
}

/*for main use - section B*/
int bytes_needed(unsigned long num) {
	int bits_needed = sizeof(num)*CHAR_BIT - __builtin_clzll(num);
	if(bits_needed == 0)
		return 1;
	else
		return (bits_needed + 7) / 8;
}

void scanArray(int *array, int *maxZero, int *cellNumber)
{
	int index = 0, howManyZero=0;
	int resultFromTwo = 0;
	*maxZero = -1;
	for(; index < ARR_LEN; index++){
		howManyZero = find_zero(&array[index], &array[index], &resultFromTwo, bytes_needed(array[index]));
		if(*maxZero < howManyZero){
			*maxZero = howManyZero;
			*cellNumber = index;
		}
	}		
}

int main()
{
	int array[ARR_LEN] = {15,15,15,15,3,5,6,7,7,9,10,11,12,13,14,15,15,17,18,19,20,21,22,23,24,25,26,27,28,29};
	int theCell = 0, numberOfZero = 0;
	scanArray(array, &numberOfZero, &theCell);
	printf("The number with maximum zero bits in the array is: %d\nIt founded in cell number: %d\nIt has %d bits off\n", array[theCell],theCell, numberOfZero);
	return 0;
}

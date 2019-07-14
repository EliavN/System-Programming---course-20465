#include <stdio.h>
#include <limits.h>

int HowManyThreeBits(void *arr, int arrLen ,int sizeOfType)
{
	int index=0 , memberCounter=0 , bitCounter=0, curBit = 0, curByte = 0;
	const unsigned char *ptr = arr;
	for(bitCounter = 0;index <arrLen; index++, bitCounter = 0){
		for(curByte = 0; curByte<sizeOfType; curByte++, ptr++){
			for(curBit = 0; curBit < CHAR_BIT; curBit++){
				if(*ptr & (1 << curBit))
					bitCounter++;
			}
		}
		if(bitCounter == 3)
				memberCounter++;
	}
	return memberCounter;
} 

int main()
{
	int arrA[9]={1,3,5,7,7,6,3,2,9};
	int arrB[7]={1,2,4,7,2,7,7};
	int counter1 , counter2;
	counter1=HowManyThreeBits(arrA,9,sizeof(int));
	counter2=HowManyThreeBits(arrB,7,sizeof(int));
	printf("array A contains %d elements with 3 bits on.\n", counter1);
	printf("array B contains %d elements with 3 bits on.\n", counter2);
	if(counter1==counter2)
		printf("Both arrays have same number of 3-bit element\n");
	else if(counter1>counter2)
		printf("array A contains more 3-bit element\n");
	else
		printf("array B contains more 3-bit element\n");
	return 0;
}

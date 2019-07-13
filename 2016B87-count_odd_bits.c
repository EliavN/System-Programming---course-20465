#include <stdio.h>
#include <limits.h>
#define COUNT_ODD_BITS(num, counter)\
{\
	int curByte = 0, curBit=0;\
 	char *ptr = (char*)&num;\
 	for(; curByte<sizeof(num); curByte++, ptr++)\
		for(curBit=1 ; curBit<CHAR_BIT;curBit+=2)\
			if(*ptr & (1 << curBit))\
				counter++;\
}

int main()
{
	double num=43.21;
	int counter=0;
	COUNT_ODD_BITS(num,counter);
	printf("counter is: %d\n", counter);
	return 0; 
}

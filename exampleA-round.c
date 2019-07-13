#include <stdio.h>
#include <math.h>
#define SIZE 5
#define ROUND(number, fracPart, intPart)\
{\
	number = modf(number, &intPart) < 0.5 ? intPart : intPart +1;\
}

void round_array(double *arrSrc, int *arrDest, int arrLen)
{
	double fracPart, intPart;
	int i=0;
	for(; i<arrLen; i++){
		ROUND(arrSrc[i], fracPart, intPart);
		arrDest[i]=intPart;
	}	
}

int main()
{
	int i=0;
	double arrSrc[SIZE]={1.23,5.45,3.01,6.025,7.25};
	int arrDest[SIZE]={0};
	round_array(arrSrc, arrDest, SIZE);
	for(; i<SIZE; i++)
		printf("%.2f ,", arrSrc[i]);
	printf("\n");
	return 0;
}

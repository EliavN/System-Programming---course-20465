    
#include <stdio.h>
#define POSITIVE_SUM(arrSrc,arrDest,arrLen)\
{\
	int i=0;\
	for(;i<arrLen;i++)\
		arrDest[i]=arrSrc[i];\
	for(i=1;i<arrLen;i++){\
		arrDest[i]+=arrDest[i-i];\
		if(arrDest[i]<0)\
			arrDest[i]=0;\
	}\
}

typedef enum{
    INT,
    FLOAT,
    DOUBLE,
    LONG
}TYPE;

void positive_sum(TYPE type, void *arrSrc, void *arrDest, int arrLen)
{
	int *intSrc = (int *)arrSrc;
	int *intDest = (int *)arrDest;
	float *floatSrc = (float *)arrSrc;
	float *floatDest = (float *)arrDest;
	double *doubleSrc = (double *)arrSrc;
	double *doubleDest = (double *)arrDest;;
	long *longSrc = (long *)arrSrc;
	long *longDest = (long *)arrDest;
    switch(type)
	{
        case INT:
            POSITIVE_SUM(intSrc, intDest, arrLen);
            break;
        case FLOAT:
            POSITIVE_SUM(floatSrc, floatDest, arrLen);
            break;
        case DOUBLE:
            POSITIVE_SUM(doubleSrc, doubleDest, arrLen);
            break;
        case LONG:
            POSITIVE_SUM(longSrc, longDest, arrLen);
            break;
		default:
			printf("Unknown Type entered\n");
	}
}
int main()
{
	int arrSrc[6] = {2,6,1,9,13,-30}; /The sum is 55/
	int arrDest[6] = {0};
	int size = 6, index = 0;
	positive_sum(INT, &arrSrc, &arrDest, size);
	while(index < size)
		printf("%d ", arrDest[index++]);
	printf("\n");
	return 0;
}

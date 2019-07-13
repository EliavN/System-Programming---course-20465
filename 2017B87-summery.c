#include <stdio.h>

#define SUMMERY(arr, sum, arrLen)\
{\
	int i=0;\
	for(; i<arrLen; i++)\
		sum+=arr[i]; \
}
#define SIZE 10
typedef enum{
CHAR,
INT,
/*add any type you want*/
FLOAT,
DOUBLE,
LONG
}TYPE;

long double summery(TYPE type, void *arr, int arrLen)
{
	int *intPtrToArray = (int *)arr;
	float *floatPtrToArray = (float *)arr;
	double *doublePtrToArray = (double *)arr;
	long *longPtrToArray = (long *)arr;
	long double sum=0;
    switch(type)
	{
        case INT:
            SUMMERY(intPtrToArray, sum, arrLen);
            break;
        case FLOAT:
            SUMMERY(floatPtrToArray, sum, arrLen);
            break;
        case DOUBLE:
            SUMMERY(doublePtrToArray, sum, arrLen);
            break;
        case LONG:
            SUMMERY(longPtrToArray, sum, arrLen);
            break;
		default:
			printf("Unknown Type entered\n");
	}
	return sum;
}

int main()
{
	int arr[SIZE]={1,2,3,4,5,6,7,8,9,10};
	printf("sum is: %Lf\n", summery(INT,arr,SIZE));
	return 0;
}

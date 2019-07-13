#include <stdio.h>
#define UNKNOWN_TYPE -1
#define SIZE 5
#define FIND_3_MIN(num1, num2, num3, min)\
{\
	min = num1 < num2 ? num1 : num2;\
	min= min < num3 ? min : num3;\
}

typedef enum{
CHAR,
INT,
/*add any type you want*/
FLOAT,
DOUBLE,
LONG
}TYPE;

long double find_3_min(TYPE type, void *num1, void *num2, void *num3)
{
	long double min=0;
    switch(type)
	{
		 case CHAR:
            FIND_3_MIN(*( char*)num1, *( char*)num2, *( char*)num3, min);
            break;
        case INT:
            FIND_3_MIN(*(int*)num1, *(int*)num2, *(int*)num3, min);
            break;
        case FLOAT:
            FIND_3_MIN(*( float*)num1, *( float*)num2, *( float*)num3, min);
            break;
        case DOUBLE:
            FIND_3_MIN(*( double*)num1, *( double*)num2, *( double*)num3, min);
            break;
        case LONG:
            FIND_3_MIN(*( long*)num1, *( long*)num2, *( long*)num3, min);
            break;
		default:
			printf("Unknown Type entered\n");
	}
	return min;
}

int main()
{
	int i=0;
	int arr1[SIZE]={2,6,5,99,7}, arr2[SIZE]={0,9,8,-3,9}, arr3[SIZE]={5,6,1,12,0}, arr[SIZE]={0};
	for(;i<SIZE;i++)
		arr[i]=find_3_min(INT,&arr1[i],&arr2[i],&arr3[i]);
	for(i=0;i<SIZE;i++)
		printf("%d ,",arr[i]);
	printf("\n");
	return 0;
}		



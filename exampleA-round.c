#include <stdio.h>
#define ROUND(number, fracPart, intPart)\
{\
	number = modf(number, &intPart) < 0.5 ? intPart : intPart +1;\
}

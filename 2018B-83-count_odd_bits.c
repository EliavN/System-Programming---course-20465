#include <stdio.h>
#include <limits.h>
int count_odd_bits(void *num, int sizeOfType)
{
  int curByte = 0 , counter = 0;
  unsigned char *ptr = num;
  for(; curByte<sizeOfType; curByte++, ptr++)
    for(*ptr>>=1; *ptr; counter+=(*ptr & 1), *ptr>>=2);
  return counter;
}

int main()
{
  int num=149;
  printf("counter is: %d\n",count_odd_bits(num));
  return 0; 
}

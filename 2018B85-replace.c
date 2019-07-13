void PrintBits(unsigned int a);

int replace(void* number, int sizeOfType)
{
	unsigned char* ptr = number;
	int counter = 0, curBit = 0, curByte = 0, changed = 0;
	for(; curByte < sizeOfType; curByte++, ptr++){
		for(curBit = 0; curBit < BITS_IN_CHAR; curBit++){
			if(*ptr & 1 << curBit)
				counter++;
			else
				counter=0;
			if(counter == 2){
				*ptr &= ~(1<<--curBit);
				*ptr &= ~(1<<++curBit);
				counter = 0;
				changed = 1;
			}
		}
	}
	return changed;
}

void PrintBits(unsigned int a)
{
	unsigned int mask = 1 << (sizeof(unsigned int)*8-1);
	while(mask)
	{
	  if ((a&mask)==0)
	     printf("0");
	  else
	     printf("1");
   	  mask>>=1;
	}
	printf("\n");
}

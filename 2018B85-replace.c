int replace(void* number, int sizeOfType)
{
	unsigned char* ptr = number;
	int counter = 0, curBit = 0, curByte = 0, changed = 0;
	for(; curByte < sizeOfType; curByte++, ptr++){
		for(curBit = 0; curBit < BITS_IN_CHAR; curBit++){
			if(*ptr & 1 << curBit)
				counter++;
			else
				counter = 0;
			if(counter == 2){
				*ptr &= ~(1 << --curBit);
				*ptr &= ~(1 << ++curBit);
				counter = 0;
				changed = 1;
			}
		}
	}
	return changed;
}

int main(void)
{
	int a1 = 180;
	int changed = replace(&a1, sizeof(int));
	if(changed)
		printf("a1 was changed\n");
	return 0;
}

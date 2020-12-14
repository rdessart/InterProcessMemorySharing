#include "Interprocess.h"

void createStorage(const char* filepath, char** dataStorage, int size, char** lock)
/* This function create a datastorage space, of [size] bytes. In
 * addition the function create a lock variable [lock] and return it's
 * pointer.
 */
{
	FILE* output;
	output = fopen(filepath, "w");
	if(*lock == NULL)
	{
		*lock = (char*)malloc(sizeof(char));
	}
	**lock = (char)0x1;
	*dataStorage = (char *)malloc(sizeof(char));

	memset(*dataStorage, 0x00, size);
	printf("Data write to file :\n");
	printf("\tStorage is at position %lx\n", (long unsigned int)*dataStorage);
	printf("\tStorage is of size %d\n", size);
	printf("\tLock is at position %lx\n", (long unsigned int)*lock);

	fprintf(output, "%lx\n%d\n%lx", (long unsigned int)*dataStorage, size, (long unsigned int)lock);
	fclose(output);
}

void loadStorageFromFile(const char* filepath, int* outSize,  char** outDataStorage, char** outLock)
{
	FILE* input;
	input = fopen(filepath, "r");
	fseek(input, 0x00, SEEK_SET);
	long unsigned int dataAddress = 0;
	long unsigned int lockAddress = 0;
	
	fscanf(input, "%lx\n%d\n%lx", &dataAddress, outSize, &lockAddress);
	fclose(input);
	
	*outDataStorage = (char *)dataAddress;
	*outLock = (unsigned char *)lockAddress;
	
	printf("Data read from file :\n");
	printf("\tStorage is at position %lx\n", (long unsigned int)*outDataStorage);
	printf("\tStorage is of size %d\n", *outSize);
	printf("\tLock is at position %lx\n", (long unsigned int)*outLock);
}


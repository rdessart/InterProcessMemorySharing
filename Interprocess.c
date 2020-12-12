#include "Interprocess.h"

void createStorage(const char* filepath, char** dataStorage, int size,
	unsigned char** lock)
/* This function create a datastorage space, of [size] bytes. In
 * addition the function create a lock variable [lock] and return it's
 * pointer.
 */
{
	FILE* output;
	output = fopen(filepath, "w");
	if(*lock == NULL)
	{
		char* lockData = (char *)malloc(sizeof(char));
		*lock = lockData;
	}
	**lock = (char)0x1;
	char* data = (char*) malloc(size);
	*dataStorage = data;

	memset(dataStorage, 0x00, size); //clean up the memory region
	printf("Data write from file :\n");
	printf("\tStorage is at position %lx\n", dataStorage);
	printf("\tStorage is of size %d\n", size);
	printf("\tLock is at position %lx\n", lockAddress);
	
	long unsigned int dataAddress = (long unsigned int)dataStorage;
	long unsigned int lockAddress = (long unsigned int)lock;
	fprintf(output, "%lx\n%d\n%lx", dataAddress, size, lockAddress);
	fclose(output);
	//~ return dataStorage;
}

void loadStorageFromFile(const char* filepath, int* outSize, 
	char* outDataStorage, unsigned char* outLock)
{
	FILE* input;
	input = fopen(filepath, "r");
	fseek(input, 0x00, SEEK_SET);
	long unsigned int dataAddress = 0;
	long unsigned int lockAddress = 0;
	
	fscanf(input, "%lx\n%d\n%lx", &dataAddress, outSize, &lockAddress);
	fclose(input);
	
	outDataStorage = (char *)dataAddress;
	outLock = (unsigned char *)lockAddress;
	
	printf("Data read from file :\n");
	printf("\tStorage is at position %lx\n", outDataStorage);
	printf("\tStorage is of size %d\n", *outSize);
	printf("\tLock is at position %lx\n", outLock);
}


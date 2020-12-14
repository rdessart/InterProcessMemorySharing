#include <stdio.h>
#include "Interprocess.h"

int main(int argc, char **argv)
{
	const char* filepath = "iobuffer.buf";
	int size = sizeof(int) * 3;
	char* lock = NULL;
	char* dataStorage = NULL;
	createStorage(filepath, &dataStorage, size, &lock);
	printf("Lock is at position %lx\n", (long unsigned int)lock);
	printf("Data is at position %lx\n", (long unsigned int)dataStorage);

	char *lock2 = NULL;
	char *dataStorage2 = NULL;
	int size2;
	loadStorageFromFile(filepath, &size2, &dataStorage2, &lock2);
	printf("Lock is at position %lx\n", (long unsigned int)lock2);
	printf("Data is at position %lx\n", (long unsigned int)dataStorage2);

	free(dataStorage);
	free(lock);

	return 0;
}


#ifndef __INTERPROCESS_H__
#define __INTERPROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct InterprocessInfoStruct{
	const char* filename;
	int size;
	char* data;
	unsigned char* lock;
};

void createStorage(const char* filepath, char** dataStorage, int size, char** lock);
void loadStorageFromFile(const char* filepath, int* outSize, char** outDataStorage, char** outLock);

#endif

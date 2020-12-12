/*
 * main.c
 * 
 * Copyright 2020 Romain DESSART <rdessart@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h> //debug
#include "Interprocess.h"

//~ void foo(int **data)
//~ {
	//~ int *dataPointer = (int *)malloc(sizeof(int));
	//~ *dataPointer =  163;
	//~ printf("Addess in function is %lx\n", dataPointer);
	//~ *data = dataPointer;
//~ }


int main(int argc, char **argv)
{
	const char* filepath = "iobuffer.buf";
	int size = sizeof(int) * 3;
	unsigned char* lock = NULL;
	printf("CREATING STORAGE\n");
	char* dataStorage = NULL;
	createStorage(filepath, &dataStorage, size, &lock);
	printf("Lock is at position %lx\n", *lock);
	printf("Data is at position %lx\n", *dataStorage);
	//~ printf("LOAD DATA FROM FILE\n");
	//~ char *dataStorage2 = NULL;
	//~ unsigned char* lock2 = NULL;
	//~ int size2 = 0;
	//~ loadStorageFromFile(filepath, &size2, dataStorage2, lock2);
	//~ printf("Lock is at position %lx\n", lock2);
	//~ printf("Data is at position %lx\n", dataStorage2);
	//~ //free the data storage and the lock to avoid memory leak
	//~ printf("FREEING DATA\n");
	//~ free(dataStorage);
	//~ free(lock);
	
	
	//--DEBUG
	//~ unsigned long int datapointer = 0;
	//~ int* data = NULL;
	//~ foo(&data);
	//~ printf("address as %lx\n", data);
	//~ printf("value  = %d\n", *data);
	//~ *data = 1756;
	//~ printf("value  = %d\n", *data);
	//--!DEBUG
	return 0;
}


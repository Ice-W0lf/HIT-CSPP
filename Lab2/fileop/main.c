#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fileop.h"

int main(int argc, char *argv[])
{
	char option[100], src[100], dest[100];
	strcpy(option, argv[1]);	// 对2.1.1，2.1.2，2.2分别设置了三个选项 1，2，3
	MyRecord record[100];
	memset(record, 0, sizeof(record));
	int recordNum = 0;
	if (argc == 4)
	{
		strcpy(src, argv[2]);
		strcpy(dest, argv[3]);
	}
	if (strcmp(option, "1") == 0)
	{
		recordNum = txtRead(src, record);
		txtWrite(dest, record, recordNum);
	}
	else if (strcmp(option, "2") == 0)
	{
		char* fltxt = "float.txt";
		char* flbin = "float.dat";
		char* chtxt = "char.txt";
		char* chbin = "char.bin";
		const int SIZE = 100;
		float fl[SIZE];
		char ch[SIZE];
		srand(time(0));
		for (int i = 0; i < SIZE; ++i)
			fl[i] = 0 + 1.0 * (rand() % RAND_MAX) / RAND_MAX * (1 - 0);
		for (int i = 0; i < SIZE; ++i)
			ch[i] = rand() % ('z' - '0') + '0';
		binWrite(fltxt, flbin, chtxt, chbin, fl, ch);
		binRead(flbin);
	}
	else if (strcmp(option, "3") == 0)
	{
		recordNum = structBinRead(src, record);
		printf("%d structures read in.\n", recordNum);
		structBinWrite(dest, record, recordNum);
	}
	else
	{
		printf("Unknown command line arguments %d.\n", 1);
		exit(1);
	}

	return 0;
}

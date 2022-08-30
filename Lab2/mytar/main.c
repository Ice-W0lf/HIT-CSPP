#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>
#include "mytar.h"

int main(int argc, char *argv[])
{
	char option[10], src[MAX_PATH_LEN], dest[MAX_PATH_LEN];
	if (argc != 4)
	{
		printf("Wrong number of input arguments.\n");
		exit(1);
	}
	strcpy(option, argv[1]);
	realpath(argv[2], src);
	realpath(argv[3], dest);
	if (strcmp(option, "-c") == 0)
	{
		pack(src, dest);
	}
	else if (strcmp(option, "-x") == 0)
	{
		unpack(src, dest);
	}
	return 0;
}
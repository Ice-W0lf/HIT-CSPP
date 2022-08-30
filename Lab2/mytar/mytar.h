#ifndef __MYTAR_H__
#define __MYTAR_H__

#define MAX_PATH_LEN 256
#define MAX_NAME_LEN 128
#define MAX_FILE_NUM 256

#include <stdbool.h>

typedef unsigned char byte;

typedef struct _File
{
	char dir[MAX_PATH_LEN];
	char name[MAX_NAME_LEN];
	bool isDir;
	byte *data;
	long size;
} File;

void pack(const char *SRC, const char *DEST);
void packRec(const char *SRC, const char *DEST, const char *DIRE);
File *createFile();
File *getFile(const char *SRC, const char *DIRE, struct dirent *dp);
void writeFile(const char *DEST, File *f);
void src2dest(const char *SRC, const char *path, char *destPath);
void unpack(const char *SRC, const char *DEST);

#endif

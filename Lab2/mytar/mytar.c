#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>
#include "mytar.h"

void pack(const char *SRC, const char *DEST)
{
	File *Ancester = createFile();
	strcpy(Ancester->dir, ".");
	char src[MAX_PATH_LEN];
	strcpy(src, SRC);
	strcpy(Ancester->name, basename(src));
	Ancester->isDir = true;
	Ancester->size = 0;
	Ancester->data = NULL;
	writeFile(DEST, Ancester);
	char path[MAX_PATH_LEN];
	realpath(SRC, path);
	packRec(path, DEST, path);
}

void packRec(const char *SRC, const char *DEST, const char *DIRE)	// DIRE is the path of the parent folder
{
	DIR * dir = opendir(DIRE);
	struct dirent *dp;
	while ((dp = readdir(dir)) != NULL)
	{
		File *f = getFile(SRC, DIRE, dp);
		writeFile(DEST, f);
		if (f && f->isDir)
		{
			char folderPath[MAX_PATH_LEN];
			sprintf(folderPath, "%s/%s", DIRE, f->name);
			packRec(SRC, DEST, folderPath);
		}
	}
	closedir(dir);
}

File *createFile()
{
	File *f = (File *)malloc(sizeof(File));
	memset(f->dir, 0, sizeof(f->dir));
	memset(f->name, 0, sizeof(f->name));
	f->isDir = true;
	f->size = 0;
	f->data = NULL;
	return f;
}

File *getFile(const char *SRC, const char *DIRE, struct dirent *dp)	// DIRE is the parent folder
{
	if (dp->d_name[0] == '.')
	{
		return NULL;
	}
	File *f = createFile();
	char dir[MAX_PATH_LEN];
	memset(dir, 0, sizeof (dir));
	src2dest(SRC, DIRE, dir);
	strcpy(f->dir, dir);
	strcpy(f->name, dp->d_name);
	struct stat st;
	if (dp->d_type == DT_DIR)
	{
		f->isDir = true;
		f->data = NULL;
		f->size = 0;
	}
	else
	{
		f->isDir = false;
		char path[MAX_PATH_LEN + MAX_NAME_LEN];
		sprintf(path, "%s/%s", DIRE, f->name);
		FILE *fp = fopen(path, "rb");
		fseek(fp, 0, SEEK_END);
		long size = ftell(fp);
		f->size = size;
		if (size != 0)
		{
			f->data = (byte *)malloc(size * sizeof(byte));
			fseek(fp, 0, SEEK_SET);
			fread(f->data, size, 1, fp);
		}
		fclose(fp);
	}
	return f;
}

void writeFile(const char *DEST, File *f)
{
	if (f == NULL)
	{
		return;
	}
	FILE *fp = fopen(DEST, "ab");
	fwrite(f, sizeof(File), 1, fp);
	if (!f->isDir && f->size!=0)
	{
		fwrite(f->data, sizeof(byte) * f->size, 1, fp);
	}
	fclose(fp);
}

void src2dest(const char *SRC, const char *path, char *destPath)
{
	if (strcmp(SRC, path) == 0)
	{
		strcpy(destPath, ".");
	}
	else
	{
		int start = strlen(SRC);
		int lenP = strlen(path);
		destPath[0] = '.';
		int j = 1;
		for (int i = start; i < lenP; ++i)
		{
			destPath[j++] = path[i];
		}
		destPath[j] = '\0';
	}
}

void unpack(const char *SRC, const char *DEST)
{
	FILE *fp = fopen(SRC, "rb");
	fseek(fp, 0, SEEK_SET);
	File *f = createFile();
	fread(f, sizeof(File), 1, fp);
	chdir(DEST);
	mkdir(f->name, 0777);
	char dest[MAX_PATH_LEN];
	sprintf(dest, "%s/%s", DEST, f->name);
	while(1)
	{
		if (feof(fp))
		{
			break;
		}
		fread(f, sizeof(File), 1, fp);
		chdir(dest);
		chdir(f->dir);
		if (f->isDir)
		{
			mkdir(f->name, 0777);
		}
		else
		{
			FILE *fpNew = fopen(f->name, "wb");
			if (f->size > 0)
			{
				byte *data = (byte *)malloc(f->size * sizeof(byte));
				fread(data, f->size * sizeof(byte), 1, fp);
				fwrite(data, f->size * sizeof(byte), 1, fpNew);
			}
			fclose(fpNew);
		}
	}
	fclose(fp);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileop.h"

/* 从文本文件读入结构体数组，返回结构体数目*/
int txtRead(char* path, MyRecord* rp)
{
	FILE* fp = fopen(path, "r");
	MyRecord rcd;
	char temp[1000];		// 暂存读入的一行字符串
	int ind = 0;
	const int NUM = 4;		// 结构体中浮点数组的长度
	while (fgets(temp, sizeof(temp), fp) != NULL)
	{
		float s[4];
		sscanf(temp, "%lu %s %f %f %f %f", &rcd.id, rcd.name, &s[0], &s[1], &s[2], &s[3]);
		for (int i = 0; i < NUM; ++i)
		{
			rcd.score[i] = s[i];
		}
		rp[ind++] = rcd;
	}
	for (int i = 0; i < ind; ++i)		// 打印到屏幕
	{
		printf("%lu %s", rp[i].id, rp[i].name);
		for (int j = 0; j < NUM; ++j)
		{
			printf(" %.1f", rp[i].score[j]);
		}
		printf("\n");
	}
	fclose(fp);
	return ind;
}

/*将结构体写入文本文件*/
void txtWrite(char* path, MyRecord* rp, int recNum)
{
	FILE* fp = fopen(path, "w");
	const int NUM = 4;
	for (int i = 0; i < recNum; ++i)
	{
		fprintf(fp, "%lu %s", rp[i].id, rp[i].name);
		for (int j = 0; j < NUM; ++j)
		{
			fprintf(fp, " %.1f", rp[i].score[j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

/*将浮点数组、字符数组分别写入到二进制文件、文本文件*/
void binWrite(char* fltxt, char* flbin, char* chtxt, char* chbin, float* fl, char* ch)
{
	FILE* fpft = fopen(fltxt, "w");
	FILE* fpfb = fopen(flbin, "wb");
	FILE* fpct = fopen(chtxt, "w");
	FILE* fpcb = fopen(chbin, "wb");
	const int SIZE = 100;			// 数组大小
	for (int i = 0; i < SIZE; ++i)
	{
		fprintf(fpft, "%f\t", fl[i]);
	}
	fwrite(fl, sizeof(float) * SIZE, 1, fpfb);
	for (int i = 0; i < SIZE; ++i)
	{
		fprintf(fpct, "%c\t", ch[i]);
	}
	fwrite(ch, sizeof(char) * SIZE, 1, fpcb);
	fclose(fpft);
	fclose(fpfb);
	fclose(fpct);
	fclose(fpcb);
}

/*从二进制文件读入浮点数组*/
void binRead(char* path)
{
	FILE* fp = fopen(path, "rb");
	const int SIZE = 100;
	float fl[SIZE];
	fread(fl, sizeof(float) * SIZE, 1, fp);
	for (int i=0; i<SIZE; ++i)
	{
		printf("%.3f\t", fl[i]);
	}
	printf("\n");
	fclose(fp);
}

/*从二进制文件读入结构体数组，返回结构体数目*/
int structBinRead(char* path, MyRecord* rp)
{
	FILE* fp = fopen(path, "rb");
	MyRecord rcd;
	char temp[1000];
	int ind = 0;
	while (fread(&rcd, sizeof(MyRecord), 1, fp) == 1)
	{
		rp[ind++] = rcd;
	}
	return ind;
}

/*将结构体数组写入二进制文件*/
void structBinWrite(char* path, MyRecord* rp, int recNum)
{
	FILE* fp = fopen(path, "wb");
	fwrite(rp, sizeof(MyRecord), recNum, fp);
	fclose(fp);
	return;
}

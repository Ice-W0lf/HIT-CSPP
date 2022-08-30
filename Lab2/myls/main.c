#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#define MAX_PATH_LENGTH 2048
#define MAX_FILENAME_LENGTH 512

/*进入PATH内，打印文件列表*/
void shallowLS(const char *PATH)
{
	DIR *dir = opendir(PATH);
	struct dirent *dptr;
	while ((dptr = readdir(dir)) != NULL)
	{
		if (dptr->d_name[0] == '.')	// 忽略"."和".."
		{
			continue;
		}
		printf("%s  ", dptr->d_name);
	}
	closedir(dir);
	return;
}

/*进入PATH内，打印文件列表，并对其中的文件夹做递归*/
void deepLS(const char *PATH)
{
	DIR *dir = opendir(PATH);
	struct dirent *dptr;
	while ((dptr = readdir(dir)) != NULL)
	{
		if (dptr->d_name[0] == '.')
		{
			continue;
		}
		char fullPath[MAX_PATH_LENGTH];
		sprintf(fullPath, "%s/%s", PATH, dptr->d_name); // 得到绝对路径
		struct stat st;
		if (lstat(fullPath, &st) == -1)
		{
			perror("lstat");
			exit(-1);
		}
		if (S_ISDIR(st.st_mode))	// 如果dptr所指的是文件夹
		{
			printf("%s:\n", fullPath);	// 打印该文件夹的绝对路径
			shallowLS(fullPath);	// 打印该文件夹的文件列表
			printf("\n\n");
			deepLS(fullPath);		// 对文件夹内的各文件夹做递归操作
		}
	}
	closedir(dir);
}

void myls(const char *PATH, bool ifRec)
{
	if (!ifRec)		// 非递归模式
	{
		shallowLS(PATH);
		printf("\n");
	}
	else			// 递归模式
	{
		shallowLS(PATH);	// 打印本文件夹的文件列表
		printf("\n\n");
		deepLS(PATH);		// 对PATH下的文件，文件夹进行递归打印
	}

	return;
}


int main(int argc, char *argv[])
{
	char path[argc][MAX_PATH_LENGTH];	// 可以接收多个待处理路径
	int pathNum = 0;
	bool ifRec = false;		// 控制是否递归
	for (int i=1; i<argc; ++i)
	{
		if (strcmp(argv[i], "-R") == 0)
		{
			ifRec = true;
		}
		else
		{
			strcpy(path[pathNum++], argv[i]);
		}
	}
	if (pathNum == 0)
	{
		strcpy(path[pathNum++], ".");	// 如果没有输入路径，默认为当前工作路径
	}
	for (int i=0; i<pathNum; ++i)
	{
		if (pathNum > 1 || ifRec)	// 只有当路径数>1或处于递归模式时，需要打印路径名
		{
			printf("%s:\n", path[i]);
		}
		if (opendir(path[i]) == NULL)	// 无法打开路径
		{
			perror("Open");
		}
		else
		{
			int len = strlen(path[i]); 
			if (path[i][len-1] == '/')	// 除去尾部多余的'/'
			{
				path[i][len-1] = '\0';
			}
			myls(path[i], ifRec);
		}
		if (i != pathNum-1 && !ifRec)
		{
			printf("\n");
		}
	}

	return 0;
}

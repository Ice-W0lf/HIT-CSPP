#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"

#define __debug__		// for printing data
//you must specify an int to indicate the data type to be sorted
int dataType = STUDENT;

//utilites to be used in main
//provide compare function
int cmp(ElemType *a, ElemType *b);
//to generate random data
void generateData(ElemType *A, int num);
void generateSameData(ElemType *A, double rate);
void randName(char *name);
void randID(char *id);
//to output small array in __debug__
void output(ElemType A[], int n, char *info);

int main(int argc, char *argv[])
{
//	if (argc < 2)
//	{
//		return 1;
//	}
//	size_t t1, t2;
//	int size;
//	sscanf(argv[1], "%d", &size);
//	if (size <= 0)
//	{
//		return 0;
//	}
//	if (argc > 2)
//	{
//		if (strcmp(argv[2], "-i") == 0)
//			dataType = INT;
//		else if (strcmp(argv[2], "-f") == 0)
//			dataType = FLOAT;
//		else if (strcmp(argv[2], "-d") == 0)
//			dataType = DOUBLE;
//		else if (strcmp(argv[2], "-s") == 0)
//			dataType = STUDENT;
//	}
//	ElemType *ori, *toSort;
//	ori = (ElemType *)malloc(sizeof(ElemType)*size);
//	toSort = (ElemType *)malloc(sizeof(ElemType)*size);
//	generateData(ori, size);
//	int (*cmpare)(ElemType *a, ElemType *b);
//	cmpare = &cmp;
//
//	// SelectSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "SelectSort: before");
//#endif
//	t1 = clock();
//	SelectSort(toSort, size, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "SelectSort: after");
//#endif
//	printf("SelectSort runs in %f seconds for %d objects\n\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);
//
//	// BubbleSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "BubbleSort: before");
//#endif
//	t1 = clock();
//	BubbleSort(toSort, size, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "BubbleSort: after");
//#endif
//	printf("BubbleSort runs in %f seconds for %d objects\n\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);
//
//	// InsertSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "InsertSort: before");
//#endif
//	t1 = clock();
//	InsertSort(toSort, size, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "InsertSort: after");
//#endif
//	printf("InsertSort runs in %f seconds for %d objects\n\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);
//
//	//QuickSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "QuickSort: before");
//#endif
//	t1 = clock();
//	QuickSort(toSort, 0, size-1, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "QuickSort: after");
//#endif
//	printf("QuickSort runs in %f seconds for %d objects\n\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);
//
//	// MergeSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "MergeSort: before");
//#endif
//	t1 = clock();
//	MergeSort(toSort, 0, size-1, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "MergeSort: after");
//#endif
//	printf("MergeSort runs in %f seconds for %d objects\n\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);
//
//	// HeapSort
//	memcpy(toSort, ori, sizeof(ElemType)*size);
//#ifdef __debug__
//	output(toSort, size, "HeapSort: before");
//#endif
//	t1 = clock();
//	HeapSort(toSort, size, cmpare);
//	t2 = clock();
//#ifdef __debug__
//	output(toSort, size, "HeapSort: after");
//#endif
//	printf("HeapSort runs in %f seconds for %d objects\n", (t2 - t1)/(double)CLOCKS_PER_SEC, size);

	// QuickSort on different shape of data
	dataType = DOUBLE;
	int (*cmpare)(ElemType *a, ElemType *b);
	cmpare = &cmp;
	QuickSortTest(cmpare);

	return 0;
}

int cmp(ElemType *a, ElemType *b)
{
	switch (dataType)
	{
	case INT:
		if (*((int *)a) == *((int *)b))
			return 0;
		else if (*((int *)a) > *((int *)b))
			return 1;
		else
			return -1;
	case FLOAT:
		if (*((float *)a) == *((float *)b))
			return 0;
		else if (*((float *)a) > *((float *)b))
			return 1;
		else
			return -1;
	case DOUBLE:
		if (*((double *)a) == *((double *)b))
			return 0;
		else if (*((double *)a) > *((double *)b))
			return 1;
		else
			return -1;
	case STUDENT:
		if (((STU *)a)->total == ((STU *)b)->total)
			return 0;
		else if (((STU *)a)->total > ((STU *)b)->total)
			return 1;
		else
			return -1;
	default:
		return 2;
	}
}

void generateData(ElemType *A, int num)
{
	switch (dataType)
	{
	case INT:
		for (int i=0; i<num; ++i)
		{
			*((int *)(A+i)) = (int)rand()%(10*num);
		}
		break;
	case FLOAT:
		for (int i=0; i<num; ++i)
		{
			*((float*)(A+i)) = (rand()%10000)/((double) 100);
		}
		break;
	case DOUBLE:
		for (int i=0; i<num; ++i)
		{
			*((double *)(A+i)) = (rand()%10000)/((double) 100);
		}
		break;
	case STUDENT:
		for (int i=0; i<num; ++i)
		{
			STU *stu = (STU *)(A+i);
			randName(stu->name);
			randID(stu->id);
			stu->total = 0;
			for (int j=0; j<5; ++j)
			{
				stu->score[j] = (rand()%10000)/((double) 100);
				stu->total += stu->score[j];
			}
		}
	}
}

void randName(char *name)
{
	char ALPHA[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char alpha[26]="abcdefghijklmnopqrstuvwxyz";
	int len = 3 + rand()%16;
	name[0] = ALPHA[rand()%26];
	for(int i=1; i<len; i++)
	{
		name[i] = alpha[rand()%26];
	}
	name[len] = '\0';
}

void randID(char *id)
{
	char buf[20] = "2021031";
	char buf1[3];
	char buf2[5];
	int classNo = rand()%100;
	int stuNo = rand()%10000;
	sprintf(buf1, "%02d", classNo);
	buf1[2] = '\0';
	sprintf(buf2, "%04d", stuNo);
	buf2[4] = '\0';
	strcat(buf, buf1);
	strcat(buf, buf2);
	strcpy(id, buf);
}

//to output small array in __debug__
void output(ElemType A[], int n, char *info)
{
	printf("%s\n", info);
	switch (dataType)
	{
	case INT:
		for (int i=0; i<n; ++i)
		{
			printf("%d  ", *((int*)(A+i)));
		}
		printf("\n");
		break;
	case FLOAT:
		for (int i=0; i<n; ++i)
		{
			printf("%5.2f  ", *((float *)(A+i)));
		}
		printf("\n");
		break;
	case DOUBLE:
		for (int i=0; i<n; ++i)
		{
			printf("%5.2f  ", *((double *)(A+i)));
		}
		printf("\n");
		break;
	case STUDENT:
		for (int i=0; i<n; ++i)
		{
			STU *stu = (STU *)(A+i);
			printf("%s  %-20s  ", stu->id, stu->name);
			for (int j=0; j<5; ++j)
			{
				printf("%5.2f  ", stu->score[j]);
			}
			printf("%6.2f\n", stu->total);
		}
		break;
	}
}
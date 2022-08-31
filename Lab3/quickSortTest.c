#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

//#define __debug__

enum
{
	SIZE = 1000000
};
ElemType toSort[SIZE];

void generateSameData(ElemType *A, double rate);
void QuickSortTest(int (*cmp)(ElemType *, ElemType *));
void outputDouble(ElemType A[], int n, char *info);
void QuickSort3Ways(ElemType *A, int low, int high, int (*cmp)(ElemType *, ElemType *));

void QuickSortTest(int (*cmp)(ElemType *, ElemType *))
{
	size_t t1, t2;
	double rates[] = {0, 0.05, 0.10, 0.20, 0.40, 0.80};
	for (int i=0; i<6; ++i)
	{
		memset(toSort, 0, sizeof (ElemType )*SIZE);
		generateSameData(toSort, rates[i]);
#ifdef __debug__
		outputDouble(toSort, SIZE, "QuickSort: before");
#endif
		t1 = clock();
		QuickSort3Ways(toSort, 0, SIZE - 1, cmp);
		t2 = clock();
#ifdef __debug__
		outputDouble(toSort, SIZE, "QuickSort: after");
#endif
		printf("QuickSort runs in %f seconds for %d objects with %.0lf%% same data.\n",
				(t2 - t1)/(double)CLOCKS_PER_SEC, SIZE, rates[i]*100);
	}
}

void generateSameData(ElemType *A, double rate)
{
	srand(time(0));
	const ElemType SAME = (rand()%10000)/((double) 100);
	for (int i=0; i<SIZE; ++i)
	{
		if ((rand()%10000)/((double) 10000) < rate)
		{
			*((ElemType *)(A+i)) = SAME;
		}
		else
		{
			*((ElemType *)(A+i)) = (rand()%10000)/((ElemType) 100);
		}
	}
}

void outputDouble(ElemType A[], int n, char *info)
{
	printf("%s\n", info);
	for (int i=0; i<n; ++i)
	{
		printf("%5.2f  ", *((ElemType *)(A+i)));
	}
	printf("\n");
}

void QuickSort3Ways(ElemType *A, int low, int high, int (*cmp)(ElemType *, ElemType *))
{
	if (low >= high) return;
	ElemType pivot = A[low];
	int l = low;
	int h = high + 1;
	int i = low + 1;
	while (i < h)
	{
		if (cmp(A+i, &pivot) < 0)
		{
			Swap(A, i, l+1);
			i++;
			l++;
		}
		else if (cmp(A+i, &pivot) > 0)
		{
			Swap(A, i, h-1);
			h--;
		}
		else
		{
			i++;
		}
	}
	Swap(A, low, l);
	QuickSort(A, low, l-1, cmp);
	QuickSort(A, h, high, cmp);
}
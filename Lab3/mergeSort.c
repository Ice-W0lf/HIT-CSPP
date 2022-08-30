#include <stdlib.h>
#include <string.h>
#include "sort.h"

void MergeSort(ElemType *A, int i, int j, int (*cmp)(ElemType *, ElemType *))
{
	if (i >= j) return;
	int mid = (i + j)/2;
	MergeSort(A, i, mid, cmp);
	MergeSort(A, mid + 1, j, cmp);
	ElemType *temp = (ElemType *)malloc(sizeof(ElemType)*(j - i + 1));
	int l = i;
	int h = mid + 1;
	int v = 0;
	while (l <= mid && h <= j)
	{
		if (cmp(A + l, A + h) <= 0)
		{
			temp[v++] = A[l++];
		}
		else
		{
			temp[v++] = A[h++];
		}
	}
	if (l <= mid)
	{
		memcpy(temp + v, A + l, (mid - l + 1)*sizeof(ElemType));
	}
	if (h <= j)
	{
		memcpy(temp + v, A + h, (j - h + 1)*sizeof(ElemType));
	}
	memcpy(A + i, temp, (j - i + 1)*sizeof(ElemType));
	free(temp);
}
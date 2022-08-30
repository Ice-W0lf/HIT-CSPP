#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void SelectSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *))
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (cmp(A + min, A + j) > 0)
			{
				min = j;
			}
		}
		Swap(A, i, min);
	}
}

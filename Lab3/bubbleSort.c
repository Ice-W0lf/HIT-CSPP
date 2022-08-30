#include "sort.h"

void BubbleSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *))
{
	for (int i=0; i<n; ++i)
	{
		for (int j=i+1; j<n; ++j)
		{
			if (cmp(A+i, A+j) >0)
			{
				Swap(A, i, j);
			}
		}
	}
}
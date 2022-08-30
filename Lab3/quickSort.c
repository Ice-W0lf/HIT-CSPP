#include "sort.h"

void QuickSort(ElemType *A, int low, int high, int (*cmp)(ElemType *, ElemType *))
{
	if (low >= high) return;
	ElemType pivot = A[low];
	int l = low;
	int h = high;
	while (l < h)
	{
		while (l<h && cmp(A+h, &pivot)>=0)
			h--;
		A[l] = A[h];
		while (l<h && cmp(A+l, &pivot)<=0)
			l++;
		A[h] = A[l];
	}
	A[l] = pivot;
	QuickSort(A, low, l-1, cmp);
	QuickSort(A, l+1, high, cmp);
}
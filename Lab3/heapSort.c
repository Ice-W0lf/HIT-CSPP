#include "sort.h"

void HeapSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void max_heapify(ElemType *A, int start, int end, int (*cmp)(ElemType *, ElemType *));

void HeapSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *))
{
	// 从最后一个父节点开始构建最大堆
	for (int i = n/2 - 1; i >= 0; --i)
	{
		max_heapify(A, i, n - 1, cmp);
	}
	for (int i = n - 1; i > 0; --i)
	{
		Swap(A, 0, i);        // 每次把堆顶放到有序序列的前一位
		max_heapify(A, 0, i - 1, cmp);    // 重新构建最大堆
	}
}

void max_heapify(ElemType *A, int start, int end, int (*cmp)(ElemType *, ElemType *))
{
	int dad = start;
	int son = dad*2 + 1;
	while (son <= end)
	{
		if (son + 1 <= end && cmp(A + son + 1, A + son) > 0)
		{
			++son;
		}
		if (cmp(A + dad, A + son) > 0)
		{
			return;
		}
		else
		{
			Swap(A, dad, son);
			dad = son;
			son = dad*2 + 1;
		}
	}
}

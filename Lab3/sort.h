#ifndef __SORT_H__
#define __SORT_H__

#define INT 0
#define FLOAT 1
#define DOUBLE 2
#define STUDENT 3

typedef struct _STU
{
	char  id[20];
	char  name[20];
	float score[5];
	float total;
} STU;

#define __QuickSortTest__		// for test QuickSort on diffrent shape of data

#ifndef __QuickSortTest__
typedef STU ElemType;
#else
typedef double ElemType;
#endif

void SelectSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void BubbleSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void InsertSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void MergeSort(ElemType *A, int i, int j, int (*cmp)(ElemType *, ElemType *));
void QuickSort(ElemType *A, int low, int high, int (*cmp)(ElemType *, ElemType *));
void HeapSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void QuickSortTest(int(*cmp)(ElemType *, ElemType *));

void Swap(ElemType *A, int i, int j);

#endif

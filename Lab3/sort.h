#ifndef __SORT_H__
#define __SORT_H__

#define INT 0
#define FLOAT 1
#define DOUBLE 2
#define STUDENT 3

typedef struct STU
{
	char  id[20];
	char  name[20];
	float score[5];
	float total;
}STU;

typedef STU ElemType;

void SelectSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void BubbleSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void InsertSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));
void MergeSort(ElemType *A, int i, int j, int (*cmp)(ElemType *, ElemType *));
void QuickSort(ElemType *A, int low, int high, int (*cmp)(ElemType *, ElemType *));
void HeapSort(ElemType *A, int n, int (*cmp)(ElemType *, ElemType *));

void Swap(ElemType *A, int i, int j);

#endif

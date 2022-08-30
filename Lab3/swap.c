#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void Swap(ElemType *A, int i, int j)
{
	ElemType tmp = *(A+i);
	*(A+i) = *(A+j);
	*(A+j) = tmp;
}

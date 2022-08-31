#include <stdlib.h>
#include "sort.h"
#include "stucourse.h"

void sort(Student *A, int n, int ind);
int cmp(Student *a, Student *b, int ind);

void sort(Student *A, int n, int ind)
{
	for (int i=1; i<n; ++i)
	{
		Student cur = A[i];
		int j = i-1;
		while (j >= 0 && cmp(A+j, &cur, ind)>0)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = cur;
	}
}

int cmp(Student *a, Student *b, int ind)
{
	if (a->score[ind] == b->score[ind])
		return 0;
	else if (a->score[ind] > b->score[ind])
		return 1;
	else
		return -1;
}
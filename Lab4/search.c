#include <string.h>
#include "op.h"
#include "stucourse.h"

int searchByName(Student *stu, int n, char name[MAX_STU_NAME_LEN])
{
	for (int i=0; i<n; ++i)
	{
		Student *this = stu + i;
		if (strcmp(this->name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int searchById(Student *stu, int n, unsigned long id)
{
	for (int i=0; i<n; ++i)
	{
		Student *this = stu + i;
		if (this->id == id)
		{
			return i;
		}
	}
	return -1;
}
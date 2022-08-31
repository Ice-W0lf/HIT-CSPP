#include <stdio.h>
#include "stucourse.h"
#include "op.h"

int main()
{
	int choice = 0;
	Student *stu = NULL;
	int stuNum = 0;
	while (1)
	{
		printGreeting();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			stu = input(stu, &stuNum);
			break;
		case 2:
			queryByName(stu, stuNum);
			break;
		case 3:
			queryById(stu, stuNum);
			break;
		case 4:
			modify(stu, stuNum);
			break;
		case 5:
			delete(stu, &stuNum);
			break;
		case 6:
			showStu(stu, stuNum);
			break;
		case 7:
			showCourse(stu, stuNum);
			break;
		case 8:
			sortByCourse(stu, stuNum);
			break;
		case 9:
			analyse(stu, stuNum);
			break;
		case 10:
			save(stu, stuNum);
			break;
		case 11:
			stu = load(stu, &stuNum);
			break;
		case 0:
			printExit();
			return 0;
		default:
			printErrorChoice();
		}
	}
}

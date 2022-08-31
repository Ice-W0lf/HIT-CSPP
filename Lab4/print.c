#include <stdio.h>
#include <stdbool.h>
#include "stucourse.h"
#include "op.h"

void printGreeting()
{
	printf("1. Append record\n"
		   "2. Search by name\n"
		   "3. Search by ID\n"
		   "4. Modify by ID\n"
		   "5. Delete by ID\n"
		   "6. Caculate total and average score of every student\n"
		   "7. Caculate average score of every course\n"
		   "8. Sort in descending order by course score\n"
		   "9. Statistic analysis for every course\n"
		   "10.Save record\n"
		   "11.Load record\n"
		   "0. Exit\n"
		   "Welcome to student score management system!\n"
		   "Please enter your choice:");
}

void printHeader(bool withSum)
{
	printf("%-16s", "ID");
	printf("%-12s", "name");
	for (int i=0; i<COURSE_NUM; ++i)
	{
		printf("%-6s", courses[i]);
	}
	if (withSum)
	{
		printf("%-6s", "Total");
	}
	printf("\n");
}

void printStu(Student *stu, int i, bool withSum)
{
	Student *this = stu + i;
	printf("%-16lu", this->id);
	printf("%-12s", this->name);
	for (int j=0; j < COURSE_NUM; ++j)
	{
		printf("%-6.1f", this->score[j]);
	}
	if (withSum)
	{
		float sum = 0;
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			sum += this->score[j];
		}
		printf("%-6.1f", sum);
	}
	printf("\n");
}

void printErrorChoice()
{
	printf("Unknown choice, please reinput.\n");
	printPause();
}

void printPause()
{
	printf("Press ENTER to continue...\n");
	empty_stdin();
	getchar();
}

void empty_stdin()
{
	int c;
	do
	{
		c = getchar();
	} while (c!= '\n' && c != EOF);
}
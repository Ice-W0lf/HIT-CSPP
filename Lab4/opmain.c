#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "sort.h"

Student *input(Student *stu, int *stuNum)        // #1
{
	int n;
	printf("Input the number of students to be appended (<= %d):", MAX_STU_NUM - *stuNum);
	scanf("%d", &n);
	if (n > MAX_STU_NUM)
	{
		printf("Student num out of range.\n");
		printPause();
		return stu;
	}
	stu = (Student *)realloc(stu, (n+*stuNum)*sizeof(Student));
	int i = 0;
	while (i < n)
	{
		Student *this = stu + *stuNum + i;
		printf("Input student %d's id:", i + 1);
		scanf("%ld", &this->id);
		printf("Input student %d's name:", i + 1);
		scanf("%s", this->name);
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			printf("Input student %d's %s score:", i + 1, courses[j]);
			scanf("%f", &this->score[j]);
		}
		printf("Student %d's records successfully appended.\n", i + 1);
		++i;
	}
	printf("%d students' records successfully appended.\n", n);
	*stuNum += n;
	printPause();
	return stu;
}

void queryByName(Student *stu, int n)        // #2
{
	char name[MAX_STU_NAME_LEN];
	printf("Input the name of query student:");
	scanf("%s", name);
	int ret = searchByName(stu, n, name);
	if (ret != -1)
	{
		printHeader(false);
		printStu(stu, ret, false);
	}
	else
	{
		printf("Student %s not found.\n", name);
	}
	printPause();
}

void queryById(Student *stu, int n)            // #3
{
	int64_t id;
	printf("Input the ID of query student:");
	scanf("%ld", &id);
	int ret = searchById(stu, n, id);
	if (ret != -1)
	{
		printHeader(false);
		printStu(stu, ret, false);
	}
	else
	{
		printf("Student with ID %lu not found.\n", id);
	}
	printPause();
}

void modify(Student *stu, int n)            // #4
{
	int64_t id;
	printf("Input the ID of student to be modified:");
	scanf("%ld", &id);
	int ind = searchById(stu, n, id);
	if (ind != -1)
	{
		for (int i = 0; i < COURSE_NUM; ++i)
		{
			Student *this = stu + ind;
			printf("Input student's %s score:", courses[i]);
			scanf("%f", &this->score[i]);
		}
	}
	else
	{
		printf("Student with ID %lu not found.\n", id);
	}
	printPause();
}

void delete(Student *stu, int *n)            // #5
{
	int64_t id;
	printf("Input the ID of student to be deleted:");
	scanf("%ld", &id);
	int ind = searchById(stu, *n, id);
	if (ind != -1)
	{
		for (int i = ind; i < *n - 1; i++)
		{
			*(stu + i) = *(stu + i + 1);
		}
		*n -= 1;
		printf("1 students' records successfully deleted.\n");
	}
	else
	{
		printf("Student with ID %lu not found.\n", id);
	}
	printPause();
}

void showStu(Student *stu, int n)            // #6
{
	float sum[n];
	memset(sum, 0, sizeof(sum));
	float mean = 0;
	for (int i = 0; i < n; ++i)
	{
		Student *this = stu + i;
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			sum[i] += this->score[j];
		}
		mean += sum[i];
	}
	mean /= (float)n;
	printHeader(true);
	for (int i = 0; i < n; ++i)
	{
		printStu(stu, i, true);
	}
	printf("Student average score： %.1f\n", mean);
	printPause();
}

void showCourse(Student *stu, int n)                // #7
{
	float mean[COURSE_NUM];
	memset(mean, 0, sizeof(mean));
	for (int i = 0; i < n; ++i)
	{
		Student *this = stu + i;
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			mean[j] += this->score[j];
		}
	}
	for (int i = 0; i < COURSE_NUM; ++i)
	{
		mean[i] /= (float)n;
		printf("%s average score: %.1f\n", courses[i], mean[i]);
	}
	printPause();
}

void sortByCourse(Student *stu, int n)                // #8
{
	printf("Input the course to be sorted\n");
	for (int i = 0; i < COURSE_NUM; ++i)
	{
		printf("%i-%s", i + 1, courses[i]);
		if (i != COURSE_NUM - 1)
		{
			printf(", ");
		}
		else
		{
			printf(":");
		}
	}
	int ind = 1;
	scanf("%d", &ind);
	--ind;
	Student *sorted = (Student *)calloc(n, sizeof(Student));
	memcpy(sorted, stu, n*sizeof(Student));
	sort(sorted, n, ind);
	printHeader(false);
	for (int i = n - 1; i >= 0; --i)
	{
		printStu(sorted, i, false);
	}
	free(sorted);
	printPause();
}

void analyse(Student *stu, int n)                    // #9
{
	const int GRADENUM = 5;
	char grades[][20] = { "Excellent", "Good", "Medium", "Pass", "Fail" };
	int eachGrade[COURSE_NUM][GRADENUM];
	float percent[COURSE_NUM][GRADENUM];
	memset(eachGrade, 0, sizeof(eachGrade));
	memset(percent, 0, sizeof(percent));
	for (int i = 0; i < n; ++i)
	{
		Student *this = stu + i;
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			int grade = ((int)this->score[j])/10;
			switch (grade)
			{
			case 10:
			case 9:
				eachGrade[j][0]++;
				break;
			case 8:
				eachGrade[j][1]++;
				break;
			case 7:
				eachGrade[j][2]++;
				break;
			case 6:
				eachGrade[j][3]++;
				break;
			default:
				eachGrade[j][4]++;
				break;
			}
		}
	}
	for (int i = 0; i < COURSE_NUM; ++i)
	{
		for (int j = 0; j < GRADENUM; ++j)
		{
			percent[i][j] = eachGrade[i][j]/(float)n;
		}
	}
	printf("%-11s", "Grade");
	for (int i = 0; i < COURSE_NUM; ++i)
	{
		printf("%-6s", courses[i]);
	}
	printf("\n");
	for (int i = 0; i < GRADENUM; ++i)
	{
		printf("%-11s", grades[i]);
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			printf("%-6d", eachGrade[j][i]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%-11s", "Grade");
	for (int i = 0; i < COURSE_NUM; ++i)
	{
		printf("%6s", courses[i]);
	}
	printf("\n");
	for (int i = 0; i < GRADENUM; ++i)
	{
		printf("%-11s", grades[i]);
		for (int j = 0; j < COURSE_NUM; ++j)
		{
			printf("%6.1f%%", percent[j][i]*100);
		}
		printf("\n");
	}
	printPause();
}

void save(Student *stu, int n)                        // #10
{
	char *fileName = "scoresheet.txt";
	FILE *fp = fopen(fileName, "wb");
	for (int i = 0; i < n; ++i)
	{
		fwrite(stu + i, sizeof(Student), 1, fp);
	}
	printf("%d students' records successfully saved at %s.\n", n, fileName);
	fclose(fp);
	printPause();
}

Student *load(Student *stu, int *stuNum)       	  	// #11
{
	char confirm = 'n';
	if (stu != NULL)
	{
		printf("Are you sure to load student's records from file? This will clear all unsaved data (y/n):");
		empty_stdin();
		scanf("%c", &confirm);
		if (confirm == 'n')
		{
			return stu;
		}
	}
//	char path[MAX_PATH_LEN];
//	printf("Input the file path:");
//	scanf("%s", path);
	FILE *fp = fopen("scoresheet.txt", "rb");
	if (fp == NULL)
	{
		printf("File not found");
		if (stu != NULL)
		{
			printf(", data recovered.\n");
		}
		else
		{
			printf(".\n");
		}
		printPause();
		return stu;
	}
	free(stu);
	stu = (Student *)calloc(MAX_STU_NUM, sizeof(Student));
	int n = 0;
	while (1)
	{
		if (feof(fp))
		{
			break;
		}
		fread(stu + n, sizeof(Student), 1, fp);
		n++;
	}
	*stuNum = n - 1;
	stu = (Student *)realloc(stu, *stuNum*sizeof (Student));
	printf("%d students' records successfully loaded.\n\n", n - 1);
	printPause();
	return stu;
}

void printExit()                                    // #0
{
	printf("Exited.\n");
}
#ifndef __OP_H__
#define __OP_H__

#include <stdbool.h>
#include "stucourse.h"

// print.c
void printGreeting();
void printHeader(bool withSum);
void printStu(Student *stu, int i, bool withSum);
void printPause();
void printErrorChoice();
void empty_stdin();

// search.c
int searchByName(Student *stu, int n, char name[MAX_STU_NAME_LEN]);
int searchById(Student *stu, int n, unsigned long id);

// opmain.c
Student *input(Student *stu, int *stuNum);			// #1
void queryByName(Student *stu, int n);				// #2
void queryById(Student *stu, int n);				// #3
void modify(Student *stu, int n);	  				// #4
void delete(Student *stu, int *n); 	 				// #5
void showStu(Student *stu, int n);					// #6
void showCourse(Student *stu, int n);				// #7
void sortByCourse(Student *stu, int n);				// #8
void analyse(Student *stu, int n);					// #9
void save(Student *stu, int n);						// #10
Student *load(Student *stu, int *stuNum);			// #11
void printExit();									// #0

#endif

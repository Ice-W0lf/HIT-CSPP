#ifndef __STU_H__
#define __STU_H__

#include <stdint.h>

#define MAX_STU_NUM 45
#define MAX_STU_NAME_LEN 12
#define MAX_COURSE_NAME_LEN 8
#define COURSE_NUM 4
#define MAX_PATH_LEN 40

static char courses[][MAX_COURSE_NAME_LEN] = {"iCS", "PDP", "DS", "DL",};

typedef struct _student
{
	int64_t id;
	char name[MAX_STU_NAME_LEN];
	float score[COURSE_NUM];
} Student;

#endif
#ifndef __fileop_h__
#define __fileop_h__

typedef struct {
	unsigned long id;
	char name[32];
	float score[4];
} MyRecord;

int txtRead(char* path, MyRecord* rp);

void txtWrite(char* path, MyRecord* rp, int recNum);

void binWrite(char* fltxt, char* flbin, char* chtxt, char* chbin, float* fl, char* ch);

void binRead(char* path);

int structBinRead(char* path, MyRecord* rp);

void structBinWrite(char* path, MyRecord* rp, int recNum);

#endif

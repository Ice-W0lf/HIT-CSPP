#include <stdio.h>
#include <string.h>

int eval(char c)
{
	if (c == 0)
		return 0;
	return c - '0';
}

void strReverse(char *dest, char *src)
{
	int length = strlen(src);
	for (int i=0; i<length; ++i)
	{
		dest[i] = src[length - i - 1];
	}
}

void sum(char *S, char* a, char* b)
{
	int ret[100];
	char retStr[100];
	char retStrRev[100];
	memset(ret, 0, sizeof(ret));
	memset(retStr, 0, sizeof (retStr));
	memset(retStrRev, 0, sizeof (retStrRev));
	char aRev[100], bRev[100];
	memset(aRev, 0, sizeof(aRev));
	memset(bRev, 0, sizeof (bRev));
	strReverse(aRev, a);
	strReverse(bRev, b);
	int maxLen = (strlen(a) > strlen(b) ? strlen(a) : strlen(b));
	for (int i=0; i<maxLen; ++i)
	{
		ret[i] = eval(aRev[i]) + eval(bRev[i]);
	}
	for (int i=0; i<maxLen; ++i)
	{
		if (ret[i] > 9)
		{
			ret[i+1] += 1;
			ret[i] -= 10;
		}
	}
	int highNone = 0;
	if (ret[maxLen] == 0)
	{
		highNone = 1;
	}
	for (int i=0; i<=maxLen - highNone; ++i)
	{
		retStr[i] = ret[i] + '0';
	}
	retStr[maxLen - highNone + 1] = '\0';
	strReverse(retStrRev, retStr);
	strcpy(S, retStrRev);
}


void F(char *f, int i)
{
	if(i == 1)
		strcpy(f, "1");
	else if(i == 2)
		strcpy(f, "1");
	else
	{
		char a[100];
		char b[100];
		memset(a, 0, sizeof (a));
		memset(b, 0, sizeof (b));
		F(a, i-1);
		F(b, i-2);
		sum(f, a, b);
	}
}

int main()
{
	int num = 100;
	char a[100] = "1";
	char b[100] = "1";
	printf("f1 = %s\n", a);
	printf("f2 = %s\n", b);
	char tempF[100] = "";
	for (int i = 3; i <= num; ++i)
	{
		F(tempF, i);
		printf("f%d = %s\n", i, tempF);
		strcpy(b, a);
		strcpy(a, tempF);
	}

	return 0;
}

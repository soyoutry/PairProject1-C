#include "stdafx.h"
int countChar(char *fn)
{
	int cnt = 0;
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("�ļ�������!");
		exit(1);
	}
	while (fgetc(file) != EOF)
	{
		cnt++;
	}
	fclose(file);
	return cnt;
}
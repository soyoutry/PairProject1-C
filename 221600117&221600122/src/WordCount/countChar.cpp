#include "stdafx.h"
int countChar(char *fn)
{
	int cnt = 0;
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("文件不存在!");
		exit(1);
	}
	while (fgetc(file) != EOF)
	{
		cnt++;
	}
	fclose(file);
	return cnt;
}
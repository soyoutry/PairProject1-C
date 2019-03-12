#include "stdafx.h"

int countLine(char *fn)
{
	int cnt = 0;
	int f = 0;//每一行的非空字符数
	char ch;
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("文件不存在!");
		exit(1);
	}
	while ((ch = fgetc(file)) != EOF)
	{
		//遇到换行符
		if (ch == '\n')
		{
			//本行内容为非空字符
			if (f > 0)
				cnt++;
			f = 0;
		}
		//遇到非空字符
		else if (ch != ' ' && ch != '\t')
			f++;
	}
	//最后一行不含回车符，特殊判断
	if (f > 0)
		cnt++;
	fclose(file);
	return cnt;
}
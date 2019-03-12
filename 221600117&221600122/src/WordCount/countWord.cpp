#include "stdafx.h"
int countWord(char *fn)
{
	char ch;
	int f = 0;//符合条件单词的英文字母数
	int cnt = 0;//单词数
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("文件不存在!");
		exit(1);
	}
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			if (f >= 0)//单词前四位是字母
				f++;
			else//单词前字母不足四位，后面字母不记录
				f = -1;
		}
		else if (ch >= '0' && ch <= '9' && f < 4)//开头不足四位字母，不算单词
		{
			f = -1;
		}
		else//读到分隔符
		{
			if (f >= 4)
				cnt++;
			f = 0;
		}
	}
	//若最后一个单词符合条件且到文件末尾
	if (f >= 4)
		cnt++;
	fclose(file);
	return cnt;
}
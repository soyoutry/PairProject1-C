#include "stdafx.h"

int countLine(char *fn)
{
	int cnt = 0;
	int f = 0;//ÿһ�еķǿ��ַ���
	char ch;
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("�ļ�������!");
		exit(1);
	}
	while ((ch = fgetc(file)) != EOF)
	{
		//�������з�
		if (ch == '\n')
		{
			//��������Ϊ�ǿ��ַ�
			if (f > 0)
				cnt++;
			f = 0;
		}
		//�����ǿ��ַ�
		else if (ch != ' ' && ch != '\t')
			f++;
	}
	//���һ�в����س����������ж�
	if (f > 0)
		cnt++;
	fclose(file);
	return cnt;
}
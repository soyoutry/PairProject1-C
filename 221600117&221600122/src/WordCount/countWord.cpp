#include "stdafx.h"
int countWord(char *fn)
{
	char ch;
	int f = 0;//�����������ʵ�Ӣ����ĸ��
	int cnt = 0;//������
	FILE *file;
	fopen_s(&file, fn, "r");
	if (file == NULL)
	{
		printf("�ļ�������!");
		exit(1);
	}
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			if (f >= 0)//����ǰ��λ����ĸ
				f++;
			else//����ǰ��ĸ������λ��������ĸ����¼
				f = -1;
		}
		else if (ch >= '0' && ch <= '9' && f < 4)//��ͷ������λ��ĸ�����㵥��
		{
			f = -1;
		}
		else//�����ָ���
		{
			if (f >= 4)
				cnt++;
			f = 0;
		}
	}
	//�����һ�����ʷ��������ҵ��ļ�ĩβ
	if (f >= 4)
		cnt++;
	fclose(file);
	return cnt;
}
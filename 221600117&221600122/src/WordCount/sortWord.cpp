#include "stdafx.h"
bool cmp(pair<int, string> a, pair<int, string> b)
{
	return (a.first != b.first) ? a.first > b.first:a.second < b.second;
}
void MapSortOfValue(vector<pair<int, string> >& vec, map<string, int>& m)
{
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		vec.push_back(make_pair(it->second, it->first));
	sort(vec.begin(), vec.end(), cmp);
}

void sortWord(char *fn)
{
	char ch;
	vector<pair<int, string> > vec;
	int f = 0, cnt = 0;
	string temp = "";
	map<string, int> wmap;
	FILE *file;
	map<string, int>::iterator it;

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
			if (ch >= 'A' && ch <= 'Z')
			{
				ch += ('a' - 'A');
			}
			if (f >= 0)//����ǰ��λ����ĸ
			{
				f++;
				temp += ch;
			}
			else//����ǰ��ĸ������λ��������ĸ����¼
				f = -1;
		}
		else if (ch >= '0' && ch <= '9')//��ͷ������λ��ĸ�����㵥��
		{
			if (f < 4)
				f = -1;
			else
				temp += ch;
		}
		else//�����ָ���
		{
			if (f >= 4)
			{
				cnt++;
				wmap[temp]++;
			}
			f = 0;
			temp = "";
		}
	}
	if (f >= 4)
	{
		cnt++;
		wmap[temp]++;
	}
	MapSortOfValue(vec, wmap);
	if (vec.size()<10)
	{
		for (int i = 0; i<vec.size(); i++)
			cout << '<' << vec[i].second.c_str() << ">: " << vec[i].first << endl;
	}
	else {
		for (int i = 0; i < 10; i++)
			cout << '<' << vec[i].second.c_str() << ">: " << vec[i].first << endl;
	}
}
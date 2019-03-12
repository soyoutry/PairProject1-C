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
		printf("文件不存在!");
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
			if (f >= 0)//单词前四位是字母
			{
				f++;
				temp += ch;
			}
			else//单词前字母不足四位，后面字母不记录
				f = -1;
		}
		else if (ch >= '0' && ch <= '9')//开头不足四位字母，不算单词
		{
			if (f < 4)
				f = -1;
			else
				temp += ch;
		}
		else//读到分隔符
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
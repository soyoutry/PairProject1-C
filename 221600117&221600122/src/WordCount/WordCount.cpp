// wordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char *argv[])
{
	ofstream of("result.txt");
	streambuf *coutbackup;
	coutbackup = cout.rdbuf(of.rdbuf());//重定向输出到resul.txt文件中
	int charTotal = countChar(argv[1]);
	int wordTotal = countWord(argv[1]);
	int lineTotal = countLine(argv[1]);

	cout << "characters: " << charTotal << endl;
	cout << "words: " << wordTotal << endl;
	cout << "lines: " << lineTotal << endl;

	sortWord(argv[1]);

	return 0;
}


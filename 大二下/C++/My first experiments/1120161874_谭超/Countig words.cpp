#include"stdafx.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
void main() {
	int count = 0;//定义一个整形变量存储单词个数
	string str;//定义一个字符串存放每次读取的单词
	fstream fin("file1.txt");//以只读方式打开文件
	if (!fin)//判断文件是否打开成功 若没打开成功，则结束程序
	{
		cout << "Error!" << endl;
		exit(-1);
	}
	while (fin>>str)//从文件中逐词读取
	{
		 count++;
	}
	cout << "The number of words:" <<count << endl;//输出单词个数
	//system("pause");
}

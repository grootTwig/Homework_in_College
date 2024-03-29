//#include"stdafx.h"
#include<iostream>
using namespace std;
const int MAX_SIZE = 100;//设置一个常量表示Set类中可以保存的元素的最大个数
class Set//定义一个Set类
{
private://此类中包括整形数组和元素个数两个属性
	int data[MAX_SIZE] = { 0 };
	int num = 0;
public:
	Set();//构造函数
	~Set();//析构函数
	int getNum();//获取元素的个数
	int getData(int);//获取某个元素
	bool IsExist(int);//判断某元素在该对象中是否存在
	void RemoveItem(int);//从该对象中移除某元素
	bool IsEqual(Set);//判断该对象与另外一个对象是否相同
	Set Intersection(Set);//求该对象与另一个对象的交集
	Set Union(Set);//求该对象与另外一个对象的并集
	bool AddItem(int);//向该对象中加入一个元素
};
Set::Set()//从这里开始函数的定义
{
	cout << "Constructor!" << endl;
}
Set::~Set()
{
	cout << "Destructor!" << endl;
}
int Set::getNum()
{
	return num;
}
int Set::getData(int n)
{
	return data[n];
}
bool Set::IsExist(int a) {
	for (int i = 0; i < num; i++)
		if (data[i] == a) return true;
	return false;
}
void Set::RemoveItem(int a) {
	for (int i = 0; i<num; i++)
		if (data[i] == a)
		{
			int j;
			for (j = i; j < num - 1; j++)
				data[j] = data[j + 1];
			data[j] = 0;
			num--;
		}//从该对象中移除一个元素后num的值要减一
}
bool Set::IsEqual(Set a) {
	if (num != a.getNum()) return false;
	for (int i = 0; i < num; i++)
		if (data[i] != a.getData(i)) return false;
	return true;
}
Set Set::Intersection(Set a)
{
	Set result;//将两个对象的交集存入另一个对象
	for (int i = 0; i<num; i++)
		for (int j = 0; j < a.getNum(); j++)
			if (data[i] == a.getData(j))
			{
				result.AddItem(data[i]);
				break;
			}
	return result;
}
Set Set::Union(Set a)
{
	Set result;//将两个对象的并集存入另一个对象
	for (int i = 0; i < num; i++)
	{
		int j = 0;
		for (j; j < result.getNum(); j++)
		{
			if (data[i] == result.getData(j))
				break;
		}
		if (j >= result.getNum())
			result.AddItem(data[i]);
	}
	for (int i = 0; i < a.getNum(); i++)
	{
		int j = 0;
		for (j; j < result.getNum(); j++)
		{
			if (a.getData(i) == result.getData(j))
				break;
		}
		if (j >= result.getNum())
			result.AddItem(a.getData(i));
	}
	return result;
}
bool Set::AddItem(int a)
{
	if (num >= MAX_SIZE) return false;
	for (int i = 0; i < num; i++)
		if (data[i] == a) return false;
	data[num++] = a;//向该对象中加入元素后，num的值要加一
	return true;
}
int main()
{
	Set set1;
	Set set2;
	int n = 10;
	while (n--)
	{
		set1.AddItem(n);//设置set1数组元素为9，8，7，6，5，4，3，2，1，0
		set2.AddItem(n * 10 + 1);//设置set2数组元素为91，81，71，61，51，41，31，21，11，1
	}
	cout << set1.IsExist(8) << endl;//判断元素8是否在set1中
	set2.RemoveItem(31);//从set2中移除元素31
	cout << set1.IsEqual(set2)<<endl;//判断set1和set2是否相等
	Set resultIntersection = set1.Intersection(set2);//求set1与set2的交集并输出
	for (int i = 0; i < resultIntersection.getNum(); i++)
		cout << resultIntersection.getData(i) << " ";
	cout << endl;
	Set resultUnion = set1.Union(set2);//求set1与set2的并集并输出
	for (int i = 0; i < resultUnion.getNum(); i++)
		cout << resultUnion.getData(i) << " ";
	cout << endl;
	//system("pause");
}
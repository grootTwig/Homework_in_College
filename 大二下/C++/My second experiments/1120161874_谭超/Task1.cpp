#include"stdafx.h"
#include<iostream>
using namespace std;
class Myclass//创建一个类
{
public:
	Myclass();
	~Myclass();
};
Myclass::Myclass()//在此类的构造函数中输出Initialize
{
	cout << "Initialize\n";
}
Myclass::~Myclass()//在此类的析构函数中输出Clear up;
{
	cout << "Clear up\n";
}
Myclass a;//声明一个对象
int main()
{
	cout << "Hello World!\n";
	//system("pause");
}

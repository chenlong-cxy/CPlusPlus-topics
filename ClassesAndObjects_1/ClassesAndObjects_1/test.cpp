//struct Test
//{
//	//成员变量
//	int a;
//	double b;
//	//成员函数
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//};
//
//class className
//{
//	//类体：由成员变量和成员函数组成
//
//};  //注意后面的分号

//#include <iostream>
//using namespace std;
////人
//class Person
//{
//public:
//	//显示基本信息
//	void ShowInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;  //姓名
//	char* _sex;   //性别
//	int _age;     //年龄
//};
//int main()
//{
//
//	return 0;
//}

#include "test.h"
#include <iostream>
using namespace std;
//显示基本信息
void Person::ShowInfo()
{
	cout << _name << "-" << _sex << "-" << _age << endl;
}
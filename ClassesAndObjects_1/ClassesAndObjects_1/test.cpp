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

//#include "test.h"
//#include <iostream>
//using namespace std;
////显示基本信息
//void Person::ShowInfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}
//class Person
//{
//public:
//	//显示基本信息
//	void ShowInfo();
//private:
//	char* _name;  //姓名
//	char* _sex;   //性别
//	int _age;     //年龄
//};


//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	//显示基本信息
//	void ShowInfo();
//private:
//	char* _name;  //姓名
//	char* _sex;   //性别
//	int _age;     //年龄
//};
//
////这里需要指定ShowInfo是属于Person这个类域
//void Person::ShowInfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}
//int main()
//{
//	Person man;
//
//	return 0;
//}

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


//#include <iostream>
//using namespace std;
//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//int main()
//{
//	cout << sizeof(class A1) << endl;
//	cout << sizeof(class A2) << endl;
//	cout << sizeof(class A3) << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;//实例化两个日期类
//	d1.SetDate(2021, 5, 25);//设置d1的日期
//	d2.SetDate(2021, 5, 26);//设置d2的日期
//	d1.Display();//打印d1的日期
//	d2.Display();//打印d2的日期
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	void Display(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	void SetDate(Date* this, int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;//实例化两个日期类
//	d1.SetDate(&d1, 2021, 5, 25);//设置d1的日期
//	d2.SetDate(&d2, 2021, 5, 26);//设置d2的日期
//	d1.Display(&d1);//打印d1的日期
//	d2.Display(&d2);//打印d2的日期
//	return 0;
//}


#include <iostream>
using namespace std;
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;  //第一句代码
	p->PrintA();     //第二句代码
	p->Show();       //第三句代码
}
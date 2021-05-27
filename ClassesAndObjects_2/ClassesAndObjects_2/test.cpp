//#include <iostream>
//using namespace std;
////日期类
//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.SetDate(2021, 5, 27);  //给d1设置内容
//	d1.Display();  //打印d1数据
//
//	Date d2;
//	d2.SetDate(2021, 5, 28);  //给d2设置内容
//	d2.Display();  //打印d2数据
//
//	return 0;
//}


#include <iostream>
using namespace std;
//日期类
class Date
{
public:
	//1.无参构造函数
	Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}
	//2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;  //调用无参的构造函数
	Date d();  //error，该代码声明了一个名为d的函数，该函数无参，返回一个日期类的对象
	Date d2(2021, 5, 27);  //调用带参的构造函数

	return 0;
}
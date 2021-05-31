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


//#include <iostream>
//using namespace std;
////日期类
//class Date
//{
//public:
//	//1.无参构造函数
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//	//2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;  //调用无参的构造函数
//	Date d();  //error，该代码声明了一个名为d的函数，该函数无参，返回一个日期类的对象
//	Date d2(2021, 5, 27);  //调用带参的构造函数
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	//Date(int year = 0, int month = 1, int day = 1)// 构造函数
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Print()
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
//	Date d1; // 编译器将调用自动生成的默认构造函数对d1进行初始化
//	d1.Print();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)// 构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()// 析构函数
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;// d1先构造
//	Date d2;// d2后构造
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)// 构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//	void Test()
//	{
//		_year += 1;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 5, 31);
//	Date d2(d1); // 用已存在的对象d1创建对象d2
//	d1.Print();
//	d2.Print();
//	d1.Test();
//	d1.Print();
//	d2.Print();
//	/*Date d(d1);*/
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_ps = (int*)malloc(sizeof(int)* capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	void Print()
//	{
//		cout << _ps << endl;// 打印栈空间地址
//	}
//private:
//	int* _ps;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Print();// 打印s1栈空间的地址
//	Stack s2(s1);// 用已存在的对象s1创建对象s2
//	s2.Print();// 打印s2栈空间的地址
//	return 0;
//}

//d1 == d2;
//IsSame(d1, d2);

#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&&_month == d._month
//			&&_day == d._day;
//	}
//private:
	int _year;
	int _month;
	int _day;
};
bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&&d1._month == d2._month
		&&d1._day == d2._day;
}

int main()
{
	Date d1(2021, 5, 31);
	Date d2(2021, 5, 14);
	d1.Print();
	d2.Print();
	cout << (d1 == d2) << endl;
	return 0;
}
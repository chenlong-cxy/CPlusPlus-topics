//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	class B
//	{
//		friend class A;
//	public:
//		void Test2()
//		{
//			cout << "void Test2() " << _b << endl;
//			cout << "void Test2() " << _long << endl;
//			cout << "void Test2() " << _lee << endl;
//		}
//		B(int a = 0, int b = 1, int c = 1)
//		{
//			_a = a;
//			_b = b;
//			_c = c;
//		}
//	private:
//		int _a;
//		int _b;
//		int _c;
//		static int _long;
//	};
//	A(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Test1()
//	{
//		cout << "void Test1() " << _year << endl;
//		cout << "void Test2() " << _long << endl;
//		cout << "void Test2() " << _lee << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	static int _lee;
//};
//int A::_lee = 10;
//int A::B::_long = 20;
//int main()
//{
//	A aa;
//	A::B bb;
//
//	aa.Test1();
//	bb.Test2();
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void Test()
//	{
//		cout << "void Test2() " << _d._long << endl;
//	}
//private:
//	B _d;
//};
//class B
//{
//	friend class A;
//public:
//	B(int a = 0, int b = 1)
//	{
//		_a = a;
//		_b = b;
//	}
//	void Test2()
//	{
//		cout << "void Test2() " << _b << endl;
//		cout << "void Test2() " << _long << endl;
//		//cout << "void Test2() " << _lee << endl;
//	}
//private:
//	int _a;
//	int _b;
//	//A _c;
//	static int _long;
//};
//int B::_long = 20;
//int main()
//{
//	A aa;
//	B bb;
//
//	bb.Test2();
//	aa.Test();
//
//	return 0;
//}

//class Date; // 前置声明
//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//Date(int year = 1900, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	d1.SetTimeOfDate(2, 2, 2);
//	return 0;
//}


//class Date; // 前置声明
class Time
{
public:
	class Date
	{
		friend class Time;
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		void SetTimeOfDate(Time& T, int hour, int minute, int second)
		{
			// 直接访问时间类私有的成员变量
			T._hour = hour;
			T._minute = minute;
			T._second = second;
		}
	private:
		int _year;
		int _month;
		int _day;
	};
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
	void Test(Date& D, int year, int month, int day)
	{
		D._year = year;
		D._month = month;
		D._day = day;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

int main()
{
	Time t1;
	Time::Date d1;
	d1.SetTimeOfDate(t1, 2, 2, 2);
	t1.Test(d1, 12, 12, 12);
	return 0;
}
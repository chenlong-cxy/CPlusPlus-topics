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

//class Date; // ǰ������
//class Time
//{
//	friend class Date; // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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


//class Date; // ǰ������
//class Time
//{
//public:
//	class Date
//	{
//		friend class Time;
//	public:
//		Date(int year = 1900, int month = 1, int day = 1)
//			: _year(year)
//			, _month(month)
//			, _day(day)
//		{}
//		void SetTimeOfDate(Time& T, int hour, int minute, int second)
//		{
//			// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//			T._hour = hour;
//			T._minute = minute;
//			T._second = second;
//		}
//	private:
//		int _year;
//		int _month;
//		int _day;
//	};
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//	void Test(Date& D, int year, int month, int day)
//	{
//		D._year = year;
//		D._month = month;
//		D._day = day;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//int main()
//{
//	Time t1;
//	Time::Date d1;
//	d1.SetTimeOfDate(t1, 2, 2, 2);
//	t1.Test(d1, 12, 12, 12);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//	Date& operator=(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 6, 5);
//	d1.Print();
//	Date d2;
//	d2 = d1;
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	// ���캯��
//	Date(int year = 0, int month = 1, int day = 1)
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

//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	// ���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;// ��һ�θ�ֵ
//		_year = 2022;// �ڶ��θ�ֵ
//		//...
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2021, 6, 5);
//	d1.Print();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A(int val)
//	{
//		_val = val;
//	}
//private:
//	int _val;
//};
//class Date
//{
//public:
//	// ���캯��
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, a(1)
//	{
//		//a = 1;
//		//_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int& _day;
//	A a;
//};
//int main()
//{
//	const int a = 10;//correct ����ʱ�ͳ�ʼ��
//	//const int b;//error ����ʱδ��ʼ��
//
//	//int a = 10;
//	//int& b = a;// ����ʱ�ͳ�ʼ��
//	//int& c;
//	//c = a;
//	//const int a;
//	Date d1(2021, 6, 5);
//	return 0;
//}


//class A //����û��Ĭ�Ϲ��캯�� 
//{
//public:
//	A(int val) //ע���������Ĭ�Ϲ��캯������Ҫ���ε��ã�
//	{
//		_val = val;
//	}
//private:
//	int _val;
//};
//
//class B
//{
//public:
//	B()
//		:_a(2021) //����ʹ�ó�ʼ���б������г�ʼ��
//	{}
//private:
//	A _a; //�Զ������ͳ�Ա������û��Ĭ�Ϲ��캯����
//};


//#include <iostream>
//using namespace std;
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}


#include <iostream>
using namespace std;
int i = 0;
class Test
{
public:
	Test()
		:_b(i++)
		,_a(i++)
	{}
	void Print()
	{
		cout << "_a:" << _a << endl;
		cout << "_b:" << _b << endl;
	}
private:
	int _a;
	int _b;
};
int main()
{
	Test test;
	test.Print(); //��ӡ���test._aΪ0��test._bΪ1
	return 0;
}
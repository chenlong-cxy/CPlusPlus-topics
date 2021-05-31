//#include <iostream>
//using namespace std;
////������
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.SetDate(2021, 5, 27);  //��d1��������
//	d1.Display();  //��ӡd1����
//
//	Date d2;
//	d2.SetDate(2021, 5, 28);  //��d2��������
//	d2.Display();  //��ӡd2����
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
////������
//class Date
//{
//public:
//	//1.�޲ι��캯��
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//	//2.���ι��캯��
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
//	Date d1;  //�����޲εĹ��캯��
//	Date d();  //error���ô���������һ����Ϊd�ĺ������ú����޲Σ�����һ��������Ķ���
//	Date d2(2021, 5, 27);  //���ô��εĹ��캯��
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	//Date(int year = 0, int month = 1, int day = 1)// ���캯��
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
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
//	Date d1; // �������������Զ����ɵ�Ĭ�Ϲ��캯����d1���г�ʼ��
//	d1.Print();
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)// ���캯��
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()// ��������
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;// d1�ȹ���
//	Date d2;// d2����
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)// ���캯��
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
//		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
//	Date d2(d1); // ���Ѵ��ڵĶ���d1��������d2
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
//		cout << _ps << endl;// ��ӡջ�ռ��ַ
//	}
//private:
//	int* _ps;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Print();// ��ӡs1ջ�ռ�ĵ�ַ
//	Stack s2(s1);// ���Ѵ��ڵĶ���s1��������s2
//	s2.Print();// ��ӡs2ջ�ռ�ĵ�ַ
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
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
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
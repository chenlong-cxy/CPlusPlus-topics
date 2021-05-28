#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	// 构造函数
	Date(int year = 0, int month = 1, int day = 1);
	// 日期+天数
	Date operator+(int day);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 前置--
	Date& operator--();
	// 后置--
	Date operator--(int);
	// 日期-日期
	int operator-(const Date& d);
	// 日期的大小关系比较
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
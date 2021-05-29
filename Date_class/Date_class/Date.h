#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	// 构造函数
	Date(int year = 0, int month = 1, int day = 1);
	// 打印函数
	void Print() const;
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day) const;
	// 日期-=天数
	Date& operator-=(int day);
	// 日期-天数
	Date operator-(int day) const;
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 前置--
	Date& operator--();
	// 后置--
	Date operator--(int);
	// 日期的大小关系比较
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	// 日期-日期
	int operator-(const Date& d) const;

	// 析构，拷贝构造，赋值重载可以不写，使用默认生成的即可

private:
	int _year;
	int _month;
	int _day;
};
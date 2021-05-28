#include "Date.h"

inline int GetMonthDay(int year, int month)
{
	// 数组存储平年每个月的天数
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		//闰年2月的天数
		day = 29;
	}
	return day;
}

// 构造函数
Date::Date(int year, int month, int day)
{

}
// 日期+天数
Date Date::operator+(int day)
{

}
// 日期+=天数
Date& Date::operator+=(int day)
{

}
// 日期-天数
Date Date::operator-(int day)
{

}
// 日期-=天数
Date& Date::operator-=(int day)
{

}
// 前置++
Date& Date::operator++()
{

}
// 后置++
Date Date::operator++(int)
{

}
// 前置--
Date& Date::operator--()
{

}
// 后置--
Date Date::operator--(int)
{

}
// 日期-日期
int operator-(const Date& d);
// 日期的大小关系比较
bool Date::operator>(const Date& d)
{

}
bool Date::operator>=(const Date& d)
{

}
bool Date::operator<(const Date& d)
{

}
bool Date::operator<=(const Date& d)
{

}
bool Date::operator==(const Date& d)
{

}
bool Date::operator!=(const Date& d)
{

}
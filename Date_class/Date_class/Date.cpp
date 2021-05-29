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
	// 检查日期的合法性
	if (year >= 0
	&& month >= 1 && month <= 12
	&& day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		// 严格来说抛异常更好
		cout << "非法日期" << endl;
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
}
// 打印函数
void Date::Print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}
// 日期+=天数
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
// 日期+天数
Date Date::operator+(int day)
{
	//Date tmp = *this;
	Date tmp(*this);
	// 复用operator+=
	tmp += day;

	return tmp;
}
// 日期-=天数
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// 日期-天数
Date Date::operator-(int day)
{
	//Date tmp = *this;
	Date tmp(*this);
	// 复用operator-=
	tmp -= day;

	return tmp;
}
// 前置++
Date& Date::operator++()
{
	// 复用operator+=
	*this += 1;
	return *this;
}
// 后置++
// int参数不需要给实参，因为没用，其作用是为了跟前置++构成函数重载
Date Date::operator++(int)
{
	Date tmp(*this);
	// 复用operator+=
	*this += 1;
	return tmp;
}
// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// 日期的大小关系比较
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&&_month == d._month
		&&_day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
// 日期-日期
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n*flag;
}
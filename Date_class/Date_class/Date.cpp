#include "Date.h"

inline int GetMonthDay(int year, int month)
{
	// ����洢ƽ��ÿ���µ�����
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		//����2�µ�����
		day = 29;
	}
	return day;
}

// ���캯��
Date::Date(int year, int month, int day)
{

}
// ����+����
Date Date::operator+(int day)
{

}
// ����+=����
Date& Date::operator+=(int day)
{

}
// ����-����
Date Date::operator-(int day)
{

}
// ����-=����
Date& Date::operator-=(int day)
{

}
// ǰ��++
Date& Date::operator++()
{

}
// ����++
Date Date::operator++(int)
{

}
// ǰ��--
Date& Date::operator--()
{

}
// ����--
Date Date::operator--(int)
{

}
// ����-����
int operator-(const Date& d);
// ���ڵĴ�С��ϵ�Ƚ�
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
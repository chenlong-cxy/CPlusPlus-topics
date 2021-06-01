#include "Date.h"

// 1.inline
// 2.static
// 3.&&
// ��ȡĳ��ĳ�µ�����
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
// �����������Ͷ���ֿ�ʱ��������ʱע��ȱʡ����������ʱ�����ȱʡ����
Date::Date(int year, int month, int day)
{
	// ������ڵĺϷ���
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
		// �ϸ���˵���쳣����
		cout << "�Ƿ�����" << endl;
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
}
// ��ӡ����
void Date::Print() const
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}
// ����+=����
Date& Date::operator+=(int day)
{
	if (day<0)
	{
		// ����operator-=
		*this -= -day;
	}
	else
	{
		_day += day;
		// ���ڲ��Ϸ���ͨ�����ϵ�����ֱ��������ںϷ�Ϊֹ
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
	}
	return *this;
}
// ����+����
Date Date::operator+(int day) const
{
	//Date tmp = *this;
	Date tmp(*this);// ��������tmp�����ڷ���
	// ����operator+=
	tmp += day;

	return tmp;
}
// ����-=����
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		// ����operator+=
		*this += -day;
	}
	else
	{
		_day -= day;
		// ���ڲ��Ϸ���ͨ�����ϵ�����ֱ��������ںϷ�Ϊֹ
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
	}
	return *this;
}
// ����-����
Date Date::operator-(int day) const
{
	//Date tmp = *this;
	Date tmp(*this);// ��������tmp�����ڷ���
	// ����operator-=
	tmp -= day;

	return tmp;
}
// ǰ��++
Date& Date::operator++()
{
	// ����operator+=
	*this += 1;
	return *this;
}
// ����++
// int��������Ҫ��ʵ�Σ���Ϊû�ã���������Ϊ�˸�ǰ��++���ɺ�������
Date Date::operator++(int)
{
	Date tmp(*this);// ��������tmp�����ڷ���
	// ����operator+=
	*this += 1;
	return tmp;
}
// ǰ��--
Date& Date::operator--()
{
	// ����operator-=
	*this -= 1;
	return *this;
}
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);// ��������tmp�����ڷ���
	// ����operator-=
	*this -= 1;
	return tmp;
}
// ���ڵĴ�С��ϵ�Ƚ�
bool Date::operator>(const Date& d) const
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
bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&&_month == d._month
		&&_day == d._day;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}
// ����-����
int Date::operator-(const Date& d) const
{
	Date max = *this;// �����һ�����ڽϴ�
	Date min = d;// ����ڶ������ڽ�С
	int flag = 1;// ��ʱ���Ӧ��Ϊ��ֵ
	if (*this < d)
	{
		// ������󣬸���
		max = d;
		min = *this;
		flag = -1;// ��ʱ���Ӧ��Ϊ��ֵ
	}
	int n = 0;// ��¼���ӵ�������
	while (min != max)
	{
		min++;// ��С������++
		n++;// ������++
	}
	return n*flag;
}
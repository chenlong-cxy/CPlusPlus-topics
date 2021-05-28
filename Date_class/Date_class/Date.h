#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	// ���캯��
	Date(int year = 0, int month = 1, int day = 1);
	// ����+����
	Date operator+(int day);
	// ����+=����
	Date& operator+=(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ǰ��--
	Date& operator--();
	// ����--
	Date operator--(int);
	// ����-����
	int operator-(const Date& d);
	// ���ڵĴ�С��ϵ�Ƚ�
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
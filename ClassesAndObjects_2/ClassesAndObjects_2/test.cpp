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


#include <iostream>
using namespace std;
//������
class Date
{
public:
	//1.�޲ι��캯��
	Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}
	//2.���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;  //�����޲εĹ��캯��
	Date d();  //error���ô���������һ����Ϊd�ĺ������ú����޲Σ�����һ��������Ķ���
	Date d2(2021, 5, 27);  //���ô��εĹ��캯��

	return 0;
}
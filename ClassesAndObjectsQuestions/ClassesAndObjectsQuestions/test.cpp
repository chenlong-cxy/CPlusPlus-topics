////��1+2+3+...+n
//#include <iostream>
//using namespace std;
//class Add
//{
//public:
//	Add() //���캯��
//	{
//		_num++;
//		_ret += _num;
//	}
//	static int _num; //��̬��Ա�������洢�����ۼӵ�����
//	static int _ret; //��̬��Ա�������洢1+2+3+...+n�Ľ��
//};
////��̬��Ա�����Ķ���
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//����������������ܻ��ε��ã����ó�ʼ������
//		Add::_num = 0;
//		Add::_ret = 0;
//		Add* p = new Add[n]; //Ϊn��Add���������ռ�
//		return Add::_ret; //����1+2+3+...+n�Ľ��
//	}
//};
//int main()
//{
//	cout << Solution().Sum_Solution(5) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Add
//{
//	friend class Solution; //����Solution��Add����Ԫ��
//public:
//	Add() //���캯��
//	{
//		_num++;
//		_ret += _num;
//	}
//private:
//	static int _num; //��̬��Ա�������洢�����ۼӵ�����
//	static int _ret; //��̬��Ա�������洢1+2+3+...+n�Ľ��
//};
////��̬��Ա�����Ķ���
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//����������������ܻ��ε��ã����ó�ʼ������
//		Add::_num = 0;
//		Add::_ret = 0;
//		Add* p = new Add[n]; //Ϊn��Add���������ռ�
//		return Add::_ret; //����1+2+3+...+n�Ľ��
//	}
//};
//int main()
//{
//	cout << Solution().Sum_Solution(5) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Add
//{
//public:
//	Add() //���캯��
//	{
//		_num++;
//		_ret += _num;
//	}
//	static void Init() //�Ծ�̬��Ա�������г�ʼ��
//	{
//		_num = 0;
//		_ret = 0;
//	}
//	static int Getret() //��ȡ��̬��Ա����_ret
//	{
//		return _ret;
//	}
//private:
//	static int _num; //��̬��Ա�������洢�����ۼӵ�����
//	static int _ret; //��̬��Ա�������洢1+2+3+...+n�Ľ��
//};
////��̬��Ա�����Ķ���
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//����������������ܻ��ε��ã����ó�ʼ������
//		Add::Init();
//		//Add arr[n];
//		Add* p = new Add[n]; //Ϊn��Add���������ռ�
//		return Add::Getret(); //����1+2+3+...+n�Ľ��
//	}
//};
//int main()
//{
//	cout << Solution().Sum_Solution(5) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}


////����һ��ĵڼ���
//#include <iostream>
//using namespace std;
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day; //��������
//
//	int daysArray[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; //daysArray[i]��ʾ1��-i�µ���������Ĭ��2��Ϊ28�죩
//	int totalDay = daysArray[month - 1] + day; //������
//	if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //�����������Ϊ3�¼����ϣ����Ҹ���Ϊ����
//	{
//		totalDay += 1; //������+1��2��29�գ�
//	}
//
//	cout << totalDay << endl; //�������������������Ϊ����ĵڼ���
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[10];
//	int i = 0;
//	while (cin >> arr[1])
//		i++;
//	for (auto& e : arr)
//	{
//		cout << e << endl;
//		
//	}
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int arr[10];
//	while (scanf("%d", &arr[1])!=EOF)
//		;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}


//���ڲ�ֵ
#include <iostream>
using namespace std;
//�ж��Ƿ�Ϊ����
bool IsLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int main()
{
	int date1, date2; //�洢��������
	int year1, year2, month1, month2, day1, day2; //�洢�������ڵ��ꡢ�¡���
	int ret = 0; //�洢�������ڵĲ�ֵ
	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]����i�µ�������ƽ�꣩
	while (cin >> date1 >> date2) //�����������
	{
		//ȷ����һ�����ڱȵڶ�������С
		if (date1 > date2)
		{
			int tmp = date1;
			date1 = date2;
			date2 = tmp;
		}
		//�����������ڵõ����ꡢ�¡���
		year1 = date1 / 10000, year2 = date2 / 10000;
		day1 = date1 % 100, day2 = date2 % 100;
		month1 = date1 % 10000 / 100, month2 = date2 % 10000 / 100;
		//��������������
		for (int year = year1; year < year2; year++)
		{
			if (IsLeapYear(year))
				ret += 366;
			else
				ret += 365;
		}
		auto getCurYearDays = [&dayArray](int year, int month, int day)->int{
			int total = 0;
			for (int i = 1; i < month; i++) {
				total += dayArray[i];
				if (i == 2 && IsLeapYear(year))
					total++;
			}
			return total + day;
		};
		//��ȥdate1���������
		int days1 = getCurYearDays(year1, month1, day1);
		ret -= days1;
		//����date2���������
		int days2 = getCurYearDays(year2, month2, day2);
		ret += days2;
		ret++; //���Ϊ������[date1, date2]��������Ҫ�ټ�1
		cout << ret << endl;
	}
	return 0;
}


////��ӡ����
//#include <iostream>
//using namespace std;
//int main()
//{
//	int year, day;
//	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]����i�µ�������ƽ�꣩
//	while (cin >> year >> day) //�����������
//	{
//		int month = 1; //month��1�¿�ʼ
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) //�жϸ����Ƿ�Ϊ����
//			dayArray[2] += 1; //����2��Ϊ29��
//		//ʹ���ںϷ�
//		while (day > dayArray[month])
//		{
//			day -= dayArray[month];
//			month++;
//		}
//		//cout<<year<<"-"<<month<<"-"<<day<<endl;
//		printf("%d-%02d-%02d\n", year, month, day); //����ʽ���
//	}
//	return 0;
//}


////�����ۼ�
//#include <iostream>
//using namespace std;
////�ж��Ƿ�Ϊ����
//bool IsLeapYear(int year)
//{
//	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//int main()
//{
//	int m, year, month, day, n;
//	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]����i�µ�������ƽ�꣩
//	cin >> m; //��ȡ��������
//	for (int i = 0; i < m; i++)
//	{
//		cin >> year >> month >> day >> n; //��ȡ�ꡢ�¡��պ���Ҫ�ۼӵ�����
//		if (IsLeapYear(year))
//			dayArray[2] = 29; //����2������Ϊ29��
//		day += n; //�Ƚ���Ҫ�ۼӵ������ӵ����ա���
//		//ʹ���ںϷ�
//		while (day > dayArray[month])
//		{
//			day -= dayArray[month];
//			month++;
//			if (month == 13) //���ꡱ��Ҫ��λ
//			{
//				year++;
//				month = 1;
//				//�ж��µ�һ���Ƿ�Ϊ����
//				if (IsLeapYear(year))
//					dayArray[2] = 29; //����2������Ϊ29��
//				else
//					dayArray[2] = 28; //ƽ��2������Ϊ28��
//			}
//		}
//		printf("%d-%02d-%02d\n", year, month, day); //����ʽ���
//	}
//	return 0;
//}

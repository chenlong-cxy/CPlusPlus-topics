////求1+2+3+...+n
//#include <iostream>
//using namespace std;
//class Add
//{
//public:
//	Add() //构造函数
//	{
//		_num++;
//		_ret += _num;
//	}
//	static int _num; //静态成员变量，存储正在累加的数字
//	static int _ret; //静态成员变量，存储1+2+3+...+n的结果
//};
////静态成员变量的定义
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//多个测试用例，可能会多次调用，做好初始化工作
//		Add::_num = 0;
//		Add::_ret = 0;
//		Add* p = new Add[n]; //为n个Add类对象申请空间
//		return Add::_ret; //返回1+2+3+...+n的结果
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
//	friend class Solution; //声明Solution是Add的有元类
//public:
//	Add() //构造函数
//	{
//		_num++;
//		_ret += _num;
//	}
//private:
//	static int _num; //静态成员变量，存储正在累加的数字
//	static int _ret; //静态成员变量，存储1+2+3+...+n的结果
//};
////静态成员变量的定义
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//多个测试用例，可能会多次调用，做好初始化工作
//		Add::_num = 0;
//		Add::_ret = 0;
//		Add* p = new Add[n]; //为n个Add类对象申请空间
//		return Add::_ret; //返回1+2+3+...+n的结果
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
//	Add() //构造函数
//	{
//		_num++;
//		_ret += _num;
//	}
//	static void Init() //对静态成员变量进行初始化
//	{
//		_num = 0;
//		_ret = 0;
//	}
//	static int Getret() //获取静态成员变量_ret
//	{
//		return _ret;
//	}
//private:
//	static int _num; //静态成员变量，存储正在累加的数字
//	static int _ret; //静态成员变量，存储1+2+3+...+n的结果
//};
////静态成员变量的定义
//int Add::_num = 0;
//int Add::_ret = 0;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//多个测试用例，可能会多次调用，做好初始化工作
//		Add::Init();
//		//Add arr[n];
//		Add* p = new Add[n]; //为n个Add类对象申请空间
//		return Add::Getret(); //返回1+2+3+...+n的结果
//	}
//};
//int main()
//{
//	cout << Solution().Sum_Solution(5) << endl;
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}


////计算一年的第几天
//#include <iostream>
//using namespace std;
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day; //输入日期
//
//	int daysArray[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; //daysArray[i]表示1月-i月的总天数（默认2月为28天）
//	int totalDay = daysArray[month - 1] + day; //总天数
//	if ((month > 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //如果所给日期为3月及以上，并且该年为闰年
//	{
//		totalDay += 1; //总天数+1（2月29日）
//	}
//
//	cout << totalDay << endl; //输出总天数，即该日期为该年的第几天
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


//日期差值
#include <iostream>
using namespace std;
//判断是否为闰年
bool IsLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
int main()
{
	int date1, date2; //存储两个日期
	int year1, year2, month1, month2, day1, day2; //存储两个日期的年、月、日
	int ret = 0; //存储两个日期的差值
	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]代表i月的天数（平年）
	while (cin >> date1 >> date2) //多组测试数据
	{
		//确保第一个日期比第二个日期小
		if (date1 > date2)
		{
			int tmp = date1;
			date1 = date2;
			date2 = tmp;
		}
		//根据两个日期得到其年、月、日
		year1 = date1 / 10000, year2 = date2 / 10000;
		day1 = date1 % 100, day2 = date2 % 100;
		month1 = date1 % 10000 / 100, month2 = date2 % 10000 / 100;
		//计算年相差的天数
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
		//减去date1当年的天数
		int days1 = getCurYearDays(year1, month1, day1);
		ret -= days1;
		//加上date2当年的天数
		int days2 = getCurYearDays(year2, month2, day2);
		ret += days2;
		ret++; //结果为闭区间[date1, date2]，所以需要再加1
		cout << ret << endl;
	}
	return 0;
}


////打印日期
//#include <iostream>
//using namespace std;
//int main()
//{
//	int year, day;
//	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]代表i月的天数（平年）
//	while (cin >> year >> day) //多组测试数据
//	{
//		int month = 1; //month从1月开始
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) //判断该年是否为闰年
//			dayArray[2] += 1; //闰年2月为29天
//		//使日期合法
//		while (day > dayArray[month])
//		{
//			day -= dayArray[month];
//			month++;
//		}
//		//cout<<year<<"-"<<month<<"-"<<day<<endl;
//		printf("%d-%02d-%02d\n", year, month, day); //按格式输出
//	}
//	return 0;
//}


////日期累加
//#include <iostream>
//using namespace std;
////判断是否为闰年
//bool IsLeapYear(int year)
//{
//	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
//}
//int main()
//{
//	int m, year, month, day, n;
//	int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //dayArray[i]代表i月的天数（平年）
//	cin >> m; //读取样例个数
//	for (int i = 0; i < m; i++)
//	{
//		cin >> year >> month >> day >> n; //读取年、月、日和需要累加的天数
//		if (IsLeapYear(year))
//			dayArray[2] = 29; //闰年2月设置为29天
//		day += n; //先将需要累加的天数加到“日”上
//		//使日期合法
//		while (day > dayArray[month])
//		{
//			day -= dayArray[month];
//			month++;
//			if (month == 13) //“年”需要进位
//			{
//				year++;
//				month = 1;
//				//判断新的一年是否为闰年
//				if (IsLeapYear(year))
//					dayArray[2] = 29; //闰年2月设置为29天
//				else
//					dayArray[2] = 28; //平年2月设置为28天
//			}
//		}
//		printf("%d-%02d-%02d\n", year, month, day); //按格式输出
//	}
//	return 0;
//}

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


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[10];
	while (scanf("%d", &arr[1])!=EOF)
		;
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
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
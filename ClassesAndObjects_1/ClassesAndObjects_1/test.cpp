//struct Test
//{
//	//��Ա����
//	int a;
//	double b;
//	//��Ա����
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//};
//
//class className
//{
//	//���壺�ɳ�Ա�����ͳ�Ա�������
//
//};  //ע�����ķֺ�

//#include <iostream>
//using namespace std;
////��
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void ShowInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;  //����
//	char* _sex;   //�Ա�
//	int _age;     //����
//};
//int main()
//{
//
//	return 0;
//}

//#include "test.h"
//#include <iostream>
//using namespace std;
////��ʾ������Ϣ
//void Person::ShowInfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void ShowInfo();
//private:
//	char* _name;  //����
//	char* _sex;   //�Ա�
//	int _age;     //����
//};


//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void ShowInfo();
//private:
//	char* _name;  //����
//	char* _sex;   //�Ա�
//	int _age;     //����
//};
//
////������Ҫָ��ShowInfo������Person�������
//void Person::ShowInfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}
//int main()
//{
//	Person man;
//
//	return 0;
//}

//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void ShowInfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;  //����
//	char* _sex;   //�Ա�
//	int _age;     //����
//};


//#include <iostream>
//using namespace std;
//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//	void f1(){}
//private:
//	int _a;
//};
//// ���н��г�Ա����
//class A2 {
//public:
//	void f2() {}
//};
//// ����ʲô��û��---����
//class A3
//{};
//int main()
//{
//	cout << sizeof(class A1) << endl;
//	cout << sizeof(class A2) << endl;
//	cout << sizeof(class A3) << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//int main()
//{
//	Date d1, d2;//ʵ��������������
//	d1.SetDate(2021, 5, 25);//����d1������
//	d2.SetDate(2021, 5, 26);//����d2������
//	d1.Display();//��ӡd1������
//	d2.Display();//��ӡd2������
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	void Display(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//	void SetDate(Date* this, int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//int main()
//{
//	Date d1, d2;//ʵ��������������
//	d1.SetDate(&d1, 2021, 5, 25);//����d1������
//	d2.SetDate(&d2, 2021, 5, 26);//����d2������
//	d1.Display(&d1);//��ӡd1������
//	d2.Display(&d2);//��ӡd2������
//	return 0;
//}


#include <iostream>
using namespace std;
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;  //��һ�����
	p->PrintA();     //�ڶ������
	p->Show();       //���������
}
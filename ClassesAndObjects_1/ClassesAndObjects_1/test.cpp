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

#include "test.h"
#include <iostream>
using namespace std;
//��ʾ������Ϣ
void Person::ShowInfo()
{
	cout << _name << "-" << _sex << "-" << _age << endl;
}
//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "����"; //����
//	int _age = 18;     //����
//};
////����
//class Student : public Person
//{
//protected:
//	int _stuid;   //ѧ��
//};
////����
//class Teacher : public Person
//{
//protected:
//	int _jobid;   //����
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//private:
//	string _name = "����"; //����
//};
////������
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl; //�������൱�з��ʻ����private��Ա��error!
//	}
//protected:
//	int _stuid;   //ѧ��
//};
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//public:
//	string _name = "����"; //����
//};
////������
//class Student : Person
//{
//protected:
//	int _stuid;   //ѧ��
//};
//int main()
//{
//	Student s;
//	cout << s._name << endl;
//	s.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//protected:
//	string _name; //����
//	string _sex;  //�Ա�
//	int _age;     //����
//};
////������
//class Student : public Person
//{
//protected:
//	int _stuid;   //ѧ��
//};
//int main()
//{
//	Student s;
//	Person p = s;     //���������ֵ���������
//	Person* ptr = &s; //���������ֵ������ָ��
//	Person& ref = s;  //���������ֵ����������
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////����
//class Person
//{
//protected:
//	int _num = 111;
//};
////����
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999;
//};
//int main()
//{
//	Student s;
//	s.fun(); //999
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
//����
class Person
{
public:
	void fun(int x)
	{
		cout << x << endl;
	}
};
//����
class Student : public Person
{
public:
	void fun(double x)
	{
		cout << x << endl;
	}
};
int main()
{
	Student s;
	s.fun(3.14);       //ֱ�ӵ������൱�еĳ�Ա����fun
	s.Person::fun(20); //ָ�����ø��൱�еĳ�Ա����fun
	return 0;
}
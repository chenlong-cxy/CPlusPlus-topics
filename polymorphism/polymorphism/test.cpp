//#include <iostream>
//using namespace std;
////����
//class Person
//{
//public:
//	//��virtual���ε����Ա����
//	//������麯��
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	//������麯����д�˸�����麯��
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//};
////����
//class Soldier : public Person
//{
//public:
//	//������麯����д�˸�����麯��
//	virtual void BuyTicket()
//	{
//		cout << "����-��Ʊ" << endl;
//	}
//};
//void Func(Person& p)
//{
//	//���벻ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
//	//�������õ����麯��
//	p.BuyTicket();
//}
//void Func(Person* p)
//{
//	//���벻ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
//	//����ָ������麯��
//	p->BuyTicket();
//}
//int main()
//{
//	Person p;   //��ͨ��
//	Student st; //ѧ��
//	Soldier sd; //����
//
//	Func(p);  //��Ʊ-ȫ��
//	Func(st); //��Ʊ-���
//	Func(sd); //������Ʊ
//
//	Func(&p);  //��Ʊ-ȫ��
//	Func(&st); //��Ʊ-���
//	Func(&sd); //������Ʊ
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{};
//class B : public A
//{};
//class Student;
//class Person
//{
//public:
//	virtual Person* f(Person& a, Student& b)
//	{
//		cout << "A* Person::f()" << endl;
//		return &a;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual Student* f(Person& a, Student& b)
//	{
//		cout << "B* Student::f()" << endl;
//		return &b;
//	}
//};
//int main()
//{
//	return 0;
//}

//#include <iostream>
//using namespace std;
////����
//class A
//{};
////����
//class B : public A
//{};
////����
//class Person
//{
//public:
//	//���ػ���A��ָ��
//	virtual A* fun()
//	{
//		cout << "A* Person::f()" << endl;
//		return new A;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	//��������B��ָ��
//	virtual B* fun()
//	{
//		cout << "B* Student::f()" << endl;
//		return new B;
//	}
//};
//int main()
//{
//	Person p;
//	Student st;
//	//����ָ��ָ�������
//	Person* ptr1 = &p;
//	//����ָ��ָ���������
//	Person* ptr2 = &st;
//	//����ָ��ptr1ָ���p�Ǹ�����󣬵��ø�����麯��
//	ptr1->fun(); //A* Person::f()
//	//����ָ��ptr2ָ���st��������󣬵���������麯��
//	ptr2->fun(); //B* Student::f()
//	return 0;
//}

#include <iostream>
using namespace std;
//����
class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
//����
class Student : public Person
{
public:
	virtual ~Student()
	{
		cout << "~Student()" << endl;
	}
};
int main()
{
	//Person p;
	//Student st;

	//�ֱ�newһ����������������󣬲����ø���ָ��ָ������
	Person* p1 = new Person;
	Person* p2 = new Student;

	//ʹ��delete���������������ͷŶ���ռ�
	delete p1;
	delete p2;

	return 0;
}
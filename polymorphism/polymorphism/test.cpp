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

//#include <iostream>
//using namespace std;
////����
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//int main()
//{
//	//Person p;
//	//Student st;
//
//	//�ֱ�newһ����������������󣬲����ø���ָ��ָ������
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//ʹ��delete���������������ͷŶ���ռ�
//	delete p1;
//	delete p2;
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int val;
//	struct Node* next;
//};
//struct Node* fun(struct Node* pd)
//{
//	struct Node* phead = (struct Node*)malloc(sizeof(struct Node));
//	phead->next = pd;
//	struct Node* prev = phead;
//	struct Node* after = prev->next;
//	struct Node* curprev = after;
//	struct Node* cur = after->next;
//	while (cur)
//	{
//		while (cur&&cur->val >= 0)
//		{
//			curprev = curprev->next;
//			cur = cur->next;
//		}
//		if (cur)
//		{
//			struct Node* tmp = cur->next;
//			curprev->next = cur->next;
//			prev->next = cur;
//			cur->next = after;
//			prev = cur;
//			cur = tmp;
//		}
//	}
//	struct Node* head = phead->next;
//	free(phead);
//	return head;
//}
//int main()
//{
//	struct Node d1;
//	struct Node d2;
//	struct Node d3;
//	struct Node d4;
//	struct Node d5;
//	struct Node d6;
//	struct Node d7;
//	d1.val = 1;
//	d2.val = -5;
//	d3.val = -4;
//	d4.val = 2;
//	d5.val = 8;
//	d6.val = -9;
//	d7.val = 10;
//	d1.next = &d2;
//	d2.next = &d3;
//	d3.next = &d4;
//	d4.next = &d5;
//	d5.next = &d6;
//	d6.next = &d7;
//	d7.next = NULL;
//	struct Node* ret = fun(&d1);
//	while (ret)
//	{
//		printf("%d ", ret->val);
//		ret = ret->next;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
////����
//class Person
//{
//public:
//	//��final���Σ����麯�������ٱ���д
//	virtual void BuyTicket() final
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//	}
//};
////����
//class Student : public Person
//{
//public:
//	//��д�����뱨��
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ-���" << endl;
//	}
//};
////����
//class Soldier : public Person
//{
//public:
//	//��д�����뱨��
//	virtual void BuyTicket()
//	{
//		cout << "����-��Ʊ" << endl;
//	}
//};

#include <iostream>
using namespace std;
//����
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};
//����
class Student : public Person
{
public:
	//��������˸����麯������д������ͨ��
	virtual void BuyTicket() override
	{
		cout << "��Ʊ-���" << endl;
	}
};
//����
class Soldier : public Person
{
public:
	//����û������˸����麯������д�����뱨��
	virtual void BuyTicket(int i) override
	{
		cout << "����-��Ʊ" << endl;
	}
};

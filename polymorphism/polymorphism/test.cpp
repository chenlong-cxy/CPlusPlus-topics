//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//	//被virtual修饰的类成员函数
//	//父类的虚函数
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//子类的虚函数重写了父类的虚函数
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
////子类
//class Soldier : public Person
//{
//public:
//	//子类的虚函数重写了父类的虚函数
//	virtual void BuyTicket()
//	{
//		cout << "优先-买票" << endl;
//	}
//};
//void Func(Person& p)
//{
//	//传入不同类型的对象，调用的是不同的函数，实现了调用的多种形态
//	//父类引用调用虚函数
//	p.BuyTicket();
//}
//void Func(Person* p)
//{
//	//传入不同类型的对象，调用的是不同的函数，实现了调用的多种形态
//	//父类指针调用虚函数
//	p->BuyTicket();
//}
//int main()
//{
//	Person p;   //普通人
//	Student st; //学生
//	Soldier sd; //军人
//
//	Func(p);  //买票-全价
//	Func(st); //买票-半价
//	Func(sd); //优先买票
//
//	Func(&p);  //买票-全价
//	Func(&st); //买票-半价
//	Func(&sd); //优先买票
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
////基类
//class A
//{};
////子类
//class B : public A
//{};
////基类
//class Person
//{
//public:
//	//返回基类A的指针
//	virtual A* fun()
//	{
//		cout << "A* Person::f()" << endl;
//		return new A;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//返回子类B的指针
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
//	//父类指针指向父类对象
//	Person* ptr1 = &p;
//	//父类指针指向子类对象
//	Person* ptr2 = &st;
//	//父类指针ptr1指向的p是父类对象，调用父类的虚函数
//	ptr1->fun(); //A* Person::f()
//	//父类指针ptr2指向的st是子类对象，调用子类的虚函数
//	ptr2->fun(); //B* Student::f()
//	return 0;
//}

//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
////子类
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
//	//分别new一个父类对象和子类对象，并均用父类指针指向它们
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	//使用delete调用析构函数并释放对象空间
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
////父类
//class Person
//{
//public:
//	//被final修饰，该虚函数不能再被重写
//	virtual void BuyTicket() final
//	{
//		cout << "买票-全价" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//重写，编译报错
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
////子类
//class Soldier : public Person
//{
//public:
//	//重写，编译报错
//	virtual void BuyTicket()
//	{
//		cout << "优先-买票" << endl;
//	}
//};

#include <iostream>
using namespace std;
//父类
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};
//子类
class Student : public Person
{
public:
	//子类完成了父类虚函数的重写，编译通过
	virtual void BuyTicket() override
	{
		cout << "买票-半价" << endl;
	}
};
//子类
class Soldier : public Person
{
public:
	//子类没有完成了父类虚函数的重写，编译报错
	virtual void BuyTicket(int i) override
	{
		cout << "优先-买票" << endl;
	}
};

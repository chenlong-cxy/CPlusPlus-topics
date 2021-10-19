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

//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	//子类完成了父类虚函数的重写，编译通过
//	virtual void BuyTicket() override
//	{
//		cout << "买票-半价" << endl;
//	}
//};
////子类
//class Soldier : public Person
//{
//public:
//	//子类没有完成了父类虚函数的重写，编译报错
//	virtual void BuyTicket(int i) override
//	{
//		cout << "优先-买票" << endl;
//	}
//};

//#include <iostream>
//using namespace std;
////抽象类（接口类）
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//int main()
//{
//	Car c; //抽象类不能实例化出对象，error
//	return 0;
//}

//#include <iostream>
//using namespace std;
////抽象类（接口类）
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
////派生类
//class Benz : public Car
//{
//public:
//	//重写纯虚函数
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
////派生类
//class BMV : public Car
//{
//public:
//	//重写纯虚函数
//	virtual void Drive()
//	{
//		cout << "BMV-操控" << endl;
//	}
//};
//int main()
//{
//	//派生类重写了纯虚函数，可以实例化出对象
//	Benz b1;
//	BMV b2;
//	//不同对象用基类指针调用Drive函数，完成不同的行为
//	Car* p1 = &b1;
//	Car* p2 = &b2;
//	p1->Drive();  //Benz-舒适
//	p2->Drive();  //BMV-操控
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl; //8
//	return 0;
//}

//#include <iostream>
//using namespace std;
////父类
//class Base
//{
//public:
//	//虚函数
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	//虚函数
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	//普通成员函数
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
////子类
//class Derive : public Base
//{
//public:
//	//重写虚函数Func1
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//	int _p = 1;
//};
////子类
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//	int _s = 2;
//};
//int main()
//{
//	Person Mike;
//	Student Johnson;
//	Johnson._p = 3; //以便观察是否完成切片
//	Person* p1 = &Mike;
//	Person* p2 = &Johnson;
//	p1->BuyTicket(); //买票-全价
//	p2->BuyTicket(); //买票-半价
//	return 0;
//}

//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
////子类
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//int main()
//{
//	Student Johnson;
//	//Person p = Johnson; //不构成多态
//	Person& p = Johnson; //构成多态
//	p.BuyTicket();
//	return 0;
//}

//#include <iostream>
//using namespace std;
////父类
//class Base
//{
//public:
//	//虚函数
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	//虚函数
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	//普通成员函数
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
////子类
//class Derive : public Base
//{
//public:
//	//重写虚函数Func1
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int j = 0;
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("vfptr:%p\n", *((int*)p)); //000FDCAC
//	int i = 0;
//	printf("栈上地址:%p\n", &i);      //005CFE24
//	printf("数据段地址:%p\n", &j);    //0010038C
//
//	int* k = new int;
//	printf("堆上地址:%p\n", k);       //00A6CA00
//	char* cp = "hello world";
//	printf("代码段地址:%p\n", cp);    //000FDCB4
//	return 0;
//}


//#include <iostream>
//using namespace std;
////基类
//class Base
//{
//public:
//	virtual void func1() { cout << "Base::func1()" << endl; }
//	virtual void func2() { cout << "Base::func2()" << endl; }
//private:
//	int _a;
//};
////派生类
//class Derive : public Base
//{
//public:
//	virtual void func1() { cout << "Derive::func1()" << endl; }
//	virtual void func3() { cout << "Derive::func3()" << endl; }
//	virtual void func4() { cout << "Derive::func4()" << endl; }
//private:
//	int _b;
//};
//typedef void(*VFPTR)(); //虚函数指针类型重命名
////打印虚表地址及其内容
//void PrintVFT(VFPTR* ptr)
//{
//	printf("虚表地址:%p\n", ptr);
//	for (int i = 0; ptr[i] != nullptr; i++)
//	{
//		printf("ptr[%d]:%p-->", i, ptr[i]); //打印虚表当中的虚函数地址
//		ptr[i](); //使用虚函数地址调用虚函数
//	}
//	printf("\n");
//}
//int main()
//{
//	Base b;
//	PrintVFT((VFPTR*)(*(int*)&b)); //打印基类对象b的虚表地址及其内容
//	Derive d;
//	PrintVFT((VFPTR*)(*(int*)&d)); //打印派生类对象d的虚表地址及其内容
//	return 0;
//}


//#include <iostream>
//using namespace std;
////基类1
//class Base1
//{
//public:
//	virtual void func1() { cout << "Base1::func1()" << endl; }
//	virtual void func2() { cout << "Base1::func2()" << endl; }
//private:
//	int _b1;
//};
////基类2
//class Base2
//{
//public:
//	virtual void func1() { cout << "Base2::func1()" << endl; }
//	virtual void func2() { cout << "Base2::func2()" << endl; }
//private:
//	int _b2;
//};
////多继承派生类
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void func1() { cout << "Derive::func1()" << endl; }
//	virtual void func3() { cout << "Derive::func3()" << endl; }
//private:
//	int _d1;
//};
//typedef void(*VFPTR)(); //虚函数指针类型重命名
////打印虚表地址及其内容
//void PrintVFT(VFPTR* ptr)
//{
//	printf("虚表地址:%p\n", ptr);
//	for (int i = 0; ptr[i] != nullptr; i++)
//	{
//		printf("ptr[%d]:%p-->", i, ptr[i]); //打印虚表当中的虚函数地址
//		ptr[i](); //使用虚函数地址调用虚函数
//	}
//	printf("\n");
//}
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	PrintVFT((VFPTR*)(*(int*)&b1)); //打印基类对象b1的虚表地址及其内容
//	PrintVFT((VFPTR*)(*(int*)&b2)); //打印基类对象b2的虚表地址及其内容
//	Derive d;
//	PrintVFT((VFPTR*)(*(int*)&d)); //打印派生类对象d的第一个虚表地址及其内容
//	PrintVFT((VFPTR*)(*(int*)((char*)&d + sizeof(Base1)))); //打印派生类对象d的第二个虚表地址及其内容
//	return 0;
//}


#include <iostream>
using namespace std;
class A
{
public:
	virtual void funcA()
	{
		cout << "A::funcA()" << endl;
	}
private:
	int _a;
};
class B : virtual public A
{
public:
	virtual void funcA()
	{
		cout << "B::funcA()" << endl;
	}
	virtual void funcB()
	{
		cout << "B::funcB()" << endl;
	}
private:
	int _b;
};
class C : virtual public A
{
public:
	virtual void funcA()
	{
		cout << "C::funcA()" << endl;
	}
	virtual void funcC()
	{
		cout << "C::funcC()" << endl;
	}
private:
	int _c;
};
class D : public B, public C
{
public:
	virtual void funcA()
	{
		cout << "D::funcA()" << endl;
	}
	virtual void funcD()
	{
		cout << "D::funcD()" << endl;
	}
private:
	int _d;
};
typedef void(*VFPTR)(); //虚函数指针类型重命名
//打印虚表地址及其内容
void PrintVFT(VFPTR* ptr)
{
	printf("虚表地址:%p\n", ptr);
	for (int i = 0; ptr[i] != nullptr; i++)
	{
		printf("ptr[%d]:%p-->", i, ptr[i]); //打印虚表当中的虚函数地址
		ptr[i](); //使用虚函数地址调用虚函数
	}
	printf("\n");
}
int main()
{
	A a;
	B b;
	C c;
	D d;

	printf("A\n");
	PrintVFT((VFPTR*)(*(int*)&a));
	printf("B\n");
	PrintVFT((VFPTR*)(*(int*)&b));
	printf("B:%d\n", sizeof(B));
	PrintVFT((VFPTR*)(*(int*)((char*)&d + 12)));
	printf("C\n");
	PrintVFT((VFPTR*)(*(int*)&c));
	return 0;
}
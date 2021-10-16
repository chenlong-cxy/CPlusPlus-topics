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

#include <iostream>
using namespace std;
//父类
class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
//子类
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

	//分别new一个父类对象和子类对象，并均用父类指针指向它们
	Person* p1 = new Person;
	Person* p2 = new Student;

	//使用delete调用析构函数并释放对象空间
	delete p1;
	delete p2;

	return 0;
}
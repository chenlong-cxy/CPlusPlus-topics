#include <iostream>
using namespace std;
//int main()
//{
//	//隐式类型转换
//	int i = 1;
//	double d = i;
//	cout << i << endl;
//	cout << d << endl;
//
//	//显式类型转换
//	int* p = &i;
//	int address = (int)p;
//	cout << p << endl;
//	cout << address << endl;
//	return 0;
//}
//static_cast
//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	int* p = &a;
//	// int address = static_cast<int>(p); //error
//	return 0;
//}

//reinterpret_cast
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int address = reinterpret_cast<int>(p);
//	cout << address << endl;
//	return 0;
//}
//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" << i << endl;
//	return 0;
//}
//int main()
//{
//	FUNC f = reinterpret_cast<FUNC>(DoSomething);
//	f();
//	cout << typeid(DoSomething).name() << endl;
//	cout << typeid(f).name() << endl;
//	return 0;
//}

//const_cast
//int main()
//{
//	//volatile const int a = 2;
//	const int a = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl;  //2
//	cout << *p << endl; //3
//	return 0;
//}

//dynamic_cast
//class A
//{
//public:
//	virtual void f()
//	{}
//};
//class B : public A
//{};
//void func(A* pa)
//{
//	//B* pb1 = static_cast<B*>(pa);
//	B* pb1 = (B*)pa;               //不安全
//	B* pb2 = dynamic_cast<B*>(pa); //安全
//
//	cout << "pb1: " << pb1 << endl;
//	cout << "pb2: " << pb2 << endl;
//}
//int main()
//{
//	A a;
//	B b;
//	func(&a);
//	func(&b);
//	return 0;
//}

//explicit
class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	//A a2 = 1; //error
	return 0;
}

//RTTI
//int main()
//{
//	int a = 10;
//	cout << typeid(a).name() << endl; //int
//
//	decltype(a) b = 20;
//	cout << typeid(b).name() << endl; //int
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//#include <iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include <iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include <stdio.h>
//namespace N1
//{
//	int printf;
//	namespace N2
//	{
//		int a;
//	}
//}
//int main()
//{
//	N1::printf = 10;
//	printf("%d\n", N1::printf);
//	N1::N2::a = 10;
//	return 0;
//}

//#include <iostream>
////命名空间的普通定义
//namespace N1 //N1为命名空间的名称
//{
//	//在命名空间中，既可以定义变量，也可以定义函数
//	int a;
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}


////命名空间的嵌套定义
//namespace N1 //定义一个名为N1的命名空间
//{
//	int a;
//	int b;
//	namespace N2 //嵌套定义另一个名为N2的命名空间
//	{
//		int c;
//		int d;
//	}
//}
//int main()
//{
//	N1::a = 20;
//	N1::N2::a = 10;
//	std::cout << N1::a << std::endl << N1::N2::a << std::endl;
//	return 0;
//}

//命名空间的使用
//加命名空间名称及作用域限定符
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//int main()
//{
//	N::a = 10;//将命名空间中的成员a赋值为10
//	printf("%d\n", N::a);//打印命名空间中的成员a
//	return 0;
//}

//使用using将命名空间中的成员引入
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//using N::a;//将命名空间中的成员a引入
//int main()
//{
//	a = 10;//将命名空间中的成员a赋值为10
//	printf("%d\n", a);//打印命名空间中的成员a
//	return 0;
//}

////使用using namespace 命名空间名称引入
//#include <stdio.h>
//namespace N
//{
//	int a;
//	double b;
//}
//using namespace N;//将命名空间N的所有成员引入
//int main()
//{
//	a = 10;//将命名空间中的成员a赋值为10
//	printf("%d\n", a);//打印命名空间中的成员a
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world!" << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i = 10;
//	double d = 3.14;
//	char arr[] = "是不是很方便？";
//	cout << i << endl;//打印整型i
//	cout << d << endl;//打印浮点型d
//	cout << arr << endl;//打印字符串arr
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i;
//	double d;
//	char arr[20];
//	cin >> i;//读取一个整型
//	cin >> d;//读取一个浮点型
//	cin >> arr;//读取一个字符串
//	cout << i << endl;//打印整型i
//	cout << d << endl;//打印浮点型d
//	cout << arr << endl;//打印字符串arr
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void Print(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print();//没有指定实参，使用参数的默认值（打印0）
//	Print(10);//指定了实参，使用指定的实参（打印10）
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void Print(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	Print();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int x = 20;
//void Print(int a, int b, int c = x)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	x = 20;
//	Print(10, 20);
//	x = 10;
//	Print(10, 20);
//	return 0;
//}

////test.h
//#include "test.h"
//#include <iostream>
//using namespace std;
////test.c
//void Print(int a, int b, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	Print(10, 20);
//	return 0;
//}

//int x = 30;//全局变量
//void Print(int a, int b, int c = x)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}


//#include <iostream>
//using namespace std;
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;//打印1+2的结果
//	cout << Add(1.1, 2.2) << endl;//打印1.1+2.2的结果
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//给变量a去了一个别名，叫b
//	cout << "a = " << a << endl;//a打印结果为10
//	cout << "b = " << b << endl;//b打印结果也是10
//	b = 20;//改变b也就是改变了a
//	cout << "a = " << a << endl;//a打印结果为20
//	cout << "b = " << b << endl;//b打印结果也是为20
//	return 0;
//}

//int a = 10;
//int& b = a;//引用在定义时必须初始化
//
//int& b;
//b = a;

//int a = 10;
//int& b = a;
//int& c = a;
//int& d = a;

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	b = c;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	const int a = 10;
//	//int& ra = a;    //该语句编译时会出错，a为常量
//	const int& ra = a;
//	//int& b = 10;    //该语句编译时会出错，10为常量
//	const int& b = 10;
//	return 0;
//}

////交换函数
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "a = " << a << " " << "b = " << b << endl;
//	Swap(a, b);
//	cout << "a = " << a << " " << "b = " << b << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//int main()
//{
//	int& a = Add(1, 2);
//	cout << a << endl;
//	Add(10, 20);
//	cout << a << endl;
//	return 0;
//}


//#include <time.h>
//#include <iostream>
//using namespace std;
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//在语法上，这里给a这块空间取了一个别名，没有新开空间
//	int& ra = a;
//	ra = 20;
//
//	//在语法上，这里定义了一个pa指针，开辟了4个字节（32位机器）的空间，用于存储a的地址
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = Add(1, 2);
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//double Fun()
//{
//	return 3.14;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'A';
//	auto d = Fun();
//	//打印变量b,c,d的类型
//	cout << typeid(b).name() << endl;//打印int
//	cout << typeid(c).name() << endl;//打印char
//	cout << typeid(d).name() << endl;//打印double
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	auto b = &a;   //自动推导出b的类型为int*
//	auto* c = &a;  //自动推导出c的类型为int*
//	auto d = a;    //自动推导出d的类型为int
//	auto& e = a;   //自动推导出e的类型为int
//	//打印变量b,c,d的类型
//	cout << typeid(b).name() << endl;//打印结果为int*
//	cout << typeid(c).name() << endl;//打印结果为int*
//	cout << typeid(d).name() << endl;//打印结果为int
//	cout << typeid(e).name() << endl;//打印结果为int
//	return 0;
//}


//int main()
//{
//	auto a = 1, b = 2; //正确
//	auto c = 3, d = 4.0; //编译器报错：“auto”必须始终推导为同一类型
//	return 0;
//}


//void TestAuto(auto x)
//{}


//int main()
//{
//	int a[] = { 1, 2, 3 };
//	auto b[] = { 4, 5, 6 };//error
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//将数组元素值全部乘以2
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		arr[i] *= 2;
//	}
//	//打印数组中的所有元素
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	//将数组元素值全部乘以2
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	//打印数组中的所有元素
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <stdio.h>
//NULL
//#define NULL    ((void *)0)

//#include <iostream>
//NULL
//#define NULL    0
//nullptr
//#include <stddef.h>
//int* p1 = NULL;
//int* p2 = 0;

//#include <iostream>
//using namespace std;
//void Fun(int p)
//{
//	cout << "Fun(int)" << endl;
//}
//void Fun(int* p)
//{
//	cout << "Fun(int*)" << endl;
//}
//int main()
//{
//	Fun(0);           //打印结果为 Fun(int)
//	Fun(NULL);        //打印结果为 Fun(int)
//	Fun((int*)NULL);  //打印结果为 Fun(int*)
//	Fun(nullptr);
//	return 0;
//}

#include <iostream>
using namespace std;
void Fun(int a, double b)
{
	cout << "a" << endl;
}
void Fun(double a, int b)
{
	cout << "b" << endl;
}
int main()
{
	Fun(1, 1.1);
	Fun(1.1, 1);
	return 0;
}
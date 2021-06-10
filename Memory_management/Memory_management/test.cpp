//#include <stdlib.h>
//
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	free(ptr1);
//	free(ptr3);
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	//栈区开辟空间，先开辟的空间地址高
//	int a = 10;
//	int b = 20;
//	cout << &a << endl;
//	cout << &b << endl;
//
//	//堆区开辟空间，先开辟的空间地址低
//	int* c = (int*)malloc(sizeof(int)* 10);
//	int* d = (int*)malloc(sizeof(int)* 10);
//	cout << c << endl;
//	cout << d << endl;
//	return 0;
//}


//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//int main()
//{
//	//动态申请10个int类型的空间
//	int* p1 = (int*)malloc(sizeof(int)* 10);
//	int* p2 = new int[10];
//	cout << p2 << endl;
//	free(p1);
//	delete[] p2;
//	cout << p2 << endl;
//	//动态申请单个int类型的空间
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//
//	free(p3);
//	delete p4;
//	
//	//动态申请单个int类型的空间并初始化为10
//	int* p5 = (int*)malloc(sizeof(int));
//	*p5 = 10;
//	int* p6 = new int(10);
//
//	free(p5);
//	delete p6;
//
//	//动态申请10个int类型的空间并初始化为0到9
//	int* p7 = (int*)malloc(sizeof(int)* 10);
//	for (int i = 0; i < 10; i++)
//	{
//		p7[i] = i;
//	}
//	int* p8 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//	free(p7);
//	delete[] p8;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Test
//{
//public:
//	Test() //构造函数
//		:_a(0)
//	{
//		cout << "构造函数" << endl;
//	}
//	~Test() //析构函数
//	{
//		cout << "析构函数" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Test* p1 = new Test;
//	delete p1;
//
//	Test* p2 = (Test*)malloc(sizeof(Test));
//	free(p2);
//
//	Test* p3 = new Test[10];
//	delete[] p3;
//
//	Test* p4 = (Test*)malloc(sizeof(Test)* 10);
//	free(p4);
//	return 0;
//}


#include <iostream>

//using namespace std;
//int main()
//{
//	void* p1 = malloc(0xffffffff);
//	if (p1 == NULL)
//	{
//		cout << "error" << endl;
//	}
//	free(p1);
//
//	//int* p2 = (int*)operator new(0xffffffff);
//	//operator delete(p2);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int* p = new int;
//	cout << p << endl;
//	delete p;
//	cout << p << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int* p1 = (int*)operator new(sizeof(int)* 10);
//	operator delete(p1);
//
//	int* p2 = (int*)operator new(sizeof(int)* 10);
//	free(p2);
//	return 0;
//}



//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//void Test()
//{
//	int* p1 = (int*)malloc(INT_MAX);
//	if (p1 == NULL)
//	{
//		cout << "malloc fail" << endl;
//	}
//	free(p1);
//
//	int* p2 = (int*)operator new(INT_MAX);
//	delete p2;
//}
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0) //构造函数 
//		:_a(a)
//	{}
//
//	~A() //析构函数
//	{}
//private:
//	int _a;
//};
//int main()
//{
//	//new(place_address)type 形式
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;
//
//	//new(place_address)type(initializer-list) 形式
//	A* p2 = (A*)malloc(sizeof(A));
//	new(p2)A(2021);
//
//	//析构函数也可以显示调用
//	p1->~A();
//	p2->~A();
//	return 0;
//}


//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 2.异常安全问题
//	int* p3 = new int[10];
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//	delete[] p3;
//}


#include <iostream>
using namespace std;
int main()
{
	//0xfffffffful转换为十进制就是4G
	void* p = malloc(0xffffffffful);
	cout << p << endl;

	return 0;
}
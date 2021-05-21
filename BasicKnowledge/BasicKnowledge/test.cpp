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

#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int& b = a;//给变量a去了一个别名，叫b
	cout << "a = " << a << endl;//a打印结果为10
	cout << "b = " << b << endl;//b打印结果也是10
	b = 20;//改变b也就是改变了a
	cout << "a = " << a << endl;//a打印结果为20
	cout << "b = " << b << endl;//b打印结果也是为20
	return 0;
}
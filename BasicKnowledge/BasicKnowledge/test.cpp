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

#include <iostream>
//命名空间的普通定义
namespace N1 //N1为命名空间的名称
{
	//在命名空间中，既可以定义变量，也可以定义函数
	int a;
	int Add(int x, int y)
	{
		return x + y;
	}
}


//命名空间的嵌套定义
namespace N1 //定义一个名为N1的命名空间
{
	int a;
	int b;
	namespace N2 //嵌套定义另一个名为N2的命名空间
	{
		int c;
		int d;
	}
}
//int main()
//{
//	N1::a = 20;
//	N1::N2::a = 10;
//	std::cout << N1::a << std::endl << N1::N2::a << std::endl;
//	return 0;
//}
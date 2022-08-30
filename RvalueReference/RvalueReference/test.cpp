//#include <iostream>
//using namespace std;
//int main()
//{
//	//以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	//以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	
//	//以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	//以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double rr3 = fmin(x, y);
//
//	//这里编译会报错：error C2106: “=”: 左操作数必须为左值（右值不能出现在赋值符号的左边）
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	cout << &rr1 << endl;
//	const double&& rr2 = x + y;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//	//rr2 = 5.5; //报错
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T>
//void func(const T& x)
//{}
//int main()
//{
//	//左值引用只能引用左值，不能引用右值
//	int a = 10;
//	int& ra1 = a; //ra1为a的别名
//	//int& ra2 = 10; //编译失败，因为10是右值
//
//	//const左值引用既可以引用左值，也可引用右值
//	const int& ra3 = a;
//	const int& ra4 = 10;
//	return 0;
//}


#include <iostream>
using namespace std;
int main()
{
	//右值引用只能引用右值，不能引用左值
	int&& r1 = 10;

	//error C2440: “初始化”: 无法从“int”转换为“int &&”
	//message : 无法将左值绑定到右值引用
	int a = 10;
	int&& r2 = a;

	//右值引用可以引用move以后的左值
	int&& r3 = std::move(a);
	return 0;
}
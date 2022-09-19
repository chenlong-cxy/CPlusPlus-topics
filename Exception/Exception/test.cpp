//try
//{
//	//保护的标识代码
//}
//catch (ExceptionName e1)
//{
//	//catch块
//}
//catch (ExceptionName e2)
//{
//	//catch块
//}
//catch (ExceptionName eN)
//{
//	//catch块
//}

////这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void func() throw(A, B, C, D);
////这里表示这个函数只会抛出bad_alloc的异常
//void* operator new(std::size_t size) throw(std::bad_alloc);
////这里表示这个函数不会抛出异常
//void* operator new(std::size_t size, void* ptr) throw();


//#include <iostream>
//using namespace std;
//int main()
//{
//	try{
//		char* ptr = new char[0x7fffffff];
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl; //bad allocation
//	}
//	return 0;
//}


//#include <iostream>
//using namespace std;
//void f1()
//{
//	int i, j;
//	cin >> i >> j;
//	if (j == 0)
//	{
//		throw 1;
//	}
//	cout << i / j << endl;
//}
//int main()
//{
//	try
//	{
//		f1();
//	}
//	catch (int errid)
//	{
//		cout << "错误码: " << errid << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
void f1()
{
	int i, j;
	cin >> i >> j;
	if (j == 0)
	{
		throw string("除零错误");
	}
	cout << i / j << endl;
}
int main()
{
	try
	{
		f1();
	}
	catch (int errid)
	{
		cout << "错误码: " << errid << endl;
	}
	catch (const string& s)
	{
		cout << "错误描述: " << s << endl;
	}
	return 0;
}
//#include <iostream>
//using namespace std;
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count: " << ++count << endl;
//	cout << "count: " << &count << endl;
//
//	return f(x);
//}
//double func(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	//������
//	cout << useF(func, 11.11) << endl;
//
//	//��������
//	cout << useF(Functor(), 11.11) << endl;
//
//	//lambda���ʽ
//	cout << useF([](double d)->double{return d / 4; }, 11.11) << endl;
//	return 0;
//}


//template <class T> function;     // undefined
//template <class Ret, class... Args>
//class function<Ret(Args...)>;


#include <iostream>
#include <functional>
using namespace std;
int f(int a, int b)
{
	return a + b;
}
struct Functor
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}
	double plusd(double a, double b)
	{
		return a + b;
	}
};
int main()
{
	//������������ָ�룩
	function<int(int, int)> func1 = f;
	cout << func1(1, 2) << endl;

	//�������󣨷º�����
	function<int(int, int)> func2 = Functor();
	cout << func2(1, 2) << endl;

	//lambda���ʽ
	function<int(int, int)> func3 = [](int a, int b){return a + b; };
	cout << func3(1, 2) << endl;

	//��ľ�̬��Ա����
	//function<int(int, int)> func4 = Plus::plusi;
	function<int(int, int)> func4 = &Plus::plusi;
	cout << func4(1, 2) << endl;

	//��ķǾ�̬��Ա����
	function<double(Plus, double, double)> func5 = &Plus::plusd;
	cout << func5(Plus(), 1.1, 2.2) << endl;
	return 0;
}
//#include <iostream>
//using namespace std;
//// 交换两个整型
//void Swapi(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//// 交换两个双精度浮点型
//void Swapd(double* p1, double* p2)
//{
//	double tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}

//// 交换两个整型
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//// 交换两个双精度浮点型
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}


//template <class T1, class T2, ..., class Tn>
//template <typename T1,typename T2,...,typename Tn>


//#include <iostream>
//using namespace std;
//template <class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	double x = 1.1;
//	double y = 2.2;
//	Swap(x, y);
//	cout << "x:" << x << endl;
//	cout << "y:" << y << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	//int a = 10, b = 20;
//	//int c = Add(a, b);//编译器根据实参a和b推演出模板参数为int类型
//
//	int a = 10;
//	double b = 1.1;
//	int c = Add(a, b);
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10;
//	double b = 1.1;
//	int c = Add<int>(a, b);//指定模板参数的实际类型为int
//	return 0;
//}


//#include <iostream>
//using namespace std;
////专门用于int类型加法的非模板函数
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////通用类型加法的函数模板
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 10, b = 20;
//	int c = Add(a, b); //调用非模板函数，编译器不需要实例化
//	int d = Add<int>(a, b); //调用编译器实例化的Add函数
//	return 0;
//}


//#include <iostream>
//using namespace std;
////专门用于int类型加法的非模板函数
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}
////通用类型加法的函数模板
//template <typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = Add(10, 20); //与非模板函数完全匹配，不需要函数模板实例化
//	int b = Add<int>(2, 2.2); //函数模板可以生成更加匹配的版本，编译器会根据实参生成更加匹配的Add函数
//	return 0;
//}

//#include <iostream>
//using namespace std;
//template<typename T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = Add(2, 2.2); //模板函数不允许自动类型转换，不能通过编译
//	return 0;
//}


//template<class T1,class T2,...,class Tn>
//class 类模板名
//{
//	//类内成员声明
//};

//#include <iostream>
//using namespace std;
//template<class T>
//class Score
//{
//public:
//	void Print()
//	{
//		cout << "数学:" << _Math << endl;
//		cout << "语文:" << _Chinese << endl;
//		cout << "英语:" << _English << endl;
//	}
//private:
//	T _Math;
//	T _Chinese;
//	T _English;
//};
//int main()
//{
//	Score<double> s1;
//	s1.Print();
//	return 0;
//}


#include <iostream>
using namespace std;
template<class T>
class Score
{
public:
	void Print();
private:
	T _Math;
	T _Chinese;
	T _English;
};
//类模板中的成员函数在类外定义，需要加模板参数列表
template<class T>
void Score<T>::Print()
{
	cout << "数学:" << _Math << endl;
	cout << "语文:" << _Chinese << endl;
	cout << "英语:" << _English << endl;
}
int main()
{
	//Score不是真正的类，Score<int>和Score<double>才是真正的类
	Score<int> s1;
	Score<double> s2;
	s1.Print();
	return 0;
}
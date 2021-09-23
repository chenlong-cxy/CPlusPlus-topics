#include "Add.h"
int main()
{
	//调用函数模板实例化的函数
	cout << Add(10, 20) << endl;
	cout << Add(10.1, 20.2) << endl;
	return 0;
}


//#include <iostream>
//using namespace std;
//
//template<class T, size_t N> //N：非类型模板参数
//class StaticArray
//{
//public:
//	size_t arraysize()
//	{
//		return N;
//	}
//private:
//	T _array[N]; //利用非类型模板参数指定静态数组的大小
//};
//
//int main()
//{
//	StaticArray<int, 10> a1; //定义一个大小为10的静态数组
//	cout << a1.arraysize() << endl; //10
//	StaticArray<int, 100> a2; //定义一个大小为100的静态数组
//	cout << a2.arraysize() << endl; //100
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//template<class T>
//bool IsEqual(T x, T y)
//{
//	return x == y;
//}
//typedef const char* cpp;
//template<>
//bool IsEqual(cpp& x, cpp& y)
//{
//	return strcmp(x, y) == 0;
//}
//template<>
//bool IsEqual<double>(double x, double y)
//{
//	return x == y;
//}
//int main()
//{
//	int i = 2;
//	int j = 9;
//	//cout << IsEqual(i, j) << endl; //1
//	//cout << IsEqual(1, 2) << endl; //0
//
//	char a1[] = "2021dragon";
//	char a2[] = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; //0
//	//cout << IsEqual(2.2, 2.2) << endl;
//	cout << typeid(a1).name() << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//template<class T>
//bool IsEqual(const T& x, const T& y)
//{
//	return x == y;
//}
////bool IsEqual(const char* x, const char* y)
////{
////	return strcmp(x, y) == 0;
////}
//typedef const char* cpp;
//template<>
//bool IsEqual<cpp>(const cpp& x, const cpp& y)
//{
//	return strcmp(x, y) == 0;
//}
//template<>
//bool IsEqual<int>(const int& x, const int& y)
//{
//	return x == y;
//}
//int main()
//{
//	cout << IsEqual(1, 1) << endl; //1
//	cout << IsEqual(1, 2) << endl; //0
//	cout << IsEqual(2.2, 2.2) << endl; //1
//	char a1[] = "2021dragon";
//	char a2[] = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; //1
//	char* p1 = "2021dragon";
//	char* p2 = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; //1
//	int a = 2;
//	int b = 2;
//	cout << IsEqual(a, b) << endl; //1
//	return 0;
//}

//#include <iostream>
//using namespace std;
////基础的函数模板
//template<class T>
//bool IsEqual(T x, T y)
//{
//	return x == y;
//}
////对于char*类型的特化
////bool IsEqual(char* x, char* y)
////{
////	return strcmp(x, y) == 0;
////}
////对于char*类型的特化
//template<>
//bool IsEqual<char*>(char* x, char* y)
//{
//	return strcmp(x, y) == 0;
//}
//template<>
//bool IsEqual<int>(int x, int y)
//{
//	return x == y;
//}
//int main()
//{
//	cout << IsEqual(1, 1) << endl; //1
//	cout << IsEqual(1.1, 2.2) << endl; //0
//	cout << IsEqual(2.2, 2.2) << endl; //1
//	char a1[] = "2021dragon";
//	char a2[] = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; //1
//	char* p1 = "2021dragon";
//	char* p2 = "2021dragon";
//	cout << IsEqual(a1, a2) << endl; //1
//	int a = 2;
//	int b = 2;
//	cout << IsEqual(a, b) << endl; //1
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//template<class T1, class T2>
//class Dragon
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _D1;
//	T2 _D2;
//};
//
////对于T1为double，T2为int的类进行特化
//template<>
//class Dragon<double, int>
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<double, int>" << endl;
//	}
//private:
//	double _D1;
//	int _D2;
//};
//
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<double, int> d2;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//template<class T1, class T2>
//class Dragon
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _D1;
//	T2 _D2;
//};
//
////对T1为int的类进行特化
//template<class T2>
//class Dragon<int, T2>
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<int, T2>" << endl;
//	}
//private:
//	int _D1;
//	T2 _D2;
//};
//
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<double, int> d2;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//template<class T1, class T2>
//class Dragon
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<T1, T2>" << endl;
//	}
//private:
//	T1 _D1;
//	T2 _D2;
//};
//
////两个参数偏特化为指针类型
//template<class T1, class T2>
//class Dragon<T1*, T2*>
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<T1*, T2*>" << endl;
//	}
//private:
//	int _D1;
//	T2 _D2;
//};
////两个参数偏特化为引用类型
//template<class T1, class T2>
//class Dragon<T1&, T2&>
//{
//public:
//	//构造函数
//	Dragon()
//	{
//		cout << "Dragon<T1&, T2&>" << endl;
//	}
//private:
//	int _D1;
//	T2 _D2;
//};
//
//int main()
//{
//	Dragon<int, int> d1;
//	Dragon<int*, int*> d2;
//	Dragon<int&, int&> d3;
//	return 0;
//}

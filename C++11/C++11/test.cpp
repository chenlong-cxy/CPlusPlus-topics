//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	vector<int> v{ 1, 2, 3, 4, 5 };
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	//内置类型变量
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//	//数组
//	int arr1[5]{1, 2, 3, 4, 5};
//	int arr2[]{1, 2, 3, 4, 5};
//	//动态数组，在C++98中不支持
//	int* arr3 = new int[5]{1, 2, 3, 4, 5};
//	//标准容器
//	vector<int> v{ 1, 2, 3, 4, 5 };
//	map<int, int> m{ { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } };
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Point
//{
//public:
//	Point(int x = 0, int y = 0)
//		:_x(x)
//		, _y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//int main()
//{
//	Point p{ 1, 2 };
//	return 0;
//}


//#include <iostream>
//#include <initializer_list>
//using namespace std;
//template<class T>
//class Vector
//{
//public:
//	//...
//	Vector(initializer_list<T> l)
//		:_capacity(l.size())
//		, _size(0)
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//		{
//			_arrayp[_size++] = e;
//		}
//	}
//	Vector<T>& operator=(initializer_list<T> l)
//	{
//		delete[] _array;
//		size_t i = 0;
//		for (auto e : l)
//		{
//			_array[i++] = e;
//		}
//		return *this;
//	}
//	//...
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//int main()
//{
//	
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	short a = 32670;
//	short b = 32670;
//	//c如果给成short，会造成数据丢失，如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题
//	short c = a + b;
//	//auto c = a + b;
//	cout << c << endl;
//
//	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "banana", "香蕉" } };
//	//使用迭代器遍历容器，迭代器类型态繁琐
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		it++;
//	}
//
//	return 0;
//}


//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//用decltype推演a+b的实际类型，作为定义c的类型
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	return 0;
//}


//#include <iostream>
//#include <malloc.h>
//using namespace std;
//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	//如果没有带参数，推导函数的类型
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	//如果带参数列表，推导的是函数返回值的类型，注意：此处只是推演，不会执行函数
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	return 0;
//}

//----------------------------

//#include <iostream>
//using namespace std;
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	//使用大括号对数组元素进行初始化
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//
//	//使用大括号对结构体元素进行初始化
//	Point p = { 1, 2 };
//	return 0;
//}


//#include <iostream>
//using namespace std;
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	//使用大括号对内置类型进行初始化
//	int x1 = { 1 }; //可添加等号
//	int x2{ 2 };    //可不添加等号
//
//	//使用大括号对数组元素进行初始化
//	int array1[]{1, 2, 3, 4, 5}; //可不添加等号
//	int array2[5]{0};            //可不添加等号
//
//	//使用大括号对结构体元素进行初始化
//	Point p{ 1, 2 }; //可不添加等号
//
//	//C++11中列表初始化也可以用于new表达式中（C++98无法初始化）
//	int* p1 = new int[4]{0};       //不可添加等号
//	int* p2 = new int[4]{1,2,3,4}; //不可添加等号
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//一般调用构造函数创建对象的方式
//	Date d1(2022, 8, 29);
//
//	//C++11支持的列表初始化，这里也会调用构造函数初始化
//	Date d2 = { 2022, 8, 30 }; //可添加等号
//	Date d3{ 2022, 8, 31 };    //可不添加等号
//	return 0;
//}


//#include <iostream>
//#include <initializer_list>
//using namespace std;
//int main()
//{
//	auto il = { 1, 2, 3, 4, 5 };
//	cout << typeid(il).name() << endl; //class std::initializer_list<int>
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <list>
//#include <map>
//using namespace std;
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//用大括号括起来的列表对容器进行初始化
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> l = { 10, 20, 30, 40, 50 };
//	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
//	map<string, string> m{ make_pair("sort", "排序"), { "insert", "插入" } };
//
//	//用大括号括起来的列表对容器赋值
//	v = { 5, 4, 3, 2, 1 };
//	return 0;
//}

//namespace cl
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		vector(initializer_list<T> il)
//		{
//			_start = new T[il.size()];
//			_finish = _start;
//			_endofstorage = _start + il.size();
//			//迭代器遍历
//			//typename initializer_list<T>::iterator it = il.begin();
//			//while (it != il.end())
//			//{
//			//	push_back(*it);
//			//	it++;
//			//}
//			//范围for遍历
//			for (auto e : il)
//			{
//				push_back(e);
//			}
//		}
//		vector<T>& operator=(initializer_list<T> il)
//		{
//			vector<T> tmp(il);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//			return *this;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}


//#include <iostream>
//#include <map>
//#include <cstring>
//using namespace std;
//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//
//	cout << typeid(p).name() << endl;  //int *
//	cout << typeid(pf).name() << endl; //char * (__cdecl*)(char *,char const *)
//
//	map<string, string> dict = { { "sort", "排序" }, { "insert", "插入" } };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();  //简化代码
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1*t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//
//	decltype(x*y) ret;
//	decltype(&x) p;
//	cout << typeid(ret).name() << endl; //double
//	cout << typeid(p).name() << endl;   //int const *
//
//	F(1, 'a'); //int
//	F(1, 2.2); //double
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//void f(int arg)
//{
//	cout << "void f(int arg)" << endl;
//}
//void f(int* arg)
//{
//	cout << "void f(int* arg)" << endl;
//}
//int main()
//{
//	f(NULL);    //void f(int arg)
//	f(nullptr); //void f(int* arg)
//	return 0;
//}


//#include <iostream>
//using namespace std;
//template<class T1, class T2>
//auto Add(T1 t1, T2 t2)->decltype(t1+t2)
//{
//	decltype(t1+t2) ret;
//	ret = t1 + t2;
//	cout << typeid(ret).name() << endl;
//	return ret;
//}
//int main()
//{
//	cout << Add(1, 2) << endl;;   //int
//	cout << Add(1, 2.2) << endl;; //double
//	return 0;
//}


//#include <iostream>
//#include <array>
//using namespace std;
//int main()
//{
//	array<int, 10> a1;
//	//a1[11] = 0;
//	//a1.at(11);
//	int arr[10];
//	arr[11]=19;
//	return 0;
//}
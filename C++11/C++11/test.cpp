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


#include <iostream>
#include <malloc.h>
using namespace std;
void* GetMemory(size_t size)
{
	return malloc(size);
}
int main()
{
	//如果没有带参数，推导函数的类型
	cout << typeid(decltype(GetMemory)).name() << endl;
	//如果带参数列表，推导的是函数返回值的类型，注意：此处只是推演，不会执行函数
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}
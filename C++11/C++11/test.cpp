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
//	//�������ͱ���
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//	//����
//	int arr1[5]{1, 2, 3, 4, 5};
//	int arr2[]{1, 2, 3, 4, 5};
//	//��̬���飬��C++98�в�֧��
//	int* arr3 = new int[5]{1, 2, 3, 4, 5};
//	//��׼����
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
//	//c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
//	short c = a + b;
//	//auto c = a + b;
//	cout << c << endl;
//
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" } };
//	//ʹ�õ�������������������������̬����
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
//	//��decltype����a+b��ʵ�����ͣ���Ϊ����c������
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
//	//���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	//����������б��Ƶ����Ǻ�������ֵ�����ͣ�ע�⣺�˴�ֻ�����ݣ�����ִ�к���
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
//	//ʹ�ô����Ŷ�����Ԫ�ؽ��г�ʼ��
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//
//	//ʹ�ô����ŶԽṹ��Ԫ�ؽ��г�ʼ��
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
//	//ʹ�ô����Ŷ��������ͽ��г�ʼ��
//	int x1 = { 1 }; //����ӵȺ�
//	int x2{ 2 };    //�ɲ���ӵȺ�
//
//	//ʹ�ô����Ŷ�����Ԫ�ؽ��г�ʼ��
//	int array1[]{1, 2, 3, 4, 5}; //�ɲ���ӵȺ�
//	int array2[5]{0};            //�ɲ���ӵȺ�
//
//	//ʹ�ô����ŶԽṹ��Ԫ�ؽ��г�ʼ��
//	Point p{ 1, 2 }; //�ɲ���ӵȺ�
//
//	//C++11���б��ʼ��Ҳ��������new���ʽ�У�C++98�޷���ʼ����
//	int* p1 = new int[4]{0};       //������ӵȺ�
//	int* p2 = new int[4]{1,2,3,4}; //������ӵȺ�
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
//	//һ����ù��캯����������ķ�ʽ
//	Date d1(2022, 8, 29);
//
//	//C++11֧�ֵ��б��ʼ��������Ҳ����ù��캯����ʼ��
//	Date d2 = { 2022, 8, 30 }; //����ӵȺ�
//	Date d3{ 2022, 8, 31 };    //�ɲ���ӵȺ�
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
//	//�ô��������������б���������г�ʼ��
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> l = { 10, 20, 30, 40, 50 };
//	vector<Date> vd = { Date(2022, 8, 29), Date{ 2022, 8, 30 }, { 2022, 8, 31 } };
//	map<string, string> m{ make_pair("sort", "����"), { "insert", "����" } };
//
//	//�ô��������������б��������ֵ
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
//			//����������
//			//typename initializer_list<T>::iterator it = il.begin();
//			//while (it != il.end())
//			//{
//			//	push_back(*it);
//			//	it++;
//			//}
//			//��Χfor����
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
//	map<string, string> dict = { { "sort", "����" }, { "insert", "����" } };
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();  //�򻯴���
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
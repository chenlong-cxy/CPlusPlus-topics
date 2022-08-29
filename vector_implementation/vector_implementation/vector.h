#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <initializer_list>
#include <assert.h>
using namespace std;

namespace cl
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		//构造函数1
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//构造函数2
		vector(size_t n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); //调用reserve函数将容器容量设置为n
			for (size_t i = 0; i < n; i++) //尾插n个值为val的数据到容器当中
			{
				push_back(val);
			}
		}
		vector(long n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); //调用reserve函数将容器容量设置为n
			for (size_t i = 0; i < n; i++) //尾插n个值为val的数据到容器当中
			{
				push_back(val);
			}
		}
		vector(int n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); //调用reserve函数将容器容量设置为n
			for (int i = 0; i < n; i++) //尾插n个值为val的数据到容器当中
			{
				push_back(val);
			}
		}
		//构造函数3
		template<class InputIterator> //模板函数
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//将迭代器区间在[first,last)的数据一个个尾插到容器当中
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//传统写法
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			_start = new T[v.capacity()]; //开辟一块和容器v大小相同的空间
			for (size_t i = 0; i < v.size(); i++) //将容器v当中的数据一个个拷贝过来
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size(); //容器有效数据的尾
			_endofstorage = _start + v.capacity(); //整个容器的尾
		}
		//现代写法
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	reserve(v.capacity()); //调用reserve函数将容器容量设置为与v相同
		//	for (auto e : v) //将容器v当中的数据一个个尾插过来
		//	{
		//		push_back(e);
		//	}
		//}
		//传统写法
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v) //防止自己给自己赋值
		//	{
		//		delete[] _start; //释放原来的空间
		//		_start = new T[v.capacity()]; //开辟一块和容器v大小相同的空间
		//		for (size_t i = 0; i < v.size(); i++) //将容器v当中的数据一个个拷贝过来
		//		{
		//			_start[i] = v[i];
		//		}
		//		_finish = _start + v.size(); //容器有效数据的尾
		//		_endofstorage = _start + v.capacity(); //整个容器的尾
		//	}
		//	return *this; //支持连续赋值
		//}
		//现代写法
		vector<T>& operator=(vector<T> v) //编译器接收右值的时候自动调用其拷贝构造函数
		{
			swap(v); //交换这两个对象
			return *this; //支持连续赋值
		}
		//析构函数
		~vector()
		{
			if (_start) //避免对空指针进行释放
			{
				delete[] _start; //释放容器存储数据的空间
				_start = nullptr; //_start置空
				_finish = nullptr; //_finish置空
				_endofstorage = nullptr; //_endofstorage置空
			}
		}
		size_t size()const
		{
			return _finish - _start; //返回容器当中有效数据的个数
		}
		size_t capacity()const
		{
			return _endofstorage - _start; //返回当前容器的最大容量
		}
		iterator begin()
		{
			return _start; //返回容器的首地址
		}
		iterator end()
		{
			return _finish; //返回容器当中有效数据的下一个数据的地址
		}
		const_iterator begin()const
		{
			return _start; //返回容器的首地址
		}
		const_iterator end()const
		{
			return _finish; //返回容器当中有效数据的下一个数据的地址
		}
		T& operator[](size_t i)
		{
			assert(i < size()); //检测下标的合法性

			return _start[i]; //返回对应数据
		}
		const T& operator[](size_t i)const
		{
			assert(i < size()); //检测下标的合法性

			return _start[i]; //返回对应数据
		}
		void reserve(size_t n)
		{
			if (n > capacity()) //判断是否需要进行操作
			{
				size_t sz = size(); //记录当前容器当中有效数据的个数
				T* tmp = new T[n]; //开辟一块可以容纳n个数据的空间
				if (_start) //判断是否为空容器
				{
					//memmove(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i < sz; i++) //将容器当中的数据一个个拷贝到tmp当中
					{
						tmp[i] = _start[i];
					}
					delete[] _start; //将容器本身存储数据的空间释放
				}
				_start = tmp; //将tmp所维护的数据交给_start进行维护
				_finish = _start + sz; //容器有效数据的尾
				_endofstorage = _start + n; //整个容器的尾
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size()) //当n小于当前的size时
			{
				_finish = _start + n; //将size缩小到n
			}
			else //当n大于当前的size时
			{
				if (n > capacity()) //判断是否需要增容
				{
					reserve(n);
				}
				while (_finish < _start + n) //将size扩大到n
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		//尾插数据
		void push_back(const T& x)
		{
			if (_finish == _endofstorage) //判断是否需要增容
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity(); //将容量扩大为原来的两倍
				reserve(newcapacity); //增容
			}
			*_finish = x; //尾插数据
			_finish++; //_finish指针后移
		}
		bool empty()const
		{
			return _start == _finish;
		}
		//尾删数据
		void pop_back()
		{
			assert(!empty()); //容器为空则断言
			_finish--; //_finish指针前移
		}
		//在pos位置插入数据
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage) //判断是否需要增容
			{
				size_t len = pos - _start; //记录pos与_start之间的间隔
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity(); //将容量扩大为原来的两倍
				reserve(newcapacity); //增容
				pos = _start + len; //通过len找到pos在增容后的容器当中的位置
			}
			//将pos位置及其之后的数据统一向后挪动一位，以留出pos位置进行插入
			iterator end = _finish;
			while (end > pos + 1)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x; //将数据插入到pos位置
			_finish++; //数据个数增加一个，_finish后移
		}
		//删除pos位置的数据
		iterator erase(iterator pos)
		{
			assert(!empty()); //容器为空则断言
			//将pos位置之后的数据统一向前挪动一位，以覆盖pos位置的数据
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--; //数据个数减少一个，_finish前移
			return pos;
		}
		//交换两个容器的数据
		void swap(vector<T>& v)
		{
			//交换容器当中的各个成员变量
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
		//----------------------C++11-----------------//
		vector(initializer_list<T> il)
		{
			_start = new T[il.size()];
			_finish = _start;
			_endofstorage = _start + il.size();
			/*typename initializer_list<T>::iterator it = il.begin();
			while (it != il.end())
			{
				push_back(*it);
				it++;
			}*/
			for (auto e : il)
			{
				push_back(e);
			}
		}
		vector<T>& operator=(initializer_list<T> il)
		{
			vector<T> tmp(il);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	template<class Con>
	void Print(Con& c)
	{
		for (auto e : c)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << c.size() << endl;
		cout << c.capacity() << endl;
	}
	//void test1()
	//{
	//	vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(5);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.pop_back();
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.pop_back();
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.pop_back();
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.pop_back();
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.pop_back();
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v.size() << endl;
	//	cout << v.capacity() << endl;
	//}
	//void test2()
	//{
	//	vector<int> v;
	//	v.insert(v.begin(), 1);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.insert(v.begin(), 2);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.insert(v.begin(), 3);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.insert(v.begin() + 3, 4);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.insert(v.begin(), 5);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;


	//	v.erase(v.begin() + 2);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.erase(v.begin());
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.erase(v.begin() + 1);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.erase(v.begin());
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	v.erase(v.begin());
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}
	//void test3()
	//{
	//	vector<int> v(6, 2);
	//	v[3] = 3;
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v.size() << endl;
	//	cout << v.capacity() << endl;
	//	vector<int> v1(v);
	//	v1[0] = 10;
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	//string s("hello world");
	//	//vector<char> c(s.begin(), s.end());
	//	//for (auto e : c)
	//	//{
	//	//	cout << e << " ";
	//	//}
	//	//cout << endl;
	//	//cout << c.size() << endl;
	//	//cout << c.capacity() << endl;
	//}
	//void test4()
	//{
	//	vector<int> v1(5, 3);
	//	vector<int> v2(6, 4);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	v1.insert(v1.begin() + 3, 9);
	//	v2.insert(v2.begin(), 9);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	v1.erase(v1.begin() + 3);
	//	v2.erase(v2.begin());
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	//v1 = v2;
	//	//for (auto e : v1)
	//	//{
	//	//	cout << e << " ";
	//	//}
	//	//cout << endl;
	//	//cout << v1.size() << endl;
	//	//cout << v1.capacity() << endl;
	//	//for (auto e : v2)
	//	//{
	//	//	cout << e << " ";
	//	//}
	//	//cout << endl;
	//	//cout << v2.size() << endl;
	//	//cout << v2.capacity() << endl;
	//}
	//void test5()
	//{
	//	vector<int> v1(5, 4);
	//	vector<int> v2(6, 3);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	v1 = v2;
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	v1[3] = 9;
	//	v2[3] = 10;
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//}
	//void test6()
	//{
	//	vector<int> v1(5, 7);
	//	vector<int> v2(6, 8);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//	v1.swap(v2);
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//}
	//void test7()
	//{
	//	vector<string> v1(5, "aa");
	//	vector<string> v2(v1.begin(), v1.end());
	//	for (auto e : v1)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v1.size() << endl;
	//	cout << v1.capacity() << endl;
	//	for (auto e : v2)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v2.size() << endl;
	//	cout << v2.capacity() << endl;
	//}
	//void test8()
	//{
	//	list<string> l;
	//	l.push_back("a");
	//	l.push_back("bb");
	//	l.push_back("ccc");
	//	l.push_back("dddd");
	//	l.push_back("eeeee");
	//	for (auto e : l)
	//	{
	//		cout << e << " ";
	//	}
	//	vector<string> v(l.begin(), l.end());
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	cout << v.size() << endl;
	//	cout << v.capacity() << endl;
	//}
	//void test9()
	//{
	//	vector<string> v;
	//	v.push_back("hello world");
	//	v.push_back("hello world");
	//	v.push_back("hello world");
	//	v.push_back("hello world");
	//	v.push_back("hello world");
	//	vector<string> copy(v);
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	for (auto e : copy)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	copy[2] = "hello Linux";
	//	for (auto e : v)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//	for (auto e : copy)
	//	{
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}
	//void test10()
	//{
	//	vector<int> v(5, 3);
	//	v.reserve(6);
	//	Print(v);
	//	v.reserve(2);
	//	Print(v);
	//	cout << int() << endl;
	//	cout << char() << endl;
	//	cout << double() << endl;
	//	cout << bool() << endl;
	//}
	//void test11()
	//{
	//	vector<int> v(5, 3);
	//	vector<int> tmp(v);
	//	for (auto e : tmp)
	//	{
	//		e += 3;
	//	}
	//	cout << endl;
	//}
	void testcpp11()
	{
		vector<int> v1{ 1, 2, 3, 4, 5 };
		for (auto e : v1)
			cout << e << " ";
		cout << endl;
		vector<int> v2={ 10, 20, 30, 40, 50 };
		for (auto e : v2)
			cout << e << " ";
		cout << endl;
		v2 = { 8, 4, 2, 1 };
		for (auto e : v2)
			cout << e << " ";
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
	}
}

//namespace cl
//{
//	//模拟实现vector
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		typedef const T* const_iterator;
//
//		//默认成员函数
//		vector();                                           //构造函数1
//		vector(size_t n, const T& val);                     //构造函数2
//		template<class InputIterator>                      
//		vector(InputIterator first, InputIterator last);    //构造函数3
//		vector(const vector<T>& v);                         //拷贝构造函数
//		vector<T>& operator=(const vector<T>& v);           //赋值运算符重载函数
//		~vector();                                          //析构函数
//
//		//迭代器相关函数
//		iterator begin();
//		iterator end();
//		const_iterator begin()const;
//		const_iterator end()const;
//
//		//容量和大小相关函数
//		size_t size()const;
//		size_t capacity()const;
//		void reserve(size_t n);
//		void resize(size_t n, const T& val = T());
//		bool empty()const;
//
//		//修改容器内容相关函数
//		void push_back(const T& x);
//		void pop_back();
//		void insert(iterator pos, const T& x);
//		iterator erase(iterator pos);
//		void swap(vector<T>& v);
//
//		//访问容器相关函数
//		T& operator[](size_t i);
//		const T& operator[](size_t i)const;
//
//	private:
//		iterator _start;        //指向容器的头
//		iterator _finish;       //指向有效数据的尾
//		iterator _endofstorage; //指向容器的尾
//	};
//}
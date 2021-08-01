#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
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
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
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
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	reserve(v.capacity());
		//	for (auto e : v)
		//	{
		//		push_back(e);
		//	}
		//}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		delete[] _start;
		//		_start = new T[v.capacity()];
		//		for (size_t i = 0; i < v.size(); i++)
		//		{
		//			_start[i] = v[i];
		//		}
		//		_finish = _start + v.size();
		//		_endofstorage = _start + v.capacity();
		//	}
		//	return *this;
		//}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
			}
			_finish = nullptr;
			_endofstorage = nullptr;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());

			return _start[i];
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memmove(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + len;
			}
			T* end = _finish;
			while (end > pos + 1)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			_finish++;
		}
		iterator erase(iterator pos)
		{
			assert(!empty());
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl;
	}
	void test2()
	{
		vector<int> v;
		v.insert(v.begin(), 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin(), 2);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin(), 3);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin() + 3, 4);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.insert(v.begin(), 5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;


		v.erase(v.begin() + 2);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.erase(v.begin());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.erase(v.begin() + 1);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.erase(v.begin());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		v.erase(v.begin());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test3()
	{
		vector<int> v(6, 2);
		v[3] = 3;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		vector<int> v1(v);
		v1[0] = 10;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		//string s("hello world");
		//vector<char> c(s.begin(), s.end());
		//for (auto e : c)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
		//cout << c.size() << endl;
		//cout << c.capacity() << endl;
	}
	void test4()
	{
		vector<int> v1(5, 3);
		vector<int> v2(6, 4);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		v1.insert(v1.begin() + 3, 9);
		v2.insert(v2.begin(), 9);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		v1.erase(v1.begin() + 3);
		v2.erase(v2.begin());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		//v1 = v2;
		//for (auto e : v1)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
		//cout << v1.size() << endl;
		//cout << v1.capacity() << endl;
		//for (auto e : v2)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
		//cout << v2.size() << endl;
		//cout << v2.capacity() << endl;
	}
	void test5()
	{
		vector<int> v1(5, 4);
		vector<int> v2(6, 3);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		v1 = v2;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		v1[3] = 9;
		v2[3] = 10;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
	}
	void test6()
	{
		vector<int> v1(5, 7);
		vector<int> v2(6, 8);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		v1.swap(v2);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
	}
	void test7()
	{
		vector<string> v1(5, "aa");
		vector<string> v2(v1.begin(), v1.end());
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
	}
	void test8()
	{
		list<string> l;
		l.push_back("a");
		l.push_back("bb");
		l.push_back("ccc");
		l.push_back("dddd");
		l.push_back("eeeee");
		for (auto e : l)
		{
			cout << e << " ";
		}
		vector<string> v(l.begin(), l.end());
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << v.size() << endl;
		cout << v.capacity() << endl;
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
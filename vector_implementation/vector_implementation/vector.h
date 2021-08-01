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
		//���캯��1
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		//���캯��2
		vector(size_t n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); //����reserve������������������Ϊn
			for (size_t i = 0; i < n; i++) //β��n��ֵΪval�����ݵ���������
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
		//���캯��3
		template<class InputIterator> //ģ�庯��
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//��������������[first,last)������һ����β�嵽��������
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		//��ͳд��
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			_start = new T[v.capacity()]; //����һ�������v��С��ͬ�Ŀռ�
			for (size_t i = 0; i < v.size(); i++) //������v���е�����һ������������
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size(); //������Ч���ݵ�β
			_endofstorage = _start + v.capacity(); //����������β
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
//	//ģ��ʵ��vector
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;
//		typedef const T* const_iterator;
//
//		//Ĭ�ϳ�Ա����
//		vector();                                           //���캯��1
//		vector(size_t n, const T& val);                     //���캯��2
//		template<class InputIterator>                      
//		vector(InputIterator first, InputIterator last);    //���캯��3
//		vector(const vector<T>& v);                         //�������캯��
//		vector<T>& operator=(const vector<T>& v);           //��ֵ��������غ���
//		~vector();                                          //��������
//
//		//��������غ���
//		iterator begin();
//		iterator end();
//		const_iterator begin()const;
//		const_iterator end()const;
//
//		//�����ʹ�С��غ���
//		size_t size()const;
//		size_t capacity()const;
//		void reserve(size_t n);
//		void resize(size_t n, const T& val = T());
//		bool empty()const;
//
//		//�޸�����������غ���
//		void push_back(const T& x);
//		void pop_back();
//		void insert(iterator pos, const T& x);
//		iterator erase(iterator pos);
//		void swap(vector<T>& v);
//
//		//����������غ���
//		T& operator[](size_t i);
//		const T& operator[](size_t i)const;
//
//	private:
//		iterator _start;        //ָ��������ͷ
//		iterator _finish;       //ָ����Ч���ݵ�β
//		iterator _endofstorage; //ָ��������β
//	};
//}
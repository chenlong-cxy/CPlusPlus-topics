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
			reserve(n); //����reserve������������������Ϊn
			for (size_t i = 0; i < n; i++) //β��n��ֵΪval�����ݵ���������
			{
				push_back(val);
			}
		}
		vector(int n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); //����reserve������������������Ϊn
			for (int i = 0; i < n; i++) //β��n��ֵΪval�����ݵ���������
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
		//�ִ�д��
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	reserve(v.capacity()); //����reserve������������������Ϊ��v��ͬ
		//	for (auto e : v) //������v���е�����һ����β�����
		//	{
		//		push_back(e);
		//	}
		//}
		//��ͳд��
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v) //��ֹ�Լ����Լ���ֵ
		//	{
		//		delete[] _start; //�ͷ�ԭ���Ŀռ�
		//		_start = new T[v.capacity()]; //����һ�������v��С��ͬ�Ŀռ�
		//		for (size_t i = 0; i < v.size(); i++) //������v���е�����һ������������
		//		{
		//			_start[i] = v[i];
		//		}
		//		_finish = _start + v.size(); //������Ч���ݵ�β
		//		_endofstorage = _start + v.capacity(); //����������β
		//	}
		//	return *this; //֧��������ֵ
		//}
		//�ִ�д��
		vector<T>& operator=(vector<T> v) //������������ֵ��ʱ���Զ������俽�����캯��
		{
			swap(v); //��������������
			return *this; //֧��������ֵ
		}
		//��������
		~vector()
		{
			if (_start) //����Կ�ָ������ͷ�
			{
				delete[] _start; //�ͷ������洢���ݵĿռ�
				_start = nullptr; //_start�ÿ�
				_finish = nullptr; //_finish�ÿ�
				_endofstorage = nullptr; //_endofstorage�ÿ�
			}
		}
		size_t size()const
		{
			return _finish - _start; //��������������Ч���ݵĸ���
		}
		size_t capacity()const
		{
			return _endofstorage - _start; //���ص�ǰ�������������
		}
		iterator begin()
		{
			return _start; //�����������׵�ַ
		}
		iterator end()
		{
			return _finish; //��������������Ч���ݵ���һ�����ݵĵ�ַ
		}
		const_iterator begin()const
		{
			return _start; //�����������׵�ַ
		}
		const_iterator end()const
		{
			return _finish; //��������������Ч���ݵ���һ�����ݵĵ�ַ
		}
		T& operator[](size_t i)
		{
			assert(i < size()); //����±�ĺϷ���

			return _start[i]; //���ض�Ӧ����
		}
		const T& operator[](size_t i)const
		{
			assert(i < size()); //����±�ĺϷ���

			return _start[i]; //���ض�Ӧ����
		}
		void reserve(size_t n)
		{
			if (n > capacity()) //�ж��Ƿ���Ҫ���в���
			{
				size_t sz = size(); //��¼��ǰ����������Ч���ݵĸ���
				T* tmp = new T[n]; //����һ���������n�����ݵĿռ�
				if (_start) //�ж��Ƿ�Ϊ������
				{
					//memmove(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i < sz; i++) //���������е�����һ����������tmp����
					{
						tmp[i] = _start[i];
					}
					delete[] _start; //����������洢���ݵĿռ��ͷ�
				}
				_start = tmp; //��tmp��ά�������ݽ���_start����ά��
				_finish = _start + sz; //������Ч���ݵ�β
				_endofstorage = _start + n; //����������β
			}
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size()) //��nС�ڵ�ǰ��sizeʱ
			{
				_finish = _start + n; //��size��С��n
			}
			else //��n���ڵ�ǰ��sizeʱ
			{
				if (n > capacity()) //�ж��Ƿ���Ҫ����
				{
					reserve(n);
				}
				while (_finish < _start + n) //��size����n
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		//β������
		void push_back(const T& x)
		{
			if (_finish == _endofstorage) //�ж��Ƿ���Ҫ����
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity(); //����������Ϊԭ��������
				reserve(newcapacity); //����
			}
			*_finish = x; //β������
			_finish++; //_finishָ�����
		}
		bool empty()const
		{
			return _start == _finish;
		}
		//βɾ����
		void pop_back()
		{
			assert(!empty()); //����Ϊ�������
			_finish--; //_finishָ��ǰ��
		}
		//��posλ�ò�������
		void insert(iterator pos, const T& x)
		{
			if (_finish == _endofstorage) //�ж��Ƿ���Ҫ����
			{
				size_t len = pos - _start; //��¼pos��_start֮��ļ��
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity(); //����������Ϊԭ��������
				reserve(newcapacity); //����
				pos = _start + len; //ͨ��len�ҵ�pos�����ݺ���������е�λ��
			}
			//��posλ�ü���֮�������ͳһ���Ų��һλ��������posλ�ý��в���
			iterator end = _finish;
			while (end > pos + 1)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x; //�����ݲ��뵽posλ��
			_finish++; //���ݸ�������һ����_finish����
		}
		//ɾ��posλ�õ�����
		iterator erase(iterator pos)
		{
			assert(!empty()); //����Ϊ�������
			//��posλ��֮�������ͳһ��ǰŲ��һλ���Ը���posλ�õ�����
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--; //���ݸ�������һ����_finishǰ��
			return pos;
		}
		//������������������
		void swap(vector<T>& v)
		{
			//�����������еĸ�����Ա����
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
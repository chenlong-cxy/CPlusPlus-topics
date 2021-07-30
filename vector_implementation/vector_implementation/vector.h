#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace cl
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

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
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		//void resize(size_t n)
		//{

		//}
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
		bool empty()
		{
			return size() == 0;
		}
		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		void insert(iterator pos, const T& val)
		{
			if (_finish == _endofstorage)
			{
				size_t gap = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + gap;
			}
			if (pos != _finish)
			{
				memmove(pos + 1, pos, sizeof(T)*(_finish - pos));
			}
			*pos = val;
			_finish++;
		}
		void erase(iterator pos)
		{
			assert(!empty());
			memmove(pos, pos + 1, (_finish - pos - 1)*sizeof(T));
			_finish--;
		}
		void swap(T& v)
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
}
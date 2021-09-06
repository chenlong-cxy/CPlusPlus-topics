#pragma once
#include <iostream>
#include <deque>
using std::cout;
using std::cin;
using std::endl;

namespace cl
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T& top()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		void swap(stack<T, Container>& st)
		{
			_con.swap(st._con);
		}
	private:
		Container _con;
	};
}
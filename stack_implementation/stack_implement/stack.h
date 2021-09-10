#pragma once
#include <iostream>
#include <deque>
using std::cout;
using std::cin;
using std::endl;


namespace cl //防止命名冲突
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		//元素入栈
		void push(const T& x)
		{
			_con.push_back(x);
		}
		//元素出栈
		void pop()
		{
			_con.pop_back();
		}
		//获取栈顶元素
		const T& top()
		{
			return _con.back();
		}
		//获取栈中有效元素个数
		size_t size() const
		{
			return _con.size();
		}
		//判断栈是否为空
		bool empty() const
		{
			return _con.empty();
		}
		//交换两个栈中的数据
		void swap(stack<T, Container>& st)
		{
			_con.swap(st._con);
		}
	private:
		Container _con;
	};
}
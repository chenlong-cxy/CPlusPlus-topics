#pragma once
#include <iostream>
#include <deque>
using std::cout;
using std::cin;
using std::endl;


namespace cl //��ֹ������ͻ
{
	template<class T, class Container = std::deque<T>>
	class stack
	{
	public:
		//Ԫ����ջ
		void push(const T& x)
		{
			_con.push_back(x);
		}
		//Ԫ�س�ջ
		void pop()
		{
			_con.pop_back();
		}
		//��ȡջ��Ԫ��
		const T& top()
		{
			return _con.back();
		}
		//��ȡջ����ЧԪ�ظ���
		size_t size() const
		{
			return _con.size();
		}
		//�ж�ջ�Ƿ�Ϊ��
		bool empty() const
		{
			return _con.empty();
		}
		//��������ջ�е�����
		void swap(stack<T, Container>& st)
		{
			_con.swap(st._con);
		}
	private:
		Container _con;
	};
}
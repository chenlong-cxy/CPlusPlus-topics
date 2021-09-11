#pragma once
#include <iostream>
#include <deque>
using std::cout;
using std::cin;
using std::endl;

namespace cl //��ֹ������ͻ
{
	template<class T, class Container = std::deque<T>>
	class queue
	{
	public:
		//��β�����
		void push(const T& x)
		{
			_con.push_back(x);
		}
		//��ͷ������
		void pop()
		{
			_con.pop_front();
		}
		//��ȡ��ͷԪ��
		T& front()
		{
			return _con.front();
		}
		const T& front() const
		{
			return _con.front();
		}
		//��ȡ��βԪ��
		T& back()
		{
			return _con.back();
		}
		const T& back() const
		{
			return _con.back();
		}
		//��ȡ��������ЧԪ�ظ���
		size_t size() const
		{
			return _con.size();
		}
		//�ж϶����Ƿ�Ϊ��
		bool empty() const
		{
			return _con.empty();
		}
		//�������������е�����
		void swap(queue<T, Container>& q)
		{
			_con.swap(q._con);
		}
	private:
		Container _con;
	};
}
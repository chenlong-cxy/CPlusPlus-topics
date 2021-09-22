#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace cl //��ֹ������ͻ
{
	//�ȽϷ�ʽ��ʹ�ڲ��ṹΪ��ѣ�
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	//�ȽϷ�ʽ��ʹ�ڲ��ṹΪС�ѣ�
	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	//���ȼ����е�ģ��ʵ��
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		//�ѵ����ϵ���
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2; //ͨ��child����parent���±�
			while (child > 0)//������������λ�ý�ֹ
			{
				if (_comp(_con[parent], _con[child]))//ͨ�������ȽϷ�ʽȷ���Ƿ���Ҫ�������λ��
				{
					//��������뺢�ӽ�㽻��
					swap(_con[child], _con[parent]);
					//�������Ͻ��е���
					child = parent;
					parent = (child - 1) / 2;
				}
				else//�ѳɶ�
				{
					break;
				}
			}
		}
		//����Ԫ�ص���β��������
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1); //�����һ��Ԫ�ؽ���һ�����ϵ���
		}
		//�ѵ����µ���
		void AdjustDown(int n, int parent)
		{
			int child = 2 * parent + 1;
			while (child < n)
			{
				if (child + 1 < n&&_comp(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (_comp(_con[parent], _con[child]))//ͨ�������ȽϷ�ʽȷ���Ƿ���Ҫ�������λ��
				{
					//��������뺢�ӽ�㽻��
					swap(_con[child], _con[parent]);
					//�������½��е���
					parent = child;
					child = 2 * parent + 1;
				}
				else//�ѳɶ�
				{
					break;
				}
			}
		}
		//������ͷԪ�أ��Ѷ�Ԫ�أ�
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(_con.size(), 0); //����0��Ԫ�ؽ���һ�����µ���
		}
		//���ʶ�ͷԪ�أ��Ѷ�Ԫ�أ�
		T& top()
		{
			return _con[0];
		}
		const T& top() const
		{
			return _con[0];
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
	private:
		Container _con; //�ײ�����
		Compare _comp; //�ȽϷ�ʽ
	};
}
#include "priority_queue.h"
//�ѵ����ϵ�������ѣ�
void AdjustUp(vector<int>& v, int child)
{
	int parent = (child - 1) / 2; //ͨ��child����parent���±�
	while (child > 0)//������������λ�ý�ֹ
	{
		if (v[parent] < v[child])//���ӽ���ֵ���ڸ�����ֵ
		{
			//��������뺢�ӽ�㽻��
			swap(v[child], v[parent]);
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
//�ѵ����µ�������ѣ�
void AdjustDown(vector<int>& v, int n, int parent)
{
	//child��¼���Һ�����ֵ�ϴ�ĺ��ӵ��±�
	int child = 2 * parent + 1;//��Ĭ�������ӵ�ֵ�ϴ�
	while (child < n)
	{
		if (child + 1 < n&&v[child] < v[child + 1])//�Һ��Ӵ��ڲ����Һ��ӱ����ӻ���
		{
			child++;//�ϴ�ĺ��Ӹ�Ϊ�Һ���
		}
		if (v[parent] < v[child])//���Һ����нϴ��ӵ�ֵ�ȸ���㻹��
		{
			//����������С���ӽ�㽻��
			swap(v[child], v[parent]);
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
void test()
{
	vector<int> v1{ 10, 23, 12, 33, 54, 76, 78, 34, 87, 89 };
	for (int i = (v1.size() - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(v1, v1.size(), i);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	v1.push_back(88);
	AdjustUp(v1, v1.size() - 1);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	v1[0] = 60;
	AdjustDown(v1, v1.size(), 0);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test();
	cl::priority_queue<int> q;
	q.push(3);
	q.push(6);
	q.push(0);
	q.push(2);
	q.push(9);
	q.push(8);
	q.push(1);
	while (!q.empty())
	{
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << std::endl; //9 8 6 3 2 1 0
	return 0;
}
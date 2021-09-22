#include "priority_queue.h"
//堆的向上调整（大堆）
void AdjustUp(vector<int>& v, int child)
{
	int parent = (child - 1) / 2; //通过child计算parent的下标
	while (child > 0)//调整到根结点的位置截止
	{
		if (v[parent] < v[child])//孩子结点的值大于父结点的值
		{
			//将父结点与孩子结点交换
			swap(v[child], v[parent]);
			//继续向上进行调整
			child = parent;
			parent = (child - 1) / 2;
		}
		else//已成堆
		{
			break;
		}
	}
}
//堆的向下调整（大堆）
void AdjustDown(vector<int>& v, int n, int parent)
{
	//child记录左右孩子中值较大的孩子的下标
	int child = 2 * parent + 1;//先默认其左孩子的值较大
	while (child < n)
	{
		if (child + 1 < n&&v[child] < v[child + 1])//右孩子存在并且右孩子比左孩子还大
		{
			child++;//较大的孩子改为右孩子
		}
		if (v[parent] < v[child])//左右孩子中较大孩子的值比父结点还大
		{
			//将父结点与较小的子结点交换
			swap(v[child], v[parent]);
			//继续向下进行调整
			parent = child;
			child = 2 * parent + 1;
		}
		else//已成堆
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
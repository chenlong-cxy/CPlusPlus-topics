#include "queue.h"

//int main()
//{
//	cl::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//	cout << q.size() << endl;
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//	return 0;
//}

int main()
{
	cl::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cl::queue<int> q2;
	q1.swap(q2);
	cout << q2.back() << endl;
	cout << q1.size() << endl;
	cout << q2.size() << endl;
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
	while (!q2.empty())
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
	return 0;
}
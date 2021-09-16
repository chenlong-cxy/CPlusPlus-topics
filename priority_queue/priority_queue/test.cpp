#include <iostream>
#include <functional>
#include <queue>
using namespace std;
void test1()
{
	priority_queue<int> q;
	//priority_queue<int, vector<int>, less<int>> q;
	q.push(3);
	q.push(6);
	q.push(0);
	q.push(2);
	q.push(9);
	q.push(8);
	q.push(1);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl; //9 8 6 3 2 1 0
}
void test2()
{
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(3);
	q.push(6);
	q.push(0);
	q.push(23);
	q.push(65);
	q.push(8);
	q.push(34);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}
int main()
{
	test1();
	return 0;
}
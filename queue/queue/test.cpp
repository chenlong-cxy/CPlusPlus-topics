#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

//int main()
//{
//	queue<int> q1;
//	queue<int, vector<int>> q2;
//	queue<int, list<int>> q3;
//	return 0;
//}

int main()
{
	queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl; //4
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl; //1 2 3 4
	return 0;
}
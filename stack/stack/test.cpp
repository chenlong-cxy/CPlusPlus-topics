#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

//int main()
//{
//	stack<int> st1;
//	stack<int, vector<int>> st2;
//	stack<int, list<int>> st3;
//
//	return 0;
//}

//int main()
//{
//	stack<int, vector<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl; //4
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl; //4 3 2 1
//	return 0;
//}

int main()
{
	stack<int> st1;
	st1.push(2);
	stack<int> st2;
	st1.swap(st2); //交换两个栈当中的数据
	cout << st2.top() << endl;
	return 0;
}
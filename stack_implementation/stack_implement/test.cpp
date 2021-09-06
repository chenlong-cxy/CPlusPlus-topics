#include "stack.h"

//int main()
//{
//	cl::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.size() << endl;
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//	return 0;
//}

int main()
{
	cl::stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	cl::stack<int> st2;
	st1.swap(st2);
	cout << st1.size() << endl;
	cout << st2.size() << endl;
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
	while (!st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl;
	return 0;
}
#include "list.h"
#include <list>

int main()
{
	//cl::test1();
	//cl::test2();
	//cl::test3();
	//cl::test4();
	cl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	cl::list<int>::iterator it = lt.begin();
	cl::list<int>::iterator it1 = it++;
	*it1 = 2022;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	return 0;
}
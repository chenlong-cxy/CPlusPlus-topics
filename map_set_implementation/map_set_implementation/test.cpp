#include "RBTree.h"
#include "map.h"
#include "set.h"
#include <string>
#include <map>
#include "list.h"
#include <set>
void test1()
{
	cl::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(4, 4));

	cl::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	cl::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	cl::set<int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;
	//set<int> s1;
	//s1.insert(1);
	//s1.insert(2);
	//s1.insert(3);
	//s1.insert(4);
	//s1.insert(5);
	//set<int>::iterator it = s1.end();
	//while (it != s1.begin())
	//{
	//	it--;
	//	cout << *it << " ";
	//}
	//cout << endl;
}
void test2()
{
	cl::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	cl::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cl::list<int>::reverse_iterator rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void test3()
{
	cl::map<string, string> m;
	m.insert(make_pair("1", "one"));
	m.insert(make_pair("2", "two"));
	m.insert(make_pair("4", "four"));
	m.insert(make_pair("3", "three"));
	cl::map<string, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << "over" << endl;
	m["2"] = "double";
	m["2021"] = "dragon";
	it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << "over" << endl;
}
void test4()
{
	cl::map<string, string> m;
	m.insert(make_pair("1", "one"));
	m.insert(make_pair("2", "two"));
	m.insert(make_pair("4", "four"));
	m.insert(make_pair("3", "three"));
	m["2"] = "double";
	m["2021"] = "dragon";
	cl::map<string, string>::reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		cout << rit->first << ":" << rit->second << endl;
		++rit;
	}
	cout << "over" << endl;
}
int main()
{
	test4();
	return 0;
}
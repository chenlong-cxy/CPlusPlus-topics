//#include <iostream>
//#include <string>
//#include <thread>
//using namespace std;
//class Person
//{
//public:
//	Person(string name, int age)
//		:_name(name)
//		, _age(age)
//	{}
//	void func() const
//	{
//		cout << typeid(this).name() << endl;
//	}
//public:
//	string _name;
//	int _age;
//};
//int main()
//{
//	Person p1("Lee", 20);
//	Person p2("Alice", 23);
//	p1 = p2;
//	p1._name = "Bob";
//	p1.func();
//	return 0;
//}
//int main()
//{
//	string* p1 = new string("hello");
//	cout << *p1 << endl;
//	delete p1;
//	string* p2 = new string[10];
//	delete[] p2;
//	return 0;
//}
//int main()
//{
//	string* p1 = (string*)malloc(sizeof(string));
//	new(p1)string;
//	//new(p1)string("hello");
//	cout << *p1 << endl;
//	free(p1);
//	return 0;
//}
//class Test
//{
//public:
//	Test()
//	{
//		cout << "Test()" << endl;
//	}
//private:
//	int _b;
//};
//class Person
//{
//public:
//	Person(int age)
//		:_age(age)
//	{
//		cout << "Person(int age)" << endl;
//	}
//public:
//	Test _name;
//	int _age;
//};
//int main()
//{
//	Person p(20);
//	return 0;
//}
//void func(int& num)
//{
//	num++;
//}
//int main()
//{
//	int a = 10;
//	cout << a << endl;
//	thread t1(func, ref(a));
//	t1.join();
//	cout << a << endl;
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	cout << a << endl;
//	thread t1([&a](){a++; });
//	t1.join();
//	cout << a << endl;
//	return 0;
//}
//void func(int* num)
//{
//	(*num)++;
//}
//int main()
//{
//	int a = 10;
//	cout << a << endl;
//	thread t1(func, &a);
//	t1.join();
//	cout << a << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;
//int main()
//{
//	vector<int> v = { 10, 20, 30 };
//	cout << accumulate(v.begin(), v.end(), 0) << endl;
//	return 0;
//}
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	list<int> l{ 3, 4, 5, 6 };
	vector<int> ret(v.size() + l.size());
	merge(v.begin(), v.end(), l.begin(), l.end(), ret.begin());
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

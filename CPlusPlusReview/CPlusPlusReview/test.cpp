#include <iostream>
#include <string>
using namespace std;
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
int main()
{
	string* p1 = (string*)malloc(sizeof(string));
	new(p1)string;
	//new(p1)string("hello");
	cout << *p1 << endl;
	free(p1);
	return 0;
}

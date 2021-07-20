#include "string.h"
#include <string>
void test()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(1);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
int main()
{
	//cl::test_string1();
	//cl::test_string2();
	//cl::test_string3();
	//cl::test_string4();
	//test();
	//cl::test_string5();
	cl::test_string6();
	return 0;
}
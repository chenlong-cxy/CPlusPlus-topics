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
	//cl::test_string6();
	//string s1("hello");
	//string s2("byebye");
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;
	//cout << s2 << endl;
	//cout << s2.size() << endl;
	//cout << s2.capacity() << endl;
	//s1.swap(s2);
	//cout << s1 << endl;
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;
	//cout << s2 << endl;
	//cout << s2.size() << endl;
	//cout << s2.capacity() << endl;
	//cl::test_string7();
	//string s("");
	//cout << s.empty() << endl;
	//string s1;
	//cout << s.empty() << endl;
	//cl::test_string8();
	//cl::test_string9();
	//cl::test_string10();
	//string s("hello world");
	//cout << s.rfind("rl", 9) << endl;
	cl::test_string11();
	return 0;
}
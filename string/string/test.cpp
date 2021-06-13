//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	char str[] = "中国";
//	for (int i = -10; i <= -2; i++)
//	{
//		str[3] = i;
//		cout << str << endl;
//	}
//	cout << sizeof(char) << endl;
//	cout << sizeof(wchar_t) << endl; //2
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////string();  //构造一个长度为零个字符的空字符串
////
////string(const char* s);  //复制s所指的以'\0'结尾的字符序列
////
////string(const char* s, size_t n);  //复制s所指字符序列的前n个字符
////
////string(size_t n, char c);  //用字符c的n个连续副本填充字符串
////
////string(const string& str);  //构造str的副本
////
////string(const string& str, size_t pos, size_t len = npos);  //复制str中从字符位置pos开始并跨越len个字符的部分
////
//////注：若str太短或len为string::npos，则复制到str的结尾
//
//int main()
//{
//	string s1; //构造空字符串
//	string s2("hello string"); //复制"hello string"
//	string s3("hello string", 3); //复制"hello string"的前3个字符
//	string s4(10, 's'); //用字符's'的10个连续副本填充字符串
//	string s5(s2); //构造s2的副本
//	string s6(s2, 0, 4); //复制s2中从字符位置0开始并跨越4个字符的部分
//	//s5.~string();
//	cout << "s1:" << s1 << endl;
//	cout << "s2:" << s2 << endl;
//	cout << "s3:" << s3 << endl;
//	cout << "s4:" << s4 << endl;
//	cout << "s5:" << s5 << endl;
//	cout << "s6:" << s6 << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("hello string");
//	cout << s1 << endl;
//	s1.~string();
//	cout << s1 << endl;
//	s1 = "hello string";
//	cout << s1 << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////string& operator= (const char* s);
////
////string& operator= (const string& str);
////
////string& operator= (char c);
//int main()
//{
//	string s1, s2, s3;
//	s1 = "hello string";
//	s2 = s1;
//	s3 = 's';
//	cout << "s1:" << s1 << endl;
//	cout << "s2:" << s2 << endl;
//	cout << "s3:" << s3 << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////返回一个指向字符串第一个字符的迭代器
////      iterator begin();
////const_iterator begin() const;
//
////返回一个指向字符串结束字符的迭代器
////      iterator end();
////const_iterator end() const;
//int main()
//{
//	string s("hello string");
//
//	//正向迭代器
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
////返回指向字符串最后一个字符的反向迭代器。
////      reverse_iterator rbegin();
////const_reverse_iterator rbegin() const;
//
////返回指向字符串第一个字符前面的理论元素的反向迭代器。
////      reverse_iterator rend();
////const_reverse_iterator rend() const;
//int main()
//{
//	string s("hello string");
//
//	//反向迭代器
//	string::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit;
//		rit++;
//	}
//	cout << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	s.push_back('C');
//	s.push_back('S');
//	s.push_back('D');
//	s.push_back('N');
//	cout << s << endl; //CSDN
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("C"); //C
//
//	//insert(pos, str)在pos位置插入字符串str
//	s.insert(1, "S"); //CS
//
//	//insert(pos, string)在pos位置插入string对象
//	string t("D");
//	s.insert(2, t); //CSD
//
//	//insert(pos, char)在pos位置插入字符char
//	s.insert(s.end(), 'N'); //CSDN
//	cout << s << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("I");
//	string s2(" like");
//
//	//append(string)完成两个string对象的拼接
//	s1.append(s2); //I like
//
//	//append(str)完成string对象和字符串str的拼接
//	s1.append(" C++"); //I like C++
//
//	//append(n, char)将n个字符char拼接到string对象后面
//	s1.append(3, '!'); //I like C++!!!
//	cout << s1 << endl; //I like C++!!!
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("C++");
//	s.pop_back();
//	s.pop_back();
//	cout << s << endl; //C
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("I like C++!!!");
//
//	//erase(pos, n)删除pos位置开始的n个字符
//	s.erase(8, 5); //I like C
//
//	//erase(pos)删除pos位置的字符
//	s.erase(s.end()-1); //I like
//
//	//erase(pos1, pos2)删除pos1到pos2的所有字符
//	s.erase(s.begin() + 1, s.end()); //I
//
//	cout << s << endl; //I
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("http://www.cplusplus.com/reference/string/string/find/");
//
//	//find(string)正向搜索与string对象所匹配的第一个位置
//	string s2("www");
//	size_t pos1 = s1.find(s2);
//	cout << pos1 << endl; //7
//
//	//find(str)正向搜索与字符串str所匹配的第一个位置
//	char str[] = "cplusplus.com";
//	size_t pos2 = s1.find(str);
//	cout << pos2 << endl;  //11
//
//	//find(char)正向搜索与字符char所匹配的第一个位置
//	size_t pos3 = s1.find(':');
//	cout << pos3 << endl; //4
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("http://www.cplusplus.com/reference/string/string/find/");
//
//	//rfind(string)反向搜索与string对象所匹配的第一个位置
//	string s2("string");
//	size_t pos1 = s1.rfind(s2);
//	cout << pos1 << endl; //42
//
//	//rfind(str)反向搜索与字符串str所匹配的第一个位置
//	char str[] = "reference";
//	size_t pos2 = s1.rfind(str);
//	cout << pos2 << endl;  //25
//
//	//rfind(char)反向搜索与字符char所匹配的第一个位置
//	size_t pos3 = s1.rfind('/');
//	cout << pos3 << endl; //53
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("hello world");
//	string s2("hello CSDN");
//
//	//"hello world"和"hello CSDN"比较
//	cout << s1.compare(s2) << endl; //1
//
//	//"ell"和"hello CSDN"比较
//	cout << s1.compare(1, 3, s2) << endl; //-1
//
//	//"hello"和"hello"比较
//	cout << s1.compare(0, 4, s2, 0, 4) << endl; //0
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("hello world");
//
//	//replace(pos, len, str)将pos位置开始的len个字符替换为字符串str
//	s.replace(6, 4, "CSDN"); //hello CSDNd
//
//	//replace(pos, len, n, char)将pos位置开始的len个字符替换为n个字符char
//	s.replace(10, 1, 3, '!'); //hello CSDN!!!
//
//	cout << s << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("hello");
//	string s2("CSDN");
//	
//	//使用string类的成员函数swap交换s1和s2
//	s1.swap(s2);
//	cout << s1 << endl; //CSDN
//	cout << s2 << endl; //hello
//
//	//使用非成员函数swap交换s1和s2
//	swap(s1, s2);
//	cout << s1 << endl; //hello
//	cout << s2 << endl; //CSDN
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s.size() << endl; //4
//	cout << s.length() << endl; //4
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s.max_size() << endl; //4294967294
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s.capacity() << endl; //15
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s("CSDN");
	cout << s << endl; //CSDN
	cout << s.size() << endl; //4
	cout << s.capacity() << endl; //15

	//resize(n)
	s.resize(20);
	cout << s << endl; //CSDN
	cout << s.size() << endl; //20
	cout << s.capacity() << endl; //31
	return 0;
}
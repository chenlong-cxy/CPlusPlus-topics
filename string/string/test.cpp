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


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s << endl; //CSDN
//	cout << s.size() << endl; //4
//	cout << s.capacity() << endl; //15
//
//	//resize(n)
//	s.resize(20);
//	cout << s << endl; //CSDN
//	cout << s.size() << endl; //20
//	cout << s.capacity() << endl; //31
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("CSDN");
//	//resize(n)n大于对象当前的size时，将size扩大到n，扩大的字符默认为'\0'
//	s1.resize(20);
//	cout << s1 << endl; //CSDN
//	cout << s1.size() << endl; //20
//	cout << s1.capacity() << endl; //31
//
//	string s2("CSDN");
//	//resize(n, char)n大于对象当前的size时，将size扩大到n，扩大的字符为char
//	s2.resize(20, 'x');
//	cout << s2 << endl; //CSDNxxxxxxxxxxxxxxxx
//	cout << s2.size() << endl; //20
//	cout << s2.capacity() << endl; //31
//
//	string s3("CSDN");
//	//resize(n)n小于对象当前的size时，将size缩小到n
//	s3.resize(2);
//	cout << s3 << endl; //CS
//	cout << s3.size() << endl; //2
//	cout << s3.capacity() << endl; //15
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s << endl; //CSDN
//	cout << s.size() << endl; //4
//	cout << s.capacity() << endl; //15
//
//	//reverse(n)当n大于对象当前的capacity时，将当前对象的capacity扩大为n或大于n
//	s.reserve(20); 
//	cout << s << endl; //CDSN
//	cout << s.size() << endl; //4
//	cout << s.capacity() << endl; //31
//
//	//reverse(n)当n小于对象当前的capacity时，什么也不做
//	s.reserve(2);
//	cout << s << endl; //CDSN
//	cout << s.size() << endl; //4
//	cout << s.capacity() << endl; //31
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s << endl;
//	//clear()删除对象的内容，该对象将变为空字符串
//	s.clear();
//	cout << s << endl; //空字符串
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	cout << s.empty() << endl; //0
//
//	//clear()删除对象的内容，该对象将变为空字符串
//	s.clear();
//	cout << s.empty() << endl; //1
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	//[]+下标访问对象元素
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		cout << s[i];
//	}
//	cout << endl;
//
//	//[]+下标修改对象元素内容
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		s[i] = 'x';
//	}
//	cout << s << endl; //xxxx
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		//at(pos)访问pos位置的元素
//		cout << s.at(i);
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		//at(pos)访问pos位置的元素，并对其进行修改
//		s.at(i) = 'x';
//	}
//	cout << s << endl; //xxxx
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	//使用范围for访问对象元素
//	for (auto e : s)
//	{
//		cout << e;
//	}
//	cout << endl; //CSDN
//
//	//使用范围for访问对象元素，并对其进行修改
//	for (auto& e : s)
//	{
//		e = 'x';
//	}
//	cout << s << endl; //xxxx
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("CSDN");
//	
//	//使用迭代器访问对象元素
//	string::iterator it1 = s.begin();
//	while (it1 != s.end())
//	{
//		cout << *it1;
//		it1++;
//	}
//	cout << endl; //CSDN
//
//	//使用迭代器访问对象元素，并对其进行修改
//	string::iterator it2 = s.begin();
//	while (it2 != s.end())
//	{
//		*it2 += 1;
//		it2++;
//	}
//	cout << s << endl; //DTEO
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2("CSDN");
//
//	//支持string类的赋值
//	s1 = s2;
//	cout << s1 << endl; //CSDN
//
//	//支持字符串的赋值
//	s1 = "hello";
//	cout << s1 << endl;  //hello
//
//	//支持字符的赋值
//	s1 = 'x';
//	cout << s1 << endl; //x
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2("hello");
//
//	//支持string类的复合赋值
//	s1 += s2;
//	cout << s1 << endl; //hello
//
//	//支持字符串的复合赋值
//	s1 += " CSDN";
//	cout << s1 << endl; //hello CSDN
//
//	//支持字符的复合赋值
//	s1 += '!';
//	cout << s1 << endl; //hello CSDN!
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	string s1("super");
//	string s2("man");
//	char str[] = "woman";
//	char ch = '!';
//
//	//string类 + string类
//	s = s1 + s2;
//	cout << s << endl; //superman
//
//	//string类 + 字符串
//	s = s1 + str;
//	cout << s << endl; //superwoman
//
//	//字符串 + string类
//	s = str + s1;
//	cout << s << endl; //womansuper
//
//	//string类 + 字符
//	s = s1 + ch;
//	cout << s << endl; //super!
//	
//	//字符 + string类
//	s = ch + s1;
//	cout << s << endl; //!super
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s; //输入
//	cout << s << endl; //输出
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("abcd");
//	string s2("abde");
//	cout << (s1 > s2) << endl; //0
//	cout << (s1 < s2) << endl; //1
//	cout << (s1 == s2) << endl; //0
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
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
//	cout << endl; //hello string
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
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
//	cout << endl; //gnirts olleh
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("hello world ");
//	const char* str1 = s.data();
//	const char* str2 = s.c_str();
//
//	cout << str1 << endl;
//	cout << str2 << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	//方式一
//	string s1("hello world");
//
//	char str[] = "hello world";
//	//方式二
//	string s2(str);
//
//	cout << s1 << endl; //hello world
//	cout << s2 << endl; //hello world
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("abcdef");
//	char str[20];
//
//	//copy(str, n, pos)复制pos位置开始的n个字符到str字符串
//	size_t length = s.copy(str, 4, 2);
//	//copy函数不会在复制内容的末尾附加'\0'，需要手动加
//	str[length] = '\0';
//	cout << str << endl; //dcef
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1("abcdef");
//	string s2;
//
//	//substr(pos, n)提取pos位置开始的n个字符序列作为返回值
//	s2 = s1.substr(2, 4);
//	cout << s2 << endl; //cdef
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s; //输入：hello CSDN
//	cout << s << endl; //输出：hello
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	//getline(cin, string)将读取到的字符串存储到string中
//	getline(cin, s); //输入：hello CSDN
//	cout << s << endl; //输出：hello CSDN
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s, 'D'); //输入：hello CSDN
	cout << s << endl; //输出：hello CS
	return 0;
}
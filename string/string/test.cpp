//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	char str[] = "�й�";
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
////string();  //����һ������Ϊ����ַ��Ŀ��ַ���
////
////string(const char* s);  //����s��ָ����'\0'��β���ַ�����
////
////string(const char* s, size_t n);  //����s��ָ�ַ����е�ǰn���ַ�
////
////string(size_t n, char c);  //���ַ�c��n��������������ַ���
////
////string(const string& str);  //����str�ĸ���
////
////string(const string& str, size_t pos, size_t len = npos);  //����str�д��ַ�λ��pos��ʼ����Խlen���ַ��Ĳ���
////
//////ע����str̫�̻�lenΪstring::npos�����Ƶ�str�Ľ�β
//
//int main()
//{
//	string s1; //������ַ���
//	string s2("hello string"); //����"hello string"
//	string s3("hello string", 3); //����"hello string"��ǰ3���ַ�
//	string s4(10, 's'); //���ַ�'s'��10��������������ַ���
//	string s5(s2); //����s2�ĸ���
//	string s6(s2, 0, 4); //����s2�д��ַ�λ��0��ʼ����Խ4���ַ��Ĳ���
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
////����һ��ָ���ַ�����һ���ַ��ĵ�����
////      iterator begin();
////const_iterator begin() const;
//
////����һ��ָ���ַ��������ַ��ĵ�����
////      iterator end();
////const_iterator end() const;
//int main()
//{
//	string s("hello string");
//
//	//���������
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
////����ָ���ַ������һ���ַ��ķ����������
////      reverse_iterator rbegin();
////const_reverse_iterator rbegin() const;
//
////����ָ���ַ�����һ���ַ�ǰ�������Ԫ�صķ����������
////      reverse_iterator rend();
////const_reverse_iterator rend() const;
//int main()
//{
//	string s("hello string");
//
//	//���������
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
//	//insert(pos, str)��posλ�ò����ַ���str
//	s.insert(1, "S"); //CS
//
//	//insert(pos, string)��posλ�ò���string����
//	string t("D");
//	s.insert(2, t); //CSD
//
//	//insert(pos, char)��posλ�ò����ַ�char
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
//	//append(string)�������string�����ƴ��
//	s1.append(s2); //I like
//
//	//append(str)���string������ַ���str��ƴ��
//	s1.append(" C++"); //I like C++
//
//	//append(n, char)��n���ַ�charƴ�ӵ�string�������
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
//	//erase(pos, n)ɾ��posλ�ÿ�ʼ��n���ַ�
//	s.erase(8, 5); //I like C
//
//	//erase(pos)ɾ��posλ�õ��ַ�
//	s.erase(s.end()-1); //I like
//
//	//erase(pos1, pos2)ɾ��pos1��pos2�������ַ�
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
//	//find(string)����������string������ƥ��ĵ�һ��λ��
//	string s2("www");
//	size_t pos1 = s1.find(s2);
//	cout << pos1 << endl; //7
//
//	//find(str)�����������ַ���str��ƥ��ĵ�һ��λ��
//	char str[] = "cplusplus.com";
//	size_t pos2 = s1.find(str);
//	cout << pos2 << endl;  //11
//
//	//find(char)�����������ַ�char��ƥ��ĵ�һ��λ��
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
//	//rfind(string)����������string������ƥ��ĵ�һ��λ��
//	string s2("string");
//	size_t pos1 = s1.rfind(s2);
//	cout << pos1 << endl; //42
//
//	//rfind(str)�����������ַ���str��ƥ��ĵ�һ��λ��
//	char str[] = "reference";
//	size_t pos2 = s1.rfind(str);
//	cout << pos2 << endl;  //25
//
//	//rfind(char)�����������ַ�char��ƥ��ĵ�һ��λ��
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
//	//"hello world"��"hello CSDN"�Ƚ�
//	cout << s1.compare(s2) << endl; //1
//
//	//"ell"��"hello CSDN"�Ƚ�
//	cout << s1.compare(1, 3, s2) << endl; //-1
//
//	//"hello"��"hello"�Ƚ�
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
//	//replace(pos, len, str)��posλ�ÿ�ʼ��len���ַ��滻Ϊ�ַ���str
//	s.replace(6, 4, "CSDN"); //hello CSDNd
//
//	//replace(pos, len, n, char)��posλ�ÿ�ʼ��len���ַ��滻Ϊn���ַ�char
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
//	//ʹ��string��ĳ�Ա����swap����s1��s2
//	s1.swap(s2);
//	cout << s1 << endl; //CSDN
//	cout << s2 << endl; //hello
//
//	//ʹ�÷ǳ�Ա����swap����s1��s2
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
//	//resize(n)n���ڶ���ǰ��sizeʱ����size����n��������ַ�Ĭ��Ϊ'\0'
//	s1.resize(20);
//	cout << s1 << endl; //CSDN
//	cout << s1.size() << endl; //20
//	cout << s1.capacity() << endl; //31
//
//	string s2("CSDN");
//	//resize(n, char)n���ڶ���ǰ��sizeʱ����size����n��������ַ�Ϊchar
//	s2.resize(20, 'x');
//	cout << s2 << endl; //CSDNxxxxxxxxxxxxxxxx
//	cout << s2.size() << endl; //20
//	cout << s2.capacity() << endl; //31
//
//	string s3("CSDN");
//	//resize(n)nС�ڶ���ǰ��sizeʱ����size��С��n
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
//	//reverse(n)��n���ڶ���ǰ��capacityʱ������ǰ�����capacity����Ϊn�����n
//	s.reserve(20); 
//	cout << s << endl; //CDSN
//	cout << s.size() << endl; //4
//	cout << s.capacity() << endl; //31
//
//	//reverse(n)��nС�ڶ���ǰ��capacityʱ��ʲôҲ����
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
//	//clear()ɾ����������ݣ��ö��󽫱�Ϊ���ַ���
//	s.clear();
//	cout << s << endl; //���ַ���
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
//	//clear()ɾ����������ݣ��ö��󽫱�Ϊ���ַ���
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
//	//[]+�±���ʶ���Ԫ��
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		cout << s[i];
//	}
//	cout << endl;
//
//	//[]+�±��޸Ķ���Ԫ������
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
//		//at(pos)����posλ�õ�Ԫ��
//		cout << s.at(i);
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		//at(pos)����posλ�õ�Ԫ�أ�����������޸�
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
//	//ʹ�÷�Χfor���ʶ���Ԫ��
//	for (auto e : s)
//	{
//		cout << e;
//	}
//	cout << endl; //CSDN
//
//	//ʹ�÷�Χfor���ʶ���Ԫ�أ�����������޸�
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
//	//ʹ�õ��������ʶ���Ԫ��
//	string::iterator it1 = s.begin();
//	while (it1 != s.end())
//	{
//		cout << *it1;
//		it1++;
//	}
//	cout << endl; //CSDN
//
//	//ʹ�õ��������ʶ���Ԫ�أ�����������޸�
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
//	//֧��string��ĸ�ֵ
//	s1 = s2;
//	cout << s1 << endl; //CSDN
//
//	//֧���ַ����ĸ�ֵ
//	s1 = "hello";
//	cout << s1 << endl;  //hello
//
//	//֧���ַ��ĸ�ֵ
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
//	//֧��string��ĸ��ϸ�ֵ
//	s1 += s2;
//	cout << s1 << endl; //hello
//
//	//֧���ַ����ĸ��ϸ�ֵ
//	s1 += " CSDN";
//	cout << s1 << endl; //hello CSDN
//
//	//֧���ַ��ĸ��ϸ�ֵ
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
//	//string�� + string��
//	s = s1 + s2;
//	cout << s << endl; //superman
//
//	//string�� + �ַ���
//	s = s1 + str;
//	cout << s << endl; //superwoman
//
//	//�ַ��� + string��
//	s = str + s1;
//	cout << s << endl; //womansuper
//
//	//string�� + �ַ�
//	s = s1 + ch;
//	cout << s << endl; //super!
//	
//	//�ַ� + string��
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
//	cin >> s; //����
//	cout << s << endl; //���
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
//	//���������
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
//	//���������
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
//	//��ʽһ
//	string s1("hello world");
//
//	char str[] = "hello world";
//	//��ʽ��
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
//	//copy(str, n, pos)����posλ�ÿ�ʼ��n���ַ���str�ַ���
//	size_t length = s.copy(str, 4, 2);
//	//copy���������ڸ������ݵ�ĩβ����'\0'����Ҫ�ֶ���
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
//	//substr(pos, n)��ȡposλ�ÿ�ʼ��n���ַ�������Ϊ����ֵ
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
//	cin >> s; //���룺hello CSDN
//	cout << s << endl; //�����hello
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	//getline(cin, string)����ȡ�����ַ����洢��string��
//	getline(cin, s); //���룺hello CSDN
//	cout << s << endl; //�����hello CSDN
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s, 'D'); //���룺hello CSDN
	cout << s << endl; //�����hello CS
	return 0;
}
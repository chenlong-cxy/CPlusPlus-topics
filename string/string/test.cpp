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
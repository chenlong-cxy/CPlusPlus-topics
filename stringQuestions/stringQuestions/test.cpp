////������ת��ĸ
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	//�ж��ַ�ch�Ƿ�����ĸ
//	bool IsLetter(char ch)
//	{
//		if ((ch >= 'a'&&ch <= 'z') 
//		 || (ch >= 'A'&&ch <= 'Z'))
//			return true;
//		else
//			return false;
//	}
//	//������ת��ĸ
//	string reverseOnlyLetters(string s) {
//		//if (s == "")
//		//	return s;
//		if (s.empty()) //��sΪ���ַ������򷵻��䱾��
//			return s;
//
//		size_t begin = 0, end = s.size() - 1; //����ͷָ���βָ�룬���ڷ�ת��ĸ
//		while (begin < end) //��������ĸ�ɷ�תʱ��ѭ������
//		{
//			while (begin < end && !IsLetter(s[begin])) //ͷָ��Ѱ�Ҵ���ת��ĸ
//				begin++;
//
//			while (begin < end && !IsLetter(s[end])) //βָ��Ѱ�Ҵ���ת��ĸ
//				end--;
//
//			swap(s[begin], s[end]); //��������������ת��ĸ
//			begin++;
//			end--;
//		}
//		return s; //���ط�ת����ַ���
//	}
//};
//
//int main()
//{
//	string s1("a-bC-dEf-ghIj");
//	Solution a;
//	string s2 = a.reverseOnlyLetters(s1);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}


////�ַ����еĵ�һ��Ψһ��ĸ
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		size_t table[26] = { 0 };
//		// ͳ��26����ĸ���ַ����г��ֵĴ���
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			table[s[i] - 'a']++;
//		}
//		// Ѱ���ַ����еĵ�һ��ֻ����һ����ĸ
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (table[s[i] - 'a'] == 1)
//				return i; // �����±�����
//		}
//		return -1; // �����ڣ�����-1
//	}
//};
//
//int main()
//{
//	Solution a;
//	string s("loveleetcode");
//	cout << a.firstUniqChar(s) << endl;
//	return 0;
//}


////�ַ������һ�����ʵĳ���
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s); //��cin��ȡһ�к��пո���ַ���
//	size_t pos = s.rfind(' '); //��ȡ�ַ��������һ���ո��λ��
//	if (pos == string::npos) //�ַ����в����ո�
//	{
//		//����ַ����ĳ���
//		cout << s.size() << endl;
//	}
//	else //�ַ����к��пո�
//	{
//		//����ַ����ĳ��� - ���һ�γ��ֿո��λ�� - 1
//		cout << s.size() - pos - 1 << endl;
//	}
//	return 0;
//}


////��֤���Ĵ�
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	//�ж�ch�Ƿ���Сд��ĸ�������ַ�
//	bool isLetterOrNumber(char ch)
//	{
//		if ((ch >= 'a' && ch <= 'z')
//			|| (ch >= '0' && ch <= '9'))
//			return true;
//		else
//			return false;
//	}
//	//��֤���Ĵ�
//	bool isPalindrome(string s) {
//		//���ַ��������д�д��ĸתΪСд��ĸ
//		for (auto& ch : s)
//		{
//			if (ch >= 'A' && ch <= 'Z')
//				ch += 32;
//		}
//		int begin = 0, end = s.size() - 1; //����ͷָ���βָ�룬������֤���Ĵ�
//		while (begin < end) //��������ĸδ�ж�ʱ��ѭ������
//		{
//			while (begin < end && !isLetterOrNumber(s[begin])) //ͷָ��Ѱ�Ҵ��ж���ĸ�������ַ�
//				begin++;
//
//			while (begin < end && !isLetterOrNumber(s[end])) //βָ��Ѱ�Ҵ��ж���ĸ�������ַ�
//				end--;
//
//			if (s[begin] == s[end]) //���ж��ַ���ȣ�������һ���ж�
//			{
//				begin++;
//				end--;
//			}
//			else
//			{
//				return false; //���ж��ַ�����ȣ����ַ������ǻ��Ĵ�
//			}
//		}
//		return true; //�ַ����������ַ��ж���ϣ����ַ����ǻ��Ĵ�
//	}
//};
//int main()
//{
//	Solution a;
//	string s("A man, a plan, a canal: Panama");
//	cout << a.isPalindrome(s) << endl;
//	return 0;
//}


////�ַ������
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1, end2 = num2.size() - 1; //���������ַ�����βָ��
//		string RetStr; //�洢�����ַ�����Ӻ�Ľ��
//		int next = 0; //��ʶ��λ
//		while (end1 >= 0 || end2 >= 0) //�����ַ�������һ��δ�����꣬�����ѭ��
//		{
//			int val1 = 0; //��һ���ַ����ȴ���ӵ�����
//			if (end1 >= 0)
//			{
//				val1 = num1[end1] - '0';
//				end1--;
//			}
//			int val2 = 0; //�ڶ����ַ����ȴ���ӵ�����
//			if (end2 >= 0)
//			{
//				val2 = num2[end2] - '0';
//				end2--;
//			}
//			int RetVal = val1 + val2 + next; //����������Ӻ�Ľ����ע����Ҫ���Ͻ�λ
//			if (RetVal > 9) //�ж��Ƿ���Ҫ��λ
//			{
//				RetVal -= 10;
//				next = 1; //��Ҫ��λ������nextΪ1
//			}
//			else
//			{
//				next = 0; //�����λ������nextΪ0
//			}
//			//RetStr.insert(RetStr.begin(), RetVal + '0');
//			//RetStr.insert(0, 1, RetVal + '0'); //��RetValͷ�嵽RetStr
//			RetStr += (RetVal + '0'); //��RetValβ�嵽RetStr
//		}
//		if (next == 1) //�ж��Ƿ����λ
//			//RetStr.insert(RetStr.begin(), '1');
//			//RetStr.insert(0, 1, '1'); //��'1'ͷ�嵽RetStr
//			RetStr += '1'; //��'1'β��嵽RetStr
//		reverse(RetStr.begin(), RetStr.end()); //���ַ���RetStr���з�ת
//		return RetStr; //�����������ַ�����Ӻ�Ľ��
//	}
//};
//int main()
//{
//	Solution a;
//	cout << a.addStrings("2345", "56") << endl;
//	return 0;
//}


#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string a = "hello world";
//	string b = a;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else 
//		cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else 
//		cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else
//		cout << "false" << endl;
//	return 0;
//}


//int main()
//{	string str("Hello Bit.");
//
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	return 0;
//}


//int main()
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//		size_prev_pos = ++size_pos;
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	string str = "Hello Bit.";
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		if (*it != ' ')
//			cout << *it;
//		else
//			str.erase(it);
//		it++;
//	}
//	return 0;
//}
////��ɾ���ո��ԭ������it�������ĸB,ֻ����it++֮��
////�����������һ����ĸi������ɾ���ո�֮����ʧ����ĸB�Ĵ�ӡ


//void main()
//{
//	string s1 = "hello world";
//	string s2 = "change world";
//	string::iterator it = s1.begin();
//	swap(s1, s2);
//	while (it != s1.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//}
////swap(s1, s2);�ַ�������֮�󣬻ᵼ�½���ǰ�ĵ�����itʧЧ��
////���Ժ����it�ķ��ʻᵼ�³������б���


////error
//void main()
//{
//	string s1 = "hello world";
//	string::iterator it = s1.begin();
//	s1 += " hello"; 
//	while (it != s1.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << isdigit('1') << endl;
//	cout << isdigit('a') << endl;
//	return 0;
//}


//���ַ���ת��Ϊ����
//class Solution {
//public:
//	int StrToInt(string str) {
//		int start = 0;
//		int end = str.size() - 1;
//		int ret = 0;
//		int i = 1;
//		while (start < end)
//		{
//			if (str[end] < '0' || str[end] > '9')
//			{
//				return 0;
//			}
//			ret += i*(str[end] - '0');
//			i *= 10;
//			end--;
//		}
//		if (str[end] >= '0' && str[end] <= '9')
//			return ret + i*(str[end] - '0');
//		if (str[end] == '+')
//			return ret;
//		if (str[end] == '-')
//			return -ret;
//		return 0;
//	}
//};


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s("Let's take LeetCode contest");
//	size_t i = 0;
//	size_t found = s.find(' ');
//	while (found != std::string::npos)
//	{
//		cout << found << endl;
//		i = found + 1;
//		found = s.find(' ', i);
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//void myReverse(string& s, size_t start, size_t end)
//{
//	while (start < end)
//	{
//		char tmp = s[start];
//		s[start] = s[end];
//		s[end] = tmp;
//		start++;
//		end--;
//	}
//}
//int main()
//{
//	string s("Let's take LeetCode contest");
//	size_t start = 0;
//	size_t end = s.find(' ');
//	while (end != std::string::npos)
//	{
//		myReverse(s, start, end-1);
//		start = end + 1;
//		end = s.find(' ', start);
//	}
//	end = s.size();
//	myReverse(s, start, end-1);
//	cout << s << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int k = 2;
//	string s("abcdefg");
//	size_t start = 0;
//	size_t end = s.size() - 1;
//	int flag = 0;
//	while (start < end)
//	{
//		if (flag % 2 == 0)
//		{
//			size_t left = start, right = start + k - 1;
//			if (right > end)
//				right = end;
//			while (left < right)
//			{
//				char tmp = s[left];
//				s[left] = s[right];
//				s[right] = tmp;
//				left++;
//				right--;
//			}
//		}
//		start += k;
//		flag++;
//	}
//	cout << s << endl;
//	return 0;
//}


class Solution {
public:
	string reverseStr(string s, int k) {
		int sz = s.size();
		for (int start = 0; start < sz; start += 2 * k)
		{
			int left = start;
			int right = start + k - 1;
			if (right >= sz)
				right = sz - 1;
			while (left < right)
				swap(s[left++], s[right--]);
		}
		return s;
	}
}
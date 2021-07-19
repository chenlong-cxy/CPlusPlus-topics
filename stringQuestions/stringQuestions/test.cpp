////仅仅反转字母
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	//判断字符ch是否是字母
//	bool IsLetter(char ch)
//	{
//		if ((ch >= 'a'&&ch <= 'z') 
//		 || (ch >= 'A'&&ch <= 'Z'))
//			return true;
//		else
//			return false;
//	}
//	//仅仅反转字母
//	string reverseOnlyLetters(string s) {
//		//if (s == "")
//		//	return s;
//		if (s.empty()) //若s为空字符串，则返回其本身
//			return s;
//
//		size_t begin = 0, end = s.size() - 1; //定义头指针和尾指针，用于反转字母
//		while (begin < end) //当还有字母可反转时，循环继续
//		{
//			while (begin < end && !IsLetter(s[begin])) //头指针寻找待反转字母
//				begin++;
//
//			while (begin < end && !IsLetter(s[end])) //尾指针寻找待反转字母
//				end--;
//
//			swap(s[begin], s[end]); //交换这两个待反转字母
//			begin++;
//			end--;
//		}
//		return s; //返回反转后的字符串
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


////字符串中的第一个唯一字母
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		size_t table[26] = { 0 };
//		// 统计26个字母在字符串中出现的次数
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			table[s[i] - 'a']++;
//		}
//		// 寻找字符串中的第一个只出现一次字母
//		for (size_t i = 0; i < s.size(); i++)
//		{
//			if (table[s[i] - 'a'] == 1)
//				return i; // 返回下标索引
//		}
//		return -1; // 不存在，返回-1
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


////字符串最后一个单词的长度
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s); //从cin读取一行含有空格的字符串
//	size_t pos = s.rfind(' '); //获取字符串中最后一个空格的位置
//	if (pos == string::npos) //字符串中不含空格
//	{
//		//输出字符串的长度
//		cout << s.size() << endl;
//	}
//	else //字符串中含有空格
//	{
//		//输出字符串的长度 - 最后一次出现空格的位置 - 1
//		cout << s.size() - pos - 1 << endl;
//	}
//	return 0;
//}


////验证回文串
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	//判断ch是否是小写字母或数字字符
//	bool isLetterOrNumber(char ch)
//	{
//		if ((ch >= 'a' && ch <= 'z')
//			|| (ch >= '0' && ch <= '9'))
//			return true;
//		else
//			return false;
//	}
//	//验证回文串
//	bool isPalindrome(string s) {
//		//将字符串中所有大写字母转为小写字母
//		for (auto& ch : s)
//		{
//			if (ch >= 'A' && ch <= 'Z')
//				ch += 32;
//		}
//		int begin = 0, end = s.size() - 1; //定义头指针和尾指针，用于验证回文串
//		while (begin < end) //当还有字母未判断时，循环继续
//		{
//			while (begin < end && !isLetterOrNumber(s[begin])) //头指针寻找待判断字母或数字字符
//				begin++;
//
//			while (begin < end && !isLetterOrNumber(s[end])) //尾指针寻找待判断字母或数字字符
//				end--;
//
//			if (s[begin] == s[end]) //待判断字符相等，继续下一次判断
//			{
//				begin++;
//				end--;
//			}
//			else
//			{
//				return false; //待判断字符不相等，该字符串不是回文串
//			}
//		}
//		return true; //字符串中所有字符判断完毕，该字符串是回文串
//	}
//};
//int main()
//{
//	Solution a;
//	string s("A man, a plan, a canal: Panama");
//	cout << a.isPalindrome(s) << endl;
//	return 0;
//}


////字符串相加
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int end1 = num1.size() - 1, end2 = num2.size() - 1; //定义两个字符串的尾指针
//		string RetStr; //存储两个字符串相加后的结果
//		int next = 0; //标识进位
//		while (end1 >= 0 || end2 >= 0) //两个字符串中有一个未遍历完，则继续循环
//		{
//			int val1 = 0; //第一个字符串等待相加的数字
//			if (end1 >= 0)
//			{
//				val1 = num1[end1] - '0';
//				end1--;
//			}
//			int val2 = 0; //第二个字符串等待相加的数字
//			if (end2 >= 0)
//			{
//				val2 = num2[end2] - '0';
//				end2--;
//			}
//			int RetVal = val1 + val2 + next; //两个数字相加后的结果，注意需要加上进位
//			if (RetVal > 9) //判断是否需要进位
//			{
//				RetVal -= 10;
//				next = 1; //需要进位，设置next为1
//			}
//			else
//			{
//				next = 0; //不需进位，设置next为0
//			}
//			//RetStr.insert(RetStr.begin(), RetVal + '0');
//			//RetStr.insert(0, 1, RetVal + '0'); //将RetVal头插到RetStr
//			RetStr += (RetVal + '0'); //将RetVal尾插到RetStr
//		}
//		if (next == 1) //判断是否还需进位
//			//RetStr.insert(RetStr.begin(), '1');
//			//RetStr.insert(0, 1, '1'); //将'1'头插到RetStr
//			RetStr += '1'; //将'1'尾插插到RetStr
//		reverse(RetStr.begin(), RetStr.end()); //将字符串RetStr进行反转
//		return RetStr; //返回这两个字符串相加后的结果
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
////当删除空格后，原迭代器it会迭代字母B,只不过it++之后，
////会继续迭代下一个字母i，所以删除空格之后会错失对字母B的打印


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
////swap(s1, s2);字符串交换之后，会导致交换前的迭代器it失效，
////所以后面对it的访问会导致程序运行崩溃


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


//把字符串转换为整数
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
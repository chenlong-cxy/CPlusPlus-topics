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


//验证回文串
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	//判断ch是否是小写字母或数字字符
	bool isLetterOrNumber(char ch)
	{
		if ((ch >= 'a' && ch <= 'z')
			|| (ch >= '0' && ch <= '9'))
			return true;
		else
			return false;
	}
	//验证回文串
	bool isPalindrome(string s) {
		//将字符串中所有大写字母转为小写字母
		for (auto& ch : s)
		{
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0, end = s.size() - 1; //定义头指针和尾指针，用于验证回文串
		while (begin < end) //当还有字母未判断时，循环继续
		{
			while (begin < end && !isLetterOrNumber(s[begin])) //头指针寻找待判断字母或数字字符
				begin++;

			while (begin < end && !isLetterOrNumber(s[end])) //尾指针寻找待判断字母或数字字符
				end--;

			if (s[begin] == s[end]) //待判断字符相等，继续下一次判断
			{
				begin++;
				end--;
			}
			else
			{
				return false; //待判断字符不相等，该字符串不是回文串
			}
		}
		return true; //字符串中所有字符判断完毕，该字符串是回文串
	}
};
int main()
{
	Solution a;
	string s("A man, a plan, a canal: Panama");
	cout << a.isPalindrome(s) << endl;
	return 0;
}
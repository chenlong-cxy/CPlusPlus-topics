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


//��֤���Ĵ�
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	//�ж�ch�Ƿ���Сд��ĸ�������ַ�
	bool isLetterOrNumber(char ch)
	{
		if ((ch >= 'a' && ch <= 'z')
			|| (ch >= '0' && ch <= '9'))
			return true;
		else
			return false;
	}
	//��֤���Ĵ�
	bool isPalindrome(string s) {
		//���ַ��������д�д��ĸתΪСд��ĸ
		for (auto& ch : s)
		{
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0, end = s.size() - 1; //����ͷָ���βָ�룬������֤���Ĵ�
		while (begin < end) //��������ĸδ�ж�ʱ��ѭ������
		{
			while (begin < end && !isLetterOrNumber(s[begin])) //ͷָ��Ѱ�Ҵ��ж���ĸ�������ַ�
				begin++;

			while (begin < end && !isLetterOrNumber(s[end])) //βָ��Ѱ�Ҵ��ж���ĸ�������ַ�
				end--;

			if (s[begin] == s[end]) //���ж��ַ���ȣ�������һ���ж�
			{
				begin++;
				end--;
			}
			else
			{
				return false; //���ж��ַ�����ȣ����ַ������ǻ��Ĵ�
			}
		}
		return true; //�ַ����������ַ��ж���ϣ����ַ����ǻ��Ĵ�
	}
};
int main()
{
	Solution a;
	string s("A man, a plan, a canal: Panama");
	cout << a.isPalindrome(s) << endl;
	return 0;
}
//#include <iostream>
//#include <string>
//#include <functional>
//#include <set>
//using namespace std;
//void test1()
//{
//	set<int> s1{ 1, 2, 3, 4 }; //����int���͵Ŀ�����
//
//	set<int> s2(s1); //��������int����s1�����ĸ���Ʒ
//	for (auto e : s2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string str("abcdef");
//	set<char> s3(str.begin(), str.end()); //����string����ĳ������ĸ���Ʒ
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	set < int, greater<int>> s4{ 23, 54, 6, 76, 8, 678, 9, 78, 9, 78 }; //����int���͵Ŀ��������ȽϷ�ʽָ��Ϊ����
//	for (auto e : s4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void test2()
//{
//	set<int> s;
//	s.insert(2);
//	s.insert(0);
//	s.insert(2);
//	s.insert(0);
//	s.insert(2);
//	s.insert(1);
//	s.insert(1);
//	s.insert(4);
//	s.insert(0);
//	s.insert(2);
//	s.insert(0);
//	s.insert(1);
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	s.erase(2);
//	set<int>::iterator pos = s.find(4); //auto
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//}
//void test3()
//{
//	set<int> s;
//	//����Ԫ��
//	s.insert(1);
//	s.insert(4);
//	s.insert(3);
//	s.insert(3);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	//��������
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 4
//	//ɾ��Ԫ�ط�ʽһ
//	s.erase(3);
//	//ɾ��Ԫ�ط�ʽ��
//	set<int>::iterator pos = s.find(1); //����ֵΪ1��Ԫ��
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	//��������
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //2 4
//	//������ֵΪ2��Ԫ�ظ���
//	cout << s.count(2) << endl; //1
//	//������С
//	cout << s.size() << endl; //2
//	//�������
//	s.clear();
//	//�����п�
//	cout << s.empty() << endl; //1
//	//������������������
//	set<int> tmp{ 11, 22, 33, 44 };
//	s.swap(tmp);
//	//��������
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //11 22 33 44
//}
//int main()
//{
//	//test1();
//	//test2();
//	test1();
//
//	return 0;
//}

//bool Erase(const K& key)
//{
//	size_t index = kv.first%_table.size();
//	if (!_table[index]) //��λ��������
//		return false;
//	Node* cur = _table[index];
//	Node* prev = nullptr;
//	while (cur)
//	{
//		if (cur->_kv.first == key)
//		{
//			prev->_next = cur->_next;
//			delete cur;
//			_size--;
//			return true;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->_next;
//		}
//	}
//	return false;
//}


//#include <iostream>
//#include <set>
//using namespace std;
//
//int main()
//{
//	set<int> s;
//	//����Ԫ�أ�ȥ�أ�
//	s.insert(1);
//	s.insert(4);
//	s.insert(3);
//	s.insert(3);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	//����������ʽһ����Χfor��
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 4
//	//ɾ��Ԫ�ط�ʽһ
//	s.erase(3);
//	//ɾ��Ԫ�ط�ʽ��
//	set<int>::iterator pos = s.find(1); //����ֵΪ1��Ԫ��
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	//����������ʽ���������������
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl; //2 4
//	//������ֵΪ2��Ԫ�ظ���
//	cout << s.count(2) << endl; //1
//	//������С
//	cout << s.size() << endl; //2
//	//�������
//	s.clear();
//	//�����п�
//	cout << s.empty() << endl; //1
//	//������������������
//	set<int> tmp{ 11, 22, 33, 44 };
//	s.swap(tmp);
//	//����������ʽ���������������
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl; //44 33 22 11
//	return 0;
//}

#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> ms;
	//����Ԫ�أ������ظ���
	ms.insert(1);
	ms.insert(4);
	ms.insert(3);
	ms.insert(3);
	ms.insert(2);
	ms.insert(2);
	ms.insert(3);
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl; //1 2 2 3 3 3 4
	return 0;
}
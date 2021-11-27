//#include <iostream>
//#include <string>
//#include <functional>
//#include <set>
//using namespace std;
//void test1()
//{
//	set<int> s1{ 1, 2, 3, 4 }; //构造int类型的空容器
//
//	set<int> s2(s1); //拷贝构造int类型s1容器的复制品
//	for (auto e : s2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string str("abcdef");
//	set<char> s3(str.begin(), str.end()); //构造string对象某段区间的复制品
//	for (auto e : s3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	set < int, greater<int>> s4{ 23, 54, 6, 76, 8, 678, 9, 78, 9, 78 }; //构造int类型的空容器，比较方式指定为大于
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
//	//插入元素
//	s.insert(1);
//	s.insert(4);
//	s.insert(3);
//	s.insert(3);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	//遍历容器
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 4
//	//删除元素方式一
//	s.erase(3);
//	//删除元素方式二
//	set<int>::iterator pos = s.find(1); //查找值为1的元素
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	//遍历容器
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //2 4
//	//容器中值为2的元素个数
//	cout << s.count(2) << endl; //1
//	//容器大小
//	cout << s.size() << endl; //2
//	//清空容器
//	s.clear();
//	//容器判空
//	cout << s.empty() << endl; //1
//	//交换两个容器的数据
//	set<int> tmp{ 11, 22, 33, 44 };
//	s.swap(tmp);
//	//遍历容器
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
//	if (!_table[index]) //该位置无数据
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
//	//插入元素（去重）
//	s.insert(1);
//	s.insert(4);
//	s.insert(3);
//	s.insert(3);
//	s.insert(2);
//	s.insert(2);
//	s.insert(3);
//	//遍历容器方式一（范围for）
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 4
//	//删除元素方式一
//	s.erase(3);
//	//删除元素方式二
//	set<int>::iterator pos = s.find(1); //查找值为1的元素
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	//遍历容器方式二（正向迭代器）
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl; //2 4
//	//容器中值为2的元素个数
//	cout << s.count(2) << endl; //1
//	//容器大小
//	cout << s.size() << endl; //2
//	//清空容器
//	s.clear();
//	//容器判空
//	cout << s.empty() << endl; //1
//	//交换两个容器的数据
//	set<int> tmp{ 11, 22, 33, 44 };
//	s.swap(tmp);
//	//遍历容器方式三（反向迭代器）
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
	//插入元素（允许重复）
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
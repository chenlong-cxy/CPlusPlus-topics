//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	vector<int> v1; //构造int类型的空容器
//	vector<int> v2(10, 0); //构造含有10个0的int类型容器
//	vector<int> v3(v2); //拷贝构造v2的复制品
//	v2.push_back(2);
//	vector<int> v4(v2.begin(), v2.end()); //使用迭代器拷贝构造v2容器的某一段内容
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//	for (auto e : v1)
//	{
//		cout << e;
//	}
//	cout << endl;
//	cout << v2.size() << endl;
//	cout << v2.capacity() << endl;
//	for (auto e : v2)
//	{
//		cout << e;
//	}
//	cout << endl;
//	cout << v3.size() << endl;
//	cout << v3.capacity() << endl;
//	for (auto e : v3)
//	{
//		cout << e;
//	}
//	cout << endl;
//	cout << v4.size() << endl;
//	cout << v4.capacity() << endl;
//	for (auto e : v4)
//	{
//		cout << e;
//	}
//	cout << endl;
//	string s("hello world");
//	vector<char> v5(s.begin(), s.end()); //拷贝构造string对象的某一段内容
//	for (auto e : v5)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	vector<int> v6(l.begin(), l.end());
//	for (auto e : v6)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	vector<int> v1(10, 0);
//	cout << v1.size() << endl; //获取当前容器中的有效元素个数
//	cout << v1.capacity() << endl; //获取当前容器的最大容量
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v1(10, 0);
//	cout << v1.empty() << endl;
//	cout << v1.size() << endl; //10
//	cout << v1.capacity() << endl; //10
//	v1.reserve(20); //改变容器的capacity为20，size不变
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << v1.size() << endl; //10
//	cout << v1.capacity() << endl; //20
//	v1.resize(15); //改变容器的size为15
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << v1.size() << endl; //15
//	cout << v1.capacity() << endl; //20
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v1;
//	v1.push_back(1); //尾插元素1
//	v1.push_back(2); //尾插元素2
//	v1.push_back(3); //尾插元素3
//	v1.push_back(4); //尾插元素4
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.pop_back(); //尾删元素
//	v1.pop_back(); //尾删元素
//	v1.pop_back(); //尾删元素
//	v1.pop_back(); //尾删元素
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v(10, 2);
//	v.push_back(0);
//	//正向迭代器遍历容器
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//反向迭代器遍历容器
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.insert(v.begin(), 0); //在容器开头插入0
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.insert(v.begin(), 5, -1); //在容器开头插入5个-1
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.erase(v.begin()); //删除容器中的第一个元素
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.erase(v.begin(), v.begin() + 5); //删除在该迭代器区间内的元素（左闭右开）
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //获取值为2的元素的迭代器
//	v.insert(pos, 10); //在2的位置插入10
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3); //获取值为3的元素的迭代器
//	v.erase(pos); //删除3
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	vector<int> v1(10, 1);
//	vector<int> v2(10, 2);
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.swap(v2); //交换v1,v2的数据空间
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v(10, 1);
//	//使用“下标+[]”的方式遍历容器
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1(2, 1);
	vector<int> v2(2, 2);
	cout << (v1 > v2) << endl;
	cout << (v1 >= v2) << endl;
	cout << (v1 < v2) << endl;
	cout << (v1 <= v2) << endl;
	cout << (v1 == v2) << endl;
	cout << (v1 != v2) << endl;
	return 0;
}
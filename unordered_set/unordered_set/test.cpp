//#include <iostream>
//#include <unordered_set>
//
//using namespace std;
//
//int main()
//{
//	unordered_set<int> us;
//	us.insert(2);
//	us.insert(4);
//	us.insert(1);
//	us.insert(2);
//	us.insert(5);
//	us.insert(3);
//	us.insert(4);
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <unordered_set>
//
//using namespace std;
//
//int main()
//{
//	unordered_set<int> us1; //构造int类型的空容器
//
//	unordered_set<int> us2(us1); //拷贝构造同类型容器us1的复制品
//
//	string str("abcedf");
//	unordered_set<char> us3(str.begin(), str.end()); //构造string对象某段区间的复制品
//
//	return 0;
//}

//#include <iostream>
//#include <unordered_set>
//using namespace std;
//
//int main()
//{
//	unordered_set<int> us;
//	//插入元素（去重）
//	us.insert(1);
//	us.insert(4);
//	us.insert(3);
//	us.insert(3);
//	us.insert(2);
//	us.insert(2);
//	us.insert(3);
//	//遍历容器方式一（范围for）
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 4 3 2
//	//删除元素方式一
//	us.erase(3);
//	//删除元素方式二
//	unordered_set<int>::iterator pos = us.find(1); //查找值为1的元素
//	if (pos != us.end())
//	{
//		us.erase(pos);
//	}
//	//遍历容器方式二（迭代器遍历）
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl; //4 2
//	//容器中值为2的元素个数
//	cout << us.count(2) << endl; //1
//	//容器大小
//	cout << us.size() << endl; //2
//	//清空容器
//	us.clear();
//	//交换两个容器的数据
//	unordered_set<int> tmp{ 11, 22, 33, 44 };
//	us.swap(tmp);
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //11 22 33 44
//	return 0;
//}


#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_multiset<int> ums;
	//插入元素（允许重复）
	ums.insert(1);
	ums.insert(4);
	ums.insert(3);
	ums.insert(3);
	ums.insert(2);
	ums.insert(2);
	ums.insert(3);
	for (auto e : ums)
	{
		cout << e << " ";
	}
	cout << endl; //1 4 3 3 3 2 2
	cout << ums.count(3) << endl;
	return 0;
}
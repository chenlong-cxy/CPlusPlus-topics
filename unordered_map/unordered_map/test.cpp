//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict["left"] = "左边";
//	dict["left"] = "剩余";
//	unordered_map<string, string>::iterator it = dict.begin();
//	while (it != dict.end())
//	{
//		cout << it->first << "->" << it->second << endl;
//		it++;
//	}
//	return 0;
//}


//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<int, double> um1; //构造一个key为int类型，value为double类型的空容器
//
//	unordered_map<int, double> um2(um1); //拷贝构造同类型容器um1的复制品
//
//	unordered_map<int, double> um3(um2.begin(), um2.end()); //使用迭代器拷贝构造um2容器某段区间的复制品
//
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<int, string> um;
//	//插入键值对方式一：构造匿名对象插入
//	um.insert(pair<int, string>(1, "one"));
//	um.insert(pair<int, string>(2, "two"));
//	um.insert(pair<int, string>(3, "three"));
//	//遍历方式一：范围for
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //1->one 2->two 3->three
//	//插入键值对方式二：调用make_pair函数模板插入
//	um.insert(make_pair(4, "four"));
//	um.insert(make_pair(5, "five"));
//	um.insert(make_pair(6, "six"));
//	//遍历方式二：迭代器遍历
//	unordered_map<int, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << "->" << it->second << " ";
//		it++;
//	}
//	cout << endl; //1->one 2->two 3->three 4->four 5->five 6->six
//	//插入键值对方式三：利用[]运算符重载函数进行插入（常用）
//	um[7] = "seven";
//	um[8] = "eight";
//	um[9] = "nine";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 5->five 6->six 7->seven 8->eight
//	//删除键值对方式一：根据key值删除
//	um.erase(5);
//	//删除键值对方式二：根据迭代器删除
//	unordered_map<int, string>::iterator pos = um.find(7); //查找键值为7的键值对
//	if (pos != um.end())
//	{
//		um.erase(pos);
//	}
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 6->six 8->eight
//	//修改键值对方式一：通过find获得迭代器，通过迭代器修改
//	pos = um.find(1);
//	if (pos != um.end())
//	{
//		pos->second = "one/first";
//	}
//	//修改键值对方式二：利用[]运算符重载函数进行修改（常用）
//	um[2] = "two/second";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one/first 2->two/second 3->three 4->four 6->six 8->eight
//	//容器中key值为3的键值对的个数
//	cout << um.count(3) << endl;
//	//容器的大小
//	cout << um.size() << endl;
//	//清空容器
//	um.clear();
//	//容器判空
//	cout << um.empty() << endl;
//	//交换两个容器的数据
//	unordered_map<int, string> tmp{ { 2021, "before" }, { 2022, "now" } };
//	um.swap(tmp);
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //2021->before 2022->now
//	return 0;
//}


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multimap<int, string> umm;
	//插入键值对（允许键值重复）
	umm.insert(make_pair(2022, "吃饭"));
	umm.insert(make_pair(2022, "睡觉"));
	umm.insert(make_pair(2022, "敲代码"));
	for (auto e : umm)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //2022->吃饭 2022->睡觉 2022->敲代码
	return 0;
}
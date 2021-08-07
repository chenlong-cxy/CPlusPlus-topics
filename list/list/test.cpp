//#include <iostream>
//#include <list>
//#include <string>
//using namespace std;
//
//template<class T>
//void Print(const T& lt)
//{
//	T::const_iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	cout << lt.size() << endl;
//	//cout << lt.capacity() << endl;
//}
//int main()
//{
//	list<int> lt1; //构造int类型的空容器
//	Print(lt1);
//	list<int> lt2(10, 2); //构造含有10个2的int类型容器
//	Print(lt2);
//	list<int> lt3(lt2); //拷贝构造int类型的lt2容器的复制品
//	Print(lt3);
//	string s("hello world");
//	list<char> lt4(s.begin(),s.end()); //构造string对象某段区间的复制品
//	Print(lt4);
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int sz = sizeof(arr) / sizeof(int);
//	list<int> lt5(arr, arr + sz); //构造数组某段区间的复制品
//	Print(lt5);
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//template<class T>
//void Print(const T& lt)
//{
//	T::const_iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	cout << lt.size() << endl;
//	//cout << lt.capacity() << endl;
//}
//int main()
//{
//	list<int> lt(10, 2);
//	lt.push_back(1);
//	//正向迭代器遍历容器
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//反向迭代器遍历容器
//	list<int>::reverse_iterator rit = lt.rbegin();
//	while (rit != lt.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(0);
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	cout << lt.front() << endl; //0
//	cout << lt.back() << endl; //4
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_front(0);
//	lt.push_front(1);
//	lt.push_front(2);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //2 1 0
//	lt.pop_front();
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 0
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(0);
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //0 1 2 3
//	lt.pop_back();
//	lt.pop_back();
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;//0 1
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
//	lt.insert(pos, 9); //在2的位置插入9
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 9 2 3
//	pos = find(lt.begin(), lt.end(), 3);
//	lt.insert(pos, 2, 8); //在3的位置插入2个8
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 9 2 8 8 3
//	vector<int> v(2, 7);
//	pos = find(lt.begin(), lt.end(), 1);
//	lt.insert(pos, v.begin(), v.end()); //在1的位置插入2个7
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //7 7 1 9 2 8 8 3
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//	list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
//	lt.erase(pos); //删除2
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 3 4 5
//	pos = find(lt.begin(), lt.end(), 4);
//	lt.erase(pos, lt.end()); //删除4及其之后的元素
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 3
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	cout << lt.size() << endl; //4
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt(5, 3);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //3 3 3 3 3
//	lt.resize(7, 6); //将size扩大为7，扩大的值为6
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //3 3 3 3 3 6 6
//	lt.resize(2); //将size缩小为2
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //3 3
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	cout << lt.empty() << endl; //1
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt(5, 2);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //2 2 2 2 2
//	cout << lt.size() << endl; //5
//	lt.clear(); //清空容器
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //(无数据)
//	cout << lt.size() << endl; //0
//	return 0;
//}


#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt;
	lt.push_back(4);
	lt.push_back(7);
	lt.push_back(5);
	lt.push_back(9);
	lt.push_back(6);
	lt.push_back(0);
	lt.push_back(3);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.sort();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
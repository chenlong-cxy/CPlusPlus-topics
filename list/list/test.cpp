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


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt;
//	lt.push_back(4);
//	lt.push_back(7);
//	lt.push_back(5);
//	lt.push_back(9);
//	lt.push_back(6);
//	lt.push_back(0);
//	lt.push_back(3);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //4 7 5 9 6 0 3
//	lt.sort(); //默认将容器内数据排为升序
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //0 3 4 5 6 7 9
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt1(4, 2);
//	list<int> lt2(4, 6);
//	lt1.splice(lt1.begin(), lt2); //将容器lt2拼接到容器lt1的开头
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //6 6 6 6 2 2 2 2 
//
//	list<int> lt3(4, 2);
//	list<int> lt4(4, 6);
//	lt3.splice(lt3.begin(), lt4, lt4.begin()); //将容器lt4的第一个数据拼接到容器lt3的开头
//	for (auto e : lt3)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //6 2 2 2 2 
//
//	list<int> lt5(4, 2);
//	list<int> lt6(4, 6);
//	lt5.splice(lt5.begin(), lt6, lt6.begin(), lt6.end()); //将容器lt6的指定迭代器区间内的数据拼接到容器lt5的开头
//	for (auto e : lt5)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //6 6 6 6 2 2 2 2
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//bool single_digit(const int& val)
//{
//	return val < 10;
//}
//int main()
//{
//	list<int> lt;
//	lt.push_back(10);
//	lt.push_back(4);
//	lt.push_back(7);
//	lt.push_back(18);
//	lt.push_back(2);
//	lt.push_back(5);
//	lt.push_back(9);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //10 4 7 18 2 5 9
//	lt.remove_if(single_digit); //删除容器当中值小于10的元素
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //10 18
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
//	lt.push_back(4);
//	lt.push_back(3);
//	lt.push_back(3);
//	lt.push_back(2);
//	lt.push_back(2);
//	lt.push_back(3);
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 4 3 3 2 2 3
//	lt.sort(); //将容器当中的元素排为升序
//	lt.unique(); //删除容器当中连续的重复元素
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 4
//	return 0;
//}


//#include <iostream>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<int> lt1;
//	lt1.push_back(3);
//	lt1.push_back(8);
//	lt1.push_back(1);
//	list<int> lt2;
//	lt2.push_back(6);
//	lt2.push_back(2);
//	lt2.push_back(9);
//	lt2.push_back(5);
//	lt1.sort(); //将容器lt1排为升序
//	lt2.sort(); //将容器lt2排为升序
//	lt1.merge(lt2); //将lt2合并到lt1当中
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 2 3 5 6 8 9 
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
//	lt.push_back(5);
//	lt.reverse(); //将容器当中元素的位置进行逆置
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //5 4 3 2 1 
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <list>
//using namespace std;
//
//int main()
//{
//	list<char> lt(3, 'a');
//	lt.assign(3, 'b'); //将新内容分配给容器，替换其当前内容
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //b b b
//	string s("hello world");
//	lt.assign(s.begin(), s.end()); //将新内容分配给容器，替换其当前内容
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //h e l l o   w o r l d
//	return 0;
//}


#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> lt1(4, 2);
	list<int> lt2(4, 6);
	lt1.swap(lt2); //交换两个容器的内容
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl; //6 6 6 6
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl; //2 2 2 2
	return 0;
}
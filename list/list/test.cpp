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
//	list<int> lt1; //����int���͵Ŀ�����
//	Print(lt1);
//	list<int> lt2(10, 2); //���캬��10��2��int��������
//	Print(lt2);
//	list<int> lt3(lt2); //��������int���͵�lt2�����ĸ���Ʒ
//	Print(lt3);
//	string s("hello world");
//	list<char> lt4(s.begin(),s.end()); //����string����ĳ������ĸ���Ʒ
//	Print(lt4);
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int sz = sizeof(arr) / sizeof(int);
//	list<int> lt5(arr, arr + sz); //��������ĳ������ĸ���Ʒ
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
//	//�����������������
//	list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//�����������������
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
//	lt.insert(pos, 9); //��2��λ�ò���9
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 9 2 3
//	pos = find(lt.begin(), lt.end(), 3);
//	lt.insert(pos, 2, 8); //��3��λ�ò���2��8
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 9 2 8 8 3
//	vector<int> v(2, 7);
//	pos = find(lt.begin(), lt.end(), 1);
//	lt.insert(pos, v.begin(), v.end()); //��1��λ�ò���2��7
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
//	lt.erase(pos); //ɾ��2
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 3 4 5
//	pos = find(lt.begin(), lt.end(), 4);
//	lt.erase(pos, lt.end()); //ɾ��4����֮���Ԫ��
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
//	lt.resize(7, 6); //��size����Ϊ7�������ֵΪ6
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //3 3 3 3 3 6 6
//	lt.resize(2); //��size��СΪ2
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
//	lt.clear(); //�������
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //(������)
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
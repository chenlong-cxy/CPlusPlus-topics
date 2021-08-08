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
//	lt.sort(); //Ĭ�Ͻ�������������Ϊ����
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
//	lt1.splice(lt1.begin(), lt2); //������lt2ƴ�ӵ�����lt1�Ŀ�ͷ
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //6 6 6 6 2 2 2 2 
//
//	list<int> lt3(4, 2);
//	list<int> lt4(4, 6);
//	lt3.splice(lt3.begin(), lt4, lt4.begin()); //������lt4�ĵ�һ������ƴ�ӵ�����lt3�Ŀ�ͷ
//	for (auto e : lt3)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //6 2 2 2 2 
//
//	list<int> lt5(4, 2);
//	list<int> lt6(4, 6);
//	lt5.splice(lt5.begin(), lt6, lt6.begin(), lt6.end()); //������lt6��ָ�������������ڵ�����ƴ�ӵ�����lt5�Ŀ�ͷ
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
//	lt.remove_if(single_digit); //ɾ����������ֵС��10��Ԫ��
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
//	lt.sort(); //���������е�Ԫ����Ϊ����
//	lt.unique(); //ɾ�����������������ظ�Ԫ��
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
//	lt1.sort(); //������lt1��Ϊ����
//	lt2.sort(); //������lt2��Ϊ����
//	lt1.merge(lt2); //��lt2�ϲ���lt1����
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
//	lt.reverse(); //����������Ԫ�ص�λ�ý�������
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
//	lt.assign(3, 'b'); //�������ݷ�����������滻�䵱ǰ����
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //b b b
//	string s("hello world");
//	lt.assign(s.begin(), s.end()); //�������ݷ�����������滻�䵱ǰ����
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
	lt1.swap(lt2); //������������������
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
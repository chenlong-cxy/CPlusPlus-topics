//#include <iostream>
//#include <functional>
//#include <map>
//using namespace std;

//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};

//int main()
//{
//	map<int, double> m1; //����һ��keyΪint���ͣ�valueΪdouble���͵Ŀ�����
//	m1[3] = 3.3;
//	m1[0] = 0.0;
//	m1[1] = 1.1;
//	m1[3] = 3.3;
//	m1[4] = 4.4;
//	cout << "m1:" << endl;
//	for (auto e : m1)
//	{
//		cout << e.first << ":" << e.second << " ";
//	}
//	cout << endl;
//	map<int, double> m2(m1); //��������keyΪint���ͣ�valueΪdouble���͵�m1�����ĸ���Ʒ
//	cout << "m2:" << endl;
//	for (auto e : m2)
//	{
//		cout << "<"<<e.first << "," << e.second << "> ";
//	}
//	cout << endl;
//	map<int, double> m3(m2.begin(), m2.end()); //ʹ�õ�������������m2����ĳ������ĸ���Ʒ
//	cout << "m3:" << endl;
//	for (auto e : m3)
//	{
//		cout << e.first << ":" << e.second << " ";
//	}
//	cout << endl;
//	map<int, double, greater<int>> m4(m1.begin(), m1.end()); //����һ��keyΪint���ͣ�valueΪdouble���͵Ŀ�������key�ȽϷ�ʽָ��Ϊ����
//	cout << "m4:" << endl;
//	for (auto e : m4)
//	{
//		cout << e.first << ":" << e.second << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
////pair<iterator, bool> insert(const value_type& val);
////typedef pair<const Key, T> value_type;
//int main()
//{
//	map<int, string> m;
//	//��ʽһ������pair�Ĺ��캯��������һ�������������
//	m.insert(pair<int, string>(2, "two"));
//	m.insert(pair<int, string>(1, "one"));
//	m.insert(pair<int, string>(3, "three"));
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
////template <class T1, class T2>
////pair<T1, T2> make_pair(T1 x, T2 y)
////{
////	return (pair<T1, T2>(x, y));
////}
//int main()
//{
//	map<int, string> m;
//	//��ʽ�������ú���ģ��make_pair������������
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	for (auto e : m)
//	{
//		cout << "<" << e.first << "," << e.second << ">" << " ";
//	}
//	cout << endl; //<1,one> <2,two> <3,three>
//	return 0;
//}

//iterator find(const key_type& k);
//void erase(iterator position);


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//��ȡkeyֵΪ2��Ԫ�صĵ�����
//	map<int, string>::iterator pos = m.find(2);
//	if (pos != m.end())
//	{
//		cout << pos->second << endl; //two
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//��ʽһ������keyֵ����ɾ��
//	m.erase(3);
//	//��ʽ�������ݵ���������ɾ��
//	map<int, string>::iterator pos = m.find(2);
//	if (pos != m.end())
//	{
//		m.erase(pos);
//	}
//	for (auto e : m)
//	{
//		cout << "<" << e.first << "," << e.second << ">" << " ";
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//��������������б���
//	map<int, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << "<" << it->first << "," << it->second << ">" << " ";
//		it++;
//	}
//	cout << endl; //<1,one> <2,two> <3,three>
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//�÷�����������б���
//	map<int, string>::reverse_iterator rit = m.rbegin();
//	while (rit != m.rend())
//	{
//		cout << "<" << rit->first << "," << rit->second << ">" << " ";
//		rit++;
//	}
//	cout << endl; //<3,three> <2,two> <1,one>
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//�÷�Χfor���б���
//	for (auto e : m)
//	{
//		cout << "<" << e.first << "," << e.second << ">" << " ";
//	}
//	cout << endl; //<1,one> <2,two> <3,three>
//	return 0;
//}


//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	//��ȡ������Ԫ�صĸ���
//	cout << m.size() << endl; //3
//	//������keyֵΪ2��Ԫ�ظ���
//	cout << m.count(2) << endl; //1
//	//�������
//	m.clear();
//	//�����п�
//	cout << m.empty() << endl; //1
//	//�������������е�����
//	map<int, string> tmp;
//	m.swap(tmp);
//	return 0;
//}


//mapped_type& operator[] (const key_type& k);
//
//(*((this->insert(make_pair(k, mapped_type()))).first)).second
//
//mapped_type& operator[] (const key_type& k)
//{
//	//1������insert���������ֵ��
//	pair<iterator, bool> ret = insert(make_pair(k, mapped_type()));
//	//2���ó���insert������ȡ���ĵ�����
//	iterator it = ret.first;
//	//3�����ظõ�����λ��Ԫ�ص�ֵvalue
//	return it->second;
//}

//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	map<int, string> m;
//	m.insert(make_pair(2, "two"));
//	m.insert(make_pair(1, "one"));
//	m.insert(make_pair(3, "three"));
//	m[2] = "dragon"; //�޸�keyֵΪ2��Ԫ�ص�valueΪdragon
//	m[6] = "six"; //�����ֵ��<6, "six">
//	for (auto e : m)
//	{
//		cout << "<" << e.first << "," << e.second << ">" << " ";
//	}
//	cout << endl; //<1,one> <2,dragon> <3,three> <6,six>
//	return 0;
//}


#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	multimap<int, string> mm;
	//����Ԫ�أ������ظ���
	mm.insert(make_pair(2, "two"));
	mm.insert(make_pair(2, "double"));
	mm.insert(make_pair(1, "one"));
	mm.insert(make_pair(3, "three"));
	auto pos = mm.find(2);
	cout << pos->first << ":" << pos->second << endl;
	cout << mm.count(2) << endl;
	for (const auto& e : mm)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,two> <2,double> <3,three>
	return 0;
}
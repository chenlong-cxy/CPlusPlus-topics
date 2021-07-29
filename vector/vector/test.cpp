//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//using namespace std;
//
//int main()
//{
//	vector<int> v1; //����int���͵Ŀ�����
//	vector<int> v2(10, 0); //���캬��10��0��int��������
//	vector<int> v3(v2); //��������v2�ĸ���Ʒ
//	v2.push_back(2);
//	vector<int> v4(v2.begin(), v2.end()); //ʹ�õ�������������v2������ĳһ������
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
//	vector<char> v5(s.begin(), s.end()); //��������string�����ĳһ������
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
//	cout << v1.size() << endl; //��ȡ��ǰ�����е���ЧԪ�ظ���
//	cout << v1.capacity() << endl; //��ȡ��ǰ�������������
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
//	v1.reserve(20); //�ı�������capacityΪ20��size����
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << v1.size() << endl; //10
//	cout << v1.capacity() << endl; //20
//	v1.resize(15); //�ı�������sizeΪ15
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
//	v1.push_back(1); //β��Ԫ��1
//	v1.push_back(2); //β��Ԫ��2
//	v1.push_back(3); //β��Ԫ��3
//	v1.push_back(4); //β��Ԫ��4
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v1.pop_back(); //βɾԪ��
//	v1.pop_back(); //βɾԪ��
//	v1.pop_back(); //βɾԪ��
//	v1.pop_back(); //βɾԪ��
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
//	//�����������������
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//�����������������
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
//	v.insert(v.begin(), 0); //��������ͷ����0
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.insert(v.begin(), 5, -1); //��������ͷ����5��-1
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.erase(v.begin()); //ɾ�������еĵ�һ��Ԫ��
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	v.erase(v.begin(), v.begin() + 5); //ɾ���ڸõ����������ڵ�Ԫ�أ�����ҿ���
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 2); //��ȡֵΪ2��Ԫ�صĵ�����
//	v.insert(pos, 10); //��2��λ�ò���10
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3); //��ȡֵΪ3��Ԫ�صĵ�����
//	v.erase(pos); //ɾ��3
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
//	v1.swap(v2); //����v1,v2�����ݿռ�
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
//	//ʹ�á��±�+[]���ķ�ʽ��������
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
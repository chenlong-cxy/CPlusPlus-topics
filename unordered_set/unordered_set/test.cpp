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
//	unordered_set<int> us1; //����int���͵Ŀ�����
//
//	unordered_set<int> us2(us1); //��������ͬ��������us1�ĸ���Ʒ
//
//	string str("abcedf");
//	unordered_set<char> us3(str.begin(), str.end()); //����string����ĳ������ĸ���Ʒ
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
//	//����Ԫ�أ�ȥ�أ�
//	us.insert(1);
//	us.insert(4);
//	us.insert(3);
//	us.insert(3);
//	us.insert(2);
//	us.insert(2);
//	us.insert(3);
//	//����������ʽһ����Χfor��
//	for (auto e : us)
//	{
//		cout << e << " ";
//	}
//	cout << endl; //1 4 3 2
//	//ɾ��Ԫ�ط�ʽһ
//	us.erase(3);
//	//ɾ��Ԫ�ط�ʽ��
//	unordered_set<int>::iterator pos = us.find(1); //����ֵΪ1��Ԫ��
//	if (pos != us.end())
//	{
//		us.erase(pos);
//	}
//	//����������ʽ����������������
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl; //4 2
//	//������ֵΪ2��Ԫ�ظ���
//	cout << us.count(2) << endl; //1
//	//������С
//	cout << us.size() << endl; //2
//	//�������
//	us.clear();
//	//������������������
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
	//����Ԫ�أ������ظ���
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
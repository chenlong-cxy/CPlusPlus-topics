//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", "����"));
//	dict["left"] = "���";
//	dict["left"] = "ʣ��";
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
//	unordered_map<int, double> um1; //����һ��keyΪint���ͣ�valueΪdouble���͵Ŀ�����
//
//	unordered_map<int, double> um2(um1); //��������ͬ��������um1�ĸ���Ʒ
//
//	unordered_map<int, double> um3(um2.begin(), um2.end()); //ʹ�õ�������������um2����ĳ������ĸ���Ʒ
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
//	//�����ֵ�Է�ʽһ�����������������
//	um.insert(pair<int, string>(1, "one"));
//	um.insert(pair<int, string>(2, "two"));
//	um.insert(pair<int, string>(3, "three"));
//	//������ʽһ����Χfor
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //1->one 2->two 3->three
//	//�����ֵ�Է�ʽ��������make_pair����ģ�����
//	um.insert(make_pair(4, "four"));
//	um.insert(make_pair(5, "five"));
//	um.insert(make_pair(6, "six"));
//	//������ʽ��������������
//	unordered_map<int, string>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << "->" << it->second << " ";
//		it++;
//	}
//	cout << endl; //1->one 2->two 3->three 4->four 5->five 6->six
//	//�����ֵ�Է�ʽ��������[]��������غ������в��루���ã�
//	um[7] = "seven";
//	um[8] = "eight";
//	um[9] = "nine";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 5->five 6->six 7->seven 8->eight
//	//ɾ����ֵ�Է�ʽһ������keyֵɾ��
//	um.erase(5);
//	//ɾ����ֵ�Է�ʽ�������ݵ�����ɾ��
//	unordered_map<int, string>::iterator pos = um.find(7); //���Ҽ�ֵΪ7�ļ�ֵ��
//	if (pos != um.end())
//	{
//		um.erase(pos);
//	}
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one 2->two 3->three 4->four 6->six 8->eight
//	//�޸ļ�ֵ�Է�ʽһ��ͨ��find��õ�������ͨ���������޸�
//	pos = um.find(1);
//	if (pos != um.end())
//	{
//		pos->second = "one/first";
//	}
//	//�޸ļ�ֵ�Է�ʽ��������[]��������غ��������޸ģ����ã�
//	um[2] = "two/second";
//	for (auto e : um)
//	{
//		cout << e.first << "->" << e.second << " ";
//	}
//	cout << endl; //9->nine 1->one/first 2->two/second 3->three 4->four 6->six 8->eight
//	//������keyֵΪ3�ļ�ֵ�Եĸ���
//	cout << um.count(3) << endl;
//	//�����Ĵ�С
//	cout << um.size() << endl;
//	//�������
//	um.clear();
//	//�����п�
//	cout << um.empty() << endl;
//	//������������������
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
	//�����ֵ�ԣ������ֵ�ظ���
	umm.insert(make_pair(2022, "�Է�"));
	umm.insert(make_pair(2022, "˯��"));
	umm.insert(make_pair(2022, "�ô���"));
	for (auto e : umm)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //2022->�Է� 2022->˯�� 2022->�ô���
	return 0;
}
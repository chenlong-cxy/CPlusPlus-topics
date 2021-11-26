#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	set<int> s1{ 1, 2, 3, 4 }; //����int���͵Ŀ�����

	set<int> s2(s1); //��������int����s1�����ĸ���Ʒ
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	string str("abcdef");
	set<char> s3(str.begin(), str.end()); //����string����ĳ������ĸ���Ʒ
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;
}

bool Erase(const K& key)
{
	size_t index = kv.first%_table.size();
	if (!_table[index]) //��λ��������
		return false;
	Node* cur = _table[index];
	Node* prev = nullptr;
	while (cur)
	{
		if (cur->_kv.first == key)
		{
			prev->_next = cur->_next;
			delete cur;
			_size--;
			return true;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
	return false;
}
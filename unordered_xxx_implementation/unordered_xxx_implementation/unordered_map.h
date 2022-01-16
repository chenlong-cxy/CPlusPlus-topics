#include "HashTable.h"

namespace cl //��ֹ������ͻ
{
	template<class K, class V>
	class unordered_map
	{
		//�º���
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) //���ؼ�ֵ�Ե��еļ�ֵkey
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		//���뺯��
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		//��ֵ���������
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			iterator it = ret.first;
			return it->second;
		}
		//ɾ������
		void erase(const K& key)
		{
			_ht.Erase(key);
		}
		//���Һ���
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}
	private:
		HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};

	void testmap()
	{
		unordered_map<string, int> um;
		um.insert(make_pair("ƻ��", 1));
		um.insert(make_pair("�㽶", 1));
		um.insert(make_pair("����", 1));
		um.insert(make_pair("����", 1));
		um["ƻ��"]--;
		um["����"] = 9;
		unordered_map<string, int>::iterator it = um.begin();
		while (it != um.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
		unordered_map<string, int> tmp(um);
		tmp["����"] = 2022;
		it = tmp.begin();
		while (it != tmp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;

		tmp = um;
		it = tmp.begin();
		while (it != tmp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
		it = tmp.find("�㽶");
		if (it != tmp.end())
		{
			cout << "�ҵ���" << endl;
		}
		else
		{
			cout << "û�ҵ�" << endl;
		}
		tmp.erase("�㽶");

		it = tmp.begin();
		while (it != tmp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
	}
}
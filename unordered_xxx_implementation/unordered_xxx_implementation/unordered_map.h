#include "HashTable.h"

namespace cl
{
	template<class K, class V>
	class unordered_map
	{
		//仿函数
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) //返回键值对当中的键值key
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
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			iterator it = ret.first;
			return it->second;
		}
		void erase(const K& key)
		{
			_ht.Erase(key);
		}
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
		um.insert(make_pair("苹果", 1));
		um.insert(make_pair("香蕉", 1));
		um.insert(make_pair("番茄", 1));
		um.insert(make_pair("葡萄", 1));
		um["苹果"]--;
		um["橙子"] = 9;
		unordered_map<string, int>::iterator it = um.begin();
		while (it != um.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
		unordered_map<string, int> tmp(um);
		tmp["橙子"] = 2022;
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
		it = tmp.find("香蕉");
		if (it != tmp.end())
		{
			cout << "找到了" << endl;
		}
		else
		{
			cout << "没找到" << endl;
		}
		tmp.erase("香蕉");

		it = tmp.begin();
		while (it != tmp.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
	}
}
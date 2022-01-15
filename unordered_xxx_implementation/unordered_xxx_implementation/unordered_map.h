#include "HashTable.h"

namespace cl
{
	template<class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
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
	private:
		HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};

	void testmap()
	{
		unordered_map<string, int> um;
		um.insert(make_pair("Æ»¹û", 1));
		um.insert(make_pair("Ïã½¶", 1));
		um.insert(make_pair("·¬ÇÑ", 1));
		um.insert(make_pair("ÆÏÌÑ", 1));
		um["Æ»¹û"]--;
		um["³È×Ó"] = 9;
		unordered_map<string, int>::iterator it = um.begin();
		while (it != um.end())
		{
			cout << it->first << ":" << it->second << " ";
			++it;
		}
		cout << endl;
		unordered_map<string, int> tmp(um);
		tmp["³È×Ó"] = 2022;
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
	}
}
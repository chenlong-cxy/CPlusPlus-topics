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
		bool insert(const pair<K, V>& kv)
		{
			_ht.Insert(kv);
			return true;
		}
		bool erase(const K& key)
		{
			_ht.Erase(key);
			return true;
		}
		bool find(const K& key)
		{
			_ht.Find(key);
			return true;
		}
	private:
		HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};
}
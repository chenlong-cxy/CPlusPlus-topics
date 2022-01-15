#include "HashTable.h"

namespace cl
{
	template<class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		//现在没有实例化，没办法到HashTable里面找iterator，所以typename就是告诉编译器这里是一个类型，实例化以后再去取
		typedef typename HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}
	private:
		HashTable<K, K, SetKeyOfT> _ht;
	};

	void testset()
	{
		unordered_set<int> us;
		us.insert(124);
		us.insert(2);
		us.insert(324);
		us.insert(4);
		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}
}
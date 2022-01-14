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
		//����Ƕ���������Ҳ�������ΪҪʵ�����������
		typedef HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		bool insert(const K& key)
		{
			_ht.Insert(key);
			return true;
		}
	private:
		HashTable<K, K, SetKeyOfT> _ht;
	};
}
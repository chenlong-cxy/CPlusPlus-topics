#include "HashTable.h"

namespace cl //��ֹ������ͻ
{
	template<class K>
	class unordered_set
	{
		//�º���
		struct SetKeyOfT
		{
			const K& operator()(const K& key) //���ؼ�ֵkey
			{
				return key;
			}
		};
	public:
		//����û��ʵ������û�취��HashTable������iterator������typename���Ǹ��߱�����������һ�����ͣ�ʵ�����Ժ���ȥȡ
		typedef typename HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		//���뺯��
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
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
		it = us.find(2);
		if (it != us.end())
		{
			cout << "�ҵ���" << endl;
		}
		else
		{
			cout << "û�ҵ�" << endl;
		}
		us.erase(2);
		it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
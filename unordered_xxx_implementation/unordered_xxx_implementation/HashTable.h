#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//ÿ����ϣͰ�д洢���ݵĽṹ
template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;

	//���캯��
	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{}
};

//ǰ������
template<class K, class T, class KeyOfT, class HashFunc>
class HashTable;

//���������
template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
struct __HTIterator
{
	typedef HashNode<T> Node;
	typedef HashTable<K, T, KeyOfT, HashFunc> HT;
	typedef __HTIterator<K, T, KeyOfT, HashFunc> Self;

	Node* _node; //���ָ��
	HT* _pht; //��ϣ��ĵ�ַ

	__HTIterator(Node* node, HT* pht)
		:_node(node)
		, _pht(pht)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	//ǰ��++
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyOfT kot;
			HashFunc hf;
			size_t index = hf(kot(_node->_data)) % _pht->_table.size();
			index++; //����һ��Ͱ��ʼ��
			while (index < _pht->_table.size())
			{
				if (_pht->_table[index])
				{
					_node = _pht->_table[index];
					return *this;
				}
				index++;
			}
			_node = nullptr;
		}
		return *this;
	}
	//ǰ��--
	Self& operator--()
	{

	}
};

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template<>
struct Hash<string>
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto ch : s)
		{
			value = value * 131 + ch; //BKDR
		}
		return value;
	}
};
//��ϣ���ʵ��
template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
class HashTable
{
	typedef HashNode<T> Node;
	typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator;
public:
	iterator begin()
	{
		size_t i = 0;
		while (i < _table.size())
		{
			if (_table[i])
			{
				return __HTIterator(_table[i], this);
			}
			i++;
		}
		return end();
	}
	iterator end()
	{
		return __HTIterator(nullptr, this);
	}
	////���캯��
	//HashTable()
	//	:_n(0)
	//{}
	////�������캯��
	//HashTable(const HashTable<K, V>& ht)
	//{
	//	//1���Ƚ�ԭ���Ĺ�ϣ���ͷ�
	//	_Destroy(_table);
	//	//2������ϣ��Ĵ�С����Ϊht._table�Ĵ�С
	//	_table.resize(ht._table.size());
	//	//3����ht._tableÿ��Ͱ���еĽ��һ�����������Լ��Ĺ�ϣ���У������
	//	for (size_t i = 0; i < ht._table.size(); i++)
	//	{
	//		if (ht._table[i])
	//		{
	//			Node* cur = ht._table[i];
	//			while (cur)
	//			{
	//				Node* next = cur->_next;
	//				Node* newnode = new Node(cur->_kv);
	//				newnode->_next = _table[i];
	//				_table[i] = newnode;
	//				cur = next;
	//			}
	//		}
	//	}
	//	//4�����Ĺ�ϣ���е���Ч���ݸ���
	//	_n = ht._n;
	//}
	////��ֵ��������غ���
	//HashTable<K, V>& operator=(const HashTable<K, V> ht)
	//{
	//	_table.swap(ht._table);
	//	swap(_n, ht._n);
	//	return *this;
	//}
	//void _Destroy(vector<Node*>& v)
	//{
	//	//����ϣ���еĽ��һ�����ͷ�
	//	for (size_t i = 0; i < v.size(); i++)
	//	{
	//		if (v[i]) //Ͱ��Ϊ��
	//		{
	//			Node* cur = v[i];
	//			while (cur)
	//			{
	//				Node* next = cur->_next;
	//				delete cur;
	//				cur = next;
	//			}
	//			v[i] = nullptr;
	//		}
	//	}
	//}
	////��������
	//~HashTable()
	//{
	//	//�ͷŹ�ϣ��
	//	_Destroy(_table);
	//}
	//��ȡ�������ݺ��ϣ��Ĵ�С
	size_t GetNextPrime(size_t prime)
	{
		const int PRIMECOUNT = 28;
		//��������
		const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		size_t i = 0;
		for (i = 0; i < PRIMECOUNT; i++)
		{
			if (primeList[i] > prime)
				return primeList[i];
		}
		return primeList[i];
	}
	//���뺯��
	bool Insert(const T& data)
	{
		KeyOfT kot;
		//1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
		Node* ret = Find(kot(data));
		if (ret) //��ϣ�����Ѿ����ڸü�ֵ�ļ�ֵ�ԣ��������������ࣩ
		{
			return false; //����ʧ��
		}

		//2���ж��Ƿ���Ҫ������ϣ��Ĵ�С
		if (_n == _table.size()) //��ϣ��Ĵ�СΪ0���������ӳ���1
		{
			//����
			//a������һ���µĹ�ϣ���¹�ϣ��Ĵ�С����Ϊԭ��ϣ���2��������ϣ���СΪ0���򽫹�ϣ��ĳ�ʼ��С����Ϊ10��
			HashFunc hf;
			vector<Node*> newtable;
			//size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//newtable.resize(newsize);

			newtable.resize(GetNextPrime(_table.size()));
				
			//b����ԭ��ϣ���еĽ����뵽�¹�ϣ��
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]) //Ͱ��Ϊ��
				{
					Node* cur = _table[i];
					while (cur) //����Ͱ�Ľ��ȡ��Ϊֹ
					{
						Node* next = cur->_next; //��¼cur����һ�����
						size_t index = hf(kot(cur->_data))%newtable.size(); //ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
						//���ý��ͷ�嵽�¹�ϣ���б��Ϊindex�Ĺ�ϣͰ��
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next; //ȡԭ��ϣ���и�Ͱ����һ�����
					}
					_table[i] = nullptr; //��Ͱȡ��󽫸�Ͱ�ÿ�
				}
			}
			//c��������������ϣ��
			_table.swap(newtable);
		}

		//3������ֵ�Բ����ϣ��
		HashFunc hf;
		size_t index = hf(kot(data)) % _table.size(); //ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
		Node* newnode = new Node(data); //�����������ݴ���һ����������
		//���ý��ͷ�嵽�¹�ϣ���б��Ϊindex�Ĺ�ϣͰ��
		newnode->_next = _table[index];
		_table[index] = newnode;

		//4����ϣ���е���ЧԪ�ظ�����һ
		_n++;
		return true;
	}
	//���Һ���
	HashNode<T>* Find(const K& key)
	{
		if (_table.size() == 0) //��ϣ���СΪ0������ʧ��
		{
			return nullptr;
		}

		KeyOfT kot;
		HashFunc hf;
		size_t index = hf(key) % _table.size(); //ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
		//�������Ϊindex�Ĺ�ϣͰ
		HashNode<T>* cur = _table[index];
		while (cur) //ֱ������Ͱ������Ϊֹ
		{
			if (kot(cur->_data) == key) //keyֵƥ�䣬����ҳɹ�
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr; //ֱ����Ͱȫ��������ϻ�û���ҵ�Ŀ��Ԫ�أ�����ʧ��
	}
	//ɾ������
	bool Erase(const K& key)
	{
		KeyOfT kot;
		HashFunc hf;
		//1��ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
		size_t index = hf(key) % _table.size();
		//2���ڱ��Ϊindex�Ĺ�ϣͰ��Ѱ�Ҵ�ɾ�����
		Node* prev = nullptr;
		Node* cur = _table[index];
		while (cur) //ֱ������Ͱ������Ϊֹ
		{
			if (kot(cur->_data) == key) //keyֵƥ�䣬����ҳɹ�
			{
				//3�����ҵ��˴�ɾ����㣬��ɾ���ý��
				if (prev == nullptr) //��ɾ������ǹ�ϣͰ�еĵ�һ�����
				{
					_table[index] = cur->_next; //����һ�����Ӹù�ϣͰ���Ƴ�
				}
				else //��ɾ����㲻�ǹ�ϣͰ�ĵ�һ�����
				{
					prev->_next = cur->_next; //���ý��ӹ�ϣͰ���Ƴ�
				}
				delete cur; //�ͷŸý��
				//4��ɾ�����󣬽���ϣ���е���ЧԪ�ظ�����һ
				_n--;
				return true; //ɾ���ɹ�
			}
			prev = cur;
			cur = cur->_next;
		}
		//��ɾ�����ܻᵼ�µ�����ʧЧ
			
		return false; //ֱ����Ͱȫ��������ϻ�û���ҵ���ɾ��Ԫ�أ�ɾ��ʧ��
	}
private:
	vector<Node*> _table;
	size_t _n;
};

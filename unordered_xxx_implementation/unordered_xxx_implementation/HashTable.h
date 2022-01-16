#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//哈希结点的定义
template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;

	//构造函数
	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{}
};

//前置声明
template<class K, class T, class KeyOfT, class HashFunc>
class HashTable;

//正向迭代器
template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
struct __HTIterator
{
	typedef HashNode<T> Node; //哈希结点的类型
	typedef HashTable<K, T, KeyOfT, HashFunc> HT; //哈希表的类型
	typedef __HTIterator<K, T, KeyOfT, HashFunc> Self; //正向迭代器的类型

	Node* _node; //结点指针
	HT* _pht; //哈希表的地址

	//构造函数
	__HTIterator(Node* node, HT* pht)
		:_node(node) //结点指针
		, _pht(pht) //哈希表地址
	{}

	T& operator*()
	{
		return _node->_data; //返回哈希结点中数据的引用
	}

	T* operator->()
	{
		return &_node->_data; //返回哈希结点中数据的地址
	}

	bool operator!=(const Self& s) const
	{
		return _node != s._node; //判断两个结点的地址是否不同
	}

	bool operator==(const Self& s) const
	{
		return _node == s._node; //判断两个结点的地址是否相同
	}

	//前置++
	Self& operator++()
	{
		if (_node->_next) //该结点不是当前哈希桶中的最后一个结点
		{
			_node = _node->_next; //++后变为当前哈希桶中的下一个结点
		}
		else //该结点是当前哈希桶中的最后一个结点
		{
			KeyOfT kot;
			HashFunc hf;
			size_t index = hf(kot(_node->_data)) % _pht->_table.size(); //通过哈希函数计算出当前所处哈希桶编号index（除数不能是capacity）
			index++; //从下一个位置开始找一个非空的哈希桶
			while (index < _pht->_table.size()) //直到将整个哈希表找完
			{
				if (_pht->_table[index]) //当前哈希桶非空
				{
					_node = _pht->_table[index]; //++后变为当前哈希桶中的第一个结点
					return *this;
				}
				index++; //当前哈希桶为空桶，找下一个哈希桶
			}
			_node = nullptr; //哈希表中已经没有空桶了，++后变为nullptr
		}
		return *this;
	}
	//前置--（单向迭代器，没有实现--，若要实现可以考虑将单链表换成双链表）
	//Self& operator--()
	//{

	//}
};

template<class K>
struct Hash
{
	size_t operator()(const K& key) //返回键值key
	{
		return key;
	}
};
//string类型的特化
template<>
struct Hash<string>
{
	size_t operator()(const string& s) //BKDRHash算法
	{
		size_t value = 0;
		for (auto ch : s)
		{
			value = value * 131 + ch;
		}
		return value;
	}
};
//哈希表的实现
template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
class HashTable
{
	//将正向迭代器类声明为哈希表类的友元
	template<class K, class T, class KeyOfT, class HashFunc>
	friend struct __HTIterator;
	//friend struct __HTIterator<K, T,KeyOfT, HashFunc>;
	typedef HashNode<T> Node; //哈希结点类型
public:
	typedef __HTIterator<K, T, KeyOfT, HashFunc> iterator; //正向迭代器的类型

	iterator begin()
	{
		size_t i = 0;
		while (i < _table.size()) //找到第一个非空哈希桶
		{
			if (_table[i]) //该哈希桶非空
			{
				return iterator(_table[i], this); //返回该哈希桶中的第一个结点的正向迭代器
			}
			i++;
		}
		return end(); //哈希桶中无数据，返回end()
	}
	iterator end()
	{
		return iterator(nullptr, this); //返回nullptr的正向迭代器
	}

	//构造函数
	HashTable() = default; //显示指定生成默认构造

	//拷贝构造函数
	HashTable(const HashTable& ht)
	{
		//1、将哈希表的大小调整为ht._table的大小
		_table.resize(ht._table.size());
		//2、将ht._table每个桶当中的结点一个个拷贝到自己的哈希表中（深拷贝）
		for (size_t i = 0; i < ht._table.size(); i++)
		{
			if (ht._table[i]) //桶不为空
			{
				Node* cur = ht._table[i];
				while (cur) //将该桶的结点取完为止
				{
					Node* copy = new Node(cur->_data); //创建拷贝结点
					//将拷贝结点头插到当前桶
					copy->_next = _table[i];
					_table[i] = copy;
					cur = cur->_next; //取下一个待拷贝结点
				}
			}
		}
		//3、更改哈希表当中的有效数据个数
		_n = ht._n;
	}
	//赋值运算符重载函数
	HashTable& operator=(HashTable ht)
	{
		//交换哈希表中两个成员变量的数据
		_table.swap(ht._table);
		swap(_n, ht._n);

		return *this; //支持连续赋值
	}
	//析构函数
	~HashTable()
	{
		//将哈希表当中的结点一个个释放
		for (size_t i = 0; i < _table.size(); i++)
		{
			if (_table[i]) //桶不为空
			{
				Node* cur = _table[i];
				while (cur) //将该桶的结点取完为止
				{
					Node* next = cur->_next; //记录下一个结点
					delete cur; //释放结点
					cur = next;
				}
				_table[i] = nullptr; //将该哈希桶置空
			}
		}
	}
	//获取本次增容后哈希表的大小
	size_t GetNextPrime(size_t prime)
	{
		const int PRIMECOUNT = 28;
		//素数序列
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
	//插入函数
	pair<iterator, bool> Insert(const T& data)
	{
		KeyOfT kot;
		//1、查看哈希表中是否存在该键值的键值对
		iterator ret = Find(kot(data));
		if (ret != end()) //哈希表中已经存在该键值的键值对（不允许数据冗余）
		{
			return make_pair(ret, false); //插入失败
		}

		//2、判断是否需要调整哈希表的大小
		if (_n == _table.size()) //哈希表的大小为0，或负载因子超过1
		{
			//增容
			//a、创建一个新的哈希表，新哈希表的大小设置为原哈希表的2倍（若哈希表大小为0，则将哈希表的初始大小设置为10）
			HashFunc hf;
			vector<Node*> newtable;
			//size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//newtable.resize(newsize);

			newtable.resize(GetNextPrime(_table.size()));
				
			//b、将原哈希表当中的结点插入到新哈希表
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]) //桶不为空
				{
					Node* cur = _table[i];
					while (cur) //将该桶的结点取完为止
					{
						Node* next = cur->_next; //记录cur的下一个结点
						size_t index = hf(kot(cur->_data))%newtable.size(); //通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
						//将该结点头插到新哈希表中编号为index的哈希桶中
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next; //取原哈希表中该桶的下一个结点
					}
					_table[i] = nullptr; //该桶取完后将该桶置空
				}
			}
			//c、交换这两个哈希表
			_table.swap(newtable);
		}

		//3、将键值对插入哈希表
		HashFunc hf;
		size_t index = hf(kot(data)) % _table.size(); //通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
		Node* newnode = new Node(data); //根据所给数据创建一个待插入结点
		//将该结点头插到新哈希表中编号为index的哈希桶中
		newnode->_next = _table[index];
		_table[index] = newnode;

		//4、哈希表中的有效元素个数加一
		_n++;
		return make_pair(iterator(newnode, this), true);
	}
	//查找函数
	iterator Find(const K& key)
	{
		if (_table.size() == 0) //哈希表大小为0，查找失败
		{
			return end();
		}

		KeyOfT kot;
		HashFunc hf;
		size_t index = hf(key) % _table.size(); //通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
		//遍历编号为index的哈希桶
		HashNode<T>* cur = _table[index];
		while (cur) //直到将该桶遍历完为止
		{
			if (kot(cur->_data) == key) //key值匹配，则查找成功
			{
				return iterator(cur, this);
			}
			cur = cur->_next;
		}
		return end(); //直到该桶全部遍历完毕还没有找到目标元素，查找失败
	}
	//删除函数
	bool Erase(const K& key)
	{
		KeyOfT kot;
		HashFunc hf;
		//1、通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
		size_t index = hf(key) % _table.size();
		//2、在编号为index的哈希桶中寻找待删除结点
		Node* prev = nullptr;
		Node* cur = _table[index];
		while (cur) //直到将该桶遍历完为止
		{
			if (kot(cur->_data) == key) //key值匹配，则查找成功
			{
				//3、若找到了待删除结点，则删除该结点
				if (prev == nullptr) //待删除结点是哈希桶中的第一个结点
				{
					_table[index] = cur->_next; //将第一个结点从该哈希桶中移除
				}
				else //待删除结点不是哈希桶的第一个结点
				{
					prev->_next = cur->_next; //将该结点从哈希桶中移除
				}
				delete cur; //释放该结点
				//4、删除结点后，将哈希表中的有效元素个数减一
				_n--;
				return true; //删除成功
			}
			prev = cur;
			cur = cur->_next;
		}
		//假删除可能会导致迭代器失效
			
		return false; //直到该桶全部遍历完毕还没有找到待删除元素，删除失败
	}
private:
	vector<Node*> _table; //哈希表
	size_t _n = 0; //哈希表中的有效元素个数
};

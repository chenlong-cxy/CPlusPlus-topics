#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace cl
{
	template<class T>
	struct _list_node
	{
		_list_node(const T& val = T())
			:_val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}

		T _val;
		_list_node<T>* _prev;
		_list_node<T>* _next;
	};

	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		_list_iterator(node* pnode)
			:_pnode(pnode)
		{}
		//前置++
		self operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		//前置--
		self operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		//后置++
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}
		//后置--
		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
		Ref operator*()
		{
			return _pnode->_val;
		}
		Ptr operator->()
		{
			return &_pnode->_val;
		}
		bool operator==(const self& s) const
		{
			return _pnode == s._pnode;
		}
		bool operator!=(const self& s) const
		{
			return _pnode != s._pnode;
		}
		node* _pnode;
	};

	template<class T>
	class list
	{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (const auto& e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}
		void swap(list<T>& lt)
		{
			::swap(_head, lt._head);
		}
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}
		//void push_back(const T& x)
		//{
		//	node* newnode = new node(x);
		//	node* tail = _head->_prev;
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	_head->_prev = newnode;
		//	newnode->_next = _head;
		//}
		void insert(iterator pos, const T& x)
		{
			assert(pos._pnode);

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		iterator erase(iterator pos)
		{
			assert(pos._pnode);
			assert(pos != end());

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
			
			return iterator(next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
		bool empty() const
		{
			return begin() == end();
		}
		size_t size() const
		{
			size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				sz++;
				it++;
			}
			return sz;
		}
		T& front()
		{
			return *begin();
		}
		const T& front() const
		{
			return *begin();
		}
		T& back()
		{
			return *(--end());
		}
		const T& back() const
		{
			return *(--end());
		}
		void resize(size_t n, const T& val = T())
		{
			iterator i = begin();
			size_t len = 0;
			while (len < n&&i != end())
			{
				len++;
				i++;
			}
			if (len == n)
			{
				while (i != end())
				{
					i = erase(i);
				}
			}
			else
			{
				while (len < n)
				{
					push_back(val);
					len++;
				}
			}

		}
	private:
		node* _head;
	};
	void test1()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
		list<int> lt2(lt1);
		lt2.pop_back();
		swap(lt2, lt1);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << lt1.size() << endl;
		cout << lt2.size() << endl;
	}
	void test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		cout << ++lt.front() << endl;
		cout << ++lt.back() << endl;
	}
	void test3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		lt.resize(10);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		lt.resize(15, 9);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		lt.resize(5);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}



namespace cl
{
	//模拟实现list当中的结点类
	template<class T>
	struct _list_node
	{
		//成员函数
		_list_node(const T& val = T()); //构造函数

		//成员变量
		T _val;                 //数据域
		_list_node<T>* _next;   //后继指针
		_list_node<T>* _prev;   //前驱指针
	};

	//模拟实现list迭代器
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		_list_iterator(node* pnode);  //构造函数

		//各种运算符重载函数
		self operator++();
		self operator--();
		self operator++(int);
		self operator--(int);
		bool operator==(const self& s) const;
		bool operator!=(const self& s) const;
		Ref operator*();
		Ptr operator->();

		//成员变量
		node* _pnode; //一个指向结点的指针
	};

	//模拟实现list
	template<class T>
	class list
	{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		//默认成员函数
		list();
		list(const list<T>& lt);
		list<T>& operator=(const list<T>& lt);
		~list();

		//迭代器相关函数
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		//访问容器相关函数
		T& front();
		T& back();
		const T& front() const;
		const T& back() const;

		//插入、删除函数
		void insert(iterator pos, const T& x);
		iterator erase(iterator pos);
		void push_back(const T& x);
		void pop_back();
		void push_front(const T& x);
		void pop_front();

		//其他函数
		size_t size() const;
		void resize(size_t n, const T& val = T());
		void clear();
		bool empty() const;
		void swap(list<T>& lt);

	private:
		node* _head; //指向链表头结点的指针
	};
}
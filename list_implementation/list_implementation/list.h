#pragma once
#include <iostream>
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
		bool operator!=(const self& s)
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
		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			_head->_prev = newnode;
			newnode->_next = _head;
		}
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
		iterator erase(iterator pos)
		{
			assert(pos._pnode);
			assert(pos._pnode != end());

			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;
			
			return iterator(next);
		}
	private:
		node* _head;
	};
	void test1()
	{
		list<int> lt;
		lt.push_back(0);
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		
	}
}
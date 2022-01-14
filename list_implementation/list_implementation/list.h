#pragma once
#include "Date.h"
#include <iostream>
#include <assert.h>
using namespace std;

namespace cl
{
	template<class T>
	struct _list_node
	{
		//构造函数
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

		//构造函数
		_list_iterator(node* pnode)
			:_pnode(pnode)
		{}
		//前置++
		self& operator++()
		{
			_pnode = _pnode->_next; //让结点指针指向后一个结点
			return *this; //返回自增后的结点指针
		}
		//前置--
		self& operator--()
		{
			_pnode = _pnode->_prev; //让结点指针指向前一个结点
			return *this; //返回自减后的结点指针
		}
		//后置++
		self operator++(int)
		{
			self tmp(*this); //记录当前结点指针的指向
			_pnode = _pnode->_next; //让结点指针指向后一个结点
			return tmp; //返回自增前的结点指针
		}
		//后置--
		self operator--(int)
		{
			self tmp(*this); //记录当前结点指针的指向
			_pnode = _pnode->_prev; //让结点指针指向前一个结点
			return tmp; //返回自减前的结点指针
		}
		Ref operator*()
		{
			return _pnode->_val; //返回结点指针所指结点的数据
		}
		Ptr operator->()
		{
			return &_pnode->_val; //返回结点指针所指结点的数据的地址
		}
		bool operator==(const self& s) const
		{
			return _pnode == s._pnode; //判断两个结点指针指向是否相同
		}
		bool operator!=(const self& s) const
		{
			return _pnode != s._pnode; //判断两个结点指针指向是否不同
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
		//构造函数
		list()
		{
			_head = new node; //申请一个头结点
			_head->_next = _head; //头结点的后继指针指向自己
			_head->_prev = _head; //头结点的前驱指针指向自己
		}
		//拷贝构造函数
		list(const list<T>& lt)
		{
			_head = new node; //申请一个头结点
			_head->_next = _head; //头结点的后继指针指向自己
			_head->_prev = _head; //头结点的前驱指针指向自己
			for (const auto& e : lt)
			{
				push_back(e); //将容器lt当中的数据一个个尾插到链表后面
			}
		}
		void clear()
		{
			iterator it = begin();
			while (it != end()) //逐个删除结点，只保留头结点
			{
				it = erase(it);
			}
		}
		////传统写法
		//list<T>& operator=(const list<T>& lt)
		//{
		//	if (this != &lt) //避免自己给自己赋值
		//	{
		//		clear(); //清空容器
		//		for (const auto& e : lt)
		//		{
		//			push_back(e); //将容器lt当中的数据一个个尾插到链表后面
		//		}
		//	}
		//	return *this; //支持连续赋值
		//}
		void swap(list<T>& lt)
		{
			::swap(_head, lt._head); //交换两个容器当中的头指针即可
		}
		//赋值运算符重载函数
		//现代写法
		list<T>& operator=(list<T> lt) //编译器接收右值的时候自动调用其拷贝构造函数
		{
			swap(lt); //交换这两个对象
			return *this; //支持连续赋值
		}
		//析构函数
		~list()
		{
			clear(); //清理容器
			delete _head; //释放头结点
			_head = nullptr; //头指针置空
		}
		iterator begin()
		{
			//返回使用头结点后一个结点的地址构造出来的普通迭代器
			return iterator(_head->_next);
		}
		iterator end()
		{
			//返回使用头结点的地址构造出来的普通迭代器
			return iterator(_head);
		}
		const_iterator begin() const
		{
			//返回使用头结点后一个结点的地址构造出来的const迭代器
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			//返回使用头结点的地址构造出来的普通const迭代器
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
		//插入函数
		void insert(iterator pos, const T& x)
		{
			assert(pos._pnode); //检测pos的合法性

			node* cur = pos._pnode; //迭代器pos处的结点指针
			node* prev = cur->_prev; //迭代器pos前一个位置的结点指针
			node* newnode = new node(x); //根据所给数据x构造一个待插入结点

			//建立newnode与cur之间的双向关系
			newnode->_next = cur;
			cur->_prev = newnode;
			//建立newnode与prev之间的双向关系
			newnode->_prev = prev;
			prev->_next = newnode;
		}
		//尾插
		void push_back(const T& x)
		{
			insert(end(), x); //在头结点前插入结点
		}
		//头插
		void push_front(const T& x)
		{
			insert(begin(), x); //在第一个有效结点前插入结点
		}
		//删除函数
		iterator erase(iterator pos)
		{
			assert(pos._pnode); //检测pos的合法性
			assert(pos != end()); //删除的结点不能是头结点

			node* cur = pos._pnode; //迭代器pos处的结点指针
			node* prev = cur->_prev; //迭代器pos前一个位置的结点指针
			node* next = cur->_next; //迭代器pos后一个位置的结点指针

			delete cur; //释放cur结点

			//建立prev与next之间的双向关系
			prev->_next = next;
			next->_prev = prev;
			
			return iterator(next); //返回所给迭代器pos的下一个迭代器
		}
		//尾删
		void pop_back()
		{
			erase(--end()); //删除头结点的前一个结点
		}
		//头删
		void pop_front()
		{
			erase(begin()); //删除第一个有效结点
		}
		bool empty() const
		{
			return begin() == end(); //判断是否只有头结点
		}
		size_t size() const
		{
			size_t sz = 0; //统计有效数据个数
			const_iterator it = begin(); //获取第一个有效数据的迭代器
			while (it != end()) //通过遍历统计有效数据个数
			{
				sz++;
				it++;
			}
			return sz; //返回有效数据个数
		}
		T& front()
		{
			return *begin(); //返回第一个有效数据的引用
		}
		const T& front() const
		{
			return *begin(); //返回第一个有效数据的const引用
		}
		T& back()
		{
			return *(--end()); //返回最后一个有效数据的引用
		}
		const T& back() const
		{
			return *(--end()); //返回最后一个有效数据的const引用
		}
		void resize(size_t n, const T& val = T())
		{
			iterator i = begin(); //获取第一个有效数据的迭代器
			size_t len = 0; //记录当前所遍历的数据个数
			while (len < n&&i != end())
			{
				len++;
				i++;
			}
			if (len == n) //说明容器当中的有效数据个数大于或是等于n
			{
				while (i != end()) //只保留前n个有效数据
				{
					i = erase(i); //每次删除后接收下一个数据的迭代器
				}
			}
			else //说明容器当中的有效数据个数小于n
			{
				while (len < n) //尾插数据为val的结点，直到容器当中的有效数据个数为n
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
	void test4()
	{
		list<Date> lt;
		Date d1(2021, 8, 10);
		Date d2(1980, 4, 3);
		Date d3(1931, 6, 29);
		lt.push_back(d1);
		lt.push_back(d2);
		lt.push_back(d3);
		list<Date>::iterator pos = lt.begin();
		cout << pos->_year << endl; //输出第一个日期的年份
	}
}



//namespace cl
//{
//	//模拟实现list当中的结点类
//	template<class T>
//	struct _list_node
//	{
//		//成员函数
//		_list_node(const T& val = T()); //构造函数
//
//		//成员变量
//		T _val;                 //数据域
//		_list_node<T>* _next;   //后继指针
//		_list_node<T>* _prev;   //前驱指针
//	};
//
//	//模拟实现list迭代器
//	template<class T, class Ref, class Ptr>
//	struct _list_iterator
//	{
//		typedef _list_node<T> node;
//		typedef _list_iterator<T, Ref, Ptr> self;
//
//		_list_iterator(node* pnode);  //构造函数
//
//		//各种运算符重载函数
//		self operator++();
//		self operator--();
//		self operator++(int);
//		self operator--(int);
//		bool operator==(const self& s) const;
//		bool operator!=(const self& s) const;
//		Ref operator*();
//		Ptr operator->();
//
//		//成员变量
//		node* _pnode; //一个指向结点的指针
//	};
//
//	//模拟实现list
//	template<class T>
//	class list
//	{
//	public:
//		typedef _list_node<T> node;
//		typedef _list_iterator<T, T&, T*> iterator;
//		typedef _list_iterator<T, const T&, const T*> const_iterator;
//
//		//默认成员函数
//		list();
//		list(const list<T>& lt);
//		list<T>& operator=(const list<T>& lt);
//		~list();
//
//		//迭代器相关函数
//		iterator begin();
//		iterator end();
//		const_iterator begin() const;
//		const_iterator end() const;
//
//		//访问容器相关函数
//		T& front();
//		T& back();
//		const T& front() const;
//		const T& back() const;
//
//		//插入、删除函数
//		void insert(iterator pos, const T& x);
//		iterator erase(iterator pos);
//		void push_back(const T& x);
//		void pop_back();
//		void push_front(const T& x);
//		void pop_front();
//
//		//其他函数
//		size_t size() const;
//		void resize(size_t n, const T& val = T());
//		void clear();
//		bool empty() const;
//		void swap(list<T>& lt);
//
//	private:
//		node* _head; //指向链表头结点的指针
//	};
//}
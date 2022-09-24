//#include <iostream>
//#include <mutex>
//using namespace std;
//
//namespace cl
//{
//	//管理权转移
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		auto_ptr(auto_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{
//			ap._ptr = nullptr;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)
//		{
//			if (this != &ap)
//			{
//				if (_ptr != nullptr)
//					delete _ptr;
//				_ptr = ap._ptr;
//				ap._ptr = nullptr;
//			}
//			return *this;
//		}
//		~auto_ptr()
//		{
//			cout << "delete " << _ptr << endl;
//			if (_ptr != nullptr)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//	private:
//		T* _ptr;
//	};
//	//防拷贝
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		~unique_ptr()
//		{
//			cout << "delete " << _ptr << endl;
//			if (_ptr != nullptr)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		unique_ptr(unique_ptr<T>& ap) = delete;
//		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
//	private:
//		T* _ptr;
//	};
//	//通过引用计数支持拷贝
//	template<class T>
//	class shared_ptr
//	{
//	private:
//		void Release()
//		{
//			bool flag = false;
//			_mtx->lock();
//			if ((--*_count) == 0)
//			{
//				if (_ptr)
//				{
//					cout << "delete " << _ptr << endl;
//					delete _ptr;
//				}
//				delete _count;
//				flag = true;
//			}
//			_mtx->unlock();
//			if (flag)
//				delete _mtx;
//		}
//		void AddRefCount()
//		{
//			_mtx->lock();
//			(*_count)++;
//			_mtx->unlock();
//		}
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _count(new int(1))
//			, _mtx(new mutex)
//		{}
//		shared_ptr(shared_ptr<T>& ap)
//		{
//			_ptr = ap._ptr;
//			_count = ap._count;
//			_mtx = ap._mtx;
//			AddRefCount();
//		}
//		shared_ptr<T>& operator=(shared_ptr<T>& ap)
//		{
//			if (_ptr != ap._ptr)
//			{
//				Release();
//				_ptr = ap._ptr;
//				_count = ap._count;
//				_mtx = ap._mtx;
//				AddRefCount();
//			}
//			return *this;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		~shared_ptr()
//		{
//			Release();
//		}
//		T* get()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		int* _count;
//		mutex* _mtx;
//	};
//	template<class T>
//	class weak_ptr
//	{
//	public:
//		weak_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		weak_ptr(weak_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{}
//		weak_ptr<T>& operator=(shared_ptr<T>& ap)
//		{
//			_ptr = ap.get();
//			return *this;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		~weak_ptr()
//		{}
//	private:
//		T* _ptr;
//	};
//};
//int main()
//{
//	//int* ptr = new int(1);
//	//cout << *ptr << endl;
//	//*ptr = 4;
//	//cout << *ptr << endl;
//	//delete ptr;
//
//	//int* ptr = new int(1);
//	//cl::auto_ptr<int> ap(ptr);
//	//cl::auto_ptr<int> cap;
//	//cap = ap;
//	//cout << *cap << endl;
//	//*cap = 4;
//	//cout << *cap << endl;
//
//	//pair<int, int>* ptr = new pair<int, int>(2, 3);
//	//cout << ptr->first << ":" << ptr->second << endl;
//	//ptr->first = 5;
//	//ptr->second = 6;
//	//cout << ptr->first << ":" << ptr->second << endl;
//	//delete ptr;
//
//	//pair<int, int>* ptr = new pair<int, int>(2, 3);
//	//cl::auto_ptr<pair<int, int>> ap(ptr);
//	//cout << ap->first << ":" << ap->second << endl;
//	//ap->first = 5;
//	//ap->second = 6;
//	//cout << ap->first << ":" << ap->second << endl;
//
//	//int* ptr = new int(0);
//	//cl::shared_ptr<int> sp1(ptr);
//	//cl::shared_ptr<int> sp2(sp1);
//	//cl::shared_ptr<int> sp3;
//	//sp3 = sp2;
//
//	//struct Node
//	//{
//	//	Node()
//	//		:_next(nullptr)
//	//		, _prev(nullptr)
//	//	{}
//	//	~Node()
//	//	{
//	//		cout << "~Node()" << endl;
//	//	}
//	//	Node* _next;
//	//	Node* _prev;
//	//};
//	//Node* node1 = new Node;
//	//Node* node2 = new Node;
//	//node1->_next = node2;
//	//node2->_prev = node1;
//	//delete node1;
//	//delete node2;
//
//	//struct Node
//	//{
//	//	Node()
//	//	:_next(nullptr)
//	//	, _prev(nullptr)
//	//	{}
//	//	~Node()
//	//	{
//	//		cout << "~Node()" << endl;
//	//	}
//	//	cl::shared_ptr<Node> _next;
//	//	cl::shared_ptr<Node> _prev;
//	//};
//	//cl::shared_ptr<Node> node1(new Node);
//	//cl::shared_ptr<Node> node2(new Node);
//	//node1->_next = node2;
//	//node2->_prev = node1;
//
//	struct Node
//	{
//		Node()
//		:_next(nullptr)
//		, _prev(nullptr)
//		{}
//		~Node()
//		{
//			cout << "~Node()" << endl;
//		}
//		cl::weak_ptr<Node> _next;
//		cl::weak_ptr<Node> _prev;
//	};
//	cl::shared_ptr<Node> node1(new Node);
//	cl::shared_ptr<Node> node2(new Node);
//	node1->_next = node2;
//	node2->_prev = node1;
//	return 0;
//}


//#include <iostream>
//#include <exception>
//using namespace std;
//int div() //throw(invalid_argument)
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void func()
//{
//	int* ptr = new int;
//	try
//	{
//		cout << div() << endl;
//	}
//	catch (...)
//	{
//		delete ptr;
//		throw;
//	}
//
//	delete ptr;
//}
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <exception>
//using namespace std;
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		cout << "delete: " << _ptr << endl;
//		delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//int div() //throw(invalid_argument)
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void func()
//{
//	//int* ptr = new int;
//	//SmartPtr<int> sp(ptr);
//	SmartPtr<int> sp(new int);
//	
//	cout << div() << endl;
//}
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <exception>
//using namespace std;
//template<class T>
//class SmartPtr
//{
//public:
//	//RAII
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		cout << "delete: " << _ptr << endl;
//		delete _ptr;
//	}
//	//可以像指针一样使用
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//int main()
//{
//	SmartPtr<int> sp1(new int(1));
//	*sp1 = 10;
//	SmartPtr<pair<int, int>> sp2(new pair<int, int>(1, 2));
//	sp2->first = 3;
//	sp2->second = 4;
//
//	return 0;
//}


#include <iostream>
#include <exception>
#include <thread>
#include <memory>
#include <mutex>
using namespace std;
namespace cl
{
	//C++98 -- 管理权转移
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr != nullptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		auto_ptr& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				delete _ptr; //释放自己的
				_ptr = ap._ptr; //接管别人的
				ap._ptr = nullptr; //把别人的置空（管理权转移）
			}
			return *this;
		}
		//可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
	//C++11 -- 防拷贝
	template<class T>
	class unique_ptr
	{
	public:
		//RAII
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		~unique_ptr()
		{
			if (_ptr != nullptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//防拷贝
		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr& operator=(unique_ptr<T>& up) = delete;
	private:
		T* _ptr;
	};
	//C++11 -- 引用计数
	template<class T>
	class shared_ptr
	{
	private:
		void AddRef()
		{
			_pmutex->lock();
			(*_pcount)++;
			_pmutex->unlock();
		}
		void ReleaseRef()
		{
			_pmutex->lock();
			bool flag = false;
			if (--(*_pcount) == 0)
			{
				if (_ptr != nullptr)
				{
					cout << "delete: " << _ptr << endl;
					delete _ptr;
					delete _pcount;
					_ptr = nullptr;
					_pcount = nullptr;
					flag = true;
				}
			}
			_pmutex->unlock();
			if (flag == true)
			{
				delete _pmutex;
			}
		}
	public:
		//RAII
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
		{}
		~shared_ptr()
		{
			ReleaseRef();
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmutex(sp._pmutex)
		{
			AddRef();
		}
		shared_ptr& operator=(shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr) //管理同一块空间的对象之间无需进行赋值操作
			{
				ReleaseRef();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmutex = sp._pmutex;
				AddRef();
			}
			return *this;
		}
		int use_count()
		{
			return *_pcount;
		}
		//可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
	};
	//template<class T>
	//class shared_ptr
	//{
	//public:
	//	//RAII
	//	shared_ptr(T* ptr)
	//		:_ptr(ptr)
	//		, _pcount(new int(1))
	//	{}
	//	~shared_ptr()
	//	{
	//		if (--(*_pcount) == 0)
	//		{
	//			if (_ptr != nullptr)
	//			{
	//				cout << "delete: " << _ptr << endl;
	//				delete _ptr;
	//				delete _pcount;
	//				_ptr = nullptr;
	//				_pcount = nullptr;
	//			}
	//		}
	//	}
	//	shared_ptr(shared_ptr<T>& sp)
	//		:_ptr(sp._ptr)
	//		, _pcount(sp._pcount)
	//	{
	//		(*_pcount)++;
	//	}
	//	shared_ptr& operator=(shared_ptr<T>& sp)
	//	{
	//		if (_ptr != sp._ptr) //管理同一块空间的对象之间无需进行赋值操作
	//		{
	//			if (--(*_pcount) == 0)
	//			{
	//				delete _ptr;
	//				delete _pcount;
	//			}
	//			_ptr = sp._ptr;
	//			_pcount = sp._pcount;
	//			(*_pcount)++;
	//		}
	//		return *this;
	//	}
	//	//可以像指针一样使用
	//	T& operator*()
	//	{
	//		return *_ptr;
	//	}
	//	T* operator->()
	//	{
	//		return _ptr;
	//	}
	//private:
	//	T* _ptr;
	//	int* _pcount;
	//};
}
//int main()
//{
//	//cl::auto_ptr<int> ap1(new int(1));
//	//cl::auto_ptr<int> ap2(sp1);
//	//*ap2 = 10;
//	////*ap1 = 20; //error
//
//	cl::auto_ptr<int> ap1(new int(1));
//	cl::auto_ptr<int> ap2(new int(2));
//	ap1 = ap2;
//	return 0;
//}
//int main()
//{
//	cl::unique_ptr<int> up1(new int(0));
//	//cl::unique_ptr<int> up2(up1);
//	return 0;
//}
//int main()
//{
//	//cl::shared_ptr<int> sp1(new int(0));
//	//cl::shared_ptr<int> sp2(sp1);
//	//cout << *sp1 << endl;
//	//*sp1 = 10;
//	//cout << *sp1 << endl;
//	//*sp2 = 20;
//	//cout << *sp1 << endl;
//	//cout << sp1.use_count() << endl;
//
//	cl::shared_ptr<int> sp1(new int(0));
//	cl::shared_ptr<int> sp2(sp1);
//
//	cl::shared_ptr<int> sp3(new int(0));
//	cl::shared_ptr<int> sp4(sp3);
//	cl::shared_ptr<int> sp5(sp3);
//	sp1 = sp1;
//	sp1 = sp2;
//	sp1 = sp3;
//	return 0;
//}
struct Date
{
	int _year = 0;
	int _month = 0;
	int _day = 0;
};
void func(cl::shared_ptr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cl::shared_ptr<Date> copy(sp);

		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
int main()
{
	cl::shared_ptr<Date> p(new Date);

	const size_t n = 10000;
	thread t1(func, p, n);
	thread t2(func, p, n);

	t1.join();
	t2.join();

	cout << p.use_count() << endl;

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	
	return 0;
}
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
//	//SmartPtr<int> sp1(new int(1));
//	//*sp1 = 10;
//	//SmartPtr<pair<int, int>> sp2(new pair<int, int>(1, 2));
//	//sp2->first = 3;
//	//sp2->second = 4;
//
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1); //拷贝构造
//
//	SmartPtr<int> sp3(new int);
//	SmartPtr<int> sp4(new int);
//	sp3 = sp4; //拷贝赋值
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
		auto_ptr(T* ptr = nullptr)
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
			ap._ptr = nullptr; //管理权转移后ap被置空
		}
		auto_ptr& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				delete _ptr;       //释放自己管理的资源
				_ptr = ap._ptr;    //接管ap对象的资源
				ap._ptr = nullptr; //管理权转移后ap被置空
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
		T* _ptr; //管理的资源
	};
	//C++11 -- 防拷贝
	template<class T>
	class unique_ptr
	{
	public:
		//RAII
		unique_ptr(T* ptr = nullptr)
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
		T* _ptr; //管理的资源
	};
	template<class T>
	class Delete
	{
		void operator()(const T* ptr)
		{
			delete ptr;
		}
	};
	//C++11 -- 引用计数
	template<class T, class D = Delete<T>>
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
					//delete _ptr;
					_del(_ptr);
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmutex->unlock();
			if (flag == true)
			{
				delete _pmutex;
			}
		}
	public:
		//RAII
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
		{}
		shared_ptr(T* ptr, D del)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
			, _del(del)
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
		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
		D _del;
	};
	////C++11 -- 引用计数
	//template<class T>
	//class shared_ptr
	//{
	//private:
	//	void AddRef()
	//	{
	//		_pmutex->lock();
	//		(*_pcount)++;
	//		_pmutex->unlock();
	//	}
	//	void ReleaseRef()
	//	{
	//		_pmutex->lock();
	//		bool flag = false;
	//		if (--(*_pcount) == 0)
	//		{
	//			if (_ptr != nullptr)
	//			{
	//				cout << "delete: " << _ptr << endl;
	//				delete _ptr;
	//				delete _pcount;
	//				_ptr = nullptr;
	//				_pcount = nullptr;
	//				flag = true;
	//			}
	//		}
	//		_pmutex->unlock();
	//		if (flag == true)
	//		{
	//			delete _pmutex;
	//		}
	//	}
	//public:
	//	//RAII
	//	shared_ptr(T* ptr = nullptr)
	//		:_ptr(ptr)
	//		, _pcount(new int(1))
	//		, _pmutex(new mutex)
	//	{}
	//	//template<class D>
	//	//shared_ptr(T* ptr, D del)
	//	//	: _ptr(ptr)
	//	//	, _pcount(new int(1))
	//	//	, _pmutex(new mutex)
	//	//	, _del(del)
	//	//{}
	//	~shared_ptr()
	//	{
	//		ReleaseRef();
	//	}
	//	shared_ptr(shared_ptr<T>& sp)
	//		:_ptr(sp._ptr)
	//		, _pcount(sp._pcount)
	//		, _pmutex(sp._pmutex)
	//	{
	//		AddRef();
	//	}
	//	shared_ptr& operator=(shared_ptr<T>& sp)
	//	{
	//		if (_ptr != sp._ptr) //管理同一块空间的对象之间无需进行赋值操作
	//		{
	//			ReleaseRef();
	//			_ptr = sp._ptr;
	//			_pcount = sp._pcount;
	//			_pmutex = sp._pmutex;
	//			AddRef();
	//		}
	//		return *this;
	//	}
	//	int use_count()
	//	{
	//		return *_pcount;
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
	//	T* get() const
	//	{
	//		return _ptr;
	//	}
	//private:
	//	T* _ptr;
	//	int* _pcount;
	//	mutex* _pmutex;
	//	//D _del;
	//};
	//C++11 -- 弱指针
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}
		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}
		weak_ptr& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
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
//资源转移
//int main()
//{
//	std::auto_ptr<int> ap1(new int(1));
//	std::auto_ptr<int> ap2(ap1);
//	*ap2 = 10;
//	//*ap1 = 20; //error
//
//	std::auto_ptr<int> ap3(new int(1));
//	std::auto_ptr<int> ap4(new int(2));
//	ap3 = ap4;
//	return 0;
//}
//防拷贝
int main()
{
	std::unique_ptr<int> up1(new int(0));
	//std::unique_ptr<int> up2(up1); //error
	return 0;
}
//资源共享
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
//线程安全
//struct Date
//{
//	int _year = 0;
//	int _month = 0;
//	int _day = 0;
//};
//void func(cl::shared_ptr<Date>& sp, size_t n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cl::shared_ptr<Date> copy(sp);
//
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	cl::shared_ptr<Date> p(new Date);
//
//	const size_t n = 10000;
//	thread t1(func, p, n);
//	thread t2(func, p, n);
//
//	t1.join();
//	t2.join();
//
//	cout << p.use_count() << endl;
//
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	
//	return 0;
//}
//循环引用
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _val;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	ListNode* node1 = new ListNode;
//	ListNode* node2 = new ListNode;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//	//...
//	delete node1;
//	delete node2;
//	return 0;
//}
//struct ListNode
//{
//	cl::shared_ptr<ListNode> _next;
//	cl::shared_ptr<ListNode> _prev;
//	int _val;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	cl::shared_ptr<ListNode> node1(new ListNode);
//	cl::shared_ptr<ListNode> node2(new ListNode);
//
//	node1->_next = node2;
//	node2->_prev = node1;
//	//...
//
//	return 0;
//}
struct ListNode
{
	cl::weak_ptr<ListNode> _next;
	cl::weak_ptr<ListNode> _prev;
	int _val;
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};
//int main()
//{
//	cl::shared_ptr<ListNode> node1(new ListNode);
//	cl::shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	//...
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}
//定制删除器
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	std::unique_ptr<int> up(pa);
//	return 0;
//}
//int main()
//{
//	//std::shared_ptr<ListNode> sp1(new ListNode[10]);
//	std::shared_ptr<FILE> sp2(fopen("test.cpp", "r"));
//
//	return 0;
//}
//template<class T>
//struct DelArr
//{
//	void operator()(const T* ptr)
//	{
//		cout << "delete[]: " << ptr << endl;
//		delete[] ptr;
//	}
//};
//int main()
//{
//	std::shared_ptr<ListNode> sp1(new ListNode[10], DelArr<ListNode>());
//	std::shared_ptr<FILE> sp2(fopen("test.cpp", "r"), [](FILE* ptr){
//		cout << "fclose: " << ptr << endl;
//		fclose(ptr);
//	});
//
//	return 0;
//}
//template<class T>
//struct DelArr
//{
//	void operator()(const T* ptr)
//	{
//		cout << "delete[]: " << ptr << endl;
//		delete[] ptr;
//	}
//};
//int main()
//{
//	cl::shared_ptr<ListNode, DelArr<ListNode>> sp1(new ListNode[10], DelArr<ListNode>());
//	//cl::shared_ptr<FILE, function<void(FILE*)>> sp2(fopen("test.cpp", "r"), [](FILE* ptr){
//	//	cout << "fclose: " << ptr << endl;
//	//	fclose(ptr);
//	//});
//	auto f = [](FILE* ptr){
//		cout << "fclose: " << ptr << endl;
//		fclose(ptr);
//	};
//	cl::shared_ptr<FILE, decltype(f)> sp2(fopen("test.cpp", "r"), f);
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//struct A{
//	A(){ //cout << typeid(this).name() << endl; 
//		foo(); }
//	virtual ~A(){ //cout << typeid(this).name() << endl; 
//		foo(); }
//	virtual void foo(){ //cout << typeid(this).name() << endl; 
//		cout << "A"; }
//	void bar(){ foo(); }
//};
//struct B :public A{
//	virtual void foo(){ cout << "B"; }
//};
//int main()
//{
//	B b;
//	b.bar();
//	return 0;
//} //ABA

//请设计一个类，只能在堆上创建对象
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	static HeapOnly* GetObj()
//	{
//		return new HeapOnly();
//	}
//private:
//	HeapOnly()
//	{}
//	HeapOnly(const HeapOnly& obj) = delete;
//};
//int main()
//{
//	HeapOnly* p = HeapOnly::GetObj();
//	//HeapOnly h(*p);
//	return 0;
//}

//请设计一个类，只能在栈上创建对象
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	static StackOnly GetObj()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
//int main()
//{
//	StackOnly obj = StackOnly::GetObj();
//	return 0;
//}

//请设计一个类，不能被拷贝
//#include <iostream>
//using namespace std;
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//private:
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//};
//int main()
//{
//	CopyBan obj1;
//	CopyBan obj2;
//	//obj1 = obj2;
//	return 0;
//}

//请设计一个类，不能被继承
//#include <iostream>
//using namespace std;
//class NonInherit
//{
//public:
//private:
//	NonInherit()
//	{}
//};
//class A :public NonInherit
//{};
//int main()
//{
//	A a;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class NonInherit final
//{
//public:
//private:
//	NonInherit()
//	{}
//};
//class A :public NonInherit
//{};
//int main()
//{
//	return 0;
//}

//请设计一个类，只能创建一个对象（单例模式）
//#include <iostream>
//using namespace std;
////饿汉模式
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &_Inst;
//	}
//	void Print()
//	{
//		cout << "OK" << endl;
//	}
//private:
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	static Singleton _Inst;
//};
//
////Singleton Singleton::_Inst = new Singleton();
//Singleton Singleton::_Inst;
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	Singleton::GetInstance()->Print();
//	//Singleton s(*Singleton::GetInstance());
//	//s.Print();
//	return 0;
//}

//#include <iostream>
//#include <mutex>
//using namespace std;
////懒汉模式
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		if (_Inst == nullptr)
//		{
//			_mtx.lock();
//			if (_Inst == nullptr)
//			{
//				_Inst = new Singleton();
//			}
//			_mtx.unlock();
//		}
//		return _Inst;
//	}
//	void Print()
//	{
//		cout << "OK" << endl;
//	}
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (_Inst != nullptr)
//			{
//				delete _Inst;
//				_Inst = nullptr;
//				cout << "Yes" << endl;
//			}
//		}
//	};
//private:
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton* _Inst;
//	static mutex _mtx;
//	static CGarbo _Garbo;
//};
//
////Singleton Singleton::_Inst = new Singleton();
//Singleton* Singleton::_Inst = nullptr;
//mutex Singleton::_mtx;
//Singleton::CGarbo Singleton::_Garbo;
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	Singleton::GetInstance()->Print();
//	//Singleton s(*Singleton::GetInstance());
//	//s.Print();
//	return 0;
//}


//请设计一个类，只能在堆上创建对象
//#include <iostream>
//using namespace std;
//class HeapOnly
//{
//public:
//	//2、提供一个获取对象的接口，并且该接口必须设置为静态成员函数
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//private:
//	//1、将构造函数设置为私有
//	HeapOnly()
//	{}
//	//3、将拷贝构造函数设置为私有，并且只声明不实现
//	//C++98
//	HeapOnly(const HeapOnly&);
//	//C++11
//	//HeapOnly(const HeapOnly&) = delete;
//};
//int main()
//{
//	HeapOnly* p = HeapOnly::CreateObj();
//	//HeapOnly copy(*p);
//	return 0;
//}

//请设计一个类，只能在栈上创建对象
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	//2、提供一个获取对象的接口，并且该接口必须设置为静态成员函数
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//private:
//	//1、将构造函数设置为私有
//	StackOnly()
//	{}
//};
//int main()
//{
//	StackOnly obj1 = StackOnly::CreateObj();
//	static StackOnly obj2(obj1); //在静态区拷贝构造对象
//	StackOnly* ptr = new StackOnly(obj1); //在堆上拷贝构造对象
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class StackOnly
//{
//public:
//	StackOnly()
//	{}
//private:
//	//C++98
//	void* operator new(size_t size);
//	void operator delete(void* p);
//	//C++11
//	//void* operator new(size_t size) = delete;
//	//void operator delete(void* p) = delete;
//};
//int main()
//{
//	StackOnly s;
//	static StackOnly obj; //在静态区创建对象
//	return 0;
//}

//请设计一个类，不能被拷贝
//#include <iostream>
//using namespace std;
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//private:
//	//C++98
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//	//C++11
//	//CopyBan(const CopyBan&) = delete;
//	//CopyBan& operator=(const CopyBan&) = delete;
//};
//int main()
//{
//	CopyBan c;
//	return 0;
//}

//请设计一个类，不能被继承
//C++98
//#include <iostream>
//using namespace std;
//class NonInherit
//{
//public:
//	static NonInherit CreateObj()
//	{
//		return NonInherit();
//	}
//private:
//	//将构造函数设置为私有
//	NonInherit()
//	{}
//};
//class A :public NonInherit
//{};
//int main()
//{
//	A a;
//	return 0;
//}

//C++11
//#include <iostream>
//using namespace std;
//class NonInherit final
//{
//	//...
//};
//class A :public NonInherit
//{};
//int main()
//{
//	return 0;
//}


//请设计一个类，只能创建一个对象（单例模式）
//饿汉模式
//#include <iostream>
//using namespace std;
//class Singleton
//{
//public:
//	//3、提供一个全局访问点获取单例对象
//	static Singleton* GetInstance()
//	{
//		return _inst;
//	}
//private:
//	//1、将构造函数设置为私有，并防拷贝
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	//2、提供一个指向单例对象的static指针
//	static Singleton* _inst;
//};
//
////在程序入口之前完成单例对象的初始化
//Singleton* Singleton::_inst = new Singleton;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	return 0;
//}

//懒汉模式
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	//3、提供一个全局访问点获取单例对象
//	static Singleton* GetInstance()
//	{
//		//双检查
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//private:
//	//1、将构造函数设置为私有，并防拷贝
//	Singleton()
//	{}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	//2、提供一个指向单例对象的static指针
//	static Singleton* _inst;
//	static mutex _mtx; //互斥锁
//};
//
////在程序入口之前先将static指针初始化为空
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx; //初始化互斥锁
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	char* p = new char[1024 * 1024 * 1024];
//	return 0;
//}

////释放
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		//双检查加锁
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//	static void DelInstance()
//	{
//		_mtx.lock();
//		if (_inst != nullptr)
//		{
//			delete _inst;
//			_inst = nullptr;
//		}
//		_mtx.unlock();
//	}
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* _inst;
//	static mutex _mtx;
//};
//
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	char* p = new char[1024 * 1024 * 1024];
//	return 0;
//}

////释放
//#include <iostream>
//#include <mutex>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		//双检查加锁
//		if (_inst == nullptr)
//		{
//			_mtx.lock();
//			if (_inst == nullptr)
//			{
//				_inst = new Singleton;
//			}
//			_mtx.unlock();
//		}
//		return _inst;
//	}
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (_inst != nullptr)
//			{
//				delete _inst;
//				_inst = nullptr;
//			}
//		}
//	};
//private:
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton* _inst;
//	static mutex _mtx;
//	static CGarbo _gc;
//};
//
//Singleton* Singleton::_inst = nullptr;
//mutex Singleton::_mtx;
//Singleton::CGarbo Singleton::_gc;
//
//int main()
//{
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//	return 0;
//}

//其他版本懒汉
#include <iostream>
#include <mutex>
using namespace std;
class Singleton
{
public:
	//2、提供一个全局访问点获取单例对象
	static Singleton* GetInstance()
	{
		static Singleton inst;
		return &inst;
	}
private:
	//1、将构造函数设置为私有，并防拷贝
	Singleton()
	{}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}